#!/usr/bin/env python3

import argparse, os, shutil, time
from itertools import repeat
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor
from tqdm import tqdm
import shutil
from oot import *

def ExtractFile(xmlPath: Path, outputPath: Path, outputSourcePath: Path, unaccounted: bool):
    # Create target folder recursivly, ignore error if it already exists
    createDir(outputSourcePath)

    zapd = Path(zapdBinary())
    zapdConfig = Path(romPath("zapd/Config.xml"))
    baserom = assetPath('baserom')
    externalXmlFolder = assetPath('xml')
    execStr = f"{zapd} e -i {xmlPath} -b {baserom} -o {outputPath} -osf {outputSourcePath} -gsf 1 -rconf {zapdConfig} --externalXmlFolder {externalXmlFolder}"

    # Use error handler only if non-windows environment, because it's not supported in windows
    if os.name != 'nt':
        execStr += " -eh"

    if "overlays" in str(xmlPath):
        execStr += " --static"

    if unaccounted == True:
        execStr += " --warn-unaccounted"
    
    # print(f"Extracting {xmlPath.stem}")
    # print(execStr)

    exitValue = os.system(execStr)

    if exitValue != 0:
        return ("failed", f"Error extracting {xmlPath}: {os.sys.stderr}")
    else:
        return ("success", f"Successfully extracted {xmlPath}")



def ExtractFunc(fullPath: Path, force: bool, unaccounted: bool):
    # Ensure that file exists. It can happen that files don't exist if paths are manually passed
    if fullPath.exists() == False:
        return ("failed", f"File cannot be found: {fullPath}")

    # Remove xml directory and suffix in path to use as output directory
    # Example: assets/xml/objects/object_example.xml -> assets/objects/object_bdoor
    rel = relPath(fullPath, romPath())[4:-4]
    outPath = Path(assetPath(rel))

    # If output is more recent than source file: skip extraction
    # Don't skip if force == True was passed
    if force == False and outPath.is_dir() and outPath.stat().st_mtime > fullPath.stat().st_mtime:
        return ("skipped", f"Skipped extraction of {fullPath}")

    # Delete target folder before extraction, ignore errors in case there is no folder to delete
    shutil.rmtree(outPath, ignore_errors=True)
    return ExtractFile(fullPath, outPath, outPath, unaccounted)

def ExtractText(force: bool):
    extract_text_path = Path(assetPath("text/message_data.h"))
    extract_staff_text_path = Path(assetPath("text/message_data_staff.h"))
    # Ensure target folder exists
    createDir(extract_text_path.parent)

    # Always extract if force flag was passed
    # otherwise check if target already exists and skip (by setting it to None) if it does
    if force == False:
        if extract_text_path.exists():
            extract_text_path = None
        if extract_staff_text_path.exists():
            extract_staff_text_path = None

    if extract_text_path is not None or extract_staff_text_path is not None:
        print("Start Extracting text")
        import msgdis
        msgdis.extract_all_text(extract_text_path, extract_staff_text_path)
        print("Finished extracting text")

def ExtractXMLAssets(xmlFiles, force: bool, unaccounted: bool):
    thread_count = os.cpu_count() or 1
    print(f"Start extracting {len(xmlFiles)} assets with %d threads" % thread_count)
    success = skipped = failed = 0
    errors = []
    # Multithreading instead of multiprocessing, because of IO heavy operation 
    with ThreadPoolExecutor(max_workers = thread_count) as executor:
        with tqdm(total=len(xmlFiles)) as progress:
            for result in executor.map(ExtractFunc, xmlFiles, repeat(force), repeat(unaccounted)):
                progress.update()
                # Parsing of results
                status = result[0]
                message = result[1]
                if status == "success":
                    success += 1
                elif status == "skipped":
                    skipped += 1
                else:
                    failed += 1
                    errors.append(message)

        print(f"Extracted: {success}, Skipped: {skipped}, Failed: {failed}")
        if errors:
            print(f"Errors: {errors}")


def main():
    # Command Line Interface
    parser = argparse.ArgumentParser(description="baserom asset extractor")
    parser.add_argument("assets", help="asset path(s) relative to assets/xml/, e.g. objects/gameplay_keep. Passing nothing will extract entire assets/xml/ tree", nargs="*", default=None)
    parser.add_argument("-f", "--force", help="Force the extraction of every asset instead of only recently modified", action="store_true", default=False)
    parser.add_argument("-u", "--unaccounted", help="Enables ZAPD unaccounted detector warning system.", action="store_true", default=False)
    args = parser.parse_args()

    shutil.rmtree(Path(assetPath('xml')), ignore_errors = True)
    shutil.copytree(Path(romPath('xml')), Path(assetPath('xml')))

    # List of xml files for extraction
    xmlFiles = None
    if args.assets and len(args.assets) > 1:
        # Generate list of Paths by transforming asset inputs into full Path structure
        # Example: objects/gameplay_keep  -->  assets/xml/objects/gameplay_keep.xml
        xmlFiles = [Path(assetPath('xml')).joinpath(file).with_suffix('.xml') for file in args.assets[1:]]
    else:
        # Get list of all xml files in assets/xml/ subdirectories recursivly 
        xmlFiles = sorted(Path(romPath()).glob('xml/**/*.xml'))

    start = time.perf_counter()
    ExtractText(args.force)
    ExtractXMLAssets(xmlFiles, args.force, args.unaccounted)
    finish = time.perf_counter()
    print(f"Finished extracting assets in {round(finish-start, 2)} seconds")

if __name__ == "__main__":
    main()