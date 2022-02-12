from os import path
import sys
import struct
import hashlib
import subprocess


def cancel():
    input("Press Enter To Cancel...")
    sys.exit(1)


def get_str_hash(byte_array):
    return str(hashlib.md5(byte_array).hexdigest())


# If the baserom exists and is correct, we don't need to change anything
if path.exists("baserom.z64"):
    with open("baserom.z64", mode="rb") as file:
        fileContent = bytearray(file.read())
        if get_str_hash(fileContent) == "39a70afa2a7eea1ea306c19e5fd1a8aa":
            print("Found valid baserom - exiting early")
            sys.exit(0)

# Determine if we have a ROM file
romFileExtensions = ["z64", "n64", "v64"]

def find_baserom_original():
    for romFileExtLower in romFileExtensions:
        for romFileExt in (romFileExtLower, romFileExtLower.upper()):
            romFileNameCandidate = "baserom_original." + romFileExt
            if path.exists(romFileNameCandidate):
                return romFileNameCandidate
    return None

romFileName = find_baserom_original()

if romFileName is None:
    print("Error: Could not find baserom_original.z64/baserom_original.n64/baserom_original.v64.")
    cancel()

# Read in the original ROM
print("File '" + romFileName + "' found.")
with open(romFileName, mode="rb") as file:
    fileContent = bytearray(file.read())

fileContentLen = len(fileContent)

# Check if ROM needs to be byte/word swapped
# Little-endian
if fileContent[0] == 0x40:
    # Word Swap ROM
    print("ROM needs to be word swapped...")
    words = str(int(fileContentLen/4))
    little_byte_format = "<" + words + "I"
    big_byte_format = ">" + words + "I"
    tmp = struct.unpack_from(little_byte_format, fileContent, 0)
    struct.pack_into(big_byte_format, fileContent, 0, *tmp)

    print("Word swapping done.")

# Byte-swapped
elif fileContent[0] == 0x37:
    # Byte Swap ROM
    print("ROM needs to be byte swapped...")
    halfwords = str(int(fileContentLen/2))
    little_byte_format = "<" + halfwords + "H"
    big_byte_format = ">" + halfwords + "H"
    tmp = struct.unpack_from(little_byte_format, fileContent, 0)
    struct.pack_into(big_byte_format, fileContent, 0, *tmp)

    print("Byte swapping done.")

# Write out our new ROM
print("Writing new ROM 'baserom.z64'.")
with open("baserom.z64", mode="wb") as file:
    file.write(bytes(fileContent))

print("Done!")
