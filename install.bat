@echo off
if exist "bat" (
	move bat\*.bat" "."
	rmdir /s /q "bat"
)
