# TDownRemaster Linux Build Dockerfile
# Multi-stage build for creating Linux packages

FROM ubuntu:22.04 AS builder

# Set environment variables
ENV APP_NAME="TDownRemaster"
ENV APP_VERSION="5.4.9"
ENV DEBIAN_FRONTEND=noninteractive

# Install build dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    qt6-base-dev \
    qt6-svg-dev \
    qt6-tools-dev \
    qml6-module-qtquick-controls2 \
    qml6-module-qtwebsockets \
    qml6-module-qtwebchannel \
    qt6-tools-dev-tools \
    appimagetool \
    dpkg-dev \
    rpm \
    wget \
    curl \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy source code
COPY . .

# Build the application
RUN mkdir -p build && \
    cd build && \
    cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr && \
    make -j$(nproc)

# Create AppDir structure
RUN mkdir -p AppDir/usr/bin && \
    mkdir -p AppDir/usr/lib && \
    mkdir -p AppDir/usr/share/applications && \
    mkdir -p AppDir/usr/share/icons/hicolor/256x256/apps && \
    mkdir -p AppDir/usr/share/metainfo

# Copy application files
RUN cp build/TDownRemaster AppDir/usr/bin/ && \
    cp build/*.so* AppDir/usr/lib/ 2>/dev/null || true

# Copy Qt libraries
RUN cp /usr/lib/x86_64-linux-gnu/libQt6*.so* AppDir/usr/lib/ 2>/dev/null || true

# Copy Qt plugins
RUN mkdir -p AppDir/usr/plugins/platforms && \
    mkdir -p AppDir/usr/plugins/imageformats && \
    mkdir -p AppDir/usr/plugins/iconengines && \
    mkdir -p AppDir/usr/plugins/styles && \
    cp /usr/lib/x86_64-linux-gnu/qt6/plugins/platforms/libqxcb.so AppDir/usr/plugins/platforms/ 2>/dev/null || true && \
    cp /usr/lib/x86_64-linux-gnu/qt6/plugins/imageformats/*.so AppDir/usr/plugins/imageformats/ 2>/dev/null || true && \
    cp /usr/lib/x86_64-linux-gnu/qt6/plugins/iconengines/*.so AppDir/usr/plugins/iconengines/ 2>/dev/null || true

# Create desktop file
RUN cat > AppDir/usr/share/applications/TDownRemaster.desktop << 'EOF' && \
[Desktop Entry]
Name=TDownRemaster
Comment=Media Downloader
Comment[tr]=Medya İndirici
Exec=TDownRemaster
Icon=TDownRemaster
Terminal=false
Type=Application
Categories=AudioVideo;Audio;Video;
MimeType=application/x-mpegURL;application/vnd.apple.mpegurl;audio/x-mpegurl;video/x-mpegURL;
EOF

# Create AppStream metadata
RUN cat > AppDir/usr/share/metainfo/TDownRemaster.metainfo.xml << 'EOF' && \
<?xml version="1.0" encoding="UTF-8"?>
<component type="desktop-application">
  <id>TDownRemaster</id>
  <metadata_license>CC0-1.0</metadata_license>
  <project_license>GPL-2.0+</project_license>
  <name>TDownRemaster</name>
  <summary>Media Downloader</summary>
  <summary xml:lang="tr">Medya İndirici</summary>
  <description>
    <p>TDownRemaster is a powerful media downloader that supports multiple platforms and formats.</p>
    <p xml:lang="tr">TDownRemaster, birden çok platformu ve formatı destekleyen güçlü bir medya indiricidir.</p>
  </description>
  <launchable type="desktop-id">TDownRemaster.desktop</launchable>
  <provides>
    <binary>TDownRemaster</binary>
  </provides>
  <url type="homepage">https://github.com/tda45/tdown-remaster</url>
  <url type="bugtracker">https://github.com/tda45/tdown-remaster/issues</url>
  <url type="help">https://github.com/tda45/tdown-remaster/wiki</url>
  <releases>
    <release version="5.4.9" date="2024-03-14"/>
  </releases>
</component>
EOF

# Create AppRun script
RUN cat > AppDir/AppRun << 'EOF' && \
#!/bin/bash
HERE="$(dirname "$(readlink -f "$0)")"
export LD_LIBRARY_PATH="${HERE}/usr/lib:${LD_LIBRARY_PATH}"
export QT_PLUGIN_PATH="${HERE}/usr/plugins"
export QT_QPA_PLATFORM_PLUGIN_PATH="${HERE}/usr/plugins/platforms"
exec "${HERE}/usr/bin/TDownRemaster" "$@"
EOF && \
chmod +x AppDir/AppRun

# Create AppImage
RUN wget https://github.com/AppImage/appimagetool/releases/download/continuous/appimagetool-x86_64.AppImage && \
    chmod +x appimagetool-x86_64.AppImage && \
    ./appimagetool-x86_64.AppImage AppDir TDownRemaster-5.4.9-x86_64.AppImage

# Create DEB package
RUN mkdir -p deb-package/DEBIAN && \
cat > deb-package/DEBIAN/control << 'EOF' && \
Package: tdownremaster
Version: 5.4.9
Section: sound
Priority: optional
Architecture: amd64
Depends: libqt6core6, libqt6gui6, libqt6widgets6, libqt6network6, libqt6svg6
Maintainer: TDownRemaster Team <support@tdownremaster.com>
Description: Media Downloader
 TDownRemaster is a powerful media downloader that supports multiple platforms
 and formats including YouTube, Vimeo, and many others.
 .
 This package includes the TDownRemaster GUI application with all necessary
 dependencies for media downloading and conversion.
EOF

# Copy files for DEB
RUN mkdir -p deb-package/usr/bin && \
    mkdir -p deb-package/usr/lib && \
    mkdir -p deb-package/usr/share/applications && \
    mkdir -p deb-package/usr/share/icons/hicolor/256x256/apps && \
    mkdir -p deb-package/usr/share/metainfo && \
    cp AppDir/usr/bin/TDownRemaster deb-package/usr/bin/ && \
    cp -r AppDir/usr/lib/* deb-package/usr/lib/ 2>/dev/null || true && \
    cp AppDir/usr/share/applications/*.desktop deb-package/usr/share/applications/ && \
    cp -r AppDir/usr/share/icons/* deb-package/usr/share/icons/ 2>/dev/null || true && \
    cp AppDir/usr/share/metainfo/*.xml deb-package/usr/share/metainfo/ && \
    dpkg-deb --build deb-package TDownRemaster_5.4.9_amd64.deb

# Create output directory
FROM scratch AS output
COPY --from=builder /app/TDownRemaster-5.4.9-x86_64.AppImage /
COPY --from=builder /app/TDownRemaster_5.4.9_amd64.deb /

# Final build stage
FROM ubuntu:22.04 AS final

# Install runtime dependencies
RUN apt-get update && apt-get install -y \
    libqt6core6 \
    libqt6gui6 \
    libqt6widgets6 \
    libqt6network6 \
    libqt6svg6 \
    && rm -rf /var/lib/apt/lists/*

# Create app user
RUN useradd -m -u 1000 tdown && \
    mkdir -p /opt/tdownremaster && \
    chown tdown:tdown /opt/tdownremaster

# Copy application
COPY --from=builder /app/AppDir /opt/tdownremaster/

# Switch to app user
USER tdown
WORKDIR /opt/tdownremaster

# Set environment variables
ENV LD_LIBRARY_PATH="/opt/tdownremaster/usr/lib:${LD_LIBRARY_PATH}"
ENV QT_PLUGIN_PATH="/opt/tdownremaster/usr/plugins"
ENV QT_QPA_PLATFORM_PLUGIN_PATH="/opt/tdownremaster/usr/plugins/platforms"

# Expose application
EXPOSE 8080

# Set entrypoint
ENTRYPOINT ["/opt/tdownremaster/AppRun"]
CMD ["--help"]
