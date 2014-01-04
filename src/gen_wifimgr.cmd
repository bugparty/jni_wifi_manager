@echo off
set GEN_PATH=../wifimgr
set BASE_PATH=com/ifancc/wifimgr
set BEAN=%BASE_PATH%/Bean
set CBEAN=com.ifancc.wifimgr.Bean
set C_FILES= %BASE_PATH%/Manager.java %BEAN%/Wifi.java %BEAN%/WlanInterfaceInfo.java
set H_FILES= %CBEAN%.WlanInterfaceState %CBEAN%.Wifi %CBEAN%.WlanInterfaceInfo


@echo on


javac %C_FILES%
javah -d %GEN_PATH% %H_FILES%

pause
exit