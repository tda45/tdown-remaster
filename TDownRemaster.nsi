
!define APPNAME "TDown Remaster"
!define APPVERSION "1.0.0"
!define APPPUBLISHER "Tda_45"
!define APPURL "https://github.com/tda45/tdown-remaster"
!define APPEXE "TDownRemaster.exe"

; Include modern UI
!include "MUI2.nsh"
!include "x64.nsh"

; General settings
Name "${APPNAME}"
OutFile "TDownRemaster-Setup-${APPVERSION}.exe"
InstallDir "$PROGRAMFILES64\${APPNAME}"
InstallDirRegKey HKLM "Software\${APPNAME}" "InstallPath"
RequestExecutionLevel admin
ShowInstDetails show
ShowUnInstDetails show

; Variables
Var StartMenuFolder

; Interface settings
!define MUI_ABORTWARNING
!define MUI_ICON "icon.ico"
!define MUI_UNICON "icon.ico"
; !define MUI_HEADERIMAGE
; !define MUI_HEADERIMAGE_BITMAP "header.bmp" ; Optional

; Language selection dialog settings
!define MUI_LANGDLL_REGISTRY_ROOT "HKLM" 
!define MUI_LANGDLL_REGISTRY_KEY "Software\${APPNAME}" 
!define MUI_LANGDLL_REGISTRY_VALUENAME "Installer Language"

; Installer pages
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_LICENSE "LICENSE.txt"
!insertmacro MUI_PAGE_COMPONENTS
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_STARTMENU Application $StartMenuFolder
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

; Uninstaller pages
!insertmacro MUI_UNPAGE_WELCOME
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES
!insertmacro MUI_UNPAGE_FINISH

; Languages
!insertmacro MUI_LANGUAGE "Turkish"
!insertmacro MUI_LANGUAGE "English"

; Installer sections
Section "TDownRemaster" SecMain
    SectionIn RO
    
    SetOutPath "$INSTDIR"
    
    ; Main executable and dependencies
    File "C:\TDown-Remaster\build\Release\TDownRemaster.exe"
    File "C:\TDown-Remaster\build\Release\*.dll"
    File "C:\TDown-Remaster\build\Release\*.exe"
    
    ; Qt plugins
    CreateDirectory "$INSTDIR\platforms"
    File /r "C:\TDown-Remaster\build\Release\platforms\*.*"
    
    CreateDirectory "$INSTDIR\imageformats"
    File /r "C:\TDown-Remaster\build\Release\imageformats\*.*"
    
    CreateDirectory "$INSTDIR\iconengines"
    File /r "C:\TDown-Remaster\build\Release\iconengines\*.*"
    
    CreateDirectory "$INSTDIR\styles"
    File /r "C:\TDown-Remaster\build\Release\styles\*.*"
    
    CreateDirectory "$INSTDIR\generic"
    File /r "C:\TDown-Remaster\build\Release\generic\*.*"
    
    CreateDirectory "$INSTDIR\networkinformation"
    File /r "C:\TDown-Remaster\build\Release\networkinformation\*.*"
    
    CreateDirectory "$INSTDIR\tls"
    File /r "C:\TDown-Remaster\build\Release\tls\*.*"
    
    CreateDirectory "$INSTDIR\translations"
    File /r "C:\TDown-Remaster\build\Release\translations\*.*"
    
    ; Documentation
    File "C:\TDown-Remaster\README.md"
    File "C:\TDown-Remaster\LICENSE.txt"
    
    ; Create uninstaller
    WriteUninstaller "$INSTDIR\Uninstall.exe"
    
    ; Registry entries
    WriteRegStr HKLM "Software\${APPNAME}" "InstallPath" "$INSTDIR"
    WriteRegStr HKLM "Software\${APPNAME}" "Version" "${APPVERSION}"
    WriteRegStr HKLM "Software\${APPNAME}" "DisplayName" "${APPNAME}"
    WriteRegStr HKLM "Software\${APPNAME}" "Publisher" "${APPPUBLISHER}"
    WriteRegStr HKLM "Software\${APPNAME}" "URLInfoAbout" "${APPURL}"
    WriteRegStr HKLM "Software\${APPNAME}" "DisplayVersion" "${APPVERSION}"
    WriteRegStr HKLM "Software\${APPNAME}" "UninstallString" "$INSTDIR\Uninstall.exe"
    
    ; Add to Programs and Features
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "DisplayName" "${APPNAME}"
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "UninstallString" "$INSTDIR\Uninstall.exe"
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "DisplayVersion" "${APPVERSION}"
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "Publisher" "${APPPUBLISHER}"
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "InstallLocation" "$INSTDIR"
    WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "NoModify" 1
    WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "NoRepair" 1
    
    ; Create shortcuts
    !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
        CreateDirectory "$SMPROGRAMS\$StartMenuFolder"
        CreateShortCut "$SMPROGRAMS\$StartMenuFolder\${APPNAME}.lnk" "$INSTDIR\${APPEXE}"
        CreateShortCut "$SMPROGRAMS\$StartMenuFolder\Uninstall.lnk" "$INSTDIR\Uninstall.exe"
    !insertmacro MUI_STARTMENU_WRITE_END
    
    ; Desktop shortcut (optional)
    CreateShortCut "$DESKTOP\${APPNAME}.lnk" "$INSTDIR\${APPEXE}"
    
    ; File associations
    WriteRegStr HKCR ".m3u8" "" "TDownRemaster.Playlist"
    WriteRegStr HKCR "TDownRemaster.Playlist" "" "M3U8 Playlist File"
    WriteRegStr HKCR "TDownRemaster.Playlist\DefaultIcon" "" "$INSTDIR\${APPEXE},0"
    WriteRegStr HKCR "TDownRemaster.Playlist\shell\open\command" "" '"$INSTDIR\${APPEXE}" "%1"'
    
