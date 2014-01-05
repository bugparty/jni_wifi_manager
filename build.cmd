@echo off
color 02
echo importing envirment vars
call var

@echo on
javac -d ./classes -cp %CLS% -sourcepath ./src %C_FILES%


javah -d %GEN_PATH% -cp ./classes  %H_FILES%
