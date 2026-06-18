# Building on Linux

## Prerequisites

To build the project, you will need Docker and Git. The installation instructions below are for Ubuntu (26.04 LTS). If you are using a different distribution, I trust in your ability to figure out how to install these things on your own. To install Git, run

```
sudo apt install docker git
```

Verify Git was properly installed by running

```
git --version
```

You should see something along the lines of

```
git version 2.53.0
```

Note that the version number may be different.

To install the Docker Engine, you should follow the method as mentioned on [Docker's own documentation](https://docs.docker.com/engine/install/). The information below on installing Docker is copied from the part of the page linked that shows how to install it through Docker's own apt-repositories. **Note that you should double check that the instructions have not changed by following the link, as the information below might be outdated by the time you read this.**

```
# Add Docker's official GPG key:
sudo apt update
sudo apt install ca-certificates curl
sudo install -m 0755 -d /etc/apt/keyrings
sudo curl -fsSL https://download.docker.com/linux/ubuntu/gpg -o /etc/apt/keyrings/docker.asc
sudo chmod a+r /etc/apt/keyrings/docker.asc

# Add the repository to Apt sources:
sudo tee /etc/apt/sources.list.d/docker.sources <<EOF
Types: deb
URIs: https://download.docker.com/linux/ubuntu
Suites: $(. /etc/os-release && echo "${UBUNTU_CODENAME:-$VERSION_CODENAME}")
Components: stable
Architectures: $(dpkg --print-architecture)
Signed-By: /etc/apt/keyrings/docker.asc
EOF

sudo apt update
```

Afterwards, install Docker by running

```
sudo apt install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
```

Verify Docker is installed by running

```
sudo systemctl status docker
```

You should see something along the lines of

```
● docker.service - Docker Application Container Engine
     Loaded: loaded (/usr/lib/systemd/system/docker.service; enabled; preset: enabled)
     Active: active (running) since Thu 2026-06-18 14:01:15 CEST; 42s ago
```

If it is not active, you might see something like this instead

```
● docker.service - Docker Application Container Engine
     Loaded: loaded (/usr/lib/systemd/system/docker.service; enabled; preset: enabled)
     Active: inactive (dead) since Thu 2026-06-18 14:02:40 CEST; 1s ago
```

In this case, start Docker manually by running

```
sudo systemctl start docker
```

Verify that Docker is running by repeating the steps mentioned above. 

Lastly, verify the installation was successful by running the hello-world image

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

For it to update, you need to log in and out again.

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

To build ZHL files, you need to install Lua and some other dependencies. Run the following commands

```
sudo apt install lua5.3 liblua5.3-dev luarocks
sudo luarocks install luafilesystem
sudo luarocks install lpeg
```

Afterwards you may run `./libzhlgen/parsefuncs.sh` to regenerate the source files generated from ZHL.
