---
layout: default
title: GoG Hyperspace Install Instructions
permalink: /install-guides/windows/gog-install/
---

## Installing FTL & Downgrading to 1.6.9

1. Install GoG Galaxy
   - Yes you *have* to use Galaxy, it's the only option GoG provides for downgrading, you can't download an EXE directly from GoG that is the older 1.6.9 version
2. Launch GoG Galaxy
3. Sign in
4. Install FTL: Faster Than Light
5. WAIT for the install to actually complete (seriously, the version options don't show up until after it's installed)
6. Select options for the game and go down to `manage installation` -> `configure`
   - ![image](https://user-images.githubusercontent.com/1423894/173690397-d192730c-06b1-46dd-b78c-d0c4f14c3de1.png)
   - ![image](https://user-images.githubusercontent.com/1423894/173690647-c66f13dd-5b02-4104-bfee-1ca3e57843d4.png)
7. Select `show more versions` and then select `1.6.9`
   - ![image](https://user-images.githubusercontent.com/1423894/173690919-3f27ea0f-60e5-41f7-a9f4-35b7462361a6.png)
8. Hit okay and wait for GoG Galaxy to download & install 1.6.9
9. You might have to have GoG retry a few times, it fails for random reasons but eventually it'll get it installed
10. Check the options again, it should now say 1.6.9
   - ![image](https://user-images.githubusercontent.com/1423894/173694163-c9b2eb75-7bd4-4826-94de-557989c21959.png)
11. Go to `manage installation` -> `show folder` and proceed with the next steps of hyperspace installation.
   - ![image](https://user-images.githubusercontent.com/1423894/173691147-8ba9eb0f-5dfd-4534-b93b-3ecf9f680274.png)

## Installing Hyperspace Binary

1. Download latest [`FTL-Hyperspace.x.x.x.zip` from here](https://github.com/FTL-Hyperspace/FTL-Hyperspace/releases/latest)
   - `x.x.x` is the hyperspace version
   - **Do not** download `Source code (zip)` or `Source code (tar.gz)` this is not what you want.
2. Open the zip
3. Open the `Windows - Extract these files into where FTLGame.exe is` folder in the zip ![FT1](https://user-images.githubusercontent.com/1423894/173667147-1cc5f424-7d9b-455b-a5db-83c2b9aba2a4.png)
5. Copy all the `DLL` files and none of the other files from this zip, you should have `Hyperspace.dll` `xinput1_4.dll` and in Hyperspace 1.2.0+ a `lua.dll`
6. Extract the DLLs and nothing else to the install directory opened by GoG in step #11 above
   - After your FTL install should look like this, no extra files, and `ftl.dat` **should be exactly the same in size** or else you might have other mods already patched in and need to revert with slipstream first
   - ![FT8](https://user-images.githubusercontent.com/1423894/173696617-18831745-856b-4d91-a5f1-da891aa3a0cb.png)

## Patching in hyperspace-based mods with Slipstream

{% include_relative windows-slipstream.md %}
