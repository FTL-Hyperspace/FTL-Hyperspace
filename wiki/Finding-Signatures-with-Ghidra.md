# Initial Setup

1. Install Ghidra
2. Get a copy of the FTL files you wish to examine
   - **Steam**
      - **Windows Version**
         - Old windows version is no longer fetchable, you'll have to downgrade with the patch tool to get access to the 1.6.9 binary.
         - The Steam 1.6.14 Windows binary does not have debug symbols but you could attempt to make signatures for it too (that would mean no downgrading for people :smile:)
         - **From MacOS** you can fetch the windows copy using the [steam console](#opening-the-steam-console) `download_depot 212680 212681` (steam will list where the files were saved)
         - **From Linux** you can either use the steam console like MacOS above, or just enable proton and Steam will download the windows EXE. (proton setting will replace your current install, you can also use the console method above if so desired)
      - **Linux Version**
         - From Linux: Install the game, make sure proton/compatibility is not enabled, you should see `FTL.x86` and `FTL.amd64` files, this will be 1.6.13 and is the latest version on Steam and is what Hyperspace is built for on Linux.
         - **From Mac or Windows** you can fetch the linux copy using the [steam console](#opening-the-steam-console) `download_depot 212680 221002` (steam will list where the files were saved)
      - **Mac Version**
         - From Mac: Install the game
         - **From Linux or Windows**: you can fetch the mac copy using the [steam console](#opening-the-steam-console) `download_depot 212680 212682` (steam will list where the files were saved)
   - **GoG**
      - **Windows Version**
         - Download GoG Galaxy
         - Install FTL
         - Select an older version of FTL from GoG Galaxy (Todo: add pictures)
         - For Linux & MacOS you'll have to still use the Windows instructions to get the binary if you want 1.6.9, if you want the latest 1.6.13b (which does have debug symbols also but isn't valid if you're trying to add new hooks for 1.6.9, then you can just download the latest installer from GoG's website)
      - **Linux Version**
         - Download the latest Linux installer from the GoG website, it'll be a shell script for `1.6.12` that you'll need to run
         - **From Windows**: You can probably run this shell script under Windows Subsystem for Linux to get access to the binary it installs
         - **From Mac**: Unknown but you might be able to run this installer from terminal as-is to get access to the binaries.
      - **Mac Version**
         - **From Mac/Windows/Linux**: Download the Offline Installer for 1.6.13, you can open the `.pkg` file directly in Ghidra without installing it.
   - **Humble Bundle**
      - **Windows Version**
         - Not sure, you might need to contact support to get the 1.6.9 installer.
      - **Linux Version**
         - **From Linux/Mac/Windows**: Download the `1.6.12` zip directly, unzip somewhere
      - **Mac Version**
         - **From Linux/Mac/Windows**: Download the `.dmg` directly, I think Ghidra can open this directly (but untested)
   - **Epic/Microsoft/Other Sources**
      No Linux or Mac binaries provided, unknown how to get old Windows binaries other than the downgraders on the forums
3. Copy all the binaries you wish to examine to their own project folder for Ghidra, you don't need to keep them in their original locations
4. Open them in Ghidra, see special instructions for each type:
   - Windows Binaries
      - After importing the EXE but before opening it you must change the language
      - ![image](https://user-images.githubusercontent.com/1423894/172201781-e00e2107-4feb-47d3-bd45-2938811b5fcc.png)
      - For Windows we must set the language to "x86" "default" "32" "little" "gcc"
      - ![image](https://user-images.githubusercontent.com/1423894/172202026-b8fcfc70-447f-4e6d-bad3-68886d5af201.png)
   - Mac Binaries
      - Depending on which file you used (the pkg, dmg, or the direct binary from Steam) your Ghidra might look a little weird, if using the `pkg` file from GoG it'll be buried under a bunch of folders like so:
      - ![image](https://user-images.githubusercontent.com/1423894/172202688-b48e90c9-0ea7-40c3-8428-fbe96772b4e4.png)
      - Steam one will probably be just `FTL` and the `dmg` I don't know yet.
      - The default language setting is "x86 default 64 little gcc" it is unknown if we should try "x86 default 64 little clang" or not at this time to get better decompile results, you could try both and find out which provides more accurate results and update this wiki.
      - ![image](https://user-images.githubusercontent.com/1423894/172203030-b2c70392-6fb0-40dc-bdc9-c84b48186222.png)
   - Linux Binaries
      - There is nothing special for the Linux binaries, they should be already autodetected as gcc (32 or 64 depending on the binary you're looking at)
5. When opening the first time you'll be prompted for auto-analysis, ***STOP and read below***!
   - You must adjust the DWARF debug item count (Mac does not seem to have DWARF information or this option)
   - ***Attention Windows Binaries*** *If you do not see this option on a windows binary (on any host system) you might of not set the language correctly above*
   - On Windows & Linux binaries, adjust the `Debug item count limit` to a higher number, adding a `0` is sufficient or changing the first number to a `3` as it only needs a number slightly higher than the default anyways
   - ![image](https://user-images.githubusercontent.com/1423894/172203859-1c02ee57-d4a6-4c97-b185-61fba29590a3.png)
   - ***Hit APPLY first*** and then Analyze
   - Note: If you have already run the analysis you can get to this window again from the `Analysis` tab
   - ![image](https://user-images.githubusercontent.com/1423894/172204501-3aaec6c0-1e3a-42bd-901e-0d71ccea0bb6.png)
   - Note: Binaries without any debugging information (such as Windows Steam 1.6.14) will not have any DWARF information let alone other debugging information, but a lack of DWARF does not imply a lack of other debugging information like with the Mac binaries.
   - DWARF provides original struct information & function argument names, it will be very helpful in reverse engineering & even finding signatures when comparing functions but it is not 100% required.
6. Let the analysis happen, repeat for any other binaries you wish to also analyze, depending on your hardware this might take a significant amount of time.
7. After the analysis has run, save the opened file in Ghidra, unless you like the pain of running the analyzer every time.

### Opening the Steam Console
#### Windows
`Win`+`R`
Type `steam://open/console`
#### Linux
From the terminal run:
If steam isn't running
```sh
steam -console
```
If steam is already running
```sh
steam steam://open/console
```
#### MacOS
Close steam
From the terminal run:
```sh
/Applications/Steam.app/Contents/MacOS/steam_osx -console
```

# ZHL Files
We define the hooks for our code in various ZHL files,
A more detailed explanation of ZHL's capabilities are explained in `Global.zhl` but this will be a short example in order to facilitate finding your first signature in Ghidra.

### File structure
A ZHL file is laid out as a series of byte code signatures & a function name to tie them to, repeated one after another.
We organize the ZHL files by approximate class names in FTL but there is no requirement to do so, in fact they are loaded as one big blob of all the files connected in the end. (Originally the load order was random but it has been tweaked to always load in sorted order by filename)

### Example definition
A simple of 3 hooks of the `AchievementTracker` class definition looks like so:
```c++
"4157be????????41564989fe4155415455534881ece8020100":
cleanup __amd64 void AchievementTracker::LoadAchievementDescriptions(AchievementTracker *this);
"4157b90200000041564989d631d241554989fd":
cleanup __amd64 std::vector<CAchievement*> AchievementTracker::GetShipAchievements(AchievementTracker *this, const std::string& ship);
".41574863c64189f7":
cleanup __amd64 void AchievementTracker::CheckShipAchievements(AchievementTracker *this, int shipId, bool hidePopups);
```
There are differences in the function name line between Windows/Linux32/Linux64/Mac but these are due to more advanced settings not touched on here that inform ZHL how this function needs to be called & returned.

### Signatures
For now we'll only touch on the signature lines:
```
"4157be????????41564989fe4155415455534881ece8020100":
```
Every 2 characters in this line is a byte, it can be thought of like so:
```
41 57 be ?? ?? ?? ?? 41 56 49 89 fe 41 55 41 54 55 53 48 81 ec e8 02 01 00
```
The `??` mean "any value" as question marks are a wildcard. Typically you'll see single byte `??` or 4-byte `????????` sections of them.
We must enter a wildcard anytime there is a value (such as a memory address) that changes between binaries.
For example, even though Steam 1.6.9 and GoG 1.6.9 are the exact same version, because they are separate binaries that were separate compiles all memory addresses in them are different, so a function might be at a different address between them.

The sample above is from Linux 1.6.12/1.6.13 AMD64 versions.
We'll get to more information about how this ties to a signature in a different section and how to get to this exact function in Ghidra later, but here's a screenshot of the starting bytes of this function:

![image](https://user-images.githubusercontent.com/1423894/172208475-2351a68b-c71d-4661-94b3-31948bea80e9.png)

We can see:
- `41 57` is `PUSH R15`
- `be ?? ?? ?? ??` matches this `MOV ESI` with some weird blue address, this is actually a global variable it's pulling from, in 1.6.13.amd64 (the steam version of the Linux binary) this global variable is at address `0x0076b9c3` in the binary (the number is backwards in the actual bytes because the x86_64 CPU architecture is "little endian" style). On the GoG version of the game this is at a slightly different address, so we must wildcard it as it's not valid to include in our match or we wouldn't successfully match both versions of the game.
- The rest of the bytes match the rest of the start of the function, *more info will be given later on as to exactly why we chose to go this far with the signature, but basically this far ensured a unique match*

# Looking at functions in Ghidra

After performing the analysis in Ghidra you'll be left at a window similar to this:

![image](https://user-images.githubusercontent.com/1423894/172209994-afd79571-1595-4e27-a065-001e0673f981.png)

### Finding functions/methods

If it's successfully analyzed & done you'll see a `Classes` section on the left in the Symbol Tree where you can expand to find the original classes & function names

![image](https://user-images.githubusercontent.com/1423894/172210133-94a3fea1-1b27-42ba-889e-2536fabf6e2b.png)

**Note**: If you are analyzing a binary like Steam's 1.6.14 that *does not* have debugging symbols you will not get any of this benefit of finding functions by their original name and instead will only have the clobbered compiled names, so matching them to our existing signatures will be much more difficult.

If we expand `AchievementTracker` and go down to `LoadAchievementDescriptions` and click on it, the listing window will jump directly to that function's assembly code in the file:

![image](https://user-images.githubusercontent.com/1423894/172210566-878259d9-eae4-430d-b92d-fad84390cd51.png)

### Finding instruction signatures

1. We select a section of code starting from the start of the function until a few lines further, the exact length we need to select will vary for each function (and some functions a unique match is not possible and there are additional tricks we can use to still match them uniquely)

![image](https://user-images.githubusercontent.com/1423894/172211117-95716d7c-00bb-4762-bea1-d9e6f50e1f8f.png)

2. After selecting the code we go to `Search` -> `For Instruction Patterns` in Ghidra's menu

![image](https://user-images.githubusercontent.com/1423894/172211209-f010a634-d9c5-4e3e-b286-2028155c2788.png)

3. From here we need to wildcard out memory addresses in this example (From FTL Linux 1.6.12's x86 binary) this is the code that was blue in Ghidra and represented the global variable for `s_data/achievements.xml`, it's visible here that there's a 4-byte (32-bit) memory address in use that is `0x083d89b3`, we can simply click on it in the instruction pattern search in order to have it ignored as a wildcard in the search. *You can also use the `A` button but it frequently selects more than just addresses and can lead to more wildcards than needed and can make it harder to find a unique match, it's a good double check though to see if you missed an obvious address*

![image](https://user-images.githubusercontent.com/1423894/172211686-08880eaa-5747-40a3-9bbd-42090916fd2c.png)

4. Now we click `Search All` at the bottom, if we find only one match like below, then we've got a good unique signature.
If there are multiple matches we might need to select more instructions and search again. If we can't make a unique match even with a tremendous amount of the function selected we might need a different approach which will be discussed later.

![image](https://user-images.githubusercontent.com/1423894/172211996-bd5f01f4-7f8f-4533-86f1-61069759f498.png)

5. At this point it's ideal if we can check other binaries, such as comparing that this signature matches in both GoG 1.6.9 Windows and Steam 1.6.9 Windows or on Linux to check 1.6.12 from GoG/Humble and 1.6.13 from Steam... if you don't have multiple copies of the game though you'll just have to try your best to find what should be a good unique signature that doesn't depend on any addresses of jumps/calls/mov's or anything else that uses a relative or absolute address.

6. Now we can go back to the Listing window, right click somewhere in the selected code and select `Copy Special`

![image](https://user-images.githubusercontent.com/1423894/172212614-41197122-5f1c-4cc3-921d-bece6d4a57fc.png)

7. We can select `Byte String (No Spaces)`

![image](https://user-images.githubusercontent.com/1423894/172212714-062a2d3f-0e4b-4170-81c2-64f29b2c454e.png)

8. And now the entire matched string (***including bytes we need to still wildcard***) will be copied to the clipboard, like so:
```
5589e557565381ecfc0101008b4508c7442404b3893d0889853cfefeff
```

9. From here we need to change the section(s) we determined needed a wildcard
```
5589e557565381ecfc0101008b4508c7442404????????89853cfefeff
```

10. And now we have the signature we need for the ZHL file, we can start that off like so:
```c++
"5589e557565381ecfc0101008b4508c7442404????????89853cfefeff":
```

11. And now we just need to define the function name
```c++
"5589e557565381ecfc0101008b4508c7442404????????89853cfefeff":
cleanup __cdecl void AchievementTracker::LoadAchievementDescriptions(AchievementTracker *this);
```
- There's a couple special things here, we look at the function definition for its arguments but now we have to deal with some OS & compiler specific quirks
![image](https://user-images.githubusercontent.com/1423894/172213421-5e2435ff-fe65-4bcd-b135-3709eb2df9fb.png)
- Because this is Linux 32-bit there's a few possible calling styles but all `__thiscall` and `__cdecl` are simply `cdecl` style under Linux x86 32-bit. We do have to look to make sure the first arguments were not on a register (if they were it might be regparm style) but *most* of the Linux x86 32-bit calls are just cdecl. More info on the calling styles are available in `Global.zhl` and will be probably mentioned in a different Wiki article because it's more involved.
- `cleanup` is required because it's required on all Linux & Mac calls, 32-bit and 64-bit, it's really only not defined on some Windows calls where there is some cases where the caller must do cleanup.


# TODO

TODO/WIP: Info about how to choose arguments & calling styles, talk about Windows binaries gotcha with ECX argument not being detected by default by Ghidra.

TODO/WIP: Info about special ZHL matching capabilities like `.` `!` & generation capabilities like `noHook`, global variables and other features.
