# Building

You will need to have Git installed. If you do not have it, it can be downloaded it here: https://git-scm.com/downloads

### Enabling Hyper-V

Press the Windows key, search for "Turn Windows feature on or off" and open it.

[[/img/building-tutorial/winfeat.png]]

Inside Windows Features, ensure that Hyper-V is activated if it is present in the list.

[[/img/building-tutorial/hyper-v.png]]

### Installing Docker Desktop

Go to [the Docker website](https://www.docker.com/products/docker-desktop/) and select "Download for Windows." You do not need to create an account.

Once downloaded, run the installer. It takes some time, so you can continue to the next step while it works.

### Installing WSL Ubuntu

The build process runs on Ubuntu, meaning you have to virtualise a UNIX environment. Windows Subsystem for Linux will provide this environment.

Open the command prompt (Win+R, type "cmd" then press enter). Inside the command prompt type `wsl --install -d Ubuntu`. This should start the installation process. You will be asked to enter a username and a password.

[[/img/building-tutorial/wslUbuntu.png]]

At the end of the installation process you will be asked to reboot you computer. If Docker Desktop is still installing, wait for it to finish before doing so.

### Setting Up Docker Desktop

Once you have rebooted your computer, launch Docker Desktop. Go inside the settings (up, next to the search bar). Under "General," ensure that `Use the WSL 2 based engine (Windows Home can only run the WSL 2 backend)` is activated.

[[/img/building-tutorial/wsldocker.png]]

Keep Docker Desktop open for the rest of the guide.

### Setting Up WSL

Return to the command prompt (Win+R, type "cmd" then enter). Type `wslconfig /l`. The output should look something like this.

[[/img/building-tutorial/badwsl.png]]

You will need to set WSL Ubuntu as the default. Type `wslconfig /s Ubuntu`. The output should look like this after rerunning `wslconfig /l`.

[[/img/building-tutorial/goodwsl.png]]

### Cloning the Repository

In the command prompt, type `wsl`, navigate to the folder you want to clone the Hyperspace repository to using the `cd` command to change directories, then run `git clone https://github.com/FTL-Hyperspace/FTL-Hyperspace.git`. Make sure you clone in a directory that has no spaces in any of the folder names or else the build scripts won't be able to run properly.

[[/img/building-tutorial/clonehs.png]]

This will clone the current Hyperspace repository from GitHub to your computer. If you plan to contribute to Hyperspace, instead of cloning the original repository, you can create a fork and clone that instead.

Once the repo is cloned, you can `cd` into `FTL-Hyperspace/buildscripts/windows/` to enter the folder where the Windows build scripts are located.

[[/img/building-tutorial/reachsh.png]]

Inside the folder, run `sudo chmod 777 *` to ensure that your system will authorize the execution of those files when building Hyperspace.

### Building Hyperspace

Ensure that you have Docker Desktop running, otherwise the build will not start. While still in WSL, inside `FTL-Hyperspace/buildscripts/windows/`, run `./build-releaseonly-from-docker.sh`

If everything has been set up correctly, the build will start. The first build of Hyperspace will take some time as it has to install all dependencies and build from scratch, subsequent builds will be faster.

At the end of the build process, you should find `Hyperspace.dll` inside `FTL-Hyperspace\build-windows-release\`.

# Troubleshooting

## Hypervisor Error

While following the above steps, you may encounter this error.

[[/img/building-tutorial/hypererror.png]]

The error means that the hardware visualization is disabled on your motherboard. This issue is hardware specific, so you'll have to Google "how to enable hardware visualization on `insert motherboard manufacturer here`" and follow the instructions you find.

You can find your motherboard's manufacturer by hitting Win+R and typing `msinfo32`.
In "System Information," the right information board you should find the item "BaseBoard Manufacturer" with its corresponding value.

[[/img/building-tutorial/board.png]]

## Building ZHL files (not required to build Hyperspace)

For building ZHL files you need some dependencies. Run all the following commands in the WSL console:
```
sudo apt-get install lua5.3 luarocks
sudo luarocks install luafilesystem
sudo luarocks install lpeg
```

Then navigate to `\FTL-Hyperspace\libzhlgen\` and run `./parsefuncs.sh` to regenerate the source files generated from ZHL.
