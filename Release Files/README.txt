This mod DOES NOT WORK with the latest version of FTL. You will need to downgrade your FTL to 1.6.9 to be able to use it. The instructions to do that are below.

==============
 Installation
==============

= Windows =

Extract the files in the "Windows - Extract these files into where FTLGame.exe is" in your FTL directory.
This is usually in C:\Program Files (x86)\Steam\steamapps\common\FTL Faster Than Light.

Steam: Run the downgrade.bat included with the Hyperspace download.
Other versions: Download the appropriate downgrader for your build from the forum post, copy it to your FTL directory and run it.

(NOTE: Installing Hyperspace.ftl is NOT necessary for FTL: Multiverse)
Install the "Hyperspace.ftl" mod with Slipstream Mod Manager, along with any other mods that utilize Hyperspace after that.

= Linux (native 64-bit) =

- Steam use 1.6.13 (Hyperspace.1.6.13.amd64.so)
- GoG/Humble use 1.6.12 (Hyperspace.1.6.12.amd64.so)
- Others (Epic/etc...) if you only have a Windows copy you'll be forced to use Wine/Proton.

You do NOT need to downgrade FTL to use the native linux versions.

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

To uninstall, simply delete the "Hyperspace.dll" or "Hyperspace.*.so" file from your FTL directory, where you installed the mod.
Windows: To revert back to 1.6.14, in your FTL directory, delete FTLGame.exe and rename FTLGame_orig.exe to FTLGame.exe.
Just removing the mod from Slipstream will NOT remove the entire mod.

===================
 Changes/Additions
===================

See changelogs/hyperspace.xml for more additions.

- Seeded runs!
  > You can now input a seed before starting a run which will disable unlocks and generate the map based on the seed
  > This means that you can redo a run or play the same run as someone else (to race them, for example!)
  > You can check your seed in the game pause menu
  > Seeds are only the same if the mods used, FTL versions, and Advanced Edition toggles are the same
 
- Added creation of custom races
  > Their abilities can be changed inside the hyperspace.xml
  > Existing crewmembers can also have their abilities changed, but you will need to rewrite the old abilities as well
  > Create a blueprint for them and put their definition in the <crew> tag in hyperspace.xml
 
- Added infinite ship list
  > The number of pages increases the more ships you have to fill them
  > Ships can be added by having a custom blueprint for them, and adding their id to the <ships> in hyperspace.xml
  > NOTE: High scores for custom ships are never saved, and they have no achievements

- Added custom augments (sort of)
  > Different augments can now be combined to make a new augment
  > Create a blueprint for the augment, then add their definition to the <augments> in hyperspace.xml
  > This can also be used to make new versions of old augments, so that the player and enemy can have seperate values for one augment, for example
  > Added hidden augments
      • Customizable per ship
      • These cannot be removed or added, and do not take up a slot
  > Added locked augments
      • These cannot be sold/swapped for different augments once equipped

- Added creation of custom drones, with unique stats

- Added Discord Rich Presence integration

- Can now change crew limits

- Added new augment, NANOBOT_DEFENSE_SYSTEM (disabled by default)
- Added FTL_JUMPER_GOOD augment which allows you to jump to any beacon in the sector (disabled by default)
- Explosive Replicator's <value> tag now works as intended

- Added ih8ih8sn0w's infinite mode (enabled in hyperspace.xml)

- Fixed hacking drone bypass bug - the drone now explodes when hacking is depowered (enabled by default -- can change in hyperspace.xml)

- Can now enable command console through hyperspace.xml
  > Added STORE command
  > Added KILL command to console which allows you to kill a crew member or boarder on your ship
- Can now enable Hull Numbers through hyperspace.xml
- Ghosts can now phase through doors
- Low O2 warning no longer appears when the ship has no oxygen system
- Added customisation of boss crew
  > Can customise the race and room that the crew member spawns in
- Can now customize the drones that the boss uses for its phase 2 drone surge
  > Customizable for each difficulty
- Different save files and continue files for vanilla and Hyperspace FTL versions
- Can customise the drone(s) that buying a drone system gives you

- Event features
  > Ships can now use the boss ship box (useful for minibosses and large ships)
  > Events can now have a label on the map, like stores and exit beacons
    • These replace quest beacon labels and exit beacon labels
  > Can add custom event files for the game to load
    • The value of <eventFile> in the <event> tag will load data/events_x.xml
    • For example, <eventFile>special</eventFile> will make the game load data/events_special.xml
    • data/events_hyperspace.xml will always be loaded if it exists
  > Added sector specific exit beacons
    • Useful for something like a miniboss at the end of a sector
  > Added sector specific fleet beacons
  > Added <preventQuest> tag to stop quests from overwriting specific events
  > No longer forces rebel fleet to show in fleet events
  > Allowed events to check cargo for the "req" attribute
    • Add your event into <events> in hyperspace.xml and add a <checkCargo/> tag
    • This also works for the <remove> tag

  > Added <noQuestText> tag which means the event does not say that a quest has been added
  > Added <removeHazards> tag
  > Added <removeNebula> tag
  > Added win events

- Added <forceDlc> tag which stops you from disabling Advanced Edition

============
 Mod Makers
============

Most of the features that you can use from Hyperspace are documented in data/hyperspace.xml in Hyperspace.ftl.
Use a hyperspace.xml.append and add the xml tags you need for your mod.
Ideally, the user would download Hyperspace as well as your mod, and install Hyperspace.ftl first then your mod.
For maximum compatibility with other mods, don't redistribute the Hyperspace resource files and instead just direct the user to download Hyperspace in your forum post.

A Lua API was planned for this release, but unfortunately, due to lack of free time, that wasn't possible.
This may be added to the mod in the future, but don't expect it too soon.

=========
 Credits
=========

Development:
	TheSwiftTiger
	Winderps
	ih8ih8sn0w
	Admiral Billy
	laszlogasd
	mathchamp93
	Mr. Doom
Art:
	SaltyFriedRice

= Special Thanks =

_Kilburn
slow (slowriderxcorps)
Masala
bamalf
Puffias Leroy McBillington III (KingdomKrafters/Kix)
BlizzArchonJ (mr_easy_money)
Paradigm
FTL Multiverse Team
