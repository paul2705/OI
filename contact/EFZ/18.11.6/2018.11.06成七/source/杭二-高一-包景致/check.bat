@echo off
:loop
fc a.out stone.ans
if errorlevel 1 pause
goto loop