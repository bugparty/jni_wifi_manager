set GEN_PATH=../wifimgr
set BASE_PATH=com/ifancc/wifimgr
set BEAN=%BASE_PATH%/Bean
set CBEAN=com.ifancc.wifimgr.Bean

javac com/ifancc/wifimgr/Bean/Wifi.java
javap -s com.ifancc.wifimgr.Bean.Wifi
javap -s %CBEAN%.WlanInterfaceState