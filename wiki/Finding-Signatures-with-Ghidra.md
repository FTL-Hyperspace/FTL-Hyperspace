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
      - [[/img/sig-tutorial/language-change.png]]
      - For Windows we must set the language to "x86" "default" "32" "little" "gcc"
      - [[/img/sig-tutorial/language-set.png]]
   - Mac Binaries
      - Depending on which file you used (the pkg, dmg, or the direct binary from Steam) your Ghidra might look a little weird, if using the `pkg` file from GoG it'll be buried under a bunch of folders like so:
      - [[/img/sig-tutorial/buried-FTL.png]]
      - Steam one will probably be just `FTL` and the `dmg` I don't know yet.
      - The default language setting is "x86 default 64 little gcc" it is unknown if we should try "x86 default 64 little clang" or not at this time to get better decompile results, you could try both and find out which provides more accurate results and update this wiki.
      - [[/img/sig-tutorial/language-mac.png]]
   - Linux Binaries
      - There is nothing special for the Linux binaries, they should be already autodetected as gcc (32 or 64 depending on the binary you're looking at)
5. When opening the first time you'll be prompted for auto-analysis, ***STOP and read below***!
   - You must adjust the DWARF debug item count (Mac does not seem to have DWARF information or this option)
   - ***Attention Windows Binaries*** *If you do not see this option on a windows binary (on any host system) you might of not set the language correctly above*
   - On Windows & Linux binaries, adjust the `Debug item count limit` to a higher number, adding a `0` is sufficient or changing the first number to a `3` as it only needs a number slightly higher than the default anyways
   - [[/img/sig-tutorial/debug-item-count.png]]
   - ***Hit APPLY first*** and then Analyze
   - Note: If you have already run the analysis you can get to this window again from the `Analysis` tab
   - [[/img/sig-tutorial/run-analysis.png]]
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

[[/img/sig-tutorial/start-bytes-ex.png]]

We can see:
- `41 57` is `PUSH R15`
- `be ?? ?? ?? ??` matches this `MOV ESI` with some weird blue address, this is actually a global variable it's pulling from, in 1.6.13.amd64 (the steam version of the Linux binary) this global variable is at address `0x0076b9c3` in the binary (the number is backwards in the actual bytes because the x86_64 CPU architecture is "little endian" style). On the GoG version of the game this is at a slightly different address, so we must wildcard it as it's not valid to include in our match or we wouldn't successfully match both versions of the game.
- The rest of the bytes match the rest of the start of the function, *more info will be given later on as to exactly why we chose to go this far with the signature, but basically this far ensured a unique match*

# Looking at functions in Ghidra

After performing the analysis in Ghidra you'll be left at a window similar to this:

[[/img/sig-tutorial/post-analysis-window.png]]

### Finding functions/methods

If it's successfully analyzed & done you'll see a `Classes` section on the left in the Symbol Tree where you can expand to find the original classes & function names

[[/img/sig-tutorial/find-func-and-method.png]]

**Note**: If you are analyzing a binary like Steam's 1.6.14 that *does not* have debugging symbols you will not get any of this benefit of finding functions by their original name and instead will only have the clobbered compiled names, so matching them to our existing signatures will be much more difficult.

If we expand `AchievementTracker` and go down to `LoadAchievementDescriptions` and click on it, the listing window will jump directly to that function's assembly code in the file:

[[/img/sig-tutorial/find-ach-ex.png]]

### Finding instruction signatures

1. We select a section of code starting from the start of the function until a few lines further, the exact length we need to select will vary for each function (and some functions a unique match is not possible and there are additional tricks we can use to still match them uniquely)

[[/img/sig-tutorial/sig-select.png]]

2. After selecting the code we go to `Search` -> `For Instruction Patterns` in Ghidra's menu

[[/img/sig-tutorial/search-pattern.png]]

3. From here we need to wildcard out memory addresses in this example (From FTL Linux 1.6.12's x86 binary) this is the code that was blue in Ghidra and represented the global variable for `s_data/achievements.xml`, it's visible here that there's a 4-byte (32-bit) memory address in use that is `0x083d89b3`, we can simply click on it in the instruction pattern search in order to have it ignored as a wildcard in the search. *You can also use the `A` button but it frequently selects more than just addresses and can lead to more wildcards than needed and can make it harder to find a unique match, it's a good double check though to see if you missed an obvious address*

[[/img/sig-tutorial/wildcard-memory.png]]

4. Now we click `Search All` at the bottom, if we find only one match like below, then we've got a good unique signature.
If there are multiple matches we might need to select more instructions and search again. If we can't make a unique match even with a tremendous amount of the function selected we might need a different approach which will be discussed later.

[[/img/sig-tutorial/search-all.png]]

5. At this point it's ideal if we can check other binaries, such as comparing that this signature matches in both GoG 1.6.9 Windows and Steam 1.6.9 Windows or on Linux to check 1.6.12 from GoG/Humble and 1.6.13 from Steam... if you don't have multiple copies of the game though you'll just have to try your best to find what should be a good unique signature that doesn't depend on any addresses of jumps/calls/mov's or anything else that uses a relative or absolute address.

6. Now we can go back to the Listing window, right click somewhere in the selected code and select `Copy Special`

[[/img/sig-tutorial/copy-special.png]]

7. We can select `Byte String (No Spaces)`

[[/img/sig-tutorial/byte-string-no-space.png]]

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
[[/img/sig-tutorial/look-func-def.png]]
- Because this is Linux 32-bit there's a few possible calling styles but all `__thiscall` and `__cdecl` are simply `cdecl` style under Linux x86 32-bit. We do have to look to make sure the first arguments were not on a register (if they were it might be regparm style) but *most* of the Linux x86 32-bit calls are just cdecl. More info on the calling styles are available in `Global.zhl` and will be probably mentioned in a different Wiki article because it's more involved.
- `cleanup` is required because it's required on all Linux & Mac calls, 32-bit and 64-bit, it's really only not defined on some Windows calls where there is some cases where the caller must do cleanup.

# Advanced ZHL methods & usage:

## Byte String additions

### What is `.` & when is it used - Hooking functions without a unique match
Sometimes you'll come across very short functions that don't offer many bytes. After that, you'll wildcard the memory addresses and realize it results in hundreds of matches. This happens more frequently on the Windows build, but there are cases of that on every platform. Here's an example of a non-unique function from the Windows build.

[[/img/sig-tutorial/Non-unique-function-example.png]]

As I mentioned, searching for `Instruction Patterns` won't give you a unique result.

[[/img/sig-tutorial/No-Unique-Match.png]]

So, how do we get hook these then? The answer can vary, actually. Either way, you'll need to understand how the `.` operator and how our hooking library (ZHL) works.
To keep it simple, ZHL scans through the FTL executeable when it's launched and compares the bytestrings we provided until it finds a match. This process starts from top to bottom and does that for each function, kind of like searching for a word in a text file. If you have multiple matches and your function is the first one to pop up in the "Instruction Patterns" search window, you can hook it like any other function without having to worry or using the `.` operator. However, this is rarely the case, so we have two options:
1. Use a "noHook"
2. Optimizing the loading order of hooks is our preferred approach. **(Prefered)**

Both of these options require us to find a function above to use as an anchor. You can either scroll up in the main window showing the ASM code or click through the function in a class and compare their memory address values. The one with a lower value is placed higher than the one with a greater value. 
This example function is above the one we're targeting:

[[/img/sig-tutorial/noHook-function-example.png]]


### The two options:

#### 1. Utilizing a `noHook`

NoHooks can be viewed as anchors. The first step is to identify a function that is above the one you are attempting to hook. In the provided example, the function is `Equipment::Open`. The process of creating a `noHook` is identical to that of adding a normal hook with regard to the bytestring.
Example:
```c++
"5589e583e4??e8????????c9c3":
noHook void Equipment::DO_NOT_HOOK_1();
```
The only difference is the addition of the `noHook` designation at the beginning.
As you can see, the only difference is the "noHook" parameter at the start of the line.

**Note:** NoHooks can be hooked as any function type. Therefore, simply use void. Additionally, parameters and passed variables do not need to be included in the brackets, as noHooks should NEVER be run.

Once the `noHook` has been added, the normal function hook should be placed immediately afterwards, with a `.` at the beginning of the bytestring. The final result should be as follows:
```c++
"5589e583e4??e8????????c9c3":
noHook void Equipment::DO_NOT_HOOK_1();
".5589e5565389ce83e4??e8":
__thiscall void Equipment::Close(Equipment *this);
```
This will prompt the library to initially search for "Do_NOT_HOOK_1," and then the `.` instructs to continue searching from that point until it encounters "Close."

#### 2. Optimized loading pattern.

As an alternative to using a noHook as an anchor, you may opt to hook the function from above normally or verify if it is already present in the current ZHL file, which will then serve as an anchor. The rules remain consistent across both scenarios, and the final result should look something like this example:
```c++
"5589e583e4??e8????????c9c3":
__thiscall void Equipment::Open(Equipment *this);
".5589e5565389ce83e4??e8":
__thiscall void Equipment::Close(Equipment *this);
```
It is also possible to do this with multiple signatures chained together, which is preferred as it significantly improves loading times.
Please refer to the following Linux ZHL example:
```c++
"4883ec188b97540200008bb7500200004889e7e8????????8b442404":
cleanup __amd64 Point Door::GetPosition(Door *this);
".5380bfec01000000":
cleanup __amd64 bool Door::ApplyDamage(Door *this, float amount);
".!554889fd5389f34883ec088b":
cleanup __amd64 void Door::SaveState(Door *this, int fd);
".!5589f5534889fb89f74883ec08e8????????89ef":
cleanup __amd64 void Door::LoadState(Door *this, int fd);
".55534889fb4883ec0883bfb400000004c6472c01":
cleanup __amd64 void Door::FakeOpen(Door *this);
".55534889fb4883ec080fb64724c6472c00":
cleanup __amd64 void Door::FakeClose(Door *this);
```

#### Short Recap
The `.` is typically used when you want to improve the loading order & speed of the ZHL. This logic also applies to any other stuff you try to hook like an `offsetVariable`.
It also makes loading more robust and less likely to hook stuff you don't want, even if the given bytestring was too short by accident.

<br/> 

### What is `!` & when is it used - Function can't be hooked for no obvious reason
Sometimes, you'll encounter functions that inexplicably fail to get hooked. When checking the zhl log, you see the hooking process fail at a certain function. Verifying the bytestring doesn't yield any further explanation. What could cause this? In most cases, you've come across one of the rare functions that don't end in a `RET` instruction. Here's an example from the Linux 1.6.13 FTL executable:

[[/img/sig-tutorial/Non-RET-function-example.png]]

If a return statement of a function ends in anything other than `RET`, e.g. `JMP` or `CALL`, zhl "derails" and fails to hook the function. Add a `!` in front of your bytestring to fix this, it ensures that ZHL stops running through the code once it has found a match. The hook for this function should look like this:
```c++
"!554889fd5389f34883ec08e8":
cleanup __amd64 void LaserBlast::SaveProjectile(LaserBlast *this, int fd);
```
You can also use both `.` and `!` together in any order without an issue.
```c++
"534889fb4883ec1080bfc400000000745f":
cleanup __amd64 void LaserBlast::OnUpdate(LaserBlast *this);
"!.554889fd5389f34883ec08e8":
cleanup __amd64 void LaserBlast::SaveProjectile(LaserBlast *this, int fd);
".5589f5534889fb4883ec08e8":
cleanup __amd64 void LaserBlast::LoadProjectile(LaserBlast *this, int fd);
".538b477c4889fb394778c7474001000000":
cleanup __amd64 void LaserBlast::OnInit(LaserBlast *this);
```

#### Short Recap
The `!` is typically used when you want to prevent ZHL from searching beyond a given bytestring. This should also be used for `offsetVariables`, `vtables`, and any other elements you're trying to hook. Sometimes a function also doesn't operate as expected or executes random code in memory, which can be fixed by its usage.

<br/>

# TODO

TODO/WIP: Info about how to choose arguments & calling styles, talk about Windows binaries gotcha with ECX argument not being detected by default by Ghidra.

TODO/WIP: Info about generation capabilities similar to the `noHook`, global variables and other features.
