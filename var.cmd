@echo off
set GEN_PATH=./wifimgr/include/java
set CLASS_PATH=./classes
set T_PATH=./tests/com/ifancc/wifimgr
set S_PATH=./src/com/ifancc/wifimgr
set CMAIN=com.ifancc.wifimgr
set SPMAIN=../src/com/ifancc/wifimgr


set C_FILES=%T_PATH%/WlanInterfaceInfoTest.java %S_PATH%/Bean/WlanInterfaceInfoList.java
set C_FILES=%C_FILES% %S_PATH%/Manager.java %T_PATH%/WlanInterfaceInfoListTest.java

set T_FILES=%T_PATH%/WlanInterfaceInfoListTest.java

set H_FILES=%CMAIN%.WlanInterfaceInfoTest %CMAIN%.Manager %CMAIN%.Bean.WlanInterfaceInfoList
set H_FILES=%H_FILES% %CMAIN%.WlanInterfaceInfoListTest

set CLS="C:\Program Files (x86)\JetBrains\IntelliJ IDEA 13.0\lib\junit-4.10.jar"
set classpath=%CLS%;%classpath%

