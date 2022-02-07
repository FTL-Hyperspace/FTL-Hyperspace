## Building

Install boost C++ library
On Ubuntu it's
`sudo apt-get install libboost-all-dev`

You need `gcc` and all the basic C dev stuff
TODO: Put some better info here :P
`sudo apt-get install build-essential gcc-multilib g++-multilib`
***NOTE*** You need **`gcc-4.8`** ideally `4.8.4` or `4.8.5` (FTL was built with 4.8.4) Ubuntu 20.04 does not have GCC 4 as an option.
***NOTE*** Any gcc `4.9.0` or above *will not work* due to a change in the C++11 libraries that occurred after FTL was built

If you are on an older version of Ubuntu (or your distro has a copy of 4.8 in it) you might be able to install it with your package manager like
`sudo apt-get install gcc-4.8-multilib g++-4.8-multilib` (on Ubuntu Xenial at least or if you have the xenial source added to Ubuntu)

You need `libsdl2-dev`
`sudo apt-get install libsdl2-dev`

Not sure if we can use a lesser library.

## Installing GCC 4.8
Honestly go look up some info online for your specific distro, you can probably find a .deb or .rpm file of GCC 4.8.4 or 4.8.5 for your distro but I chose to compile it from source.
https://gcc.gnu.org/wiki/InstallingGCC

As a heads up, if you choose to do this pain yourself, go compile GCC 4.9.4 first since GCC 4.8 doesn't compile with modern GCC :) So yeah, go find a package file for your distro and just install it or build all of this mod in a VM/container with an old linux version or something unless you're quite confident in the Linux world.

On Ubuntu 20.04
Go add
```
deb http://dk.archive.ubuntu.com/ubuntu/ xenial main
deb http://dk.archive.ubuntu.com/ubuntu/ xenial universe
```
To your sources
These are the old Xenial repositories

Afterwards
```sh
sudo apt-get update
sudo apt-get install g++-4.8-multilib
```

## Building ZHL files
Instal Lua, I don't know exactly which version but on Windows they use 5.1 so at least that.
I used 5.3
You'll also need luarocks to install some lua libraries

```sh
> sudo apt-get install lua5.3 liblua5.3-dev luarocks
> sudo luarocks install luafilesystem
> sudo luarocks install lpeg
```


#### Makefile stuff
```sh
> make -f Makefile.x86.unix
> make -f Makefile.x86.unix clean
```
