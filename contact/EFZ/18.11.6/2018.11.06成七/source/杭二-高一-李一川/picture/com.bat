:loop
maker.exe
bl.exe
picture.exe
fc bl.out picture.out
if %errorlevel%==1 pause
goto loop