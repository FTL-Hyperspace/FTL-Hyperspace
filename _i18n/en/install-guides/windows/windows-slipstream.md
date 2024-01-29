### Installing Slipstream

1. **Make certain** you have a vanilla FTL install before doing a new install of slipstream or upgrading slipstream
   - If you check the size of `ftl.dat` in your FTL install folder it should be around 270MB (or 212MB for GoG) or so, if it's significantly larger you still have mods installed and you need to revert to vanilla first!
   - Slipstream 1.9.1 is not smart about checking if the file is vanilla, it will use whatever `ftl.dat` exists when you first open it (so if you have mods installed & you run a new slipstream install it will consider that one "vanilla" even if it's not!)
   - *Save yourself many heacahes & problems by making sure you have a clean vanilla ftl.dat first*
2. [Download slipstream 1.9.1](https://subsetgames.com/forum/viewtopic.php?f=12&t=17102)
3. Extract it to a folder where you'll keep it around, ***do not run it from inside the zip***
4. You must have Java installed on your machine (probably fine for most people)

### Patching with Slipstream

1. Download the hyperspace-based mods you are interested in
2. Launch slipstream
3. Click `Open mods/`
   - ![image](https://user-images.githubusercontent.com/1423894/173680447-24bdb0df-0a50-44a9-ad79-1f9a6a38f61d.png)
4. Move the mods `.ftl` or `.zip` files from wherever you downloaded them into this mods folder
5. Rescan mods
   - Go to `file` `Re-Scan mods/`
   - ![image](https://user-images.githubusercontent.com/1423894/173680307-c9d1da5f-9a7e-43af-a933-d53431da27ad.png)


#### Most Hyperspace Mods
1. Move `Hyperspace` to the top of the list in slipstream
2. Patch Hyperspace and any other hyperspace mods after it you want
   - ![image](https://user-images.githubusercontent.com/1423894/173682067-297f466c-bfad-4493-904c-0c27c836657b.png)
   - ***DO NOT Patch Multiverse*** See Below for Multiverse instructions.
3. Click `Patch`
4. Launch FTL
5. See: [Checking if Hyperspace is installed correctly](#installed-correctly)

#### Multiverse Only
1. Enable Slipstream's ability to recognize ZIP files as mods
   - Go to slipstream's preferences
   - ![image](https://user-images.githubusercontent.com/1423894/173679563-2f5dbe3d-dabf-4278-b8c0-f26351426021.png)
   - Check `allow_zip`
   - ![image](https://user-images.githubusercontent.com/1423894/173679698-b2f5d369-182e-41a1-939c-39c40b6a0bd5.png)
2. Rescan mods
   - Go to `file` `Re-Scan mods/`
   - ![image](https://user-images.githubusercontent.com/1423894/173680307-c9d1da5f-9a7e-43af-a933-d53431da27ad.png)
3. Patch multiverse
   - Patch `FTL-Multiverse` **as the first in the list**
   - **Do not select Hyperspace**
   - Patch any FTL Multiverse compatible mods after multiverse
   - **Do not** patch mods that are not designed for FTL Multiverse or they may conflict (even small UI mods can sometime conflict, seek help on the MV Discord if you have questions about a specific favorite mod of yours compatibility)
   - Example: ![image](https://user-images.githubusercontent.com/1423894/173681032-76e9b056-ede6-42f5-ad5a-ffa0fece384a.png)
   - Click `Patch`
4. See: [Checking if Hyperspace is installed correctly](#installed-correctly)

### Installed Correctly

- If hyperspace's DLL is installed correctly, you'll see a little message in the top right of FTL about half-way through the loading screen and on into the menu screen that looks similar to this (it'll look a little different for each version):
   - ![image](https://user-images.githubusercontent.com/1423894/173682629-6aa843d8-bb36-4a3b-afad-bd6b23463a8a.png)

- After that if you get a version AND you patched with Slipstream correctly 

- You should get to your mods main menu with no errors or warnings, Multiverse 5.2.3 installed correctly looks like this:
   - ![image](https://user-images.githubusercontent.com/1423894/173683306-2b92a3e2-d0d2-4bff-ac19-33ff6ef0a749.png)

- FTL Strawberry Edition looks like this:
   - ![image](https://user-images.githubusercontent.com/1423894/173683567-598bc5fe-a7f8-4bad-8dd1-2b6ff161d695.png)

- FTL Hyperspace with no other mods looks like this:
   - ![image](https://user-images.githubusercontent.com/1423894/173684224-64a24d41-e5ae-4c52-b45f-82fafb42abea.png)



### Installed Incorrectly

- If you see your mod's main menu but there is no version information in the upper right, Hyperspace's DLL might not of been installed correctly.

- If you get an error message about `AcheivementTracker` you did not downgrade FTL to 1.6.9 successfully.

- If you see an error message about `hyperspace.xml` not found you may have failed to patch `Hyperspace.ftl` or `Multiverse` with slipstream

- If you see an error message about patching both multiverse & hyperspace you either patched both in Slipstream and need to correct this, or you didn't  have a clean FTL.dat before installing slipstream and slipstream thought that your FTL.dat was vanilla and you need to clear slipstream's cache & revert to a vanilla FTL.dat.
