@echo off
IF NOT EXIST %1\NUL (
  @echo source folder invalid
) else (
    IF NOT EXIST %2\NUL (
      MKDIR %2 && XCOPY /Y /Q %1\*.* %2\*.*
    ) ELSE (
      XCOPY /Y /Q %1\*.* %2\*.*
    )
)