SectionEnd

Section "Desktop Shortcut" SecDesktop
    CreateShortCut "$DESKTOP\${APPNAME}.lnk" "$INSTDIR\${APPEXE}"
SectionEnd

Section "Quick Launch Shortcut" SecQuickLaunch
    CreateShortCut "$QUICKLAUNCH\${APPNAME}.lnk" "$INSTDIR\${APPEXE}"
SectionEnd

; Section descriptions
!insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
    !insertmacro MUI_DESCRIPTION_TEXT ${SecMain} "Install TDownRemaster Media Downloader and all required components."
    !insertmacro MUI_DESCRIPTION_TEXT ${SecDesktop} "Create a desktop shortcut for easy access."
    !insertmacro MUI_DESCRIPTION_TEXT ${SecQuickLaunch} "Create a Quick Launch shortcut."
!insertmacro MUI_FUNCTION_DESCRIPTION_END

; Uninstaller section
Section "Uninstall"
    
    ; Remove files and directories
    RMDir /r "$INSTDIR\platforms"
    RMDir /r "$INSTDIR\imageformats"
    RMDir /r "$INSTDIR\iconengines"
    RMDir /r "$INSTDIR\styles"
    RMDir /r "$INSTDIR\generic"
    RMDir /r "$INSTDIR\networkinformation"
    RMDir /r "$INSTDIR\tls"
    RMDir /r "$INSTDIR\translations"
    
    Delete "$INSTDIR\*.exe"
    Delete "$INSTDIR\*.dll"
    Delete "$INSTDIR\*.md"
    Delete "$INSTDIR\*.txt"
    Delete "$INSTDIR\Uninstall.exe"
    
    RMDir "$INSTDIR"
    
    ; Remove shortcuts
    !insertmacro MUI_STARTMENU_GETFOLDER Application $StartMenuFolder
    Delete "$SMPROGRAMS\$StartMenuFolder\${APPNAME}.lnk"
    Delete "$SMPROGRAMS\$StartMenuFolder\Uninstall.lnk"
    RMDir "$SMPROGRAMS\$StartMenuFolder"
    Delete "$DESKTOP\${APPNAME}.lnk"
    Delete "$QUICKLAUNCH\${APPNAME}.lnk"
    
    ; Remove registry entries
    DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}"
    DeleteRegKey HKLM "Software\${APPNAME}"
    DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}"
    
    ; Remove file associations
    DeleteRegKey HKCR "TDownRemaster.Playlist"
    DeleteRegValue HKCR ".m3u8" ""
    
SectionEnd

; Functions
Function .onInit
    ; Check if already installed
    ReadRegStr $R0 HKLM "Software\${APPNAME}" "InstallPath"
    StrCmp $R0 "" done
    
    ; Show upgrade message
    MessageBox MB_OKCANCEL|MB_ICONINFORMATION \
        "${APPNAME} is already installed.$\n$\nClick OK to upgrade the existing installation or Cancel to exit." \
        IDOK done
    Abort
    
done:
FunctionEnd

Function un.onInit
    ; Confirm uninstall
    MessageBox MB_OKCANCEL|MB_ICONQUESTION \
        "Are you sure you want to completely remove ${APPNAME} and all of its components?" \
        IDOK done
    Abort
    
done:
FunctionEnd
