# Building

Note that these instructions are a WIP so if you follow them, please report any issues you find and propose any recommendations (e.g., if you needed to perform an additional step or if you were able to omit a step).

We Used to build in CodeBlocks... But now a new method far simpler is in place to build Hyperspace.
You will need to have Git installed, if you do not have it, get it here: https://git-scm.com/downloads

The basis of the building process is that it is ran through a virtual UNIX, allowing for a less restrictive and automated "tool installation" process.

### Enabling Hyper-V
As said you will need to virtualise Ubuntu in order to build Hypespace.
We need to ensure that your OS is set to do so.

In windows search bar, search for "Turn Windows feature on or off" and open it:
[[/img/building-tutorial/winfeat.png]]

Inside Windows Features ensure that (if it exists) Hyper-V is activated:
[[/img/building-tutorial/hyper-v.png]]

### Installing Docker Desktop
Go to the following link https://www.docker.com/products/docker-desktop/
and select "Download for Windows", you do not need to create an account.

Once downloaded, run the installation process, the process is fairly long, so you can start the "Installing WSL Ubuntu" section of this guide in the meantime.

### Installing WSL Ubuntu
The build process runs on Ubuntu, meaning you have to virtualise a UNIX environment, thankfully Windows as an in-built tool for that purpose.

Open the command prompt (Win+R, type "cmd" then enter).

Inside the command prompt type `wsl --install Ubuntu` this should start the installation process. You will be asked to enter a username and a password.
[[/img/building-tutorial/wslUbuntu.png]]

At the end of the installation process you will be asked to reboot you computer, if you are doing it at the same time as the Docker Desktop application, wait for it to finish before doing so.

### Setting Up Docker Desktop

Once you have rebooted your computer launch Docker Desktop, go inside the settings (up, next to the search bar). In General, ensure that `Use the WSL 2 based engine (Windows Home can only run the WSL 2 backend)` is activated.
[[/img/building-tutorial/wsldocker.png]]

Keep Docker Desktop open for the rest of the guide.

### Setting Up WSL

Return to the command prompt (Win+R, type "cmd" then enter).
Type `wslconfig /l`, you should have something like [[/img/building-tutorial/badwsl.png]]

You will need to set wsl Ubuntu as the default. Type `wslconfig /s Ubuntu`. You should obtain this after rerunning `wslconfig /l` [[/img/building-tutorial/goodwsl.png]]

### Cloning The Repository and setting up permission
You are nearly done, you will only need to clone the Hyperspace repository inside wsl to be able to start the build process.

Return to the command prompt.
Type `wsl`, navigate to the folder you want to clone the Hyperspace repository, then run `git clone https://github.com/FTL-Hyperspace/FTL-Hyperspace`
[[/img/building-tutorial/clonehs.png]]

This will clone the current Hyperspace repository from GitHub to your computer (when working with Hyperspace it is recommended to fork the Hyperspace repository and to work on it instead)

Now you need to navigate the cloned repository to reach buildscripts/windows/ .sh files, running `cd FTL-Hyperspace/buildscripts/windows/` where you cloned the repository should work (otherwise use `ls` and `cd` to navigate to the right folder)

[[/img/building-tutorial/reachsh.png]]

Inside the folder run `sudo chmod 777 *` to ensure that your system will authorize the execution of those file when building Hyperspace.

### Building Hyperspace

Ensure that you have Docker Desktop running, otherwise the build will not start.
While still in wsl, inside `FTL-Hyperspace/buildscripts/windows/` run `sudo bash ./build-releaseonly-from-docker.sh`

This will prompt the building of Hypespace. From now on the .sh file will take care of the rest.

The first build of Hyperspace is the lenghty as it has to install all dependencies and build all of Hyperspace, the following one will be faster.

At the end of the building process you should find your new hyperspace.dll at `FTL-Hyperspace\build-windows-release\` ready to be tested.

# Optional

## Hypervisor Error
During the above guide it may happen that you encounter this error [[/img/building-tutorial/hypererror.png]]

This error means that the hardware visualization is disabled on your motherboard, it is an issue that is hardware specific so we recommend the following solution:

Google "how to enable hardware visualization on `insert motherboard manufacturer here`" and follow the guide that present themselves.

You can find out who's motherboard you have by, hitting Win+R and typing `msinfo32`.
In the "System Information", the right information board you should find the item "BaseBoard Manufacturer" with its corresponding value.[[/img/building-tutorial/board.png]]

## Building ZHL files (not required to build Hyperspace)


For building ZHL files you need some dependencies, run all the following command in `wsl`
`sudo apt install lua5.3`
`sudo apt-get install lua5.3-dev`
`sudo apt-get install lua5.3 luarocks`
`sudo luarocks install luafilesystem`
`sudo luarocks install lpeg`

The navigate to `\FTL-Hyperspace\libzhlgen\`
and run
`sudo bash ./parsefuncs.sh`
your ZHL files should now be built.
