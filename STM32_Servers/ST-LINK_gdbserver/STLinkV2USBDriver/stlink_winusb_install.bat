@echo off

REM First ensure the command runs with enough rights

openfiles > NUL 2>&1 
if %errorlevel%==0 goto ADMIN 
echo Installing ST-Link drivers requires elevated rights; launch the command prompt in administrator mode and/or change user account 
REM pause
goto END 

:ADMIN

REM If enough rights, check the machine architecture
if /I "%PROCESSOR_ARCHITECTURE%"=="AMD64" goto AMD64
REM If here, we are running a 32-bit version of cmd; but still may be on a 64-bit machine
if /I "%PROCESSOR_ARCHITEW6432%"=="AMD64" goto AMD64
"%~dp0/dpinst_x86.exe"
goto END

:AMD64
"%~dp0/dpinst_amd64.exe"

:END
