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

**Note: This repository does not include any of the assets necessary to build the ROM. A prior copy of the game is required to extract the needed assets.**

**Discord:** <https://discord.gg/s4BskkKf>

## Installation

### Windows

**Visual Studio 2019+ is the only currently supported build environment, and only the 32-bit X86 Debug build**

**Visual Studio 2019+ is the only currently supported build environment, and only the 32-bit X86 Debug build**

**Visual Studio 2019+ is the only currently supported build environment, and only the 32-bit X86 Debug build**

**Visual Studio 2019+ is the only currently supported build environment, and only the 32-bit X86 Debug build**

To build, first you must use run ``make setup`` and ``make`` in this directory using either linux or WSL to extract the assets into the assets and build directories.
If you run it on another computer, just copy over the asset and build directories.  The make does not need to succeed, as long as it extracts all assets.
If you have any problems extracting, you should check the more in depth instructions at https://github.com/zeldaret/oot/blob/master/README.md

You must use the ZAPD that is included with this repository, and not the main branch as it is modified.

Run these commands from the root ooot directory after you have extracted assets and build directories:
```
tools\extract_missing_assets.py
tools\create_luts.py
tools\mark_segments.py
```

You must then open up GLideN64/projects/msvc/GLideN64.sln and build **Debug_mupenplus - Win32**, which should copy GLideN64d.lib, libGLideNHQd.lib, and osald.lib files to externals/Win32/

Then open vs/OOT.sln, select **Debug - X86** then hit build.

Once the build completes, press F5 to start it.

### macOS

Not currently supported, however a makefile and porting of GLideN64 would allow this and a PR is welcome.

### Linux (Native or under WSL / VM)

Not currently supported, however a makefile and porting of GLideN64 would allow this and a PR is welcome.



## Contributing

This project is currently maintained by blawar/vertigo and Zel.

All contributions are welcome. This is a group effort, and even small contributions can make a difference.
Some tasks also don't require much knowledge to get started.  The best contribution that can be made, is playing the game and reporting bugs by opening a github issue on this repository.  Code contributions, as well as porting changes from the [upstream repo](https://github.com/zeldaret/oot) are greatly appreciated.

Most discussions happen on our [Discord Server](https://discord.gg/s4BskkKf), where you are welcome to ask if you need help getting started, or if you have any questions regarding this project and other decompilation projects.

## License

This software is licensed under the terms of the GPLv2, with exemptions noted below:

[Nintendo] (https://github.com/Nintendo) is exempt from GPLv2 licensing and may (at its option) instead license any source code authored for this project under the MIT license.

