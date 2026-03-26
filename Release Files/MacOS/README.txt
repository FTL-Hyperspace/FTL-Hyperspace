==============
 Installation
==============

= MacOS =

STEP 1: LOCATE YOUR FTL INSTALLATION
--------------------------------------------------------------------------------

Your FTL folder location depends on where you purchased the game:

  Steam:        ~/Library/Application Support/Steam/steamapps/common/FTL Faster Than Light/
  GOG:          /Applications/
  Other:        ~/Games/

To navigate there in Finder:
  1. Open Finder
  2. Press Cmd + Shift + G (or click Go > Go to Folder in the menu bar)
  3. Paste the appropriate path and press Enter

Steam users can also right-click FTL in their library and select
"Manage > Browse Local Files"


STEP 2: EDIT INFO.PLIST
--------------------------------------------------------------------------------

1. Right-click the FTL app
2. Select "Show Package Contents"
3. Open the "Contents" folder
4. Open "Info.plist" in any text editor

Find this section:

    <key>CFBundleExecutable</key>
    <string>FTL</string>

Change it to:

    <key>CFBundleExecutable</key>
    <string>Hyperspace.command</string>

Save the file.

NOTE: While editing, look for this line to check your FTL version:

    <key>CFBundleVersion</key>
    <string>1.6.13</string>

Remember this version number - you'll need it for the next step.


STEP 3: COPY HYPERSPACE FILES
--------------------------------------------------------------------------------

Navigate to the "MacOS" folder (located inside Contents, next to Info.plist).

Copy the following files into the MacOS folder:

  - Hyperspace.command

  - The EXACTLY ONE dylib for your version:
      Version 1.6.13  -->  Hyperspace.1.6.13.amd64.dylib
      Version 1.6.12  -->  Hyperspace.1.6.12.amd64.dylib


STEP 4: INSTALL FTLMAN (MOD MANAGER)
--------------------------------------------------------------------------------

Download FTLMan from:
https://github.com/afishhh/ftlman/releases/latest

Choose the correct version for your Mac:
  - Apple Silicon (M1/M2/M3):  ftlman-aarch64-apple-darwin.tar.gz
  - Intel Mac:                 ftlman-x86_64-apple-darwin.tar.gz

Unzip the downloaded file and run FTLMan.

If macOS blocks the app:
  - Go to System Settings > Privacy & Security
  - Scroll to the bottom and click "Open Anyway"
  - On older macOS versions: right-click the app and select "Open"


STEP 5: CONFIGURE FTLMAN
--------------------------------------------------------------------------------

1. Open FTLMan settings
2. Point it to your ftl.dat file

   The ftl.dat file is located at:
   FTL.app/Contents/Resources/ftl.dat

   Full Steam path example:
   /Users/[username]/Library/Application Support/Steam/steamapps/common/FTL Faster Than Light/FTL.app/Contents/Resources/

   To copy the full path in Finder:
     1. Navigate to the Contents/Resources folder
     2. Right-click "ftl.dat"
     3. Hold the Option key - "Copy" changes to "Copy as Pathname"
     4. Click "Copy as Pathname"
     5. Paste into FTLMan
	 6. Delete "ftl.dat" from the end of the path (FTLMan needs the Resources folder, not the file)

3. Click "Scan"


STEP 6: INSTALL MODS
--------------------------------------------------------------------------------

1. Place your mod files (Multiverse Assets, Multiverse Data, hyperspace.ftl, etc.) into the "mods"
   folder that was extracted alongside FTLMan

2. Select each mod in FTLMan

2. In FTLMan, click "Apply"

NOTE: Error "FTL executable not found" can be ignored.


STEP 7: SIGN THE APP (REQUIRED)
--------------------------------------------------------------------------------

After completing all the above steps, you MUST sign the app or macOS will
refuse to run it.

1. Open Terminal (Applications > Utilities > Terminal)
2. Paste this command (replace the path with your actual FTL.app location):

   codesign -f -s - --timestamp=none --all-architectures --deep /path/to/FTL.app

Example for Steam installation:

   codesign -f -s - --timestamp=none --all-architectures --deep /Users/[username]/Library/Application\ Support/Steam/steamapps/common/FTL\ Faster\ Than\ Light/FTL.app

TIP: Type the command up to "deep " then drag and drop FTL.app from Finder
     into the Terminal window - it will auto-fill the path for you.


DONE!
--------------------------------------------------------------------------------

Launch the game by double-clicking FTL.app directly.
Do NOT launch through Steam or other game launchers.

OPTIONAL: You can copy FTL.app to any folder you like (such as /Applications)
and rename it to something memorable like "FTL Hyperspace.app" or
"FTL Multiverse.app" - this is useful if you want to keep multiple versions.

================================================================================


= Uninstalling =

To uninstall right-click FTL.app > "Show Package Contents" and make these changes:

1. EDIT Contents/Info.plist
   Change:  <string>Hyperspace.command</string>
   Back to: <string>FTL</string>

2. DELETE from Contents/MacOS:
   - Hyperspace.command
   - Hyperspace.*.dylib

3. IN Contents/Resources:
   - Delete "ftl.dat"
   - Rename "ftl.dat.vanilla" to "ftl.dat"


Done - FTL is restored to vanilla.

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
