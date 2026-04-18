@echo off
set /p re=echo clean?:
if "%re%"=="yes" (
	rmdir /s /q build
	rmdir /s /q result
) else (
	exit /b 0
)
exit /b 0