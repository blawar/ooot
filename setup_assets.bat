python3 -m pip install tqdm
python3 -m pip install pathtools
python3 fixbaserom.py
python3 extract_baserom.py
python3 extract_assets.py

python3 tools\convert_assets.py

mkdir build\assets\text
python3 tools\msgenc.py assets\text\charmap.txt assets\text\message_data.h build\assets\text\message_data.enc.h
python3 tools\msgenc.py assets\text\charmap.txt assets\text\message_data_staff.h build\assets\text\message_data_staff.enc.h

python3 tools\extract_missing_assets.py
python3 tools\create_luts.py
python3 tools\mark_segments.py



