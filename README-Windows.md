# TDownRemaster Windows Installation Guide
# Windows için TDownRemaster Kurulum Kılavuzu

## 🪟 Windows için TDownRemaster Kurulum

Windows'ta TDownRemaster kurulumu için farklı yöntemler mevcuttur.

## 📦 Kurulum Seçenekleri

### 1. NSIS Setup (Tavsiye Edilen)
En kolay kurulum yöntemi - tek tıkla kurulum!

```powershell
# PowerShell'de çalıştırın
# İndir
Invoke-WebRequest -Uri "https://github.com/tda45/tdown-remaster/releases/download/v1.0.0/TDownRemaster-Setup-1.0.0.exe" -OutFile "TDownRemaster-Setup-1.0.0.exe"

# Kur
Start-Process -FilePath "TDownRemaster-Setup-1.0.0.exe" -Wait
```

### 2. Manuel İndirme
Tarayıcıdan indirme:

1. https://github.com/tda45/tdown-remaster/releases/latest adresine gidin
2. `TDownRemaster-Setup-1.0.0.exe` dosyasını indirin
3. İndirilen dosyaya çift tıklayarak kurulumu başlatın

### 3. PowerShell ile Otomatik Kurulum
```powershell
# Kurulum dosyasını indir ve sessizce kur
$url = "https://github.com/tda45/tdown-remaster/releases/download/v1.0.0/TDownRemaster-Setup-1.0.0.exe"
$output = "TDownRemaster-Setup-1.0.0.exe"
Invoke-WebRequest -Uri $url -OutFile $output
Start-Process -FilePath $output -ArgumentList "/S" -Wait
```

### 4. Portatif Versiyon
Kurulum gerektirmeyen taşınabilir versiyon:

```powershell
# Portatif paketi indir
Invoke-WebRequest -Uri "https://github.com/tda45/tdown-remaster/releases/download/v1.0.0/TDownRemaster-Portable-1.0.0.zip" -OutFile "TDownRemaster-Portable-1.0.0.zip"

# Çıkar
Expand-Archive -Path "TDownRemaster-Portable-1.0.0.zip" -DestinationPath "TDownRemaster-Portable"

# Çalıştır
Start-Process -FilePath "TDownRemaster-Portable\TDownRemaster.exe"
```

## 🔧 Windows Sistem Gereksinimleri

### Minimum Gereksinimler
- **İşletim Sistemi**: Windows 10/11 (x64)
- **RAM**: 2GB minimum
- **Depolama**: 500MB boş alan
- **.NET Framework**: 4.8 veya üstü

### Önerilen Gereksinimler
- **İşletim Sistemi**: Windows 10/11 (x64)
- **RAM**: 4GB+
- **Depolama**: 1GB+
- **.NET Framework**: 4.8+

## 🚀 Windows PowerShell Komutları

### İndirme Komutları
```powershell
# NSIS Setup
Invoke-WebRequest -Uri "https://github.com/tda45/tdown-remaster/releases/download/v1.0.0/TDownRemaster-Setup-1.0.0.exe" -OutFile "TDownRemaster-Setup-1.0.0.exe"

# Portatif ZIP
Invoke-WebRequest -Uri "https://github.com/tda45/tdown-remaster/releases/download/v1.0.0/TDownRemaster-Portable-1.0.0.zip" -OutFile "TDownRemaster-Portable-1.0.0.zip"

# Kaynak kodu
Invoke-WebRequest -Uri "https://github.com/tda45/tdown-remaster/archive/refs/tags/v1.0.0.zip" -OutFile "TDownRemaster-Source-1.0.0.zip"
```

### Kurulum Komutları
```powershell
# Normal kurulum
Start-Process -FilePath "TDownRemaster-Setup-1.0.0.exe" -Wait

# Sessiz kurulum
Start-Process -FilePath "TDownRemaster-Setup-1.0.0.exe" -ArgumentList "/S" -Wait

# Portatif sürümü çalıştır
Expand-Archive -Path "TDownRemaster-Portable-1.0.0.zip" -DestinationPath "."
Start-Process -FilePath "TDownRemaster.exe"
```

