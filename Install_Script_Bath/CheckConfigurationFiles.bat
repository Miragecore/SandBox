@echo off
echo CheckRequisiteConfigurationFiles

SET BASEROOT=%1

echo Check LocalServer Configuration
SET LocalServerConf=%BASEROOT%LocalServer\Settings.xml
IF NOT EXIST  %LocalServerConf% (
	echo %LocalServerConf% Not Exist)

echo Check TCRecoder Configuration
SET TCRecoderConf=%BASEROOT%TCRecoder\Settings.xml
IF NOT EXIST  %TCRecoderConf% (
	echo %TCRecoderConf% Not Exist)

echo Check ProcessWatcher Configuration
SET PWConf=%BASEROOT%ProcessWatcher\monitor.json
IF NOT EXIST %PWConf% (
	echo %PWConf% Not Exist)

echo Check Watchdog Configuration
SET Watchconfigs=debug.xml,environment.xml,radarlist.json
for %%i in (%Watchconfigs%) do (
	IF NOT EXIST %BASEROOT%Watchdog\%%i (
		echo %BASEROOT%Watchdog\%%i Not Exist)
	)

pause