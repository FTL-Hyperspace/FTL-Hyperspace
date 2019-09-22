==============
 Installation
==============

= Windows =

Extract the files in the "Where FTLGame.exe is" folder into the directory that FTLGame.exe is in.
(This will usually be "C:\Program Files (x86)\Steam\steamapps\common\FTL Faster Than Light")

Install the "Hyperspace.ftl" mod with Slipstream Mod Manager, along with any other mods that utilize Hyperspace after that one.

= Linux =
(May also work for Mac, untested)

For the Linux install, you will need to have WINE installed. 
Download the Windows version of FTL by either running Steam through WINE and downloading it through there,
or by going to this link (steam://nav/console) and entering this command:
"download_depot 212680 212681 7584602879744021840"
It should tell you where it's downloaded once it's complete.

Install the "Hyperspace.ftl" mod with Slipstream Mod Manager, along with any other mods that utilize Hyperspace after that one.

Extract the files in the "Where FTLGame.exe is" into the FTL/depot's directory.
Then, open a terminal emulator and run the command "winecfg"
Open the "Libraries" tab, and write "xinput1_4" in the "New override for library:" textbox. Click on "Add" and you should see "xinput1_4 (native, builtin)" inside "Existing overrides:". Select it, click on "Edit...", select "Native (Windows)".
Do the same for the Hyperspace dll.

Now running FTLGame.exe should open Hyperspace.

NOTE: There may be a bug with fullscreen on Linux. To avoid this, play in windowed mode.

= Uninstalling =

To uninstall, simply delete the "Hyperspace.dll" file from your FTL directory, where you installed the mod.
Just removing the mod from Slipstream will NOT remove the entire mod.

===================
 Changes/Additions
===================

- Added new augment, NANOBOT_DEFENSE_SYSTEM (disabled by default)
- Explosive Replicator's <value> tag now works as intended
- Added ih8ih8sn0w's infinite mode (enabled in hyperspace.xml)
- Fixed hacking drone bypass bug - the drone now explodes when hacking is depowered (enabled by default -- can change in hyperspace.xml)
- Can now enable command console through hyperspace.xml
  > Added STORE command
- Can now enable Hull Numbers through hyperspace.xml
- Ghosts can now phase through doors

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

- Allowed events to check cargo for the "req" attribute
  > Add your event into <events> in hyperspace.xml and add a <checkCargo/> tag

=========
 Credits
=========

Development:
	TheSwiftTiger#7324 - Discord    (TheSwiftTiger - forum name)
	Winderps#0001                   (Winderps)
	ih8ih8sn0w💙#9183               (ih8ih8sn0w)

Art:
	SaltyFriedRice#0605

= Special Thanks =

_Kilburn#5703
slow#7018                           (slowriderxcorps)
Masala#0621
bamalf#8127                         (bamalf)
Puffias Leroy McBillington III#8899 (KingdomKrafters)
BlizzArchonJ#3158                   (mr_easy_money)
Paradigm#0001
