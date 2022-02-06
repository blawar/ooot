@echo off
pip3 install tqdm
pip3 install pathtools
fixbaserom.py
extract_baserom.py
extract_assets.py

tools\convert_assets.py

mkdir build\assets\text
tools\msgenc.py assets\text\charmap.txt assets\text\message_data.h build\assets\text\message_data.enc.h
tools\msgenc.py assets\text\charmap.txt assets\text\message_data_staff.h build\assets\text\message_data_staff.enc.h

tools\extract_missing_assets.py
tools\create_luts.py
tools\mark_segments.py
