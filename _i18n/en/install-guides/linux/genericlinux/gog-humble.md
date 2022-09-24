# Before you start
**Uninstall any other FTL mods before proceeding!**

***NOTE***
This guide assumes the GoG installed version and that it's installed to `~/GOG Games/FTL Advanced Edition` (the `GOG Games` folder in your user's home directory) If you are using the Humble Bundle version or have installed the GOG version somewhere else the instructions are *exactly the same* but obviously the game's location may differ.

***NOTE***
This guide assumes your system is using KDE Plasma as the desktop environment (Same as the Steam Deck & Kubuntu) and shows shortcuts and navigation in the filebrowser & apps common to KDE, if you're using a different desktop environment things might be slightly different but it should be close enough to send you down the right path. One noteable thing `Konsole` is KDE's form of the terminal/command line/xterm/gterm/whatever your system calls it.

1. Launch FTL to make sure you're running the correct version
![image]({{ '/assets/img/install/steamdeck/gog-humble/1.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/2.png' | relative_url }})
2. Ensure the version says `1.6.12` in the lower right.
![image]({{ '/assets/img/install/steamdeck/gog-humble/3.png' | relative_url }})
5. Download Hyperspace <a id="hyperspace-download-link" href="https://github.com/FTL-Hyperspace/FTL-Hyperspace/releases/latest">`FTL-Hyperspace.x.x.x.zip` from here</a> to your `Downloads` folder
***Do not extract this ZIP yet***
6. Download [Vhati's Slipstream 1.9.1 for Linux](https://sourceforge.net/projects/slipstreammodmanager/files/Slipstream/1.9.1/SlipstreamModManager_1.9.1-Unix.tar.gz/download) to your `Downloads` folder
***Do not extract this tar.gz yet***
7. Open your file browser and navigate to the FTL install folder and into the game & data folders
![image]({{ '/assets/img/install/steamdeck/gog-humble/4.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/5.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/6.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/7.png' | relative_url }})
10. It should look like this, for an unmodified vanilla install
![image]({{ '/assets/img/install/steamdeck/gog-humble/8.png' | relative_url }})
11. Open the Downloads folder in a new window where we previously downloaded Hyperspace & Slipstream to
![image]({{ '/assets/img/install/steamdeck/gog-humble/9.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/10.png' | relative_url }})
12. Right click the Hyperspace zip file and `Open with Ark` as we need to extract just a few files from it and not everything
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_15.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_16.png' | relative_url }})
13. Expand the `Linux` folder in Ark by clicking on the little arrow to the left of it.
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_17.png' | relative_url }})
14. Select only `Hyperspace.1.6.12.amd64.so` and `liblua5.3.so.0` and drag them over to the data folder to extract them there
![image]({{ '/assets/img/install/steamdeck/gog-humble/11.png' | relative_url }})
15. Your data folder should now look like this
![image]({{ '/assets/img/install/steamdeck/gog-humble/12.png' | relative_url }})
16. Right click the `FTL` file and `Open with KWrite` or whatever text editor you want
![image]({{ '/assets/img/install/steamdeck/gog-humble/13.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/14.png' | relative_url }})
17. Modify the last few lines of the file to look ***EXACTLY*** like this
You must add these two lines before the `exec` line but after the other `export` lines
```sh
export LD_LIBRARY_PATH="$here":${LD_LIBRARY_PATH}
export LD_PRELOAD=Hyperspace.1.6.12.amd64.so
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
export LD_PRELOAD=Hyperspace.1.6.12.amd64.so
exec "$here/$command.$arch" "$@"
```
So to be clear you are just adding the two lines but it's ***very important*** you add them before that last line of the file that has `exec`
![image]({{ '/assets/img/install/steamdeck/gog-humble/15.png' | relative_url }})
18. Save the file & close KWrite
![image]({{ '/assets/img/install/steamdeck/gog-humble/16.png' | relative_url }})
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
26. Launch Slipstream by right clicking `modman.command` and selecting `Run In Konsole`
![image]({{ '/assets/img/install/steamdeck/steam/37.png' | relative_url }})
27. Slipstream will likely not auto-detect a GoG or Humble install, you'll have to tell it where the `FTL.dat` file is
![image]({{ '/assets/img/install/steamdeck/gog-humble/17.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/18.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/19.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/20.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/21.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/22.png' | relative_url }})
28. Select that it was not installed via Steam
![image]({{ '/assets/img/install/steamdeck/gog-humble/23.png' | relative_url }})
29. Your choice, yes/no if you want it to check for updates
![image]({{ '/assets/img/install/steamdeck/slipstream_update_prompt.png' | relative_url }})
30. Slipstream running, check the box next to `Hyperspace` and hit `Patch`
![image]({{ '/assets/img/install/steamdeck/slipstream_checkhyperspace_hit_patch.png' | relative_url }})
32. Say ***NO*** to running the game right now, we need to stop here and go disable steam cloud saves & delete the save files to ensure a successful start.
![image]({{ '/assets/img/install/steamdeck/steam/51.png' | relative_url }})
#### Removing old saves that will probably freeze the game
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
![image]({{ '/assets/img/install/steamdeck/steam/61.png' | relative_url }})
42. Launch FTL
43. You should see a language selector if you deleted all the saves correctly.
![image]({{ '/assets/img/install/steamdeck/steam/63.png' | relative_url }})
44. You should notice it says `HS-x.x.x x64` in the upper right corner, this indicates the Hyperspace.so file is running
The `1.6.12 (Hyperspace x.x.x)` in the lower right indicates a successful patching of Hyperspace.ftl with slipstream.
You should see **BOTH** indicators showing hyperspace is running correctly.
![image]({{ '/assets/img/install/steamdeck/gog-humble/24.png' | relative_url }})
