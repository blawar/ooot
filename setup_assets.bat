@echo off
python -m pip install tqdm
python -m pip install pathtools
python -m pip install multiprocessing
python fixbaserom.py
python extract_baserom.py
python extract_assets.py

python tools\convert_assets.py

mkdir build\assets\text
python tools\msgenc.py assets\text\charmap.txt assets\text\message_data.h build\assets\text\message_data.enc.h
python tools\msgenc.py assets\text\charmap.txt assets\text\message_data_staff.h build\assets\text\message_data_staff.enc.h

python tools\extract_missing_assets.py
python tools\create_luts.py
python tools\mark_segments.py
