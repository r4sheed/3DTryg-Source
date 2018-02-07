@ECHO OFF

COLOR 9F
TITLE 3DTryg Merge

IF EXIST "%CD%\3DTryg.inc" DEL /Q /A "%CD%\3DTryg.inc"
IF EXIST "%CD%\errors.log" DEL /Q /A "%CD%\errors.log"

FOR /F "tokens=*" %%s IN ('TYPE "%CD%\core.lst"') DO CALL :MERGE %%s

COPY /Y "%CD%\3DTryg.inc" "%CD%\..\SAMP\include\ADM\3DTryg.inc" > nul
PAUSE
GOTO :eof

:MERGE
IF "%~1" == "import"	CALL :IMPORT "%~2"
IF "%~1" == "write"		ECHO %~2 >> "%CD%\3DTryg.inc"
IF "%~1" == "rule"		CALL :RULE "%~2"
IF "%~1" == "endrule"	CALL :ENDRULE
GOTO :eof

:RULE
IF NOT EXIST "%CD%\rules\%~1.txt" GOTO :eof
TYPE "%CD%\rules\%~1.txt" >> "%CD%\3DTryg.inc"
ECHO. >> "%CD%\3DTryg.inc"
ECHO. >> "%CD%\3DTryg.inc"
GOTO :eof

:ENDRULE
ECHO #endif >> "%CD%\3DTryg.inc"
ECHO. >> "%CD%\3DTryg.inc"
GOTO :eof

:IMPORT
SET BUFFER=%~1
IF "%BUFFER:~0,1%" == "#" GOTO :eof
IF "%~1" == "" GOTO :eof

IF NOT EXIST "%CD%\%~1" (
	ECHO Error load module: "%~1"
	ECHO Error "%~1" >> "%CD%\errors.log"
	GOTO :eof
)
ECHO Merge %~1
TYPE "%CD%\%~1" >> "%CD%\3DTryg.inc"
ECHO. >> "%CD%\3DTryg.inc"
ECHO. >> "%CD%\3DTryg.inc"
GOTO :eof