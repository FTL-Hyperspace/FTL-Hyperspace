#### Dropped functions
##### Non-op
```c++
void CApp::ParseArgs(CApp *this<ecx>, int unk, const char** args);
virtual void GenericButton::OnRightClick(GenericButton *this<ecx>);
virtual void GenericButton::ResetPrimitives(GenericButton *this<ecx>);
virtual void GenericButton::OnClick(GenericButton *this<ecx>);
```
Was dropped as it's just a no-op in the ELF binaries and cannot be hooked with the current ZHL.
(must be mocked out in our code to prevent uses of it or to non-op uses of it)

##### Unknowns
```c++
void CrewMember::Cleanup(CrewMember *this<ecx>); // Appeared to have a bad match in the Win32 version also maybe should be removed entirely?
static int DebugHelper::CrashCatcher(void* exception_pointers); // Couldn't find any equivalent in the Linux binaries
```

```c++
void TopScore::copy_constructor(TopScore *this<ecx>, const TopScore& other);
```
Does not exist in the linux binaries (might of simply been removed between 1.6.9 and 1.6.12)

##### Dummy/Mocks
```c++
static cleanup int FileHelper::fileLength(int file);
```
On Linux this is just mocked to always return 1 and is too short to match with ZHL, needs to be mocked (or actually legit implemented) in our code if we use it.


#### Potential issues
```c++
virtual void CompleteShip::PauseLoop(CompleteShip *this<ecx>);
```
Might be problematic to hook in the Linux version.

