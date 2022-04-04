#!/usr/bin/python3

import os
import sys
import struct
from multiprocessing import Pool, cpu_count
from libyaz0 import decompress
from oot import *

conf = config()

ROM_FILE_NAME = romPath('baserom.z64')
FILE_TABLE_OFFSET = conf.rom.FILE_TABLE_OFFSET

FILE_NAMES = conf.rom.FILE_NAMES

romData = None


def initialize_worker(rom_data):
    global romData
    romData = rom_data

def read_uint32_be(offset):
    return struct.unpack('>I', romData[offset:offset+4])[0]

def write_output_file(name, offset, size):
    try:
        with open(name, 'wb') as f:
            f.write(romData[offset:offset+size])
    except IOError:
        print('failed to write file ' + name)

def ExtractFunc(i):
    filename = str(Path(assetPath('baserom')) / FILE_NAMES[i])
    entryOffset = FILE_TABLE_OFFSET + 16 * i

    virtStart = read_uint32_be(entryOffset + 0)
    virtEnd   = read_uint32_be(entryOffset + 4)
    physStart = read_uint32_be(entryOffset + 8)
    physEnd   = read_uint32_be(entryOffset + 12)

    if physEnd == 0:  # uncompressed
        compressed = False
        size = virtEnd - virtStart
    else:             # compressed
        compressed = True
        size = physEnd - physStart
    
    print('extracting ' + filename + " (0x%08X, 0x%08X)" % (virtStart, virtEnd))
    write_output_file(filename, physStart, size)
    if compressed:
        os.system(yaz0Binary() + ' -d ' + filename + ' ' + filename)


#####################################################################

def main():
    try:
        createDir(assetPath('baserom'))
    except:
        raise

    # read baserom data
    try:
        with open(ROM_FILE_NAME, 'rb') as f:
            rom_data = f.read()
    except IOError:
        print('failed to read file' + ROM_FILE_NAME)
        sys.exit(1)

    # extract files
    num_cores = cpu_count()
    print("Extracting baserom with " + str(num_cores) + " CPU cores.")
    with Pool(num_cores, initialize_worker, (rom_data,)) as p:
        p.map(ExtractFunc, range(len(FILE_NAMES)))

if __name__ == "__main__":
    main()
