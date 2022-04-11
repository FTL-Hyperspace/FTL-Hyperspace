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

### Installing GCC 4.8
Honestly go look up some info online for your specific distro, you can probably find a .deb or .rpm file of GCC 4.8.4 or 4.8.5 for your distro
https://gcc.gnu.org/wiki/InstallingGCC

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

### Compiling, requires LLVM-Clang
In the end you need GCC 4.8 for its old version of the libstdc++ library but we'll use LLVM-Clang for the actual build
Install Clang (I've only built with Clang 10, my other versions didn't work for some reason to build 32-bit executables)

If you wanted to build purely with GCC 4.8.5 there would be significant more tweaks neccessary to the code because of old compiler differences that are not libstdc++ library differences.
Clang was chosen because it'll generate something compatible, using the old libstdc++ from GCC 4.8.5 just fine but without the pains of lacking compiler features like naked functions and other features Hyperspace depends on.

`sudo apt-get install clang-10`
Afterwards you can setup a toolchain folder for clang, I called mine `/usr/gcc-4.8-clang-toolchain` and to not have to change any settings in the compile call yours the same.

```
mkdir -p /usr/gcc-4.8-clang-toolchain/usr/lib/gcc/x86_64-linux-gnu
cd /usr/gcc-4.8-clang-toolchain
ln -s /usr/include include
ln -s /usr/bin bin
cd lib/gcc/x86_64-linux-gnu
ln -s /usr/lib/gcc/x86_64-linux-gnu/4.8 4.8
```

If GCC 4.8 was the only version of GCC on the system this would not be neccessary, but if you have multiple versions of GCC it's best to create this toolchain folder so Clang can be told to use this specific toolchain rather than guessing which version of GCC's libraries to use (since we need it explicitly to use 4.8 anyways)

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
