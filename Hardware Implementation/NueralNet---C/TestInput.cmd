@echo off

python record.py


wav.exe > data.txt

python sendData.py


timeout /t 5

exit