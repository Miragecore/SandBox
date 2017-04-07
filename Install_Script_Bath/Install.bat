@echo off

SET TARGETS=Localserver,TCRecoder,AutoPwrCtrl,ProcessWatcher,WatchDog,LogAnalysis
SET TARGETROOT=C:\Metabuild\

IF NOT EXIST %TARGETROOT% (
 Mkdir %TARGETROOT%
)

echo Install Directory is %TARGETROOT%
echo.

for %%i in (%TARGETS%) do (
  IF NOT EXIST .\%%i (
   echo .\%%i INSTALL Source does not exist   
   echo Pass Installation %%i
  ) else (
  echo Start %%i Intallation
  echo.
  call DirectoryFilesCopy .\%%i %TARGETROOT%%%i
  echo.
  echo.
 )
)
echo.
echo.
echo.

call CheckConfigurationFiles %TARGETROOT%

pause



