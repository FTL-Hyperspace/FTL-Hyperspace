---
layout: default
title: "Steam Windows Hyperspace Install Instructions"
permalink: /install-guides/windows/steam-install/
---

**Uninstall any other FTL mods before proceeding!**

## Downgrading & Installing Hyperspace Library

This downgrader will **ONLY** work for Steam's 1.6.14 version of FTL, if you have any other FTL install not from steam you need to look at the [other install instructions for your source](/install-guides/windows/).

1. Start FTL, at the main menu in the lower right it ***MUST*** say `Steam Version: 1.6.14`, if it says `1.6.9` you have already downgraded. If it says anything else you might have some mods still installed! (where x.x.x is the version of Hyperspace)
2. Download [`FTL-Hyperspace.x.x.x.zip` from here](https://github.com/FTL-Hyperspace/FTL-Hyperspace/releases/latest)
   - Don't download the source code zip or tar.gz, only the `FTL-Hyperspace` zip
3. Navigate in Steam to FTL and browse local files. ![image](https://user-images.githubusercontent.com/1423894/173640622-7c442fc2-89a2-418f-ba28-354568381263.png)
4. Your local files should look like so: (please note there are some language differences in Windows here)
   - You should see *the __same file sizes__ and files present*
   - ![image](https://user-images.githubusercontent.com/1423894/173657085-225a9560-411e-4a20-b707-b836ba36e551.png)

5. Open `FTL-Hyperspace.x.x.x.zip` that you downloaded
6. Open the `Windows - Extract these files into where FTLGame.exe is` folder in the zip ![FT1](https://user-images.githubusercontent.com/1423894/173667147-1cc5f424-7d9b-455b-a5db-83c2b9aba2a4.png)

7. Extract all the files & folders in the `Windows` folder to the same location where `FTLGame.exe` is on your computer
   - *do not extract the entire zip to the folder, you only need the contents of the Windows folder for this step*
   - **NOTE:** Hyperspace 1.2.0 and above will also have a `lua.dll` that must also be extracted but is not shown in these screenshots.
   - ![FT2](https://user-images.githubusercontent.com/1423894/173667301-421fb58e-57c8-43e9-8339-7a01490fd18a.png)

8. At this point your game folder should look exactly like this:
   - You might have a `crashlogs` folder or a settings file or a couple extra log files but there shouldn't be any other files in here, no `.ftl` files no `zip` files.
   - **NOTE:** Hyperspace 1.2.0 and above will also have a `lua.dll` that is not shown in these screenshots.
   - Your `ftl.dat` **should be very close or exactly the same size** or else you might still have mods installed
   - ![image](https://user-images.githubusercontent.com/1423894/173661274-86382f69-9141-4ff9-a23f-f7cbd0c8aec0.png)
9. Double click and run `downgrade.bat`
10. After downgrading your game folder should look exactly the same as here
   - **Please note the size** of `FTLGame.exe` and `FTLGame_orig.exe` if, `FTLGame.exe` is not `122MB` then the downgrade was not successful
   - ![image](https://user-images.githubusercontent.com/1423894/173661659-51d293fa-7f33-4292-8a13-80b7050e5e9d.png)
11. Hyperspace is now **Halfway-installed** you still need to patch a FTL Mod which uses hyperspace.

## Patching in hyperspace-based mods with Slipstream
{% include_relative windows-slipstream.md %}

#### Special Thanks
Special thanks to Cedric for providing many of the install images from Windows above
