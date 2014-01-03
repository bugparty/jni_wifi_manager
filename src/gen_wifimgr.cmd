@echo off
set GEN_PATH=../wifimgr
set BASE_PATH=com/ifancc/wifimgr
set BEAN=%BASE_PATH%/Bean

set C_FILES= %BASE_PATH%/Manager.java %BEAN%/Wifi.java %BEAN%/WlanInterfaceInfo.java

@echo on


javac %C_FILES%
javah -d %GEN_PATH% com.ifancc.wifimgr.Manager com.ifancc.wifimgr.Bean.Wifi

