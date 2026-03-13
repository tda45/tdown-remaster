#!/bin/bash

# TDownRemaster Linux Build Script
# Creates AppImage, DEB and RPM packages

set -e

APP_NAME="TDownRemaster"
APP_VERSION="1.0.0"
BUILD_DIR="build-linux"
APPDIR="AppDir"

echo "🚀 Building TDownRemaster for Linux..."

# Clean previous builds
rm -rf $BUILD_DIR $APPDIR
mkdir -p $BUILD_DIR

# Install dependencies
echo "📦 Installing dependencies..."
sudo apt update
sudo apt install -y build-essential cmake git
sudo apt install -y qt6-base-dev qt6-svg-dev qt6-tools-dev \
    qml6-module-qtquick-controls2 qml6-module-qtwebsockets \
    qml6-module-qtwebchannel qt6-tools-dev-tools

# Install packaging tools
sudo apt install -y appimagetool dpkg-dev rpm

# Build the application
echo "📦 Building with CMake..."
cd $BUILD_DIR
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
make -j$(nproc)

# Create AppDir structure
echo "📁 Creating AppDir structure..."
cd ..
mkdir -p $APPDIR/usr/bin
mkdir -p $APPDIR/usr/lib
mkdir -p $APPDIR/usr/share/applications
mkdir -p $APPDIR/usr/share/icons/hicolor/256x256/apps
mkdir -p $APPDIR/usr/share/metainfo

