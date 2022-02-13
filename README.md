# Open Ocarina - The Master Port


```diff
- WARNING! -

This repository is a work in progress, and while it can be used to make certain changes, it's still
constantly evolving.

Currently assets are statically linked, however this is just until we get the game sorted.  Once its stable,
we will switch to an external asset loader.  Stability, 60 FPS, and external asset loading are the top priorities.

While it is playable in it's current state, if you are not interested in contributing, then you should
wait until the project is further along before playing it.  This is a development branch.  We need help
finding bugs and PR's for bug fixes and enhancements.

Only Visual Studio Debug 32-bit is currently supported.

Though most of the work for 64-bit is done, 32-bit is being buttoned up first.

32-bit Release works, but is buggy due to optimizations breaking many assumptions.
```

**Note: This repository does not include any of the assets necessary to build the ROM. A prior copy of the game is required to extract the needed assets. The required ROM is The Legend of Zelda: Ocarina of Time PAL 1.0. The correct checksum is** ``e040de91a74b61e3201db0e2323f768a``**.**
 
**Note: Be sure to use ``git clone --recursive https://github.com/blawar/ooot.git`` when cloning the repo for the submodules.**

**Discord:** <https://discord.com/invite/8tktBEhbZm>

## Contributers
The current main contributers of this project are [blawar](https://github.com/blawar), [mrneo240](https://github.com/mrneo240), and [DaMarkov](https://github.com/damarkov)

## Installation

### Windows

**Visual Studio 2019+ is the only currently supported build environment, and only the 32-bit X86 Debug build**

**Visual Studio 2019+ is the only currently supported build environment, and only the 32-bit X86 Debug build**

**Visual Studio 2019+ is the only currently supported build environment, and only the 32-bit X86 Debug build**

**Visual Studio 2019+ is the only currently supported build environment, and only the 32-bit X86 Debug build**

You must use the ZAPD that is included with this repository, and not the main branch as it is modified.

Run this command to extract the assets from the rom (baserom_original.z64 must exist in the directory)
```
setup.py
```

Open vs/OOT.sln, make sure **Debug - Win32** is selected, then hit build.

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