```c++
static std::string& CrewAnimation::GetShootingSound(std::string& strRef<ecx>, CrewAnimation *anim);
```
Was impossible to match uniquely in the Linux version (it's also impossible in the Win32 version).
However, it's also in reverse order in the Win32 binary so CrewAnimation::GetShootingSound can be matched directly there but Linux will match MantisAnimation::GetShootingSound first instead.
Instead I attempted a similar trick with CompleteShip::PauseLoop by just matching it 3 times (and defining do not hooks to the other ones)

```c++
void CrewAnimation::destructor(CrewAnimation *this<ecx>);
```
Was impossible to match uniquely (yet in Win32 it's pretty simple to match it), the ELF binary has tons of destructors that match the same signature although CrewAnimation is the first destructor with the signature in the binary so hopefully it'll hook to the right one.

```c++
static cleanup void CSurface::GL_Rotate(float angle, float x, float y, float z=1.f);
static cleanup void CSurface::GL_Rotate2(float angle, float x, float y, float z=1.f);
```
Win32 defines two different `CSurface::GL_Rotate` functions, the Linux version only has one `CSurface::GL_Rotate`, both calls have been mapped to the same address

```c++
static cleanup int FileHelper::getPosition(int file);
```
getPosition is a single instruction method on Linux (it's much more complicated in Win32) and just references a global variable FileHelper::iFilePosition however, that global variable is surrounded by tons of just plain 0's and might be incredibly difficult to target.
This function might require re-implementation or tweaking to ZHL to allow matching a single instruction function in special cases?
```x86asm
                             **************************************************************
                             * FileHelper::getPosition(int)                               *
                             **************************************************************
                             int __cdecl getPosition(int fd)
             int               EAX:4          <RETURN>
             int               Stack[0x4]:4   fd
                             _ZN10FileHelper11getPositionEi                  XREF[3]:     Entry Point(*), 0841a7f4, 
                             FileHelper::getPosition                                      0844a0e8(*)  
        08208af0 a1 50 2a        MOV        EAX,[FileHelper::iFilePosition]
                 4a 08
        08208af5 c3              RET
```
For now I attempted to just match it from the function before it which is `FileHelper::deleteAllSaveFiles`

```c++
std::vector<Door*>& ShipGraph::GetDoors(ShipGraph *this<ecx>, int unk);
```
Might need to be redefined as static and move the return reference into the arguments because of __thiscall style on GCC.

```c++
static cleanup void ShipSystem::GetLevelDescription(void* unk<esi>, std::string& retStr, int systemId, int level, bool tooltip);
```
Not sure why this has a `void* unk<esi>` at the beginning, the retStr is visible from how this function returns and is replacing the this parameter but nothing appears to be passed in on `ESI` regardless.

```c++
/* ZHL: */ void SpaceManager::SwitchBeacon(SpaceManager *this<ecx>);
/* Win: */ void __thiscall SpaceManager::SwitchBeacon(SpaceManager *this)
/* Lin: */ ImageDesc * __thiscall SpaceManager::SwitchBeacon(ImageDesc *__return_storage_ptr__,SpaceManager *this)
```

#### Reworked function pointers
`CApp::OnEvent` in Win32 is a wrapper function that just calls `CEvent:OnEvent` but it has enough in the binary to actually match.
On Linux the compiler simplified it to just a static `JMP` to the `CEvent:OnEvent` code instead of a `CALL` so instead I pointed the code at `CEvent::OnEvent` for the function named `CApp:OnEvent` in the ZHL hooks.

`CrewDrone::SetCurrentShip` is just jumped to `CrewMember::SetCurrentShip`

`CSurface::FinishFrame` is just jumped to `sys_graphics_finish_frame`
`CSurface::GL_OrthoProjection` jumped to `graphics_set_parallel_projection`

#### Oddities
```c++
void CrewMember::SetCrewTask(CrewMember *this<ecx>, CrewTask task);
void CrewMember::SetTask(CrewMember *this<ecx>, CrewTask task);
```
Are duplicates

```c++
virtual void EquipmentBox::Free(EquipmentBox *this<ecx>);
```
Appears to be EquipmentBox's destructor but doesn't match the naming of all others in the ZHL files.

#### Animation.zhl 
win32
```c++
void Animation::constructor(Animation *this<ecx>, const std::string& _image, int _length, float _time, Pointf _position, int _imageWidth, int _imageHeight, int _stripStartX, int _numFrames);
```
Pattern might differ in 1.6.13 and/or linux as the signature is:
```c++
void __thiscall Animation::Animation (Animation *this, string *image, int frames, float length, Pointf position, int image_width, int image_height, int image_start, int sub_frames)
```
It looks like length & time may have swapped but the 1.6.9.exe doesn't identify the variable names in decompilation so maybe this was just a guess at the original values and maybe Hyperspace uses _length as frames?


win32
```c++
void Animation::AddSoundQueue(Animation *this<ecx>, int unk, const std::string& sound);
```
is seen as in Linux
```c++
void __thiscall Animation::AddSoundQueue(Animation *this,int frame,string *sound)
```


win32/ZHL decl
```c++
float AsteroidGenerator::Initialize(AsteroidGenerator *this<ecx>, int numberOfShips, int shieldCount, bool unk);
```
Linux Raw Dissassembly
```c++
void __thiscall AsteroidGenerator::Initialize(AsteroidGenerator *this,int numShips,int shields,bool defense)
```

win32/ZHL decl
```c++
bool AsteroidGenerator::SaveAsteroids(AsteroidGenerator *this<ecx>, void* file);
void AsteroidGenerator::LoadAsteroids(AsteroidGenerator *this<ecx>, void* file);
```
Dissasembly revealed that in all binaries file is an integer (filedescriptor) not a void pointer although the void pointer does make sense given its use to FileHelper::readInteger


win32/ZHL decl
```c++
static std::vector<std::string>& BlueprintManager::GetBlueprintList(std::vector<std::string>& vec<ecx>, BlueprintManager *bpM, const std::string& str);
```
Linux Raw Dissassembly
```c++
vector<std--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
* __thiscall
BlueprintManager::GetBlueprintList
          (vector<std--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
           *__return_storage_ptr__,BlueprintManager *this,string *name)
```

win32/ZHL decl
```c++
char BossShip::Defeated(BossShip *this<ecx>);
```
Linux Raw Dissassembly
```c++
bool __thiscall BossShip::Defeated(BossShip *this)
```
Bool vs char return.

win32/ZHL decl
```c++
void Button::OnInit(Button *this<ecx>, const std::string& img, int x, int y);
```
Linux Raw Dissassembly
```c++
void __thiscall Button::OnInit(Button *this,string *imageBase,Point pos)
```
Point struct vs x/y

win32/ZHL decl
```c++
void CAchievement::OnRender(CAchievement *this<ecx>, Point pos, int selected, bool unk);
```
Linux Raw Dissassembly
```c++
void __thiscall CAchievement::OnRender(CAchievement *this,Point pos,int style,bool showNew)
```

win32/ZHL decl
```c++
void CompleteShip::constructor(CompleteShip *this<ecx>, SpaceManager *space, bool unk, int unk2);
```
Linux Raw Dissassembly
```c++
void __thiscall CompleteShip::CompleteShip(CompleteShip *this,SpaceManager *space,bool bPlayerShip,int iShipId)
```

win32/ZHL decl
```c++
void CompleteShip::AddBoarders(CompleteShip *this<ecx>, int amount, const std::string& race, bool unk2);
```
Linux Raw Dissassembly
```c++
void __thiscall CompleteShip::AddBoarders(CompleteShip *this,int amount,string *type,bool breach)
```

win32/ZHL decl
```c++
CrewMember *CompleteShip::AddCrewMember2(CompleteShip *this<ecx>, CrewMember *member, int unk);
```
Linux Raw Dissassembly
```c++
void __thiscall CompleteShip::AddCrewMember(CompleteShip *this,CrewMember *crew,int roomId)
```

win32/ZHL decl
```c++
Drone *CompleteShip::AddDrone(CompleteShip *this<ecx>, const DroneBlueprint *blueprint, int unk);
```
Linux Raw Dissassembly
```c++
Drone * __thiscall CompleteShip::AddDrone(CompleteShip *this,DroneBlueprint *blueprint,int slot)
```

win32/ZHL decl
```c++
void CompleteShip::OnRenderShip(CompleteShip *this<ecx>, bool unk1, bool unk2);
```
Linux Raw Dissassembly
```c++
void __thiscall CompleteShip::OnRenderShip(CompleteShip *this,bool showInterior,bool doorControlMode)
```

ZHL declares
```c++
static int Globals::GetNextSpaceId();
```
Linux & Win32 Raw Dissassembly
```c++
uint Globals::GetNextSpaceId(void)
```
Note that we treat GetNextSpaceId as signed but it appears to be unsigned.


win32/ZHL decl
```c++
GL_Primitive* ResourceControl::CreateImagePrimitive(ResourceControl *this<ecx>, GL_Texture *tex, int unk1, int unk2, int unk3, GL_Color color, float alpha, bool mirror);
```
Linux Raw Dissassembly
```c++
GL_Primitive * __thiscall ResourceControl::CreateImagePrimitive(ResourceControl *this,GL_Texture *image,int x,int y,int rotation,GL_Color color,float alpha,bool mirror)
```

win32/ZHL decl
```c++
```
Linux Raw Dissassembly
```c++
```

# Weird
ZHL:
```c++
void BombProjectile::constructor(LaserBlast *this<ecx>, Pointf _position, int _ownerId, int _targetId, Pointf _target);
```
Why is this a LaserBlast for this and not a BombProjectile?


# Double Matches
```c++
void Blueprint::destructor(Blueprint *this<ecx>);
```
Is matched twice in all binaries however in the Linux binaries the order of the matches is reversed! So it may be using the wrong variant of the function.
The functions are almost identical except for an additional operator.delete command.


# Syntax Differences noticed!

```c++
void CApp::OnEvent(CApp *this<ecx>, const InputEvent* inputEvent);
```
Linux and/or 1.6.12+
```c++
void __thiscall CEvent::OnEvent(CEvent *this,EventType *Event)
```
`InputEvent` appears to have changed to `EventType` not sure if the struct is compatible or not

```c++
char CombatControl::CurrentTargetIsBoss(CombatControl *this<ecx>);
char CombatControl::CanTargetSelf(CombatControl *this<ecx>);
```
On linux decompile this is a bool (might matter for 64bit?)

```c++
void* CommandGui::GetWorldCoordinates(CommandGui *this<ecx>, Point point, bool fromTarget);
```
Returns a `Point` struct in decompilation not a void pointer


ZHL declares
```c++
void ArmamentControl::SetPosition(ArmamentControl *this<ecx>, int x, int y);
```
All decompilers (1.6.13/12 ELFx86 & 1.6.9 Windows) show a Point struct
```c++
void __thiscall ArmamentControl::SetPosition(ArmamentControl *this,Point loc)
```


ZHL declares
```c++
void BeamWeapon::constructor(BeamWeapon *this<ecx>, Pointf _position, int _ownerId, int _targetId, Pointf _target, Pointf _target2, int _length, Targetable *_targetable);
```
Linux Raw Dissassembly
```c++
void __thiscall BeamWeapon::BeamWeapon(BeamWeapon *this,Pointf position,int ownerId,int targetId,Pointf targetPosition,Pointf targetPosition2,int length,Targetable *movingTarget,float heading)

```
Win32 Raw Dissassembly
```c++
void __thiscall BeamWeapon::BeamWeapon(BeamWeapon *this,Pointf param_1,int param_2,int param_3,Pointf param_4,Pointf param_5,int param_6,Targetable *param_7,float param_8)
```
Note the extra unhandled parameter for heading!


ZHL declares
```c++
static cleanup double freetype::easy_measurePrintLines(int fontData, float x, float y, int width, const std::string& text);
static cleanup int freetype::easy_print(int fontData, float x, float y, const std::string& text);
static cleanup int freetype::easy_printRightAlign(int fontData, float x, float y, const std::string& text);
static cleanup int freetype::easy_printNewlinesCentered(int fontData, float x, float y, int width, const std::string& text);
static cleanup int freetype::easy_printAutoNewlines(int fontData, float x, float y, int width, const std::string& text);
static cleanup double freetype::easy_printCenter(int fontData, float x, float y, const std::string& text);
```
Linux Raw Dissassembly
```c++
Pointf freetype::easy_measurePrintLines(int fontSize,float x,float y,int line_length,string *text)
Pointf freetype::easy_print(int fontSize,float x,float y,string *text)
Pointf freetype::easy_printRightAlign(int fontSize,float x,float y,string *text)
Pointf freetype::easy_printNewlinesCentered(int fontSize,float x,float y,int line_length,string *text
Pointf freetype::easy_printAutoNewlines(int fontSize,float x,float y,int line_length,string *text)
Pointf freetype::easy_printCenter(int fontSize,float x,float y,string *text)
```
Pointf struct two different datatypes, what the heck, may matter for 64-bit


ZHL declares
```c++
int ScoreKeeper::GetShipIdType(ScoreKeeper *this<ecx>, const std::string& blueprintName);
```
Windows Raw Dissassembly
```c++
ulonglong ScoreKeeper::GetShipId(basic_string param_1)
```
Linux Raw Dissassembly
```c++
pair<int,int> __thiscall ScoreKeeper::GetShipId(ScoreKeeper *this,string *blueprintName)
```
^ note the pair of ints or on windows the ulonglong

ZHL declares
```c++
double ShipAI::GetTeleportCommand(ShipAI *this<ecx>);
```
Linux Raw Dissassembly
```c++
pair<int,int> __thiscall ShipAI::GetTeleportCommand(ShipAI *this)
```

ZHL declares
```c++
int ShipGraph::ConnectingDoor(ShipGraph *this<ecx>, int x1, int y1, int x2, int y2);
```
Linux Raw Dissassembly
```c++
Door * __thiscall ShipGraph::ConnectingDoor(ShipGraph *this,int x1,int y1,int x2,int y2)
```

ZHL declares
```c++
int64_t ShipGraph::ConvertToWorldPosition(ShipGraph *this<ecx>, Pointf p);
```
Linux Raw Dissassembly
```c++
Pointf __thiscall ShipGraph::ConvertToWorldPosition(ShipGraph *this,Pointf local)
```

ZHL declares
```c++
```
Linux Raw Dissassembly
```c++
```

ZHL declares
```c++
```
Linux Raw Dissassembly
```c++
```
