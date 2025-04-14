# Running Linux on Windows

Since Hyperspace is available both on Linux and Windows we have to ensure that new features and signatures work on both sides.
For Linux testing we can make use of WSL, the integrated method of running Linux on Windows.

### Enabling Hyper-V

Press the Windows key, search for "Turn Windows feature on or off" and open it.

[[/img/building-tutorial/winfeat.png]]

Inside Windows Features, ensure that Hyper-V is activated if it is present in the list.

[[/img/building-tutorial/hyper-v.png]]

### Installing WSL Ubuntu

Windows Subsystem for Linux will provide this environment. We recommend Ubuntu since this is also the environment used for building Hyperspace.

Open the command prompt (Win+R, type "cmd" then press enter). Inside the command prompt type `wsl --install -d Ubuntu`. This should start the installation process. You will be asked to enter a username and a password.

[[/img/building-tutorial/wslUbuntu.png]]

At the end of the installation process you will be asked to reboot your computer. If Docker Desktop is still installing, wait for it to finish before doing so.

### Setting Up WSL

Return to the command prompt (Win+R, type "cmd" then enter). Type `wslconfig /l`. The output should look something like this.

[[/img/building-tutorial/badwsl.png]]

You will need to set WSL Ubuntu as the default. Type `wslconfig /s Ubuntu`. The output should look like this after rerunning `wslconfig /l`.

[[/img/building-tutorial/goodwsl.png]]

### Downloading Linux FTL from Steam
You can fetch the Linux copy using the `steam console`:

`Win`+`R`

[[/img/wsl-linux/win-r-steam.png]]

Type `steam://open/console`

[[/img/wsl-linux/command-steam.png]]

`download_depot 212680 221002` (Steam will list where the files were saved)

[[/img/wsl-linux/steam-output-path.png]]

[[/img/wsl-linux/linux-files-steam.png]]

After downloading the Linux files through Steam, we recommend moving them to a more accessible path and renaming the parent folder to something recognizable, such as "FTL-Linux".

### Preparing Linux FTL

#### Downloading Necessary Packages

Both of these packages are necessary to run FTL under Linux (by extension WSL):
`sudo apt-get install libgl1-mesa-glx libasound2 libSDL2-2.0`

#### Set up Hyperspace

Download the latest [Hyperspace](https://github.com/FTL-Hyperspace/FTL-Hyperspace/releases) version.
In the Hyperspace zip, go into the `Linux` folder, move `Hyperspace.1.6.13.amd64.so` and `liblua5.3.so.0` into the `data` folder of your Linux installation.

[[/img/wsl-linux/file-to-linux.png]]

In the `FTL` file of the `data` folder add the two following lines:
```sh
export LD_PRELOAD=Hyperspace.1.6.13.amd64.so
exec "$here/$command.$arch" "$@"
```

The file should look like this at the end:
[[/img/wsl-linux/ftl-file-change.png]]

#### ModManager

Download [Vhati's Slipstream 1.9.1 for Linux](https://sourceforge.net/projects/slipstreammodmanager/files/Slipstream/1.9.1/SlipstreamModManager_1.9.1-Unix.tar.gz/download) and extract it where you see fit. We recommend putting it in the `data` folder so you can easily find it.

Start the modman.jar and select `data/ftl.dat` for the path.

Now in the Hyperspace zip, move the `Hyperspace.ftl` into the mod folder of your mod manager.
Patch the file with the mod manager (this can be done on Windows).
[[/img/wsl-linux/mod-manager-hs.png.png]]

### Running Linux FTL

Open the cmd, navigate to the root of your Linux FTL installation and run `wsl ./FTL`

# Additional Mention

With `gdb` the Linux version of Hyperspace FTL gives better stack trace in case of crash compared to the Windows version. To exploit this you will have to build and use the debug version of Hyperspace for Linux.

WSL lacks sound support by default, which shouldn't be a cause of issue for most testing scenarios but is still something to be mindful about.
