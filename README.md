[![Windows Build](https://github.com/blawar/ooot/actions/workflows/msbuild.yml/badge.svg)](https://github.com/blawar/ooot/actions/workflows/msbuild.yml)

# Open Ocarina - The Master Port

**Note: This repository does not include any of the assets necessary to build the ROM. A prior copy of the game is required to extract the needed assets.**

**Note: Be sure to use ``git clone --recursive https://github.com/blawar/ooot.git`` when cloning the repo for the submodules.**

**Discord:** <https://discord.com/invite/8tktBEhbZm>

## How to Acquire the ROM needed

You must get that on your own and please do not ask for that in the discord due to discord's TOS.

PAL 1.0 MD5 

`9526b263b60577d8ed22fb7a33c2facd`

EUR MQD MD5 

`f0b7f35375f9cc8ca1b2d59d78e35405`

[MattsCreative](https://youtu.be/k1fjHLU9gGU) has a great videos and tutorial on how to compile this project Below: 

[How to use OOT Builder](https://youtu.be/pZi0r6g3YJ8)

## FAQ

[FAQ](https://github.com/blawar/ooot/wiki/FAQ)
Click here for more infomation on the Project!

## Features

- 20, 30, 60, and 120 FPS support (experimental) (defaults to original bug free 20 FPS)
- Right joystick free camera control (can be disabled)
- Ability to load high resolution GLideN64 texture packs such as [oot-reloaded](https://evilgames.eu/texture-packs/oot-reloaded.htm).
- The ability to assign equipment (boots, tunic, etc) to C-Buttons.
- The ability to assign equipment (boots, tunic, etc) to keyboard keys and gamepad buttons.
- Using B/Attack to execute the currently equiped C-Button equipment in first person mode (so you can fire the hookshot with either the C-Button or B).
- Gryo aiming.
- Controller rumble support.
- Keyboard and mouse aiming support.
- Fast text option (hold B during dialog).
- Fast forward gameplay keybind.
- Multilanguage supported (F9 to toggle).  Currently supports English, German and French (more languages on the way!).
- Pause menu keyboard/gamepad rebind screen.
- Ability to disable the Owl prompts in config.json
- Cheats in config.json
- Ability to invert gryo, mouse, left stick, and right stick in config.json

## Contributers
The current main contributers of this project are [blawar](https://github.com/blawar) and [DaMarkov](https://github.com/damarkov)

## How to Acquire the ROM needed

You must get that on your own and please do not ask for that in the discord due to discord's TOS.

### Windows and Required Programs

Step one install all required Programs below

[Python 3.10](https://www.python.org/downloads/) **Add to path during the install**

![68747470733a2f2f692e696d6775722e636f6d2f4544326c5139512e706e67](https://user-images.githubusercontent.com/84041391/163289314-75bf3467-9506-4df6-bdf8-ece6a7114792.png)


[Git Deskktop](https://central.github.com/deployments/desktop/desktop/latest/win32) **Install with your github account and clone using URL**

![image](https://user-images.githubusercontent.com/84041391/233754962-5c28c5e7-9c91-4ca3-8862-91f79e68dbb9.png)

Next we switch to Dev branch 

![image](https://user-images.githubusercontent.com/84041391/233754991-bb94b133-74d5-4e2c-9563-cf5279d93202.png)

Next click Fetch 

![image](https://user-images.githubusercontent.com/84041391/233755011-a14ef259-0367-4a74-8cfc-781d1a560358.png)

[Visual Studio Community 2022](https://visualstudio.microsoft.com/vs/community/) **During setup click C++ development**
![vcc](https://user-images.githubusercontent.com/84041391/163289227-6fdfd616-edeb-4314-b29c-9a5ed50aa1c5.png)


**Visual Studio 2019+ is the only currently supported build environment, and only the 32-bit X86/WIN32 build**

You must use the ZAPD that is included with this repository, and not the main branch as it is modified.

Step 2 Follow what is below!

### PAL 1.0 RETAIL ROM
If you are using the EUR PAL 1.0 retail rom,

make sure baserom_original.z64 or baserom_original.n64 is inside the correct folder as shown below:
`\ooot\roms\PAL_1.0\` 

![rom pal](https://user-images.githubusercontent.com/84041391/163308550-bc9afea2-ce38-4021-bafc-2a83c63d9b85.png)


iF the roms hash is not correct it won't extract the assets and continue. `"hash_md5": ["c02c1d79679f7ceb9a3bde55fff8aa13"] `

Open command prompt and type:

```
cd .\source\repo\ooot 
```

![image](https://user-images.githubusercontent.com/84041391/233755375-b20fd588-1879-4f8f-a2cb-c5c1bd590ea3.png)


after it's done type:

![image](https://user-images.githubusercontent.com/84041391/233755385-f85fbc3b-e1ad-4766-aa9e-0c364356b44c.png)

```
python setup.py -b PAL_1.0
```

### EUR Masterquest Debug ROM
if you are using the EUR Master Quest Debug rom.

make sure baserom_original.z64 or baserom_original.n64 is inside the correct folder as shown below:
`\ooot\roms\EUR_MQD\`

![rom mq](https://user-images.githubusercontent.com/84041391/163308745-19d57f25-8ec7-45fb-9874-c0ddd865c50f.png)


if the roms hash is not correct it won't extract the assets and continue. `"hash_md5": ["f0b7f35375f9cc8ca1b2d59d78e35405", "8ca71e87de4ce5e9f6ec916202a623e9"`

Open command prompt and type:

```
cd .\source\repo\ooot 
```

![image](https://user-images.githubusercontent.com/84041391/233755375-b20fd588-1879-4f8f-a2cb-c5c1bd590ea3.png)

run this command next to extract the assets from the rom. (baserom_original.z64 must exist in the directory `\ooot\roms\EUR_MQD\`)

![image](https://user-images.githubusercontent.com/84041391/233755458-da107be7-65ab-4bd1-b897-3f83ea3a31e5.png)

```
python setup.py -b EUR_MQD
```

Open `OOT.sln`, you will find this in `\ooot\vs` 
![sln](https://user-images.githubusercontent.com/84041391/163309469-165d0695-bbac-4838-ab1e-c09b29ccfb8f.png)



make sure `Debug - Win32** or **Release - Win32` is selected, then hit build.

Once the build completes, press F5 to start it if you are testing code but if you are compiling to play right click `oot` on the side and click build.

## How to Enable 60FPS

`git checkout dev`

`git pull origin dev`

`git submodule update --init --recursive`

`python setup.py -b PAL_1.0`

And compile as normal! when in game press F7 to go back to 20FPS and F8 to go up to 30FPs 60FPs and 120FPS!

## How to update local repo

open git bash type:

`cd ooot`

`git pull`

`python setup.py -b PAL_1.0`

`python setup.py -b EUR_MQD`

and Open `OOT.sln`, you will find this in `\ooot\vs` make sure `Debug - Win32** or **Release - Win32` is selected, then hit build.

![release](https://user-images.githubusercontent.com/84041391/163309769-b4573b11-4650-4563-90a3-56cfef390206.png)
![debug](https://user-images.githubusercontent.com/84041391/163309770-859ea356-345a-4e6e-871c-3ffceba7c36a.png)


### macOS

Not currently supported, however a makefile and porting of GLideN64 would allow this and a PR is welcome.

### Linux (Native or under WSL / VM)
Linux does not currently work.  The below steps are for development purposes.

```
Debian/Ubuntu

sudo dpkg --add-architecture i386
sudo apt update
sudo apt install gcc-multilib g++-multilib
sudo apt install libsdl2-dev
sudo apt install libsdl2-dev:i386
sudo apt install libpng-dev
sudo apt install libfreetype6-dev
sudo apt install libfreetype6-dev:i386
sudo apt install python3
sudo apt install python3-pip
sudo apt install meson

Arch Linux

edit /etc/pacman.conf annd go to the bottom uncomment multilib so remove the # do not touch testing.

sudo pacman -S gcc lib32-gcc-libs
sudo pacman -S sdl2 lib32-sdl2
sudo pacman -S meson
sudo pacman -S python-pip
sudo pacman -S libpng

Fedora Linux

sudo dnf in gcc
sudo dnf in SDL2-devel
sudo dnf in meson
sudo dnf in python3-pip
sudo dnf in libpng
sudo dnf in g++

setup.py -b EUR_MQD
meson setup linux --cross-file x86-linux-gnu
cd linux
ninja
```



## Contributing

All contributions are welcome. This is a group effort, and even small contributions can make a difference.
Some tasks also don't require much knowledge to get started.  The best contribution that can be made, is playing the game and reporting bugs by opening a github issue on this repository.  Code contributions, as well as porting changes from the [upstream repo](https://github.com/zeldaret/oot) are greatly appreciated.

Most discussions happen on our [Discord Server](https://discord.com/invite/8tktBEhbZm), where you are welcome to ask if you need help getting started, or if you have any questions regarding this project and other decompilation projects.

## License

Only commits *after* Dec 27, 2021 [a862411](https://github.com/blawar/ooot/commit/a862411f00c536770850f2c4e9e9b2edfea8947b) are covered under this GPL v2 license, as the original [upstream repo](https://github.com/zeldaret/oot/) unfortunately did not have a license and can not be relicensed retroactively.

This software is licensed under the terms of the GPLv2, with exemptions noted below:

[Nintendo](https://github.com/Nintendo) is exempt from GPLv2 licensing and may (at its option) instead license any source code authored for this project under the MIT license.

[Ship of Harkinian](https://github.com/HarbourMasters/Shipwright) is exempt from GPLv2 for the ZAPD XML files and the below commit hashes and may instead license those files/changes under the MIT license as long as they properly credit the contributors of those files in their primary readme.

[52011c3d](https://github.com/blawar/ooot/commit/52011c3d38464a75461c9eb09bf6cb86b4c171b3)
[55765bca](https://github.com/blawar/ooot/commit/55765bca971154215348ae3eb533b0902af24d66)

## Special Thanks
- damarkov: Programming
- frizzle101101: Free Camera and high framerate fixes
- lehpumeh: Endless Testing
- mattscreative: Videos, Tutorials, and Wiki
