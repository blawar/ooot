[![Windows Build](https://github.com/blawar/ooot/actions/workflows/msbuild.yml/badge.svg)](https://github.com/blawar/ooot/actions/workflows/msbuild.yml)

# Open Ocarina - The Master Port


```diff
- WARNING! -

Currently assets are statically linked, however this is just until we get the game sorted.  Once its stable,
we will switch to an external asset loader.  Stability, 60 FPS, and external asset loading are the top priorities.

Though most of the work for 64-bit is done, 32-bit is being buttoned up first.
```

**Note: This repository does not include any of the assets necessary to build the ROM. A prior copy of the game is required to extract the needed assets.**

**Note: Be sure to use ``git clone --recursive https://github.com/blawar/ooot.git`` when cloning the repo for the submodules.**

**Discord:** <https://discord.com/invite/8tktBEhbZm>

## Contributers
The current main contributers of this project are [blawar](https://github.com/blawar) and [DaMarkov](https://github.com/damarkov)

## Installation

### Windows

**Visual Studio 2019+ is the only currently supported build environment, and only the 32-bit X86/WIN32 build**

You must use the ZAPD that is included with this repository, and not the main branch as it is modified.

### PAL 1.0 RETAIL ROM
If you are using the EUR PAL 1.0 retail rom, than place it at roms/PAL_1.0/baserom_original.z64

Run this command to extract the assets from the rom (baserom_original.z64 must exist in the directory)
```
setup.py -b PAL_1.0
```

### EUR Masterquest Debug ROM
If you are using the EUR Master Quest Debug rom, than place it at roms/EUR_MQD/baserom_original.z64

Run this command to extract the assets from the rom (baserom_original.z64 must exist in the directory)
```
setup.py -b EUR_MQD
```

Open vs/OOT.sln, make sure **Debug - Win32** or **Release - Win32** is selected, then hit build.

Once the build completes, press F5 to start it.

### macOS

Not currently supported, however a makefile and porting of GLideN64 would allow this and a PR is welcome.

### Linux (Native or under WSL / VM)

Not currently supported, however a makefile and porting of GLideN64 would allow this and a PR is welcome.



## Contributing

All contributions are welcome. This is a group effort, and even small contributions can make a difference.
Some tasks also don't require much knowledge to get started.  The best contribution that can be made, is playing the game and reporting bugs by opening a github issue on this repository.  Code contributions, as well as porting changes from the [upstream repo](https://github.com/zeldaret/oot) are greatly appreciated.

Most discussions happen on our [Discord Server](https://discord.com/invite/8tktBEhbZm), where you are welcome to ask if you need help getting started, or if you have any questions regarding this project and other decompilation projects.

## License

This software is licensed under the terms of the GPLv2, with exemptions noted below:

[Nintendo](https://github.com/Nintendo) is exempt from GPLv2 licensing and may (at its option) instead license any source code authored for this project under the MIT license.

Only commits *after* Dec 27, 2021 [a862411](https://github.com/blawar/ooot/commit/a862411f00c536770850f2c4e9e9b2edfea8947b) are covered under this GPL v2 license, as the original [upstream repo](https://github.com/zeldaret/oot/) unfortunately did not have a license and can not be relicensed retroactively.
