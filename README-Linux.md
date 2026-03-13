# TDownRemaster Linux Installation Guide

## 🐧 Linux için TDownRemaster Kurulum

TDownRemaster Linux'ta birden çok şekilde kurulabilir ve çalıştırılabilir.

## 📦 Kurulum Seçenekleri

### 1. AppImage (Tavsiye Edilen)
En kolay kurulum yöntemi - hiçbir kurulum gerektirmez!

```bash
# İndir ve çalıştır
wget https://github.com/tda45/tdown-remaster/releases/download/v1.0.0/TDownRemaster-1.0.0-x86_64.AppImage
chmod +x TDownRemaster-1.0.0-x86_64.AppImage
./TDownRemaster-1.0.0-x86_64.AppImage
```

### 2. DEB Paketi (Ubuntu/Debian)
```bash
# İndir ve kur
wget https://github.com/tda45/tdown-remaster/releases/download/v1.0.0/TDownRemaster_1.0.0_amd64.deb
sudo dpkg -i TDownRemaster_1.0.0_amd64.deb

# Eğer bağımlılık hatası alırsanız:
sudo apt-get install -f
```

### 3. RPM Paketi (Fedora/CentOS/RHEL)
```bash
# İndir ve kur
wget https://github.com/tda45/tdown-remaster/releases/download/v1.0.0/TDownRemaster-1.0.0-1.x86_64.rpm
sudo rpm -i TDownRemaster-1.0.0-1.x86_64.rpm
```

### 4. Docker ile Çalıştırma
```bash
# Docker image'ı çalıştır
docker run --rm -it \
  -v /path/to/downloads:/downloads \
  -v /path/to/config:/config \
  tdownremaster-builder
```

### 5. Kaynak Koddan Derleme

#### Gerekli Paketler
```bash
# Ubuntu/Debian
sudo apt update
sudo apt install -y build-essential cmake git
sudo apt install -y qt6-base-dev qt6-svg-dev qt6-tools-dev \
    qml6-module-qtquick-controls2 qml6-module-qtwebsockets \
    qml6-module-qtwebchannel qt6-tools-dev-tools

# Fedora
sudo dnf groupinstall -y "Development Tools"
sudo dnf install -y cmake git
sudo dnf install -y qt6-qtbase-devel qt6-qtsvg-devel qt6-qttools-devel
```

#### Derleme
```bash
git clone https://github.com/tda45/tdown-remaster.git
cd tdown-remaster
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
./TDownRemaster
```

## 🔧 Sistem Gereksinimleri

### Minimum Gereksinimler
- **İşletim Sistemi**: Linux (x86_64)
- **Qt**: 6.0 veya üstü
- **RAM**: 2GB minimum
- **Depolama**: 500MB boş alan

### Önerilen Gereksinimler
- **İşletim Sistemi**: Ubuntu 20.04+, Fedora 38+, Debian 11+
- **Qt**: 6.4+
- **RAM**: 4GB+
- **Depolama**: 1GB+

## 📋 Dağıtım Destekleri

| Dağıtım | DEB | RPM | AppImage | Docker |
|---------|-----|-----|----------|--------|
| Ubuntu | ✅ | ❌ | ✅ | ✅ |
| Debian | ✅ | ❌ | ✅ | ✅ |
| Fedora | ❌ | ✅ | ✅ | ✅ |
| CentOS | ❌ | ✅ | ✅ | ✅ |
| Arch | ❌ | ❌ | ✅ | ✅ |
| openSUSE | ❌ | ✅ | ✅ | ✅ |

## 🚀 Hızlı Başlangıç

### AppImage ile (En Kolay)
```bash
# 1. İndir
wget https://github.com/tda45/tdown-remaster/releases/download/v1.0.0/TDownRemaster-1.0.0-x86_64.AppImage

# 2. Çalıştırma izni ver
chmod +x TDownRemaster-1.0.0-x86_64.AppImage

# 3. Başlat
./TDownRemaster-1.0.0-x86_64.AppImage
```

### Ubuntu/DEB ile
```bash
# 1. Depoyu ekle (opsiyonel)
echo "deb [trusted=yes] https://github.com/tda45/tdown-remaster/releases/download/latest/ ./" | sudo tee /etc/apt/sources.list.d/tdownremaster.list

# 2. Kur
sudo apt update
sudo apt install tdownremaster

# 3. Başlat
TDownRemaster
```

## 🔧 Sorun Giderme

### Yaygın Sorunlar

#### 1. Qt Bağımlılık Hatası
```bash
# Ubuntu/Debian
sudo apt install libqt6core6 libqt6gui6 libqt6widgets6 libqt6network6 libqt6svg6

# Fedora
sudo dnf install qt6-qtbase qt6-qtsvg
```

#### 2. İzin Hatası
```bash
# AppImage için
chmod +x TDownRemaster-*.AppImage

# Derlenmiş binary için
chmod +x TDownRemaster
```

#### 3. Kütüphane Bulunamadı
```bash
# Kütüphane yollarını kontrol et
ldd TDownRemaster

# Eksik kütüphaneleri kur
sudo apt install $(ldd TDownRemaster | grep 'not found' | awk '{print $1}' | sed 's/.*=>//' | sed 's/.*//')
```

#### 4. Wayland Sorunu
```bash
# X11 ile çalıştır
QT_QPA_PLATFORM=xcb ./TDownRemaster

# Varsayılan olarak ayarla
export QT_QPA_PLATFORM=xcb
```

## 🐳 Docker Kullanımı

### Docker ile Çalıştırma
```bash
# Image'ı çek
docker pull tdownremaster/tdownremaster:latest

# Çalıştır
docker run -d \
  --name tdownremaster \
  -v /path/to/downloads:/downloads \
  -v /path/to/config:/config \
  -p 8080:8080 \
  tdownremaster/tdownremaster:latest
```

### Docker ile Derleme
```bash
# Derle
./build_docker.sh

# Paketleri çıkar
ls docker-output/
```

## 📱 Masaüstü Entegrasyonu

### .desktop Dosyası
```bash
# ~/.local/share/applications/tdownremaster.desktop oluşturun
cat > ~/.local/share/applications/tdownremaster.desktop << EOF
[Desktop Entry]
Name=TDownRemaster
Comment=Media Downloader
Exec=/path/to/TDownRemaster.AppImage
Icon=tdownremaster
Terminal=false
Type=Application
Categories=AudioVideo;Audio;Video;
EOF
```

### İkon Ekleme
```bash
# İkonu kopyala
cp icon.png ~/.local/share/icons/hicolor/256x256/apps/tdownremaster.png

# İkon veritabanını güncelle
update-desktop-database ~/.local/share/applications/
gtk-update-icon-cache ~/.local/share/icons/
```

## 🔗 Faydalı Linkler

- **Resmi Web Sitesi**: https://github.com/tda45/tdown-remaster
- **Belgeler**: https://github.com/tda45/tdown-remaster/wiki
- **Sorun Bildir**: https://github.com/tda45/tdown-remaster/issues
- **Discord**: (varsa link ekle)

## 📞 Destek

Sorun yaşarsanız:
1. [GitHub Issues](https://github.com/tda45/tdown-remaster/issues) üzerinden bildirin
2. Sistem bilgilerinizi ve hata mesajlarını ekleyin
3. Hangi dağıtımı kullandığınızı belirtin

## 📄 Lisans

TDownRemaster GPL-2.0 lisansı altında dağıtılmaktadır. Detaylar için [LICENSE](LICENSE) dosyasını inceleyin.
