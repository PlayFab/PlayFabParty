@echo off

set platform=%1
set arch=%2
set configuration=%3
if not defined platform goto FAIL
if not defined arch goto FAIL
if not defined configuration goto FAIL

git rev-parse --show-toplevel > gitdir.tmp
set /P gitdirtmp=<gitdir.tmp
del gitdir.tmp

REM git provides directory paths with forward slashes, which most Windows commands don't accept.
REM cd works, though. Pop around to get a path format that is more familiar to windows.
pushd "%gitdirtmp%"
set gitdir=%cd%
popd

set outputdir=%gitdir%\output\%platform%\%arch%\%configuration%

%outputdir%\VerifyCHeaderCompiles.exe

goto :EOF

:FAIL
echo "First parameters must specify a platform, arch, and configuration! e.g. Win10 x64 Debug"