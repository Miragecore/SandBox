@echo off

For /f "tokens=1-3 delims=/ " %%a in ('date /t') do (set backupdate=%%a)

SET TARGETS=Localserver,TCRecoder
SET TARGETROOT=C:\Metabuild\

IF NOT EXIST %TARGETROOT% (
 echo Target Folder does not exist
 GOTO PAUSE
)

SET /A COUNT=0
SET BACKUPROOT_REF=%TARGETROOT%Backup\%backupdate%
SET BACKUPROOT=%TARGETROOT%Backup\%backupdate%

:LOOP
IF EXIST %BACKUPROOT% (
 echo %BACKUPROOT% IS EXIST TRY NEXT BACKUP DIRECTORY
 SET /A COUNT=%COUNT%+1
 SET BACKUPROOT=%BACKUPROOT_REF%_%COUNT%
 GOTO LOOP
)
echo.

SET BACKUPROOT=%BACKUPROOT%\

echo Backup Directory is %BACKUPROOT%
echo.

for %%i in (%TARGETS%) do (

  IF NOT EXIST .\%%i (
   echo .\%%i Update Source does not exist   
  ) else (
  echo Start %%i Backup 
  echo.
  call DirectoryFilesCopy %TARGETROOT%%%i %BACKUPROOT%%%i
  echo.
  echo.

  echo Start %%i Update
  echo.
  call DirectoryFilesCopy .\%%i %TARGETROOT%%%i
  echo.
  echo.
 )
)

echo Start Configuration Rollback
echo.
IF EXIST %BACKUPROOT%LocalServer\settings.xml XCOPY /Y %BACKUPROOT%LocalServer\settings.xml %TARGETROOT%LocalServer\settings.xml
IF EXIST %BACKUPROOT%LocalServer\ServiceInfo.xml XCOPY /Y %BACKUPROOT%LocalServer\EventData.db %TARGETROOT%LocalServer\ServiceInfo.xml
IF EXIST %BACKUPROOT%LocalServer\EventData.db XCOPY /Y %BACKUPROOT%LocalServer\EventData.db %TARGETROOT%LocalServer\EventData.db
IF EXIST %BACKUPROOT%TCRecoder\settings.xml XCOPY /Y %BACKUPROOT%TCRecoder\settings.xml %TARGETROOT%TCRecoder\settings.xml

:PAUSE
pause



