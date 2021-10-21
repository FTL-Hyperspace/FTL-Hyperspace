## Building

Install boost C++ library
On Ubuntu it's
`sudo apt-get install libboost-all-dev`

You need `gcc` and all the basic C dev stuff
TODO: Put some better info here :P
`sudo apt-get install build-essential gcc-multilib g++-multilib`

Not sure if we can use a lesser library.

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