## 📱 Windows Entegrasyonu

### Başlat Menüsü
Kurulum otomatik olarak başlat menüsüne ekler:
- **TDownRemaster** - Ana uygulama
- **Uninstall TDownRemaster** - Kaldırma

### Masaüstü Kısayolu
Kurulum sırasında masaüstü kısayolu oluşturulabilir.

### Dosya İlişkilendirmesi
Windows'ta desteklenen formatlar:
- **M3U8** playlist dosyaları
- **MP4** video dosyaları
- **MP3** ses dosyaları
- **YouTube** linkleri (drag & drop)

## 🔍 Windows'ta Linux Komutları

### wget yerine PowerShell equivalent:
```powershell
# Linux: wget URL
# Windows: Invoke-WebRequest
Invoke-WebRequest -Uri "URL" -OutFile "dosya_adı"

# Alternatif: curl (Windows 10+)
curl -L "URL" -o "dosya_adı"
```

### chmod yerine (Windows'ta gerekmez):
```powershell
# Linux: chmod +x dosya
# Windows: Genellikle gerekmez, .exe dosyaları zaten çalıştırılabilir
# Eğer gerekirse:
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope Process
```

### ./dosya yerine:
```powershell
# Linux: ./dosya
# Windows: 
Start-Process -FilePath "dosya.exe"
# veya
.\dosya.exe
```

## 🐳 Docker ile Windows

### Docker Desktop Kurulumu
```powershell
# Docker image'ı çek
docker pull tdownremaster/tdownremaster:1.0.0

# Çalıştır
docker run -d --name tdownremaster `
  -v "$env:USERPROFILE\Downloads:/downloads" `
  -v "$env:USERPROFILE\Documents\TDownRemaster:/config" `
  -p 8080:8080 `
  tdownremaster/tdownremaster:1.0.0
```

## 📋 Windows Package Manager (Winget)

### Winget ile Kurulum
```powershell
# Winget ile kurulum (varsa)
winget install TDownRemaster

# Güncelleme
winget upgrade TDownRemaster

# Kaldırma
winget uninstall TDownRemaster
```

## 🔧 Sorun Giderme (Windows)

### Yaygın Windows Sorunları

#### 1. "Bu uygulama çalıştırılamıyor" hatası
```powershell
# Çözüm: Execution Policy ayarla
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
```

#### 2. Antivirüs engeliyor
- Antivirüs ayarlarından TDownRemaster'i güvenli olarak işaretleyin
- Setup dosyasını sağ tık → Özellikler → Engellemeyi kaldır

#### 3. .NET Framework eksik
```powershell
# .NET Framework 4.8 kurulumu
Enable-WindowsOptionalFeature -Online -FeatureName NetFx4Extended-ASPNET45Support -NoRestart
```

#### 4. Visual C++ Redistributable eksik
```powershell
# Microsoft Visual C++ Redistributable indir
Invoke-WebRequest -Uri "https://aka.ms/vs/17/release/vc_redist.x64.exe" -OutFile "vc_redist.x64.exe"
Start-Process -FilePath "vc_redist.x64.exe" -ArgumentList "/quiet" -Wait
```

## 📞 Windows Destek

Windows'ta sorun yaşarsanız:
1. **Event Viewer**'ı kontrol edin
2. **Windows Defender** ayarlarını kontrol edin
3. **UAC** ayarlarını kontrol edin
4. GitHub Issues üzerinden bildirin

## 🎯 Hızlı Windows Başlangıç

```powershell
# 1. İndir
Invoke-WebRequest -Uri "https://github.com/tda45/tdown-remaster/releases/download/v1.0.0/TDownRemaster-Setup-1.0.0.exe" -OutFile "TDownRemaster-Setup-1.0.0.exe"

# 2. Kur
Start-Process -FilePath "TDownRemaster-Setup-1.0.0.exe" -Wait

# 3. Başlat
Start-Process -FilePath "C:\Program Files\TDownRemaster\TDownRemaster.exe"
```

**Windows için TDownRemaster kurulumu hazır!** 🪟
