@echo off
pip3 install tqdm
pip3 install pathtools

:: capture exit code 1 errors (missing pip modules, baserom_original missing or incorrect hash)
fixbaserom.py
if errorlevel 1 (
   echo Exit code %errorlevel%. Python process aborted!
   timeout /t 5
   exit /b %errorlevel%
)

extract_baserom.py
extract_assets.py

tools\convert_assets.py

mkdir build\assets\text
tools\msgenc.py assets\text\charmap.txt assets\text\message_data.h build\assets\text\message_data.enc.h
tools\msgenc.py assets\text\charmap.txt assets\text\message_data_staff.h build\assets\text\message_data_staff.enc.h

tools\extract_missing_assets.py
tools\create_luts.py
tools\mark_segments.py