# Copy application files
echo "📋 Copying application files..."
cp $BUILD_DIR/TDownRemaster $APPDIR/usr/bin/
cp $BUILD_DIR/*.so* $APPDIR/usr/lib/ 2>/dev/null || true

# Copy Qt libraries
echo "🔧 Copying Qt libraries..."
QT_PATH="/usr/lib/x86_64-linux-gnu"
if [ -d "$QT_PATH" ]; then
    cp $QT_PATH/libQt6*.so* $APPDIR/usr/lib/ 2>/dev/null || true
fi

# Copy Qt plugins
echo "🔌 Copying Qt plugins..."
mkdir -p $APPDIR/usr/plugins/platforms
mkdir -p $APPDIR/usr/plugins/imageformats
mkdir -p $APPDIR/usr/plugins/iconengines
mkdir -p $APPDIR/usr/plugins/styles

QT_PLUGINS="/usr/lib/x86_64-linux-gnu/qt6/plugins"
if [ -d "$QT_PLUGINS" ]; then
    cp $QT_PLUGINS/platforms/libqxcb.so $APPDIR/usr/plugins/platforms/ 2>/dev/null || true
    cp $QT_PLUGINS/imageformats/*.so $APPDIR/usr/plugins/imageformats/ 2>/dev/null || true
    cp $QT_PLUGINS/iconengines/*.so $APPDIR/usr/plugins/iconengines/ 2>/dev/null || true
fi

# Create desktop file
echo "📄 Creating desktop file..."
cat > $APPDIR/usr/share/applications/${APP_NAME}.desktop << EOF
[Desktop Entry]
Name=TDownRemaster
Comment=Media Downloader
Comment[tr]=Medya İndirici
Exec=TDownRemaster
Icon=${APP_NAME}
Terminal=false
Type=Application
Categories=AudioVideo;Audio;Video;
MimeType=application/x-mpegURL;application/vnd.apple.mpegurl;audio/x-mpegurl;video/x-mpegURL;
EOF

# Create AppStream metadata
echo "📝 Creating AppStream metadata..."
cat > $APPDIR/usr/share/metainfo/${APP_NAME}.metainfo.xml << EOF
<?xml version="1.0" encoding="UTF-8"?>
<component type="desktop-application">
  <id>${APP_NAME}</id>
  <metadata_license>CC0-1.0</metadata_license>
  <project_license>GPL-2.0+</project_license>
  <name>TDownRemaster</name>
  <summary>Media Downloader</summary>
  <summary xml:lang="tr">Medya İndirici</summary>
  <description>
    <p>TDownRemaster is a powerful media downloader that supports multiple platforms and formats.</p>
    <p xml:lang="tr">TDownRemaster, birden çok platformu ve formatı destekleyen güçlü bir medya indiricidir.</p>
  </description>
  <launchable type="desktop-id">${APP_NAME}.desktop</launchable>
  <provides>
    <binary>TDownRemaster</binary>
  </provides>
  <url type="homepage">https://github.com/tda45/tdown-remaster</url>
  <url type="bugtracker">https://github.com/tda45/tdown-remaster/issues</url>
  <url type="help">https://github.com/tda45/tdown-remaster/wiki</url>
  <releases>
    <release version="${APP_VERSION}" date="2024-03-14"/>
  </releases>
</component>
EOF

# Copy icon (if available)
if [ -f "icon.ico" ]; then
    # Convert to PNG if possible
    if command -v convert >/dev/null 2>&1; then
        convert icon.ico -resize 256x256 $APPDIR/usr/share/icons/hicolor/256x256/apps/${APP_NAME}.png
    else
        cp icon.ico $APPDIR/usr/share/icons/hicolor/256x256/apps/${APP_NAME}.ico
    fi
fi

# Create AppRun script
echo "🏃 Creating AppRun script..."
cat > $APPDIR/AppRun << EOF
#!/bin/bash
HERE="\$(dirname "\$(readlink -f "\$0")")"
export LD_LIBRARY_PATH="\${HERE}/usr/lib:\${LD_LIBRARY_PATH}"
export QT_PLUGIN_PATH="\${HERE}/usr/plugins"
export QT_QPA_PLATFORM_PLUGIN_PATH="\${HERE}/usr/plugins/platforms"
exec "\${HERE}/usr/bin/TDownRemaster" "\$@"
EOF
chmod +x $APPDIR/AppRun

# Create AppImage
echo "📦 Creating AppImage..."
if command -v appimagetool >/dev/null 2>&1; then
    appimagetool $APPDIR ${APP_NAME}-${APP_VERSION}-x86_64.AppImage
else
    echo "⚠️  appimagetool not found, skipping AppImage creation"
fi

# Create DEB package
echo "📦 Creating DEB package..."
mkdir -p deb-package/DEBIAN
cat > deb-package/DEBIAN/control << EOF
Package: tdownremaster
Version: ${APP_VERSION}
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
mkdir -p deb-package/usr/bin
mkdir -p deb-package/usr/lib
mkdir -p deb-package/usr/share/applications
mkdir -p deb-package/usr/share/icons/hicolor/256x256/apps
mkdir -p deb-package/usr/share/metainfo

cp $APPDIR/usr/bin/TDownRemaster deb-package/usr/bin/
cp -r $APPDIR/usr/lib/* deb-package/usr/lib/ 2>/dev/null || true
cp $APPDIR/usr/share/applications/*.desktop deb-package/usr/share/applications/
cp -r $APPDIR/usr/share/icons/* deb-package/usr/share/icons/ 2>/dev/null || true
cp $APPDIR/usr/share/metainfo/*.xml deb-package/usr/share/metainfo/

# Build DEB
dpkg-deb --build deb-package ${APP_NAME}_${APP_VERSION}_amd64.deb

# Create RPM package (if rpmbuild is available)
if command -v rpmbuild >/dev/null 2>&1; then
    echo "📦 Creating RPM package..."
    mkdir -p ~/rpmbuild/SPECS
    mkdir -p ~/rpmbuild/SOURCES
    mkdir -p ~/rpmbuild/BUILD
    
    cat > ~/rpmbuild/SPECS/${APP_NAME}.spec << EOF
Name:           ${APP_NAME}
Version:        ${APP_VERSION}
Release:        1%{?dist}
Summary:        Media Downloader
License:        GPL-2.0+
URL:            https://github.com/tda45/tdown-remaster
Source0:        %{name}-%{version}.tar.gz

BuildRequires:  qt6-qtbase-devel
BuildRequires:  qt6-qtsvg-devel
BuildRequires:  gcc
BuildRequires:  cmake

Requires:       qt6-qtbase
Requires:       qt6-qtsvg

%description
TDownRemaster is a powerful media downloader that supports multiple platforms
and formats including YouTube, Vimeo, and many others.

%prep
%autosetup

%build
%cmake
%cmake_build

%install
%cmake_install

%files
%license LICENSE
%doc README.md
%{_bindir}/TDownRemaster
%{_libdir}/*.so*
%{_datadir}/applications/*.desktop
%{_datadir}/icons/hicolor/256x256/apps/*.png
%{_datadir}/metainfo/*.xml

%changelog
* $(date +'%a %b %d %Y') TDownRemaster Team <support@tdownremaster.com> - ${APP_VERSION}-1
- Initial RPM release
EOF
    
    # Build RPM
    rpmbuild -ba ~/rpmbuild/SPECS/${APP_NAME}.spec
    cp ~/rpmbuild/RPMS/x86_64/${APP_NAME}-${APP_VERSION}-1.x86_64.rpm ./
else
    echo "⚠️  rpmbuild not found, skipping RPM creation"
fi

echo "✅ Linux packages created successfully!"
echo "📦 Generated files:"
ls -la *.AppImage *.deb *.rpm 2>/dev/null || echo "Some packages may not have been created"

echo ""
echo "🚀 Installation instructions:"
echo "  AppImage: chmod +x ${APP_NAME}-${APP_VERSION}-x86_64.AppImage && ./${APP_NAME}-${APP_VERSION}-x86_64.AppImage"
echo "  DEB: sudo dpkg -i ${APP_NAME}_${APP_VERSION}_amd64.deb"
echo "  RPM: sudo rpm -i ${APP_NAME}-${APP_VERSION}-1.x86_64.rpm"
