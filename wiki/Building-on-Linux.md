# Building on Linux

## Prerequisites

#### Installing Git

To build the project, you will need Docker and Git. The installation instructions below have been confirmed to work on Ubuntu (26.04 LTS), but we are including instructions for other distributions. First, install Git.

| Distributions         | Install command        |
|:----------------------|:-----------------------|
| Ubuntu / Debain       | `sudo apt install git` |
| Fedora / RHEL         | `sudo dnf install git` |
| Arch                  | `sudo pacman -S git`   |


Verify Git was properly installed by running

```
git --version
```

You should see something along the lines of

```
git version 2.53.0
```

Note that the version number may be different.

#### Installing Docker

To install Docker, we will be using the [convenience script](https://docs.docker.com/engine/install/ubuntu/#install-using-the-convenience-script) provided by Docker. If you want to customize the installation, feel free to install the Docker Engine [through other means](https://docs.docker.com/engine/install/ubuntu/#installation-methods). **It is recommended to double check the installation instructions by following the first hyperlink, as they may have changed since writing this.**

Run the following commands in the terminal:

```
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh ./get-docker.sh
```

After the script is finished, Docker will be installed and the `docker` service should start automatically. **Note:** On RPM-based distributions, such as Fedora and RHEL, you need to manually start the `docker` service using `systemctl`.

```
sudo systemctl start docker
```

Next, verify Docker is installed by running

```
sudo systemctl status docker
```

You should see something along the lines of

```
● docker.service - Docker Application Container Engine
     Loaded: loaded (/usr/lib/systemd/system/docker.service; enabled; preset: enabled)
     Active: active (running) since Thu 2026-06-18 14:01:15 CEST; 42s ago
```

Verify the installation was successful by running the hello-world image

```
sudo docker run hello-world
```

If successful, it will write some text to the screen, including

```
Hello from Docker!
This message shows that your installation appears to be working correctly.
```

**Note:** While not required, it may be useful to add your user to the `docker` group. This will let you run Docker commands (and, by extension, the script to build the project) without needing sudo. First, ensure the group exists by running

```
sudo groupadd docker
```

If you get a message saying `groupadd: group 'docker' already exists`, ignore it. It just means the group was already created.

Then, add yourself to it by running

```
sudo usermod -aG docker ${USER}
```

For it to update, either log out and back in or run the following command in the terminal to get a new terminal session:

```
exec su - $USER
```

To check if you were added to the group successfully, run the `hello-world` image again, this time without `sudo`.

```
docker run hello-world
```

If successful, you will see the following text:

```
Hello from Docker!
This message shows that your installation appears to be working correctly.
```

## Building Hyperspace

Now that Docker and Git are properly installed, we can go ahead and actually build the project. Navigate to your preferred directory by using `cd` and clone the repository by running

```
git clone https://github.com/FTL-Hyperspace/FTL-Hyperspace
```

Afterwards, navigate into it by running

```
cd FTL-Hyperspace/
```

The `./buildscripts/` directory has the scripts to (you guessed it!) build the project. Within `./buildscripts/` there are different folders for different platforms and (at times) different versions. Within these folders, you want to run the ones that end with `from-docker.sh`. Below we will be compiling Hyperspace version `1.6.13` for Linux by running

```
./buildscripts/linux-1.6.13/build-releaseonly-from-docker.sh
```

Compiling will take longer the first time since everything needs to be compiled. Compiling afterwards will be quicker.

**If you did not add your user to the `docker` group, you will see the following error**

```
permission denied while trying to connect to the docker API at unix:///var/run/docker.sock
```

**In this case, either follow the instructions to add your user to the `docker` group, or run the script with sudo.**

After the compiling is done, you will find a new folder in the `FTL-Hyperspace` directory, named `build-linux-1.6.13-release` (may have a different name if you compile a different version or `debug` instead of `release`). Within it, you will find `Hyperspace.1.6.13.amd64.so`!

## Building ZHL files (not required to build Hyperspace)

To build ZHL files, you need to install Lua and some relate dependencies. Run the following commands

```
sudo apt install lua5.3 liblua5.3-dev luarocks
sudo luarocks install luafilesystem
sudo luarocks install lpeg
```

Afterwards you may run `./libzhlgen/parsefuncs.sh` to regenerate the source files generated from ZHL.
