# Before you start
**Uninstall any other FTL mods before proceeding!**

***NOTE***
This guide assumes your system is using KDE Plasma as the desktop environment (Same as the Steam Deck & Kubuntu) and shows shortcuts and navigation in the filebrowser & apps common to KDE, if you're using a different desktop environment things might be slightly different but it should be close enough to send you down the right path. One noteable thing `Konsole` is KDE's form of the terminal/command line/xterm/gterm/whatever your system calls it.

1. Launch FTL to make sure you're running the correct version
![image]({{ '/assets/img/install/genericlinux/steam_FTL_launch.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_2.png' | relative_url }})
2. Ensure the version says `1.6.13` in the lower right, if it says 1.6.14 or somehow 1.6.9 you're accidentally running the Windows version under proton and need to turn off Steam play compatibility to run the native version.
![image]({{ '/assets/img/install/steamdeck/steam/check_ftl_version.png' | relative_url }})
5. Download Hyperspace <a id="hyperspace-download-link" href="https://github.com/FTL-Hyperspace/FTL-Hyperspace/releases/latest">`FTL-Hyperspace.x.x.x.zip` from here</a> to your `Downloads` folder
***Do not extract this ZIP yet***
6. Download [Vhati's Slipstream 1.9.1 for Linux](https://sourceforge.net/projects/slipstreammodmanager/files/Slipstream/1.9.1/SlipstreamModManager_1.9.1-Unix.tar.gz/download) to your `Downloads` folder
***Do not extract this tar.gz yet***
7. Launch the Steam library
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_8.png' | relative_url }})
8. Browse for FTL's local files by right clicking the game in Steam and going to `Manage` and then `Browse local files`
![image]({{ '/assets/img/install/browse_local_files_steam.png' | relative_url }})
9. Navigate to the `data` folder *(if you see `FTLGame.exe` then you need to stop & go disable SteamPlay compatibility on the title as you have the windows version installed)*
![image]({{ '/assets/img/install/genericlinux/steam_navigate_to_data_folder.png' | relative_url }})
10. It should look ***exactly*** like this, for an unmodified vanilla install
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_12.png' | relative_url }})
11. Open the Downloads folder in a new window where we previously downloaded Hyperspace & Slipstream to
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_13.png' | relative_url }})
![image]({{ '/assets/img/install/genericlinux/genericlinux_14.png' | relative_url }})
12. Right click the Hyperspace zip file and `Open with Ark` as we need to extract just a few files from it and not everything
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_15.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_16.png' | relative_url }})
13. Expand the `Linux` folder in Ark by clicking on the little arrow to the left of it.
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_17.png' | relative_url }})
14. Select only `Hyperspace.1.6.13.amd64.so` and `liblua5.3.so.0` and drag them over to the data folder to extract them there
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_18.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_19.png' | relative_url }})
15. Your data folder should now look like this
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_20.png' | relative_url }})
16. Open the file `FTL` with a text editor (KWrite/Kate/Vim/Gedit/etc...) *(Or whatever your favorite editor is and it still better be Vim and not Emacs)*
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_21.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/14.png' | relative_url }})
17. Modify the last few lines of the file to look ***EXACTLY*** like this
You must add these two lines before the `exec` line but after the other `export` lines
```sh
export LD_LIBRARY_PATH="$here":${LD_LIBRARY_PATH}
export LD_PRELOAD=Hyperspace.1.6.13.amd64.so
```
For reference, ***BEFORE*** it will look like this:
```sh
export LANG="${LC_ALL:-$LANG}"
export LC_ALL=
export LC_NUMERIC=C
exec "$here/$command.$arch" "$@"
```
***AFTER*** it must look exactly like this at the end of the file:
```sh
export LANG="${LC_ALL:-$LANG}"
export LC_ALL=
export LC_NUMERIC=C
export LD_LIBRARY_PATH="$here":${LD_LIBRARY_PATH}
export LD_PRELOAD=Hyperspace.1.6.13.amd64.so
exec "$here/$command.$arch" "$@"
```
So to be clear you are just adding the two lines but it's ***very important*** you add them before that last line of the file that has `exec`
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_23.png' | relative_url }})
18. Save the file & close your text editor
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_24.png' | relative_url }})
#### Slipstream
19. Go back to the downloads folder
20. Right click `SlipstreamModManager_1.9.1-Unix.tar.gz` and go down to `Extract` and select `Extract archive here`
![image]({{ '/assets/img/install/steamdeck/downloads_extract_slipstream.png' | relative_url }})
21. Navigate into the `SlipstreamModManager_1.9.1-Unix` folder
***NOTE*** At this point we're done with the Ark window for Slipstream (but not the other Ark window that has Hyperspace.zip open) we're also done with any use of `SlipstreamModManager_1.9.1-Unix.tar.gz` so you can delete it now if you want to free up space.
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_27.png' | relative_url }})
22. Navigate into the `mods` folder
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_29.png' | relative_url }})
It should look like this without any mods added
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_30.png' | relative_url }})
23. Go back over to the Ark window that has the hyperspace zip file open & select `Hyperspace.ftl`
24. Drag `Hyperspace.ftl` over into the `mods` folder of Slipstream
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_32.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_33.png' | relative_url }})
***NOTE*** You can now close the hyperspace Ark window and delete `Hyperspace.x.x.x.zip` from your downloads if you want we're done with it for good
25. Navigate back up to the slipstream folder (you can click `SlipstreamModManager`  in the title bar like I show here
![image]({{ '/assets/img/install/steamdeck/steam/35.png' | relative_url }})
26. Launch Slipstream by running `modman.command` (on KDE based environments you can right click and select `Run In Konsole`)
***NOTE*** Your system might be different if you're not running a KDE Plasma environment, you might have an option like `Run in Terminal` or your desktop environment might not provide a shortcut for it, you might have to navigate here from the terminal and instead run `./modman.command` in the terminal.
![image]({{ '/assets/img/install/steamdeck/steam/37.png' | relative_url }})
27. Slipstream will ask several questions, they should all match what you see here and you can just hit yes to them unless you installed FTL in a non-standard location (such as a second SteamLibrary in Steam) then it might prompt you to find the FTL.dat file.
![image]({{ '/assets/img/install/steamdeck/steam/38.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/steam/39.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/steam/40.png' | relative_url }})
28. You probably want to select `Steam` at this option.
![image]({{ '/assets/img/install/steamdeck/steam/41.png' | relative_url }})
29. Your choice, yes/no if you want it to check for updates
![image]({{ '/assets/img/install/steamdeck/slipstream_update_prompt.png' | relative_url }})
30. Slipstream running, check the box next to `Hyperspace` and hit `Patch`
![image]({{ '/assets/img/install/steamdeck/slipstream_checkhyperspace_hit_patch.png' | relative_url }})
32. Say ***NO*** to running the game right now, we need to stop here and go disable steam cloud saves & delete the save files to ensure a successful start.
![image]({{ '/assets/img/install/steamdeck/steam/51.png' | relative_url }})
#### Disabling Steam Cloud sync & removing old saves
33. Go back to the Steam library
34. Right click FTL: Faster Than Light and select `Properties`
![image]({{ '/assets/img/install/steam_properties.png' | relative_url }})
35. Uncheck `Keep games saves in the Steam Cloud for FTL: Faster Than Light`
*This is very important because otherwise it'll constantly break the game from loading properly*
![image]({{ '/assets/img/install/steam_properties_uncheck_cloud_saves.png' | relative_url }})
36. Go back to your file browser (Dolphin) select `Home` on the left hand side
![image]({{ '/assets/img/install/steamdeck/steam/56.png' | relative_url }})
37. Select the hamburger menu in the top right and check `Show Hidden Files`
![image]({{ '/assets/img/install/steamdeck/steam/57.png' | relative_url }})
38. Navigate into the `.local` folder
![image]({{ '/assets/img/install/steamdeck/steam/58.png' | relative_url }})
39. And then the `share` folder
![image]({{ '/assets/img/install/steamdeck/steam/59.png' | relative_url }})
40. Find the `FasterThanLight` folder, you can back it up somewhere at this point if you want to save your vanilla save
![image]({{ '/assets/img/install/steamdeck/steam/60.png' | relative_url }})
41. Right click `FasterThanLight` and select `Move to Trash`
***It is very important to delete this folder*** the first time after cloud sync is off as cloud sync results in a save file that Hyperspace can't read and will result in the game freezing at the end of the loading bar.
![image]({{ '/assets/img/install/steamdeck/steam/61.png' | relative_url }})
42. Launch FTL from Steam
![image]({{ '/assets/img/install/genericlinux/steam_FTL_launch.png' | relative_url }})
43. You should see a language selector if you deleted the saves correctly.
![image]({{ '/assets/img/install/steamdeck/steam/63.png' | relative_url }})
44. You should notice it says `HS-x.x.x x64` in the upper right corner, this indicates the Hyperspace.so file is running
The `1.6.13 (Hyperspace x.x.x)` in the lower right indicates a successful patching of Hyperspace.ftl with slipstream.
You should see **BOTH** indicators showing hyperspace is running correctly.
![image]({{ '/assets/img/install/steamdeck/steam/64.png' | relative_url }})

