==============
 Installation
==============

= Linux (native 64-bit) =

- Steam use 1.6.13 (Hyperspace.1.6.13.amd64.so)
- GoG/Humble use 1.6.12 (Hyperspace.1.6.12.amd64.so)
- Others (Epic/etc...) if you only have a Windows copy you'll be forced to use Wine/Proton.


Copy the appropriate library for your FTL version from the "Linux" directory into the same directory as the FTL executable (wherever FTL.amd64 is).

Modify the FTL file to add the following before exec (change the name of the Hyperspace .so file in the command to the one you are using!)
LD_PRELOAD=./Hyperspace.1.6.13.amd64.so exec "$here/$command.$arch" "$@"

(NOTE: Installing Hyperspace.ftl is NOT necessary for FTL: Multiverse)
Install the "Hyperspace.ftl" mod with Slipstream Mod Manager, along with any other mods that utilize Hyperspace after that.

Minimum Requirements: (Multiverse: 5+ GB of RAM, Other HS mods: varies), Any GPU with OpenGL support, Vulkan not required

Note: Some people have used the following modification their FTL file instead of the suggested one above:
export LD_LIBRARY_PATH="$here":${LD_LIBRARY_PATH}
export LD_PRELOAD=Hyperspace.1.6.13.amd64.so
exec "$here/$command.$arch" "$@"

It seems setting LD_LIBRARY_PATH might be important on some machines. 

= Uninstalling =

To uninstall, simply delete the "Hyperspace.*.so" file from your FTL directory, where you installed the mod.

============
 Mod Makers
============

Most of the features that you can use from Hyperspace are documented in data/hyperspace.xml in Hyperspace.ftl.
Use a hyperspace.xml.append and add the xml tags you need for your mod.
Ideally, the user would download Hyperspace as well as your mod, and install Hyperspace.ftl first then your mod.
For maximum compatibility with other mods, don't redistribute the Hyperspace resource files and instead just direct the user to download Hyperspace in your forum post.

=========
 Credits
=========

Development:
	TheSwiftTiger
	Amyseni (Winderps)
	ih8ih8sn0w
	Admiral Billy
	laszlogasd
	mathchamp93
	Mr. Doom
	Chrono Vortex
	Pepson
	ranhai
	sillysandvich
	The Dumb Dino
Art:
	SaltyFriedRice

= Special Thanks =

_Kilburn
zerofreed
slow (slowriderxcorps)
Masala
bamalf
Puffias Leroy McBillington III (KingdomKrafters/Kix)
BlizzArchonJ (mr_easy_money)
Paradigm
FTL Multiverse Team
