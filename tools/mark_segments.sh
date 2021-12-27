#!/bin/bash
find assets/ -iname '*.h' -exec sed -i -b 's/\(gsSP[A-Za-z]*\)(\(0x0[0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z]\)/\1SEG(SEGMENT_ADDRESS(\2)/g' '{}' \;
find assets/ -iname '*.c' -exec sed -i -b 's/\(gsSP[A-Za-z]*\)(\(0x0[0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z]\)/\1SEG(SEGMENT_ADDRESS(\2)/g' '{}' \;
find assets -iname '*.c' -exec sed -ib 's/gsDPLoadTextureBlock(\(0x[A-Za-z0-9]*\),/gsDPLoadTextureBlockSEG(SEGMENT_ADDRESS(\1),/g' "{}" \;
find assets -iname '*.c' -exec sed -ib 's/gsDPLoadMultiBlock(\(0x[A-Za-z0-9]*\),/gsDPLoadMultiBlockSEG(SEGMENT_ADDRESS(\1),/g' "{}" \;
#find src/ -iname '*.c' -exec sed -i -b 's/\(gsSP[A-Za-z]*\)(\(0x0[0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z]\)/\1SEG(SEGMENT_ADDRESS(\2)/g' '{}' \;

