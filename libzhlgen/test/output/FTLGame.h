#pragma once

#pragma warning( disable : 4722 )

#define LIBZHL_API 
#define LIBZHL_INTERFACE __declspec(novtable)

__declspec(noreturn) inline void __cdecl __NOP() {}
#define LIBZHL_PLACEHOLDER {__NOP();}


#include "zhl.h"
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <deque>
#include <stdarg.h>




struct Point;

struct Point
{
	Point(int x, int y) { constructor(x, y); }

	LIBZHL_API static void __stdcall __BS_FUNCTION_DONT_USE();
	LIBZHL_API void constructor(int x, int y);
	
	int x;
	int y;
};

struct FocusWindow
{
	int _base;
	int _show;
	Point field_8;
	int field_10;
	Point field_14;
};

struct Upgrades
{
	Point field_0;
	int field_8;
	char **field_C;
	char **field_10;
	char **field_14;
	int field_18;
	int field_1C;
	char gap_20[4];
	int field_24;
	char field_28;
	char gap_29[3];
	char **field_2C;
	char **field_30;
	int field_34;
	char gap_38[8];
	int field_40;
	int field_44;
	Point field_48;
	int field_50;
	char **field_54;
	char field_58;
	char gap_59[3];
	char **field_5C;
	int field_60;
	int field_64;
	int field_68;
	char **field_6C;
};

struct Button;

struct Button
{
	LIBZHL_API int SetLocation(int x, int y);
	LIBZHL_API int SetLocationX(int x);
	LIBZHL_API int SetLocationY(int y);
	LIBZHL_API int SetActive(bool active);
	
	char gap_0[16];
	int field_10;
	int field_14;
	int field_18;
	int _posX;
	int _posY;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	char field_3C;
	char field_3D;
	char field_3E;
	char field_3F;
	char field_40;
	char field_41;
	char gap_42[2];
	int _anim;
	int field_48;
	char field_4C;
	char gap_4D[3];
	float field_50;
	char field_54;
	char field_55;
	char field_56;
	char gap_57[1];
	int field_58;
	int field_5C;
	char _canPress;
	char _isSelected;
	char field_62;
	char field_63;
	int field_64;
};

struct Description
{
	char *_name;
	char *_short;
	char *_desc;
	int field_C;
	int field_10;
	char gap_14[4];
	int field_18;
	char field_1C;
	char gap_1D[3];
	char **field_20;
	char **field_24;
};

struct Blueprint
{
	int _base;
	int field_4;
	Description _desc;
	int field_30;
};

struct CrewBlueprint : Blueprint
{
	char *_displayName;
	char *_fullName;
	char **_powers;
	int field_40;
	int field_44;
	int field_48;
	int vec_4C;
	char gap_50[8];
	char **field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
};

struct ShipSelect
{
	Point field_0;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	char field_20;
	char gap_21[3];
	int field_24;
	Upgrades field_28;
	int field_98;
	Button field_9C;
	Button field_104;
	Button field_16C;
	Button field_1D4;
	char field_23C;
	char gap_23D[3];
	int field_240;
	FocusWindow field_244;
	int field_260;
	int field_264;
	char **field_268;
	int field_26C;
	int field_270;
	int field_274;
	int field_278;
	int field_27C;
	int field_280;
	int field_284;
	int field_288;
	int field_28C;
	int field_290;
	char field_294;
	char gap_295[3];
	int field_298;
	char gap_29C[4];
	int field_2A0;
	int field_2A4;
	int field_2A8;
	int field_2AC;
	int field_2B0;
	char gap_2B4[1];
	char field_2B5;
	char gap_2B6[2];
	char **field_2B8;
	char **field_2BC;
	int field_2C0;
	int field_2C4;
	int field_2C8;
	CrewBlueprint field_2CC;
	int field_340;
	int field_344;
	int field_348;
	char field_34C;
	char field_34D;
	char gap_34E[2];
	int field_350;
	int field_354;
	int field_358;
	int field_35C;
	int field_360;
	float field_364;
	float field_368;
	float field_36C;
	float field_370;
	Point field_374;
	int field_37C;
};

struct MenuScreen
{
};

struct CrewMetadata
{
	int field_0;
};

struct SpaceStatus
{
};

struct GL_Primitive
{
};

struct CrewControl
{
};

struct CombatAI;

struct CombatAI
{
	LIBZHL_API unsigned int PrioritizeSystem(int unk);
	
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	char field_2C;
	char bs_1;
	char bs_2;
	char bs_3;
	int field_30;
};

struct CrewTarget
{
};

struct Room
{
};

struct ArmamentControl
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	Point field_18;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	char field_50;
	char gap_51[3];
	Point field_54;
	Point field_5C;
	int field_64;
	int field_68;
	char field_6C;
	char gap_6D[3];
	int field_70;
	char field_74;
	char gap_75[3];
	int field_78;
	int field_7C;
};

struct LocationEvent
{
};

struct ScoreKeeper;

struct ScoreKeeper
{
	LIBZHL_API int UnlockShip(int shipType, char shipVariant, bool unk1, bool unk2);
	LIBZHL_API bool GetShipUnlocked(int shipType, int shipVariant);
	
};

struct SystemNetwork
{
};

struct CooldownSystemBox
{
};

struct CrewAI
{
	int field_0;
	char field_4;
	char field_5;
	char field_6;
	char field_7;
	char field_8;
	char gap_9[3];
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	char field_60;
	char field_61;
	char gap_62[2];
	int field_64;
	char field_68;
	char field_69;
	char bs_1;
	char bs_2;
};

struct ShipAI
{
	int field_0;
	int field_4;
	CrewAI field_8;
	CombatAI field_74;
	char field_A8;
	char field_A9;
	char field_AA;
	char field_AB;
	int field_AC;
	int field_B0;
	int field_B4;
	int field_B8;
	int field_BC;
	int field_C0;
	int field_C4;
	int field_C8;
	int field_CC;
	int field_D0;
	int field_D4;
	int field_D8;
	int field_DC;
	int field_E0;
	int field_E4;
	int field_E8;
	char field_EC;
	char gap_ED[3];
	int field_F0;
	int field_F4;
	char field_F8;
	char gap_F9[3];
	int field_FC;
};

struct FileHelper
{
};

struct CrewMemberFactory;

struct CrewMemberFactory
{
	int GetCrewCount(bool enemyShip)
	{
		return enemyShip ? this->_enemyCrewCount : this->_playerCrewCount;
	}

	LIBZHL_API void *CreateCrewmember(int unk1, int unk2, bool unk3);
	LIBZHL_API static bool __stdcall IsRace(std::string *race);
	
	int _playerCrewCount;
	int _enemyCrewCount;
};

struct GL_FrameBuffer
{
};

struct WeaponSystem
{
};

struct Animation
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	float field_24;
	char field_28;
	char gap_29[3];
	float field_2C;
	char field_30;
	char field_31;
	char field_32;
	char gap_33[1];
	float field_34;
	float field_38;
	Point field_3C;
	char *field_44;
	char *field_48;
	int field_4C;
	int field_50;
	float field_54;
	int field_58;
	char field_5C;
	char gap_5D[3];
	int field_60;
	int field_64;
	int field_68;
	float field_6C;
	float field_70;
	char *field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
};

struct TeleportSystem
{
};

struct CloneSystem
{
};

struct BoardingEvent
{
};

struct CombatControl;

struct ShipObject;

struct Pointf;

struct Pointf
{
	Pointf(float x, float y) { constructor(x, y); }

	LIBZHL_API static void __stdcall __BS_FUNCTION_DONT_USE();
	LIBZHL_API void constructor(float x, float y);
	
	float x;
	float y;
};

struct HandAnimation
{
	int field_0;
	Point field_4;
	Point field_C;
	Pointf field_14;
	char field_1C;
	char bs_1;
	char bs_2;
	char bs_3;
};

struct ShipManager;

struct CachedImage
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	float field_18;
	float field_1C;
	float field_20;
	float field_24;
	float field_28;
	float field_2C;
	float field_30;
	char field_34;
	char bs_1;
	char bs_2;
	char bs_3;
};

struct CombatControl
{
	LIBZHL_API int RenderShipStatus(float unk1, float unk2);
	LIBZHL_API int RenderTarget();
	LIBZHL_API int ClearSysBoxes();
	LIBZHL_API int ClearCrewSelection();
	LIBZHL_API ShipManager *GetCurrentTarget();
	LIBZHL_API int KeyDown(int key);
	LIBZHL_API bool CanTargetSelf();
	LIBZHL_API bool MouseClick(int x, int y, bool unk);
	LIBZHL_API bool MouseMove(int x, int y);
	
	int field_0;
	int field_4;
	Point field_8;
	int field_10;
	char gap_14[940];
	int field_3C0;
	int field_3C4;
	int field_3C8;
	int field_3CC;
	int field_3D0;
	int field_3D4;
	ShipObject *_enemyShip;
	int field_3DC;
	Point field_3E0;
	int field_3E8;
	int field_3EC;
	Point field_3F0;
	Point field_3F8;
	int field_400;
	CachedImage field_404;
	CachedImage field_43C;
	CachedImage field_474;
	CachedImage field_4AC;
	CachedImage field_4E4;
	CachedImage field_51C;
	CachedImage field_554;
	CachedImage field_58C;
	CachedImage field_5C4;
	CachedImage field_5FC;
	CachedImage field_634;
	CachedImage field_66C;
	CachedImage field_6A4;
	CachedImage field_6DC;
	CachedImage field_714;
	CachedImage field_74C;
	CachedImage field_784;
	CachedImage field_7BC;
	CachedImage field_7F4;
	CachedImage field_82C;
	CachedImage field_864;
	CachedImage field_89C;
	CachedImage field_8D4;
	CachedImage field_90C;
	int field_944;
	int field_948;
	Point field_94C;
	int field_954;
	int field_958;
	int field_95C;
	Point field_960;
	char field_968;
	char field_969;
	char gap_96A[2];
	Point field_96C;
	int field_974;
	Point field_978;
	int field_980;
	int field_984;
	int field_988;
	CachedImage field_98C;
	CachedImage field_9C4;
	CachedImage field_9FC;
	CachedImage field_A34;
	int field_A6C;
	int field_A70;
	char field_A74;
	char gap_A75[3];
	float field_A78;
	char field_A7C;
	char field_A7D;
	char field_A7E;
	char gap_A7F[1];
	float field_A80;
	float field_A84;
	int field_A88;
	int field_A8C;
	int field_A90;
	int field_A94;
	int field_A98;
	char field_A9C;
	char gap_A9D[3];
	float field_AA0;
	char field_AA4;
	char field_AA5;
	char field_AA6;
	char gap_AA7[1];
	float field_AA8;
	float field_AAC;
	int field_AB0;
	int field_AB4;
	int field_AB8;
	char _fightingBoss;
	char field_ABD;
	char gap_ABE[2];
	int field_AC0;
	HandAnimation field_AC4[8];
};

struct UpgradeBox
{
};

struct CrewBlueprint;
struct BlueprintManager;

struct BlueprintManager
{
	LIBZHL_API CrewBlueprint *GetCrewBlueprint(int unk, std::string *raceName);
	
};

struct TimerHelper;

struct TimerHelper
{
	LIBZHL_API int Start(int unk);
	LIBZHL_API bool Running();
	LIBZHL_API void ResetMinMax(int min, int max);
	LIBZHL_API void SetMaxTime(float time);
	LIBZHL_API void Stop();
	LIBZHL_API void Update();
	LIBZHL_API bool Done();
	
	int _max;
	int _min;
	float field_8;
	int field_C;
	char field_10;
	char _running;
	char bs_2;
	char bs_3;
};

struct ChoiceBox : FocusWindow
{
	int field_1C;
	int field_20;
	char **field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	char field_50;
	char gap_51[3];
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	char gap_70[1];
	char field_71;
	char gap_72[2];
	char **field_74;
	char **field_78;
	int field_7C;
	int field_80;
	int field_84;
	CrewBlueprint field_88;
	int field_FC;
	int field_100;
	char field_104;
	char gap_105[3];
	char field_108;
	char field_109;
	char gap_10A[2];
	int field_10C;
	int field_110;
	int field_114;
	int field_118;
	int field_11C;
	float field_120;
	float field_124;
	float field_128;
	float field_12C;
	Pointf field_130;
};

struct OptionsScreen : ChoiceBox
{
	Point field_138;
	Point field_140;
	char gap_148[120];
	int field_1C0;
	char gap_1C4[556];
	Button field_3F0;
	Button field_458;
	int field_4C0;
	int field_4C4;
	int field_4C8;
	int field_4CC;
	int field_4D0;
	int field_4D4;
	int field_4D8;
	int field_4DC;
	int field_4E0;
	int field_4E4;
	int field_4E8;
	char field_4EC;
	char field_4ED;
	char field_4EE;
	char field_4EF;
	Button field_4F0;
	Button field_558;
	int field_5C0;
};

struct ShipBuilder;

struct TextInput
{
	char **field_0;
	char **field_4;
	int field_8;
	int field_C;
	char gap_10[4];
	char field_14;
	char field_15;
	char gap_16[2];
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	char field_2C;
	char field_2D;
	char bs_1;
	char bs_2;
};

struct ShipBuilder
{
	LIBZHL_API int CycleShipNext();
	LIBZHL_API int CycleShipPrevious();
	LIBZHL_API int SwapType(int type);
	LIBZHL_API int SwitchShip(int ship, int type);
	LIBZHL_API int CheckTypes();
	LIBZHL_API int Open();
	
	ShipManager *_playerShip;
	int _isOpen;
	int field_8;
	int field_C;
	int field_10;
	Button field_14;
	Button field_7C;
	Button field_E4;
	Button field_14C;
	Button field_1B4;
	Button field_21C;
	Button field_284;
	Button field_2EC;
	Button field_354;
	Button field_3BC;
	Button field_424;
	Button field_48C;
	Button _typeA;
	Button _typeB;
	Button _typeC;
	Point _typeAPos;
	Point _typeBPos;
	Point _typeCPos;
	Button field_644;
	Button field_6AC;
	Button field_714;
	int field_77C;
	int field_780;
	int field_784;
	int field_788;
	int field_78C;
	int field_790;
	int field_794;
	int field_798;
	int field_79C;
	char field_7A0;
	char gap_7A1[3];
	int field_7A4;
	int field_7A8;
	int field_7AC;
	int field_7B0;
	Upgrades field_7B4;
	int field_824;
	int field_828;
	int field_82C;
	int field_830;
	int field_834;
	int field_838;
	char field_83C;
	char gap_83D[3];
	char field_840[120];
	int _shipType;
	char field_8BC[16];
	char **field_8CC;
	int field_8D0;
	char field_8D4;
	char field_8D5;
	char gap_8D6[2];
	int field_8D8;
	int field_8DC;
	int field_8E0;
	int field_8E4;
	int field_8E8;
	int field_8EC;
	int field_8F0;
	int field_8F4;
	int field_8F8;
	float field_8FC;
	int field_900;
	float field_904;
	char field_908;
	char field_909;
	char field_90A;
	char gap_90B[1];
	float field_90C;
	float field_910;
	Point field_914;
	char **field_91C;
	char **field_920;
	char field_924;
	char gap_925[3];
	int field_928;
	float field_92C;
	int field_930;
	char field_934;
	char gap_935[3];
	int field_938;
	int field_93C;
	int field_940;
	float field_944;
	float field_948;
	char **field_94C;
	int field_950;
	int field_954;
	int field_958;
	int field_95C;
	Pointf field_960;
	ShipSelect field_968;
	ChoiceBox field_CE8;
	char field_E20;
	char gap_E21[3];
	int _shipVariant;
	TextInput field_E28;
	int field_E58;
	char gap_E5C[4];
	Point field_E60;
	int field_E68;
	int field_E6C;
	int field_E70;
	int field_E74;
	int field_E78;
	int field_E7C;
	int _anim;
	int field_E84;
	char field_E88;
	char gap_E89[3];
	float field_E8C;
	char field_E90;
	char field_E91;
	char gap_E92[2];
	float field_E94;
	int field_E98;
	int field_E9C;
};

struct MainMenu;

struct MainMenu
{
	LIBZHL_API bool Close();
	LIBZHL_API static bool __stdcall SaveFileExists();
	LIBZHL_API bool OnKeyDown(int key, bool unk);
	LIBZHL_API int MouseMove(int x, int y);
	LIBZHL_API int MouseUp(int x, int y);
	LIBZHL_API int MouseRClick(int x, int y);
	LIBZHL_API int OpenShipBuilder();
	LIBZHL_API int Choice();
	LIBZHL_API static ShipManager *__stdcall GetTutorialShip();
	LIBZHL_API ShipManager *GetShip();
	LIBZHL_API int MouseClick(int x, int y);
	LIBZHL_API int OnLoop();
	LIBZHL_API int OnRender();
	LIBZHL_API bool Open();
	LIBZHL_API int constructor();
	
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	char field_18;
	char gap_19[3];
	float field_1C;
	char field_20;
	char field_21;
	char field_22;
	char gap_23[1];
	float field_24;
	int field_28;
	Button field_2C;
	Button field_94;
	Button field_FC;
	Button field_164;
	Button field_1CC;
	Button field_234;
	Button field_29C;
	int field_304;
	int field_308;
	int field_30C;
	int field_310;
	ShipBuilder _shipBuilder;
	int field_11B4;
	OptionsScreen _optionsScreen;
	Button field_177C;
	Button field_17E4;
	Point field_184C;
	FocusWindow field_1854;
	int field_1870;
	int field_1874;
	char *field_1878;
	int field_187C;
	int field_1880;
	int field_1884;
	int field_1888;
	int field_188C;
	int field_1890;
	int field_1894;
	int field_1898;
	int field_189C;
	int field_18A0;
	char field_18A4;
	char gap_18A5[3];
	int field_18A8;
	int field_18AC;
	int field_18B0;
	int field_18B4;
	int field_18B8;
	int field_18BC;
	int field_18C0;
	char gap_18C4[1];
	char field_18C5;
	char gap_18C6[2];
	char *field_18C8;
	char *field_18CC;
	int field_18D0;
	int field_18D4;
	int field_18D8;
	CrewBlueprint field_18DC;
	int field_1950;
	int field_1954;
	int field_1958;
	char field_195C;
	char field_195D;
	char gap_195E[2];
	int field_1960;
	int field_1964;
	int field_1968;
	int field_196C;
	int field_1970;
	float field_1974;
	float field_1978;
	float field_197C;
	float field_1980;
	Pointf field_1984;
	char field_198C;
	char gap_198D[3];
	int field_1990;
	int field_1994;
	int field_1998;
	int field_199C;
	int field_19A0;
	int field_19A4;
	int field_19A8;
	int field_19AC;
	int field_19B0;
	int field_19B4;
	int field_19B8;
	int field_19BC;
	int field_19C0;
	int field_19C4;
	int field_19C8;
	int field_19CC;
	int field_19D0;
	int field_19D4;
	int field_19D8;
	char *field_19DC;
	int field_19E0;
	int field_19E4;
	int field_19E8;
	int field_19EC;
};

struct SystemControl
{
};

struct DroneBlueprint
{
};

struct SoundControl
{
};

struct CommandGui;
struct CompleteShip;

struct CommandGui
{
	LIBZHL_API int constructor();
	LIBZHL_API int KeyDown(int key, char unk);
	LIBZHL_API int RunCommand(char **command);
	LIBZHL_API int LinkShip(CompleteShip *ship);
	LIBZHL_API int RenderStatic();
	LIBZHL_API int CreateNewStore(int sectorNumber);
	
};

struct ReactorButton
{
};

struct WindowFrame
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
};

struct ShipGraph;

struct RoomShape;

struct ShipGraph
{
	LIBZHL_API Point GetSlotWorldPosition(int room, int slot);
	LIBZHL_API int DoorCount(int room);
	LIBZHL_API int GetNumSlots(int room);
	LIBZHL_API int GetIntoRoom(int room, Point unk);
	LIBZHL_API int GetSelectedRoom(int unk1, int unk2, bool unk3);
	LIBZHL_API int RoomCount();
	LIBZHL_API int GetRoomShape(RoomShape *ref, int room);
	LIBZHL_API int ComputeCenter();
	LIBZHL_API bool GetRoomBlackedOut(int room);
	LIBZHL_API static Point __stdcall TranslateToGrid(int x, int y);
	LIBZHL_API static Point __stdcall TranslateFromGrid(int x, int y);
	LIBZHL_API static Point __stdcall TranslateToGrid(Point point);
	LIBZHL_API static Point __stdcall TranslateFromGrid(Point point);
	LIBZHL_API static bool __stdcall Adjacent(Point point1, Point point2);
	LIBZHL_API static bool __stdcall Valid(Point point);
	LIBZHL_API static bool __stdcall Adjacent(int x1, int y1, int x2, int y2);
	LIBZHL_API int ConnectingDoor(int unk1, int unk2, int unk3, int unk4);
	LIBZHL_API int ConnectedGridSquares(int x1, int y1, int x2, int y2);
	LIBZHL_API int ConnectedGridSquares(Point point1, Point point2);
	LIBZHL_API static int __stdcall PopClosestDoor(int unk1, int unk2);
	LIBZHL_API int OnInit(int unk1, int unk2);
	LIBZHL_API int GetRoomNeighbors(int ignore, int room);
	LIBZHL_API int GetDoors(int unk1, int unk2);
	LIBZHL_API int GetConnectedRooms(int ignore, int room, bool unk);
	LIBZHL_API int ConnectivityDFSHelper(int unk1, int unk2, int unk3, int unk4);
	LIBZHL_API int ConnectivityDFS(int ignore, int unk1);
	LIBZHL_API bool IsRoomConnected(int room1, int room2);
	LIBZHL_API int Dijkstra(int ignore, Point unk1, Point unk2, int unk3);
	LIBZHL_API int FindPath(int ignore, Point unk1, Point unk2, int unk3);
	LIBZHL_API int GetClosestSlot(int ignore, Point unk1, int unk2, bool unk3);
	LIBZHL_API static ShipGraph *__stdcall GetShipInfo(int isEnemy);
	LIBZHL_API static int __stdcall Restart();
	
};

struct ExplosionAnimation
{
	int field_0;
	int field_4;
	char field_8;
	char gap_9[3];
	float field_C;
	char field_10;
	char field_11;
	char field_12;
	char gap_13[1];
	float field_14;
	float field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	int field_88;
	int field_8C;
	float field_90;
	float field_94;
	char field_98;
	char field_99;
	char gap_9A[2];
	int field_9C;
	int field_A0;
	int field_A4;
	Point field_A8;
};

struct WarningMessage
{
	int field_0;
	float field_4;
	char field_8;
	char gap_9[3];
	float field_C;
	char field_10;
	char field_11;
	char field_12;
	char gap_13[1];
	float field_14;
	int field_18;
	CachedImage field_1C;
	int field_54;
	char field_58;
	char gap_59[3];
	char *field_5C;
	int field_60;
	int field_64;
	char field_68;
	char gap_69[3];
	float field_6C;
	char field_70;
	char field_71;
	char field_72;
	char gap_73[1];
	float field_74;
	int field_78;
};

struct ItemBlueprint
{
};

struct ProjectileFactory;

struct Targetable;

struct FileHelper;
struct std_string;
struct Projectile;

struct WeaponAnimation
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	float field_24;
	char field_28;
	char gap_29[3];
	float field_2C;
	char field_30;
	char field_31;
	char field_32;
	char gap_33[1];
	float field_34;
	float field_38;
	int field_3C;
	int field_40;
	char *field_44;
	char *field_48;
	char field_4C;
	char gap_4D[3];
	float field_50;
	float field_54;
	int field_58;
	char field_5C;
	char gap_5D[3];
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
	char *field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	char field_88;
	char field_89;
	char gap_8A[2];
	float field_8C;
	int field_90;
	int field_94;
	char field_98;
	char field_99;
	char gap_9A[2];
	int field_9C;
	int field_A0;
	char field_A4;
	char gap_A5[3];
	int field_A8;
	int field_AC;
	int field_B0;
	int field_B4;
	int field_B8;
	int field_BC;
	int field_C0;
	float field_C4;
	char field_C8;
	char gap_C9[3];
	float field_CC;
	char field_D0;
	char field_D1;
	char field_D2;
	char gap_D3[1];
	float field_D4;
	float field_D8;
	int field_DC;
	CachedImage field_E0;
	int field_118;
	int field_11C;
	int field_120;
	int field_124;
	int field_128;
	int field_12C;
	int field_130;
	int field_134;
	int field_138;
	float field_13C;
	char field_140;
	char gap_141[3];
	float field_144;
	char field_148;
	char field_149;
	char field_14A;
	char gap_14B[1];
	float field_14C;
	float field_150;
	int field_154;
	int field_158;
	char *field_15C;
	char *field_160;
	char field_164;
	char gap_165[3];
	float field_168;
	float field_16C;
	int field_170;
	char field_174;
	char gap_175[3];
	int field_178;
	int field_17C;
	int field_180;
	float field_184;
	float field_188;
	char *field_18C;
	int field_190;
	int field_194;
	int field_198;
	int field_19C;
	int field_1A0;
	int field_1A4;
	int field_1A8;
	int field_1AC;
	int field_1B0;
	float field_1B4;
	int field_1B8;
	int field_1BC;
	int field_1C0;
	int field_1C4;
	int field_1C8;
	int field_1CC;
	int field_1D0;
	int field_1D4;
	int field_1D8;
	float field_1DC;
	char field_1E0;
	char gap_1E1[3];
	float field_1E4;
	char field_1E8;
	char field_1E9;
	char field_1EA;
	char gap_1EB[1];
	float field_1EC;
	float field_1F0;
	int field_1F4;
	int field_1F8;
	char *field_1FC;
	char *field_200;
	char field_204;
	char gap_205[3];
	float field_208;
	float field_20C;
	int field_210;
	char field_214;
	char gap_215[3];
	int field_218;
	int field_21C;
	int field_220;
	int field_224;
	int field_228;
	char *field_22C;
	int field_230;
	int field_234;
	int field_238;
	int field_23C;
	int field_240;
	char field_244;
	char gap_245[3];
	float field_248;
	int field_24C;
	int field_250;
	int field_254;
	CachedImage field_258;
	CachedImage field_290;
	int field_2C8;
	int field_2CC;
	int field_2D0;
	int field_2D4;
	int field_2D8;
	int field_2DC;
	int field_2E0;
	int field_2E4;
	int field_2E8;
	int field_2EC;
	float field_2F0;
	char field_2F4;
	char gap_2F5[3];
	float field_2F8;
	char field_2FC;
	char field_2FD;
	char field_2FE;
	char gap_2FF[1];
	float field_300;
	float field_304;
	int field_308;
	int field_30C;
	char *field_310;
	char *field_314;
	char field_318;
	char gap_319[3];
	float field_31C;
	float field_320;
	int field_324;
	char field_328;
	char gap_329[3];
	int field_32C;
	int field_330;
	int field_334;
	float field_338;
	float field_33C;
	char *field_340;
	int field_344;
	int field_348;
	int field_34C;
	int field_350;
	char field_354;
	char bs_1;
	char bs_2;
	char bs_3;
};

struct WeaponBlueprint;

struct ProjectileFactory
{
	static int StringToWeapon(const char* weaponType)
	{
		if (strcmp(weaponType, "LASER") == 0) return 0;
		else if (strcmp(weaponType, "MISSILES") == 0) return 1;
		else if (strcmp(weaponType, "BEAM") == 0) return 2;
		else if (strcmp(weaponType, "BOMB") == 0) return 3;
		else if (strcmp(weaponType, "BURST") == 0) return 4;
		else return -1;
	}

	LIBZHL_API int SelectChargeGoal();
	LIBZHL_API bool IsChargedGoal();
	LIBZHL_API int SetHacked(int hacked);
	LIBZHL_API int SetCurrentShip(Targetable *ship);
	LIBZHL_API void SetCooldownModifier(float cooldownMod);
	LIBZHL_API int ForceCoolup();
	LIBZHL_API int RenderChargeBar(float unk);
	LIBZHL_API int OnRender(float unk1, bool unk2);
	LIBZHL_API int SetMount(bool unk1, int unk2, int unk3, int unk4, int unk5);
	LIBZHL_API bool SetAutoFire(bool autoFiring);
	LIBZHL_API bool ReadyToFire();
	LIBZHL_API bool FireNextShot();
	LIBZHL_API static int __stdcall StringToWeapon(std_string *weaponType);
	LIBZHL_API bool QueuedShots();
	LIBZHL_API int SpendMissiles();
	LIBZHL_API int NumTargetsRequired();
	LIBZHL_API int ClearAiming();
	LIBZHL_API int SetPowered(bool unk1);
	LIBZHL_API int ReconnectProjectile(Projectile *proj);
	LIBZHL_API int GetBoostLevel();
	LIBZHL_API static int __stdcall SaveProjectile(Projectile *proj, int unk);
	LIBZHL_API static Projectile *__stdcall LoadProjectile(int unk);
	LIBZHL_API int SaveState(int unk);
	LIBZHL_API int Fire(int pointfArr, int unk);
	LIBZHL_API int LoadState(FileHelper *fileHelper);
	LIBZHL_API int constructor(WeaponBlueprint *bp, int unk);
	
	int field_0;
	int field_4;
	float field_8;
	float field_C;
	float field_10;
	float field_14;
	float field_18;
	int field_1C;
	Point field_20;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	float field_4C;
	char field_50;
	char gap_51[3];
	float field_54;
	char field_58;
	char field_59;
	char field_5A;
	char gap_5B[1];
	float field_5C;
	int field_60;
	Pointf field_64;
	char *field_6C;
	char *field_70;
	char field_74;
	char gap_75[3];
	int field_78;
	float field_7C;
	int field_80;
	char field_84;
	char gap_85[3];
	int field_88;
	int field_8C;
	int field_90;
	float field_94;
	float field_98;
	char *field_9C;
	int field_A0;
	int field_A4;
	int field_A8;
	int field_AC;
	char field_B0;
	char gap_B1[3];
	int field_B4;
	int field_B8;
	int field_BC;
	int field_C0;
	int field_C4;
	int field_C8;
	int field_CC;
	int field_D0;
	int field_D4;
	char *field_D8;
	int field_DC;
	float field_E0;
	float field_E4;
	int field_E8;
	int field_EC;
	WeaponAnimation field_F0;
	Point field_448;
	char field_450;
	char field_451;
	char gap_452[2];
	int field_454;
	int field_458;
	int field_45C;
	int field_460;
	int field_464;
	int field_468;
	char field_46C;
	char gap_46D[3];
	int field_470;
	int field_474;
	int field_478;
	int field_47C;
	int field_480;
	int field_484;
	int field_488;
	int field_48C;
	int field_490;
	char field_494;
	char bs_1;
	char bs_2;
	char bs_3;
};

struct Ship;

struct Ship
{


	LIBZHL_API int SetSelectedRoom(int roomIndex);
	LIBZHL_API int64_t GetRoomCenter(int roomIndex);
	LIBZHL_API bool BreachSpecificHull(int ignore, int roomId, int slot);
	
	int _base;
	int _isEnemy;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int _hull;
	int _maxHull;
	int field_40;
	int field_44;
	int field_48;
	char *_floorFilePath;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	char *_baseFilePath;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	Point field_88;
	int field_90;
	char *_cloakFilePath;
	int field_98;
	int field_9C;
	int field_A0;
	int field_A4;
	int field_A8;
	int field_AC;
	int field_B0;
	int field_B4;
	int field_B8;
	int field_BC;
	int field_C0;
	int field_C4;
	int field_C8;
	int field_CC;
	int field_D0;
	char gap_D4[4];
	int field_D8;
	int field_DC;
	int field_E0;
	ExplosionAnimation _explosionAnim;
	char field_194;
	char gap_195[3];
	Point field_198;
	float field_1A0;
	float field_1A4;
	Animation field_1A8;
	Animation field_230;
	int field_2B8;
	int field_2BC;
	char field_2C0;
	char gap_2C1[3];
	float field_2C4;
	char field_2C8;
	char field_2C9;
	char field_2CA;
	char gap_2CB[1];
	float field_2CC;
	int field_2D0;
	char field_2D4;
	char field_2D5;
	char gap_2D6[2];
	int field_2D8;
	int field_2DC;
	int field_2E0;
};

struct MindSystem;

struct MindSystem
{
	LIBZHL_API int ReleaseCrew();
	LIBZHL_API bool Jump();
	LIBZHL_API int GetControlLimit();
	LIBZHL_API bool Charged();
	LIBZHL_API bool CanUse();
	
};

struct UnlockArrow
{
};

struct WeaponControl : ArmamentControl
{
	int field_80;
	int field_84;
	char field_88;
	char field_89;
	char gap_8A[2];
	int field_8C;
	int field_90;
	int field_94;
	int field_98;
	int field_9C;
	char field_A0;
	char gap_A1[3];
	int field_A4;
	int field_A8;
	int field_AC;
	int field_B0;
	Pointf field_B4;
	char gap_BC[248];
	int field_1B4;
};

struct DroneSystem
{
};

struct StarMap;

struct StarMap : FocusWindow
{
	LIBZHL_API int constructor();
	
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	char gap_2C[3];
	char field_2F;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	Point field_5C;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
	Pointf field_74;
	int field_7C;
	Pointf field_80;
	int field_88;
	char gap_8C[8];
	Button field_94;
	Button field_FC;
	Button field_164;
	char gap_1CC[28];
	Button field_1E8;
	int _sectorNumber;
	char gap_254[4];
	int field_258;
	char gap_25C[4];
	char gap_260[28];
	char field_27C[148];
	int field_310;
	int field_314;
	char field_318;
	char gap_319[3];
	float field_31C;
	char field_320;
	char field_321;
	char field_322;
	char gap_323[1];
	int field_324;
	int field_328;
	int field_32C;
	Button field_330;
	char field_398[48];
	int field_3C8;
	int field_3CC;
	int field_3D0;
	int field_3D4;
	int field_3D8;
	int field_3DC;
	int field_3E0;
	int field_3E4;
	ShipManager *_playerShip;
	char field_3EC;
	char gap_3ED[3];
	int field_3F0;
	int field_3F4;
	char field_3F8;
	char gap_3F9[3];
	float field_3FC;
	char field_400;
	char field_401;
	char field_402;
	char gap_403[1];
	float field_404;
	float field_408;
	int field_40C;
	int field_410;
	int field_414;
	char field_418;
	char gap_419[3];
	float field_41C;
	char field_420;
	char field_421;
	char field_422;
	char gap_423[1];
	float field_424;
	float field_428;
	int field_42C;
	int field_430;
	int field_434;
	int field_438;
	int field_43C;
	int field_440;
	int field_444;
	int field_448;
	int field_44C;
	char _showSectorMap;
	char field_451;
	char gap_452[2];
	char gap_454[156];
	int field_4F0;
	int field_4F4;
	int field_4F8;
	int field_4FC;
	int field_500;
	int field_504;
	int field_508;
	int field_50C;
	int field_510;
	int field_514;
	int field_518;
	int field_51C;
	int field_520;
	int field_524;
	int field_528;
	int field_52C;
	int field_530;
	int field_534;
	int field_538;
	int field_53C;
	int field_540;
	int field_544;
	int field_548;
	int field_54C;
	int field_550;
	int field_554;
	int field_558;
	int field_55C;
	int field_560;
	int field_564;
	int field_568;
	int field_56C;
	int field_570;
	int field_574;
	int field_578;
	char field_57C;
	char field_57D;
	char gap_57E[2];
	int field_580;
	int field_584;
	int field_588;
	char field_58C;
	char field_58D;
	char gap_58E[2];
	Pointf field_590;
	char *field_598;
	char field_59C;
	char field_59D;
	char field_59E;
	char gap_59F[1];
	int field_5A0;
	int field_5A4;
	int field_5A8;
	Button field_5AC;
	int field_614;
	int field_618;
	int field_61C;
	char *field_620;
	int field_624;
	int field_628;
	int field_62C;
	int field_630;
	int field_634;
	int field_638;
	int field_63C;
	int field_640;
	int field_644;
	int field_648;
	int field_64C;
	int field_650;
	int field_654;
	int field_658;
	int field_65C;
	int field_660;
	int field_664;
	Point field_668;
	int field_670;
	int field_674;
	int field_678;
	int field_67C;
	int field_680;
};

struct SpaceManager;

struct SpaceManager
{

	LIBZHL_API static void __stdcall __BS_FUNCTION_DONT_USE();
	LIBZHL_API bool GetScreenShake();
	LIBZHL_API int SaveSpace(int ignore, FileHelper *fileHelper);
	LIBZHL_API void *SwitchBackground(int unk, std_string *bg);
	LIBZHL_API int StartAsteroids(int unk1, bool unk2);
	LIBZHL_API int SetFireLevel(bool unk);
	LIBZHL_API int SetPulsarLevel(bool unk);
	LIBZHL_API bool DangerousEnvironment();
	LIBZHL_API int GetSelectedDrone(int unk1, int unk2, int unk3);
	LIBZHL_API float GetFlashOpacity();
	LIBZHL_API bool OnRenderFleet();
	LIBZHL_API bool OnRenderForeground();
	LIBZHL_API bool SetDangerZone();
	LIBZHL_API int OnRenderAsteroids(int unk1, float unk2);
	LIBZHL_API int OnRenderProjectiles(int unk1, int unk2);
	LIBZHL_API int OnInit();
	LIBZHL_API void ClearEnvironment();
	LIBZHL_API void Clear();
	LIBZHL_API int UpdateProjectile(Projectile *proj);
	LIBZHL_API int TransferProjectiles(Projectile *proj);
	LIBZHL_API int OnRenderBackground();
	LIBZHL_API int AddShip(ShipManager *ship);
	LIBZHL_API int OnLoopNebulas();
	LIBZHL_API int SetNebula(bool nebula);
	LIBZHL_API int SetStorm(bool storm);
	LIBZHL_API int UpdatePDS();
	LIBZHL_API int OnLoop();
	LIBZHL_API int SetPlanetaryDefense(bool pds, int unk);
	LIBZHL_API int LoadSpace(FileHelper *fileHelper);
	LIBZHL_API int SwitchImages(int aLotOfArguments);
	LIBZHL_API void *SwitchPlanet(std_string *planet);
	LIBZHL_API int constructor();
	
	int field_0;
	int field_4;
	int field_8;
	char gap_C[144];
	int field_9C;
	int field_A0;
	int field_A4;
	int field_A8;
	int field_AC;
	int field_B0;
	char field_B4;
	char gap_B5[3];
	int field_B8;
	int field_BC;
	int field_C0;
	int field_C4;
	int field_C8;
	int field_CC;
	int field_D0;
	char gap_D4[56];
	int field_10C;
	int field_110;
	int field_114;
	int field_118;
	int field_11C;
	int field_120;
	Point field_124;
	int field_12C;
	int field_130;
	int field_134;
	int field_138;
	int field_13C;
	int field_140;
	int field_144;
	Point field_148;
	Point field_150;
	Point field_158;
	Point field_160;
	Point field_168;
	Point field_170;
	Point field_178;
	Point field_180;
	Point field_188;
	Point field_190;
	Point field_198;
	Point field_1A0;
	Point field_1A8;
	char gap_1B0[96];
	int field_210;
	int field_214;
	int field_218;
	int field_21C;
	char field_220;
	char gap_221[3];
	float field_224;
	char field_228;
	char field_229;
	char field_22A;
	char gap_22B[1];
	float field_22C;
	float field_230;
	int field_234;
	int field_238;
	char field_23C;
	char gap_23D[3];
	float field_240;
	char field_244;
	char field_245;
	char field_246;
	char gap_247[1];
	float field_248;
	float field_24C;
	int field_250;
	int field_254;
	char field_258;
	char gap_259[3];
	float field_25C;
	char field_260;
	char field_261;
	char field_262;
	char gap_263[1];
	float field_264;
	float field_268;
	char field_26C;
	char field_26D;
	char gap_26E[2];
	int field_270;
	int field_274;
	int field_278;
	char field_27C;
	char gap_27D[3];
	int field_280;
	Point field_284;
	float field_28C;
	int field_290;
	int field_294;
	int field_298;
	TimerHelper _environmentTimer;
	int field_2B0;
	int field_2B4;
	char field_2B8;
	char gap_2B9[3];
	float field_2BC;
	char field_2C0;
	char field_2C1;
	char field_2C2;
	char gap_2C3[1];
	float field_2C4;
	float field_2C8;
	int field_2CC;
	int field_2D0;
	int field_2D4;
	int field_2D8;
	int field_2DC;
	int field_2E0;
	int field_2E4;
	int field_2E8;
	int field_2EC;
	int field_2F0;
	int field_2F4;
	int field_2F8;
	int field_2FC;
	int field_300;
	char field_304;
	char gap_305[3];
	float field_308;
	char field_30C;
	char field_30D;
	char field_30E;
	char gap_30F[1];
	float field_310;
	int field_314;
	char field_318;
	char field_319;
	char field_31A;
	char gap_31B[1];
	int field_31C;
	int field_320;
	int field_324;
	int field_328;
	int field_32C;
	int field_330;
	int field_334;
	int field_338;
	int field_33C;
	int field_340;
	int field_344;
	float field_348;
	int field_34C;
	char field_350;
	char field_351;
	char gap_352[2];
	int field_354;
	int field_358;
	int field_35C;
	int field_360;
	char field_364;
	char field_365;
	char bs_1;
	char bs_2;
	int field_368;
};

struct ShipEvent;
struct WorldManager;
struct Location;
struct LocationEvent;
struct BoardingEvent;

struct WorldManager
{
	LIBZHL_API int OnInit();
	LIBZHL_API int PossibleDamage(int unk1, int unk2, int unk3);
	LIBZHL_API int CreateStore(LocationEvent *loc);
	LIBZHL_API bool CheckRequirements(LocationEvent *loc, bool unk2);
	LIBZHL_API bool AddBoarders(BoardingEvent *event);
	LIBZHL_API int CreateCommandGui();
	LIBZHL_API bool HostileEnvironment();
	LIBZHL_API int CheckMusic();
	LIBZHL_API int ModifyEnvironment(int hazard, int lvl);
	LIBZHL_API bool ModifyStatusEffect(int unk1, int unk2, int unk3, int unk4, ShipManager *ship, int unk5);
	LIBZHL_API int ModifyAllStatusEffects(ShipManager *ship, int unk);
	LIBZHL_API int CheckStatusEffects(int arr);
	LIBZHL_API int UpdateNameDefinitions(LocationEvent *loc);
	LIBZHL_API int constructor();
	LIBZHL_API void *RetrieveShipList(LocationEvent *loc);
	LIBZHL_API int ClearLocation();
	LIBZHL_API int OnCleanup();
	LIBZHL_API int AddShip(int ignore, CompleteShip *ship);
	LIBZHL_API int CreateShip(ShipEvent *event, bool unk);
	LIBZHL_API void *FormatText(int unk1, int unk2);
	LIBZHL_API void *ModifyResources(LocationEvent *loc);
	LIBZHL_API int CreateChoiceBox(LocationEvent *loc);
	LIBZHL_API int UpdateLocation(LocationEvent *loc);
	LIBZHL_API int CreateLocation(int ignore, Location *loc);
	LIBZHL_API int CreateNewGame();
	LIBZHL_API int Restart();
	LIBZHL_API int StartGame(ShipManager *playerShip);
	LIBZHL_API bool CheckForNewLocation(int unk1, bool unk2);
	LIBZHL_API int SaveGame();
	LIBZHL_API bool PrepareAutoSave();
	LIBZHL_API int CheckLoadEvent();
	LIBZHL_API int PauseLoop();
	LIBZHL_API int OnLoop();
	LIBZHL_API int LoadGame(char **unk);
	
	int field_0;
	int field_4;
	SpaceManager _spaceManager;
	int field_374;
	int field_378;
	int field_37C;
	StarMap _starMap;
	CommandGui *_commandGui;
	int field_A08;
	int field_A0C;
	char gap_A10[424];
	int field_BB8;
	int field_BBC;
	int field_BC0;
	char *field_BC4;
	int field_BC8;
	int field_BCC;
	int field_BD0;
	int field_BD4;
	int field_BD8;
	int field_BDC;
	int field_BE0;
	int field_BE4;
	int field_BE8;
	int field_BEC;
	int field_BF0;
	int field_BF4;
	int field_BF8;
	int field_BFC;
	int field_C00;
	int field_C04;
	int field_C08;
	int field_C0C;
	int field_C10;
	char _inGame;
	char field_C15;
	char field_C16;
	char field_C17;
	int field_C18;
	int field_C1C;
	int field_C20;
	int field_C24;
	int field_C28;
	int field_C2C;
	int field_C30;
	int field_C34;
	int field_C38;
	int field_C3C;
	int field_C40;
	int field_C44;
	char field_C48;
	char gap_C49[3];
	int field_C4C;
	int field_C50;
	int field_C54;
};

struct PowerManager
{
};

struct ResourcesTemplate
{
	int field_0;
	int field_4;
	float field_8;
	int field_C;
	int field_10;
	float field_14;
	int field_18;
	int field_1C;
	float field_20;
	int field_24;
	int field_28;
	float field_2C;
	int field_30;
	int field_34;
	float field_38;
	int field_3C;
	std::string *field_40;
	std::string *field_44;
	int field_48;
	std::string *field_4C;
	int field_50;
	int field_54;
	int field_58;
	std::string *field_5C;
	std::string *field_60;
	std::string *field_64;
	std::string *field_68;
	char field_6C;
	char gap_6D[3];
	int field_70;
	int field_74;
};

struct GL_Texture
{
};

struct CachedRect
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
};

struct std_string
{
	LIBZHL_API static void *__stdcall constructor(std_string *a1, char *str, int alloc);
	
	char field_0;
};

struct WeaponSystem;

struct ShipSystem;
struct DroneSystem;
struct CrewMember;
struct OxygenSystem;
struct Shields;

struct ShipObject
{
	/*
	bool HasAugmentation(char* augment) 
	{
		bool ret = 0;
		
		for (int i = 0; i < this->GetAugmentationCount(); i++) 
		{
			if (strcmp(this->_augments[i], augment) == 0)
				ret = 1;
		}
		
		return ret;
	}
	*/

	LIBZHL_API int HasAugmentation(std_string *a2);
	LIBZHL_API int GetAugmentationCount();
	
	int _base;
	int _isEnemy;
	char gap_8[4];
	int field_C;
	char field_10;
	char field_11;
	char gap_12[2];
	int field_14;
	ShipSystem **_systems;
	int field_1C;
	int field_20;
	OxygenSystem *_oxygenSystem;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	char gap_44[92];
	char _showHacking;
	char gap_A1[3];
	Shields *_shields;
	WeaponSystem *_weapons;
	DroneSystem *_drones;
	char gap_B0[8];
	int field_B8;
	int field_BC;
	int field_C0;
	CrewMember **_crewList;
	int field_C8;
	int _ftlTimer;
	int field_D0;
	char gap_D4[32];
	Ship _ship;
	int field_3D8;
	char field_3DC[40];
	ShipObject *_target;
	float _ftlCharge;
	float _ftlThreshold;
	int _fuel;
	char gap_414[1];
	char _dead;
	char gap_416[2];
	int _lastDamage;
	int field_41C;
	int field_420;
	char field_424;
	char gap_425[3];
	float field_428;
	char field_42C;
	char field_42D;
	char field_42E;
	char gap_42F[1];
	float field_430;
	int field_434;
	int field_438;
	int field_43C;
	int field_440;
	int field_444;
	int field_448;
	char gap_44C[4];
	int _scrap;
	char _jumping;
	char field_455;
	char gap_456[6];
	char gap_45C[296];
	char field_584;
	char field_585;
	char gap_586[6];
	int field_58C;
	int field_590;
	int field_594;
	int _droneCount;
	int _missileCount;
	int field_5A0;
	int field_5A4;
	int field_5A8;
	int field_5AC;
	int field_5B0;
	int field_5B4;
	int field_5B8;
	int field_5BC;
	char field_5C0;
	char gap_5C1[3];
	int field_5C4;
	int field_5C8;
	int field_5CC;
	int field_5D0;
	int field_5D4;
	int field_5D8;
	int field_5DC;
	int field_5E0;
	int field_5E4;
	int field_5E8;
	int field_5EC;
	char field_5F0;
	char gap_5F1[3];
	int field_5F4;
	int field_5F8;
	int field_5FC;
	int field_600;
	int field_604;
	int field_608;
	int field_60C;
	int field_610;
	int field_614;
	int field_618;
	int field_61C;
	int field_620;
	int field_624;
	int field_628;
	int field_62C;
	int field_630;
	char gap_634[4];
	int field_638;
	int field_63C;
	int field_640;
	int field_644;
	int field_648;
	int field_64C;
	int field_650;
	int field_654;
};

struct GameOver
{
};

struct CAchievement;

struct CAchievement
{
	LIBZHL_API int OnRender(int x, int y, int unk1, bool unk2);
	LIBZHL_API int destructor();
	LIBZHL_API int constructor();
	
	char *field_0;
	int field_4;
	int field_8;
	int field_C;
	char *field_10;
	char *field_14;
	char field_18;
	char field_19;
	char gap_1A[2];
	int field_1C;
	char *field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	CachedImage field_34;
	CachedImage field_6C;
	CachedImage field_A4;
	CachedImage field_DC;
	CachedImage field_114;
	CachedImage field_14C;
	int field_184;
	int field_188;
	int field_18C;
};

struct Repairable
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	Point field_14;
	int field_1C;
	char *_name;
	int field_24;
	int field_28;
};

struct Location
{
	Pointf field_0;
	int field_8;
	int field_C;
	int field_10;
	char field_14;
	char field_15;
	char gap_16[2];
	int field_18;
	char field_1C;
	char field_1D;
	char field_1E;
	char field_1F;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	char field_70;
	char gap_71[3];
	int field_74;
	int field_78;
	char field_7C;
	char gap_7D[3];
	float field_80;
	char field_84;
	char field_85;
	char field_86;
	char gap_87[1];
	float field_88;
	int field_8C;
	char field_90;
	char gap_91[3];
	char *field_94;
	char *field_98;
};

struct TutorialManager
{
};

struct CombatDrone
{
};

struct SystemStoreBox
{
};

struct RandomAmount
{
};

struct DroneControl : ArmamentControl
{
	WarningMessage field_80;
	WarningMessage field_FC;
	WarningMessage field_178;
};

struct MouseControl
{
};

struct ArtillerySystem
{
};

struct BoarderDrone
{
};

struct InfoBox;
struct AchievementTracker;

struct AchievementTracker
{
	LIBZHL_API int SaveProfile(FileHelper *fileHelper);
	LIBZHL_API int WipeProfile();
	LIBZHL_API int CheckCrystalUnlock();
	LIBZHL_API CAchievement *GetAchievement(std_string *ach);
	LIBZHL_API static CAchievement *__stdcall GetShipMarker(std_string *unk1, std_string *unk2);
	LIBZHL_API static int __stdcall SetInfoBox(CAchievement *ach, InfoBox *infobox);
	LIBZHL_API int OnRender();
	LIBZHL_API static int __stdcall SetTooltip(CAchievement *ach);
	LIBZHL_API int OnLoop();
	LIBZHL_API int ResetFlags();
	LIBZHL_API int constructor();
	LIBZHL_API int SaveGame(int unk);
	LIBZHL_API void UnlockShip(int shipType, int shipVariant);
	LIBZHL_API void *GetShipAchievements(int unk1, std_string *unk2);
	LIBZHL_API int CheckShipAchievements(int shipType, bool unk);
	LIBZHL_API int ForceUnlock(std_string *unk1, int unk2, int unk3);
	LIBZHL_API int LoadProfile(int unk1, int unk2);
	LIBZHL_API int SetAchievement(std_string *ach, bool unk1, bool unk2);
	LIBZHL_API int SetVictoryAchievement();
	LIBZHL_API int LoadGame(int unk1);
	LIBZHL_API bool GetFlag(std_string *flag);
	LIBZHL_API int GetFlagValue(int unk1);
	LIBZHL_API int SetSectorEight();
	LIBZHL_API int SetFlag(std_string *flag);
	LIBZHL_API int destructor();
	LIBZHL_API int LoadAchievementDescriptions();
	
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	char field_44;
	char gap_45[3];
	float field_48;
	char field_4C;
	char field_4D;
	char field_4E;
	char gap_4F[1];
	float field_50;
	int field_54;
	int field_58;
};

struct EventSystem
{
};

struct GL_Texture;
struct Colorf;
struct GL_Primitive;
struct GL_FrameBuffer;

struct CSurface
{
	LIBZHL_API static void __stdcall __BS_FUNCTION_DONT_USE();
	LIBZHL_API static int __stdcall StartFrame();
	LIBZHL_API static int __stdcall FinishFrame();
	LIBZHL_API static int __stdcall GL_ClearAll();
	LIBZHL_API static int __stdcall GL_ClearColor();
	LIBZHL_API static bool __stdcall GL_SetViewPort(int x1, int y1, int x2, int y2);
	LIBZHL_API static int __stdcall GL_PopScissor();
	LIBZHL_API static int __stdcall GL_SetStencilMode(int stencilMode, int unk1, int unk2);
	LIBZHL_API static int __stdcall GL_PopStencilMode();
	LIBZHL_API static int __stdcall GL_OrthoProjection(float unk1, float unk2, float unk3, float unk4, float unk5, float unk6);
	LIBZHL_API static int __stdcall GL_LoadIdentity();
	LIBZHL_API static int __stdcall GL_PushMatrix();
	LIBZHL_API static int __stdcall GL_PopMatrix();
	LIBZHL_API static int64_t __stdcall GL_Rotate(float angle, float x, float y, float z);
	LIBZHL_API static int64_t __stdcall GL_Scale(float x, float y, float z);
	LIBZHL_API static int64_t __stdcall GL_Translate(float x, float y, float z);
	LIBZHL_API static int __stdcall GL_SetColor(float r, float g, float b, float a);
	LIBZHL_API static int __stdcall GL_RemoveColorTint();
	LIBZHL_API static Colorf *__stdcall GetColorTint(Colorf &ref);
	LIBZHL_API static int __stdcall GL_EnableBlend();
	LIBZHL_API static int __stdcall GL_DisableBlend();
	LIBZHL_API static bool __stdcall GL_DrawLine(float x1, float y1, float x2, float y2, float lineWidth, float r, float g, float b, float a);
	LIBZHL_API static bool __stdcall GL_DrawRect(float x1, float y1, float x2, float y2, float r, float g, float b, float a);
	LIBZHL_API static bool __stdcall GL_DrawRectOutline(float x1, float y1, float x2, float y2, float width, float r, float g, float b, float a);
	LIBZHL_API static int __stdcall GL_BlitImage(GL_Texture *tex, float unk2, float unk3, float unk4, float unk5, float unk6, float unk7, float unk8, float unk9, float unk10, bool unk11);
	LIBZHL_API static bool __stdcall GL_BlitPixelImage(GL_Texture *tex, float unk2, float unk3, float unk4, float unk5, float unk6, float unk7, float unk8, float unk9, float unk10, bool unk11);
	LIBZHL_API static int __stdcall GL_BlitImagePartial(GL_Texture *tex, float unk2, float unk3, float unk4, float unk5, float unk6, float unk7, float unk8, float unk9, float unk10, float unk11, float unk12, float unk13, int unk14, bool unk15);
	LIBZHL_API static bool __stdcall GL_TilePixelImage(GL_Texture *tex, float unk2, float unk3, float unk4, float unk5, float unk6, float unk7, float unk8, float r, float g, float b, float a);
	LIBZHL_API static void *__stdcall GL_CreateFrameBuffer();
	LIBZHL_API static int __stdcall GL_BindFrameBuffer(GL_FrameBuffer *buf);
	LIBZHL_API static int __stdcall GL_BlitFrameBuffer(GL_FrameBuffer *buf, float unk1, float unk2, bool unk3);
	LIBZHL_API static int __stdcall GL_SetPrimitiveAntialias(GL_Primitive *prim, bool unk2);
	LIBZHL_API static void __stdcall GL_DestroyPrimitive(GL_Primitive *prim);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateTrianglePrimitive(int unk1, int unk2, int unk3, int unk4, int unk5, int unk6, char unk7);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateRectPrimitive(float x1, float y1, float x2, float y2, float r, float g, float b, float a);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateMultiRectPrimitive(int arr, float r, float g, float b, float a);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateRectOutlinePrimitive(int x1, int y1, int x2, int y2, float width, float r, float g, float b, float a);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateMultiLinePrimitive(int arr, float width, float r, float g, float b, float a);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateCirclePrimitive(int unk1, int unk2, float unk3, float unk4, float unk5, float unk6, float unk7);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreatePiePartialPrimitive(int unk1, int unk2, float unk3, float unk4, float unk5, float unk6, float unk7, float unk8, float unk9, float unk10);
	LIBZHL_API static bool __stdcall GL_DrawShield(int x, int y, float unk3, float unk4, int unk5, int unk6, float unk7, float unk8, float unk9, float unk10);
	LIBZHL_API static bool __stdcall GL_DrawLaser(int x1, int y1, int x2, int y2, float r, float g, float b);
	LIBZHL_API static bool __stdcall GL_DrawEllipse(int x1, int y1, int x2, int y2, float unk5, float unk6, float unk7, float unk8);
	LIBZHL_API static bool __stdcall GL_DrawCirclePartial(int x, int y, float unk3, float ang, float r, float g, float b, float a);
	LIBZHL_API static bool __stdcall GL_DrawCircle(int x, int y, float unk3, float r, float g, float b, float a);
	LIBZHL_API static bool __stdcall GL_PushScissor(int unk1, int unk2, int unk3, int unk4);
	LIBZHL_API static int __stdcall GL_SetScissor(int unk1, int unk2, int unk3, int unk4);
	LIBZHL_API static int __stdcall GL_PushStencilMode();
	LIBZHL_API static int __stdcall GL_SetColorTint(float r, float g, float b, float a);
	LIBZHL_API static int __stdcall GL_CreateMultiColorPrimitive(GL_Texture *tex, int arr);
	LIBZHL_API static int __stdcall GL_BlitMultiColorImage(GL_Texture *tex, int arr, unsigned char unk);
	LIBZHL_API static int __stdcall GL_CreateMultiImagePrimitive(GL_Texture *tex, int arr, float r, float g, float b, float a);
	LIBZHL_API static bool __stdcall GL_DrawFadingDottedLine(int x1, int y1, int x2, int y2, float unk1, float unk2, float r, float g, float b, float a);
	LIBZHL_API static int __stdcall GL_RenderPrimitiveWithColor(GL_Primitive *prim, float r, float g, float b, float a);
	LIBZHL_API static int __stdcall GL_RenderPrimitiveWithAlpha(GL_Primitive *prim, float alpha);
	LIBZHL_API static int __stdcall GL_RenderPrimitiveWithColor(GL_Primitive *prim);
	LIBZHL_API static int __stdcall AddTexVertices(int arr, float unk2, float unk3, float unk4, float unk5, float unk6, float unk7, float unk8, float unk9);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateImagePartialPrimitive(GL_Texture *tex, float unk2, float unk3, float unk4, float unk5, float unk6, float unk7, float unk8, float unk9, float unk10, float unk11, float unk12, float unk13, int unk14, bool unk15);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreatePixelImagePrimitive(GL_Texture *tex, float unk2, float unk3, float unk4, float unk5, float unk6, float unk7, float unk8, float unk9, float unk10, bool unk11);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateImagePrimitive(GL_Texture *tex, float unk2, float unk3, float unk4, float unk5, float unk6, float unk7, float unk8, float unk9, float unk10);
	
};

struct ShipInfo;

struct ShipInfo
{
	

	LIBZHL_API int HasAugmentation(std_string *a1);
	
};

struct NebulaCloud
{
};

struct CachedRectOutline
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
};

struct FTLButton
{
};

struct ArmamentBox
{
};

struct ShipBlueprint : Blueprint
{
	Description _desc;
	char *_shipId;
	char *_shipName;
	char *_shipClass;
	char *_shipType;
	int _shipLayout;
	char *_shipImg;
	char *field_74;
	char *field_78;
	char gap_7C[4];
	char field_80[16];
	int field_90;
	int field_94;
	int field_98;
	int field_9C;
	int field_A0;
	int field_A4;
	int field_A8;
	char *field_AC;
	int field_B0;
	int field_B4;
	int field_B8;
	int field_BC;
	int field_C0;
	int field_C4;
	int field_C8;
	int field_CC;
	int field_D0;
	char *field_D4;
	int field_D8;
	int field_DC;
	int field_E0;
	int field_E4;
	int field_E8;
	int field_EC;
	int field_F0;
	int field_F4;
	int field_F8;
	int field_FC;
	int field_100;
	int field_104;
	int field_108;
	int field_10C;
	int field_110;
	int field_114;
	int field_118;
	int field_11C;
	int field_120;
	char *field_124;
};

struct BossShip;

struct ShipBlueprint;

struct CompleteShip
{
	LIBZHL_API int Restart();
	LIBZHL_API int PauseLoop();
	LIBZHL_API int constructor(SpaceManager *spaceMan, bool unk1, int unk2);
	LIBZHL_API int SetShip(ShipManager *ship);
	LIBZHL_API int OnInit(const ShipBlueprint &bp, int unk);
	LIBZHL_API int AddBoarders(int unk1, std_string *unk2, bool unk3);
	LIBZHL_API int AddCrewMember(std_string *unk1, std_string *unk2, bool unk3);
	LIBZHL_API char *AddCrewMember(CrewMember *crew, int unk);
	LIBZHL_API bool SaveState(FileHelper *fileHelper);
	LIBZHL_API int Jump();
	LIBZHL_API int SetEnemeyShip(CompleteShip *enemy);
	LIBZHL_API bool DeadCrew();
	LIBZHL_API void TeleportCrew(ShipManager *ship, int unk1, bool unk2);
	LIBZHL_API int OnRenderShip(bool unk1, bool unk2);
	LIBZHL_API int InitiateTeleport(int unk1, int unk2);
	LIBZHL_API int OnLoop();
	LIBZHL_API int LoadState(FileHelper *fileHelper);
	LIBZHL_API int AddCrewMember(const CrewBlueprint &bp, bool unk);
	
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	char field_14;
	char gap_15[3];
	ShipAI field_18;
	int field_118;
	int field_11C;
	int field_120;
	int field_124;
	int field_128;
	int field_12C;
};

struct BossShip : CompleteShip
{
	LIBZHL_API int OnLoop();
	LIBZHL_API int ClearLocation();
	LIBZHL_API bool Defeated();
	LIBZHL_API void *GetSubEvent();
	LIBZHL_API int constructor();
	LIBZHL_API int LoadBoss(FileHelper *fileHelper);
	LIBZHL_API int SaveBoss(FileHelper *fileHelper);
	LIBZHL_API int StartStage();
	LIBZHL_API int GetEvent();
	
	int field_130;
	int field_134;
	int field_138;
	int field_13C;
	int field_140;
	int field_144;
	char field_148;
	char field_149;
	char gap_14A[2];
	int field_14C;
	int field_150;
	int field_154;
	int field_158;
	char field_15C;
	char gap_15D[3];
	int field_160;
};

struct TouchTooltip
{
};

struct HackingDrone
{
};

struct Settings
{
	LIBZHL_API static int __stdcall SaveSettings();
	LIBZHL_API static bool __stdcall GetCommandConsole();
	
};

struct DefenseDrone
{
};

struct ShipEvent
{
	char field_0;
	char gap_1[3];
	char *field_4;
	char *field_8;
	char *field_C;
	int field_10;
	int field_14;
	int field_18;
	ShipBlueprint field_1C;
	char field_144;
	char gap_145[3];
	char *field_148;
	char *field_14C;
	char *field_150;
	int field_154;
	int field_158;
	int field_15C;
	int field_160;
	int field_164;
	float field_168;
	int field_16C;
	int field_170;
	float field_174;
	int field_178;
	int field_17C;
	int field_180;
	int field_184;
	int field_188;
	int field_18C;
	int field_190;
	int field_194;
	int field_198;
	int field_19C;
	int field_1A0;
	int field_1A4;
};

struct SystemNode
{
};

struct Globals
{
};

struct CrewManifest
{
};

struct Targetable
{
};

struct AnimationTracker
{
};

struct SystemBox
{
};

struct DroneBlueprint;
struct ItemBlueprint;

struct PowerManager;
struct Drone;
struct Room;

struct ShipManager : ShipObject
{
	std::vector<CrewMember*> GetCrewList()
	{
		auto vec = std::vector<CrewMember*>();
		for (int i = 0; i < ((CrewMemberFactory*)0x0079F780)->GetCrewCount(this->_isEnemy); i++)
		{
			vec.push_back(this->_crewList[i]);
		}
		return vec;
	}
	
	std::vector<CrewMember*> GetBoarderList()
	{
		auto vec = std::vector<CrewMember*>();
		int total = 0;
		for (int i = 0; i < ShipGraph::GetShipInfo(this->_isEnemy)->RoomCount(); i++)
			total += this->CountBoarders(i);

		int crewCount = ((CrewMemberFactory*)0x0079F780)->GetCrewCount(this->_isEnemy);
		for (int i = 0; i < total; i++) 
		{
			vec.push_back(this->_crewList[i + crewCount]);
		}
		return vec;
	}
		
	Pointf GetRoomCenter(int roomIndex)
	{
		auto result = this->_ship.GetRoomCenter(roomIndex);
		return *((Pointf*)&result);
	}
	
	Pointf GetRandomRoomCenter()
	{
		auto graph = ShipGraph::GetShipInfo(this->_isEnemy);
		return this->GetRoomCenter(rand() % graph->RoomCount());
	}

	LIBZHL_API bool ManipulateDoors(int doorIndex, bool open);
	LIBZHL_API bool ContainsMindControlledEnemy();
	LIBZHL_API int UpgradeAll();
	LIBZHL_API bool CanFitSubsystem();
	LIBZHL_API void HackingStunPulse(int unk1, float unk2);
	LIBZHL_API int CountBoarders(int roomIndex);
	LIBZHL_API int DamageHull(int damage, bool checkAugments);
	LIBZHL_API int ModifyScrapCount(int amt, bool checkAugments);
	LIBZHL_API CrewMember *GetCrewmember(int index, int unk);
	LIBZHL_API CrewMember *FindCrew(CrewBlueprint &blueprint);
	LIBZHL_API int ResetScrapLevel();
	LIBZHL_API int GetSystemCount();
	LIBZHL_API int GetSubsystemCount();
	LIBZHL_API int CountPlayerCrew();
	LIBZHL_API int CountCrew(bool unk);
	LIBZHL_API int CountCrewShipId(int unk1, int unk2);
	LIBZHL_API int CheckBatteryPower();
	LIBZHL_API bool IsCrewOverFull();
	LIBZHL_API bool IsCrewFull();
	LIBZHL_API bool CheckCloakAchievement();
	LIBZHL_API int PauseLoop();
	LIBZHL_API PowerManager *UpdateReactor();
	LIBZHL_API bool ResistDamage(int unk1, int unk2);
	LIBZHL_API bool GetShowHacking();
	LIBZHL_API ShipManager *SetShowHacking(bool showHacking);
	LIBZHL_API int GetLastDamage();
	LIBZHL_API int SetDestroyed();
	LIBZHL_API int Blowup();
	LIBZHL_API void DrainSuperShields();
	LIBZHL_API int PowerSuperShields();
	LIBZHL_API int SystemJump();
	LIBZHL_API int JumpLeave();
	LIBZHL_API bool DamageCrew(CrewMember *crew, int unk2, int unk3, int unk4, int unk5, int unk6, int unk7, int unk8, int unk9, int unk10, int unk11, int unk12, int unk13);
	LIBZHL_API void AssignRoom(CrewMember *crew, int unk);
	LIBZHL_API int SaveSuperDrones(int unk);
	LIBZHL_API int DestroyBoardingDrones();
	LIBZHL_API bool IntrudersArrived();
	LIBZHL_API int CheckForRepair(int x1, int y1, int x2, int y2);
	LIBZHL_API bool CanReceiveTeleport();
	LIBZHL_API int OnCleanup();
	LIBZHL_API Pointf GetRandomTargettingPoint(bool unk);
	LIBZHL_API int CheckSpreadDamage();
	LIBZHL_API CrewMember **GetCrewList(int ignore);
	LIBZHL_API ShipSystem **GetSystemList(int ignore);
	LIBZHL_API int GetAvailablePower();
	LIBZHL_API int GetSystemPower(int systemId);
	LIBZHL_API int ClearStatus();
	LIBZHL_API int GetSystemAvailablePower(int systemId);
	LIBZHL_API int GetSystemDamage(int systemId);
	LIBZHL_API int GetSystemPowerLevel(int systemId);
	LIBZHL_API int GetSystemHealth(int systemId);
	LIBZHL_API int IncreaseSystemPower(int systemId);
	LIBZHL_API ShipSystem *GetSystemInRoom(int roomIndex);
	LIBZHL_API ShipSystem *GetSystem(int systemId);
	LIBZHL_API Room *GetSystemRoom(int systemId);
	LIBZHL_API bool ForceDecreaseSystemPower(int systemId);
	LIBZHL_API bool ForceIncreaseSystemPower(int systemId);
	LIBZHL_API bool SetSystemDividePower(int systemId, int dividePower);
	LIBZHL_API bool SetSystemPowerLoss(int systemId, int powerLoss);
	LIBZHL_API bool SetSystemPowerLimit(int systemId, int powerCap);
	LIBZHL_API int ClearStatus(int systemId);
	LIBZHL_API bool SystemLocked(int systemId);
	LIBZHL_API bool SystemFunctions(int systemId);
	LIBZHL_API bool DoorsFunction();
	LIBZHL_API bool ManipulateAllDoors(bool open);
	LIBZHL_API bool HasSystem();
	LIBZHL_API bool SetBoostFTL(bool unk);
	LIBZHL_API bool SetCloaked(bool cloaked);
	LIBZHL_API bool CanCloak();
	LIBZHL_API bool SetSafe(bool safe);
	LIBZHL_API bool CloneHealing();
	LIBZHL_API bool InstantPowerShields();
	LIBZHL_API bool Wait();
	LIBZHL_API bool CanFitSystem(int systemId);
	LIBZHL_API int JumpArrive();
	LIBZHL_API int SystemRoom(int systemId);
	LIBZHL_API int GetSystemPowerMax(int systemId);
	LIBZHL_API int CanUpgrade(int systemId, int unk);
	LIBZHL_API int UpgradeSystem(int systemId, int unk);
	LIBZHL_API static bool __stdcall CommandCrewMoveRoom(CrewMember *crew, int room);
	LIBZHL_API int GetSelectedCrew(int unk1, int unk2, int unk3);
	LIBZHL_API unsigned int ClearCrewSelection();
	LIBZHL_API bool PowerWeapon(ProjectileFactory *weapon, bool unk1, bool unk2);
	LIBZHL_API bool DePowerWeapon(ProjectileFactory *weapon, bool unk);
	LIBZHL_API int GetDroneCount();
	LIBZHL_API int ModifyDroneCount(int amt);
	LIBZHL_API int GetWeaponTotal();
	LIBZHL_API int GetDroneTotal();
	LIBZHL_API float GetOxygenPercentage();
	LIBZHL_API int AddWeapon(const WeaponBlueprint *weapon, int unk);
	LIBZHL_API WeaponSystem *GetWeaponSystem();
	LIBZHL_API int GetNextShot();
	LIBZHL_API int ModifyMissileCount(int amt);
	LIBZHL_API int AddItem(const ItemBlueprint *item);
	LIBZHL_API int GetMissileCount();
	LIBZHL_API int GetSpaceDrones();
	LIBZHL_API int IsSystemHacked();
	LIBZHL_API bool ShipFlying();
	LIBZHL_API bool JumpCharging();
	LIBZHL_API int GetDodgeFactor();
	LIBZHL_API int GetNetDodgeFactor();
	LIBZHL_API bool GetDodged();
	LIBZHL_API bool DoSensorsProvide(int sensorLevel);
	LIBZHL_API int CheckVision();
	LIBZHL_API DroneSystem *GetDroneSystem();
	LIBZHL_API int ShutdownAllPower();
	LIBZHL_API bool DePowerDrone();
	LIBZHL_API int GetDroneList();
	LIBZHL_API void *GetOxygenLevels();
	LIBZHL_API int GetWeaponList();
	LIBZHL_API bool SetShowWeaponCharge(bool showCharge);
	LIBZHL_API bool StartFire(int roomId);
	LIBZHL_API int GetFireCountInRoom(int roomId);
	LIBZHL_API int GetFireCountTotal();
	LIBZHL_API void *GetTooltip(int unk1, int unk2);
	LIBZHL_API int GetNewDroneArrivals();
	LIBZHL_API static int __stdcall SaveCrewPositions();
	LIBZHL_API static bool __stdcall RestoreCrewPositions();
	LIBZHL_API int ExportBattleState(FileHelper *fileHelper);
	LIBZHL_API int AddCrewMember(CrewBlueprint *blueprint, int unk1, bool unk2, int unk3, bool unk4);
	LIBZHL_API int GetSelectedCrew(int unk1, int unk2, int unk3, int unk4, int unk5, bool unk6);
	LIBZHL_API int TeleportCrew(int unk1, int unk2, bool unk3);
	LIBZHL_API int KillRandomCrew();
	LIBZHL_API int GetLeavingCrew(int unk2, bool unk3);
	LIBZHL_API bool AddCrewMember(CrewMember *crew, int unk);
	LIBZHL_API int SetTarget(ShipManager *target);
	LIBZHL_API int CreateCrewDrone(const DroneBlueprint *blueprint);
	LIBZHL_API void *DamageShield(int unk1, int unk2, float unk3, int unk4, int unk5, int unk6, int unk7, int unk8, int unk9, int unk10, int unk11, int unk12, int unk13, int unk14, int unk15, int unk16, int unk17, int unk18, bool unk19);
	LIBZHL_API int PulsarDamage();
	LIBZHL_API int DamageSystem(ShipSystem *sys, unsigned int dmg, int unk1, int unk2, int unk3, int unk4, int unk5, int unk6, int unk7, int unk8, int unk9, int unk10, int unk11, int unk12);
	LIBZHL_API void *CollisionMoving(int unk1, float unk2, float unk3, float unk4, float unk5, int unk6, int unk7, int unk8, int unk9, int unk10, int unk11, int unk12, int unk13, int unk14, int unk15, int unk16, int unk17, int unk18, bool unk19);
	LIBZHL_API int SunDamage();
	LIBZHL_API int StartSubExplosion();
	LIBZHL_API int LoadSuperDrones(int unk);
	LIBZHL_API int PrepareSuperDrones();
	LIBZHL_API void *GetArtilleryWeapons(int unk1);
	LIBZHL_API int RenderWeapons();
	LIBZHL_API int OnRender(bool unk1, bool unk2);
	LIBZHL_API int RenderChargeBars();
	LIBZHL_API void *GetAllTargettingPoints(int unk1);
	LIBZHL_API int UpdateEnvironment();
	LIBZHL_API void *GetFires(int unk1, int unk2);
	LIBZHL_API int CheckCrystalAugment(int unk1, int unk2);
	LIBZHL_API bool DamageArea(int unk1, int unk2, int unk3, int unk4, int unk5, int unk6, int unk7, int unk8, int unk9, int unk10, bool unk11, int unk12, int unk13, int64_t unk14, int unk15, bool unk16);
	LIBZHL_API int PrepareSuperBarrage();
	LIBZHL_API void *SelectRandomCrew(int unk1, int unk2, char *unk3);
	LIBZHL_API int CreateSpaceDrone(const DroneBlueprint *blueprint);
	LIBZHL_API int CreateDrone(const DroneBlueprint *blueprint);
	LIBZHL_API int AddDrone(const DroneBlueprint *blueprint, int unk1);
	LIBZHL_API int CreateArmory();
	LIBZHL_API int CheckDlcEnabled();
	LIBZHL_API int AddSystem(int systemId);
	LIBZHL_API bool CreateSystems();
	LIBZHL_API void *GetMaxSystemLevel(int systemId);
	LIBZHL_API bool DamageBeam(int unk1, int unk2, size_t unk3, int unk4, int unk5, int unk6, int unk7, int unk8, int unk9, int unk10, int unk11, int unk12, bool unk13, int unk14, bool unk15);
	LIBZHL_API int UpdateCrewmembers();
	LIBZHL_API bool PowerDrone(Drone *drone, int unk1, bool unk2, bool unk3);
	LIBZHL_API int ImportBattleState(int unk1);
	LIBZHL_API int KillEveryone(bool unk);
	LIBZHL_API int OnLoop();
	LIBZHL_API int SaveToBlueprint(int unk1, bool unk2);
	LIBZHL_API int ExportShip(int unk);
	LIBZHL_API int KillCrew(const CrewBlueprint *blueprint);
	LIBZHL_API int AddCrewMember(char *unk1, char *unk2, bool unk3, int unk4, bool unk5);
	LIBZHL_API int AddInitialCrew(void *unk);
	LIBZHL_API int Restart();
	LIBZHL_API bool OnInit(const ShipBlueprint *blueprint, int unk);
	LIBZHL_API int ImportShip(int unk);
	LIBZHL_API int destructor();
	LIBZHL_API int constructor(int unk);
	
};

struct SpaceDrone
{
};

struct Equipment;

struct Equipment
{
	LIBZHL_API int OnLoop();
	
};

struct CloakingSystem
{
};

struct SCrewStats
{
};

struct ResourceControl;

struct ResourceControl
{
	LIBZHL_API static int __stdcall PreloadImage(void *lump, int size);
	LIBZHL_API int GetFontData(int fontSize);
	
};

struct freetype
{
	static float easy_measurePrintLines(int fontType, float x, float y, int unk, char* text)
	{
		int font = ((ResourceControl*)0x007A7720)->GetFontData(fontType);
		return freetype::measurePrintLines(font, floor(x), floor(y), unk, fontType, text);
	}
	
	static void easy_print(int fontType, float x, float y, char* text)
	{
		int font = ((ResourceControl*)0x007A7720)->GetFontData(fontType);
		freetype::print(font, x, y, text);
	}
	
	static void easy_printRightAlign(int fontType, float x, float y, char* text) 
	{
		double minus = freetype::easy_measurePrintLines(fontType, 0.f, 0.f, 1000, text);
		freetype::easy_print(fontType, x - minus, y, text);
	}

	LIBZHL_API static int64_t __stdcall easy_print(int fontType, float x, float y, char **text);
	LIBZHL_API static int64_t __stdcall easy_printAutoNewlines(int fontType, float x, float y, int unk, std_string *text);
	LIBZHL_API static int64_t __stdcall print(int fontData, float x, float y, char *text);
	LIBZHL_API static int __stdcall printCenter(int fontData, float x, float y, char *text);
	LIBZHL_API static int64_t __stdcall measurePrintLines(int fontData, int x, int y, int unk1, int unk2, char *text);
	
};

struct RoomShape
{
	float unk1;
	float unk2;
	float unk3;
	float unk4;
};

struct CEvent
{
	LIBZHL_API static bool __stdcall GetShiftState();
	LIBZHL_API static bool __stdcall GetCtrlState();
	
	int field_0;
};

struct CApp;

struct CApp
{
	LIBZHL_API int OnMButtonDown(int unk1, int unk2);
	LIBZHL_API int OnExit();
	LIBZHL_API int OnRequestExit();
	LIBZHL_API bool OnEvent(int event);
	LIBZHL_API bool OnInputBlur();
	LIBZHL_API int OnInputFocus();
	LIBZHL_API int OnKeyUp(int key);
	LIBZHL_API int OnKeyDown(int key);
	LIBZHL_API int constructor();
	LIBZHL_API int OnLoop();
	LIBZHL_API int OnRender();
	LIBZHL_API bool SetupWindow();
	LIBZHL_API int OnInit();
	LIBZHL_API void OnExecute();
	LIBZHL_API int64_t TranslateMouse(int x, int y);
	LIBZHL_API void OnRButtonUp(int x, int y);
	LIBZHL_API int OnRButtonDown(int x, int y);
	LIBZHL_API int OnMouseMove(int x, int y, int unk4, int unk5, int unk6, int unk7, int unk8);
	LIBZHL_API void OnLButtonDown(int x, int y);
	LIBZHL_API bool OnLButtonUp(int x, int y);
	
	CEvent field_0;
	char field_4;
	char gap_5[3];
	int field_8;
	int field_C;
	int _commandGui;
	int field_14;
	MainMenu _mainMenu;
	char field_1A08;
	char field_1A09;
	char field_1A0A;
	char field_1A0B;
	char field_1A0C;
	char field_1A0D;
	char field_1A0E;
	char field_1A0F;
	int field_1A10;
	float field_1A14;
	float field_1A18;
	int field_1A1C;
	int field_1A20;
	int field_1A24;
	int field_1A28;
	int field_1A2C;
	char field_1A30;
	char field_1A31;
	char bs_1;
	char bs_2;
};

struct EffectsBlueprint
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	char *field_30;
};

struct Description;

struct InfoBox
{
	LIBZHL_API int SetDescription(Description *desc, bool unk);
	
};

struct BatterySystem
{
};

struct CrewAnimation
{
};

struct SectorDescription
{
};

struct CFPS;

struct CFPS
{
	LIBZHL_API void OnLoop();
	
	int field_0;
	int field_4;
	double field_8;
	double field_10;
	float _speedFactor;
	int field_1C;
	int _frameCount;
};

struct WeaponBlueprint : Blueprint
{
	LIBZHL_API int constructor();
	LIBZHL_API int copy(WeaponBlueprint &other);
	
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	char field_58;
	char gap_59[3];
	int field_5C;
	int field_60;
	char field_64;
	char field_65;
	char field_66;
	char gap_67[1];
	int field_68;
	int field_6C;
	int field_70;
	float field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	EffectsBlueprint _effects;
	char *field_BC;
	char *field_C0;
	char *field_C4;
	int field_C8;
	int field_CC;
	int field_D0;
	int field_D4;
	int field_D8;
	int field_DC;
	int field_E0;
	int field_E4;
	int field_E8;
	int field_EC;
	char *field_F0;
	int field_F4;
};

struct CrewCustomizeBox
{
};

struct CrewAnimation;

struct Repairable;
struct CrewTarget;
struct TouchTooltip;

struct CrewMember
{
	LIBZHL_API int SetOutOfGame();
	LIBZHL_API int OnRender(bool unk);
	LIBZHL_API int SaveState(int unk);
	LIBZHL_API int GetSkillFromSystem(int systemId);
	LIBZHL_API int SetResisted(int resisted);
	LIBZHL_API int GetResisted();
	LIBZHL_API int SetSkillProgress(int skillId, int progress);
	LIBZHL_API int GetSkillLevel(int skillId);
	LIBZHL_API int IncreaseSkill(int skillId);
	LIBZHL_API int GetSkillProgress(int skillId);
	LIBZHL_API bool BadAtCombat();
	LIBZHL_API bool DirectModifyHealth(int edx, float health);
	LIBZHL_API bool ApplyDamage(int edx, float health);
	LIBZHL_API bool ModifyHealth(float health);
	LIBZHL_API void SavePosition();
	LIBZHL_API void ClearPosition();
	LIBZHL_API void *GetSavedPosition();
	LIBZHL_API void SetSavePosition(bool unk1, int unk2, int unk3, int unk4);
	LIBZHL_API void StopRepairing();
	LIBZHL_API bool Repairing();
	LIBZHL_API bool Sabotaging();
	LIBZHL_API int64_t SelectSabotageTarget();
	LIBZHL_API bool RepairingSoundEffect();
	LIBZHL_API bool CheckSkills();
	LIBZHL_API bool SetFrozen(bool frozen);
	LIBZHL_API CrewMember *SetFrozenLocation(bool unk);
	LIBZHL_API void SetTask(bool unk1, int unk2, int unk3);
	LIBZHL_API int FindSlot(int unk1, int unk2, int unk3, bool unk4);
	LIBZHL_API bool CheckRoomPath(int unk1, int unk2);
	LIBZHL_API void EmptySlot();
	LIBZHL_API int ClearTask();
	LIBZHL_API double GetMoveSpeed();
	LIBZHL_API unsigned int Restart();
	LIBZHL_API void SetDamageBoost(float boost);
	LIBZHL_API int SetHealthBoost(int boost);
	LIBZHL_API void InitializeSkills();
	LIBZHL_API int SetCloneReady(bool cloneReady);
	LIBZHL_API int Kill(bool unk);
	LIBZHL_API int SetCurrentShip(int unk1);
	LIBZHL_API void CheckFighting();
	LIBZHL_API int SetDeathNumber(int deathCount);
	LIBZHL_API CrewMember *ForceMindControl(bool mindControlled);
	LIBZHL_API int RenderSkillUpAnimation(int unk1, int unk2);
	LIBZHL_API int UpdateHealth();
	LIBZHL_API int64_t GetLocation();
	LIBZHL_API bool AtGoal();
	LIBZHL_API bool AtFinalGoal();
	LIBZHL_API void OnRenderPath();
	LIBZHL_API bool NeedFrozenLocation();
	LIBZHL_API bool IsBusy();
	LIBZHL_API bool SetCurrentSystem(ShipSystem *system);
	LIBZHL_API void OnRenderHealth();
	LIBZHL_API int GetIntegerHealth();
	LIBZHL_API bool WithinRect(int x1, int x2, int y1, int y2);
	LIBZHL_API std::string *GetLongName(int unk);
	LIBZHL_API int SetName(std::string *name, bool unk);
	LIBZHL_API std::string *GetName(int unk);
	LIBZHL_API int SetCurrentTarget(CrewTarget *target, bool unk);
	LIBZHL_API bool ContainsPoint(int unk1, int unk2, int unk3, int unk4);
	LIBZHL_API void SetMedbay(float unk);
	LIBZHL_API int StartTeleport();
	LIBZHL_API int LoadState(int unk);
	LIBZHL_API int StartTeleportArrive();
	LIBZHL_API int Clone();
	LIBZHL_API void CheckForTeleport();
	LIBZHL_API void SetPosition(int x, int y);
	LIBZHL_API bool StartRepair(Repairable *repairing);
	LIBZHL_API int UpdateRepair();
	LIBZHL_API TouchTooltip *GetTooltip(int unk);
	LIBZHL_API TouchTooltip *GetSkillTooltip(int unk1, int unk2, bool unk3, bool unk4, bool unk5);
	LIBZHL_API bool SetPath(int path);
	LIBZHL_API int SetRoomPath(int unk1, int unk2);
	LIBZHL_API bool MoveToRoom(int unk1, int unk2, bool unk3);
	LIBZHL_API bool RestorePosition();
	LIBZHL_API int ClearPath();
	LIBZHL_API double SetRoom(int room);
	LIBZHL_API void SetMindControl(bool mindControlled);
	LIBZHL_API bool GetNewGoal();
	LIBZHL_API void UpdateMovement();
	LIBZHL_API int OnLoop();
	LIBZHL_API int CycleColorLayer(int unk);
	LIBZHL_API CrewMember *SetSex(bool male);
	LIBZHL_API int constructor(const CrewBlueprint &blueprint, int unk1, bool unk2, CrewAnimation *anim);
	
	int _base;
	int _isEnemy;
	int field_8;
	float _posX;
	float _posY;
	int field_14;
	int field_18;
	float _targetPosX;
	float _targetPosY;
	char gap_24[8];
	float _health;
	float _maxHealth;
	float field_34;
	float field_38;
	Point field_3C;
	int field_44;
	int field_48;
	int field_4C;
	Point field_50;
	int field_58;
	char field_5C;
	char gap_5D[11];
	int _sex;
	int field_6C;
	bool _suffocating;
	char gap_71[7];
	int field_78;
	int _roomIndex;
	char gap_80[8];
	int field_88;
	int _targetRoom;
	int field_90;
	Point field_94;
	char _inEnemyShip;
	char _fighting;
	char field_9E;
	char gap_9F[1];
	int field_A0;
	char gap_A4[4];
	char *field_A8;
	char field_AC;
	char gap_AD[51];
	char *field_E0;
	int field_E4;
	char gap_E8[48];
	int _cachedRect;
	char gap_11C[20];
	int field_130;
	int field_134;
	int field_138;
	int field_13C;
	int field_140;
	int field_144;
	char field_148;
	char gap_149[3];
	float field_14C;
	char field_150;
	char field_151;
	char field_152;
	char gap_153[1];
	float field_154;
	int field_158;
	Point field_15C;
	int field_164;
	int field_168;
	int field_16C;
	int field_170;
	int field_174;
	int field_178;
	bool field_17C;
	char gap_17D[3];
	int field_180;
	int field_184;
	int field_188;
	char *field_18C;
	int field_190;
	int field_194;
	int field_198;
	Point field_19C;
	int field_1A4;
	int field_1A8;
	char *_race;
	int field_1B0;
	int field_1B4;
	int field_1B8;
	int field_1BC;
	int field_1C0;
	char gap_1C4[116];
	int field_238;
	char gap_23C[132];
	int field_2C0;
	char gap_2C4[132];
	int field_348;
	int field_34C;
	char field_350;
	char gap_351[3];
	float field_354;
	char field_358;
	char field_359;
	char field_35A;
	char gap_35B[1];
	float field_35C;
	int field_360;
	int field_364;
	int _sCrewStats;
	char gap_36C[32];
	char field_38C;
	char _mindControlled;
	char gap_38E[2];
	int field_390;
	int field_394;
	char gap_398[132];
	int field_41C;
	char gap_420[132];
	int field_4A4;
	int field_4A8;
	int field_4AC;
	int field_4B0;
	int field_4B4;
	int field_4B8;
	int field_4BC;
	int field_4C0;
	int field_4C4;
	Point field_4C8;
	float _stunTime;
	char *field_4D4;
	int field_4D8;
	char gap_4DC[44];
	char *field_508;
	int field_50C;
};

struct Scroller
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	float field_14;
	float field_18;
	int field_1C;
};

struct OxygenSystem
{
	LIBZHL_API static void __stdcall __BS_FUNCTION_DONT_USE();
	LIBZHL_API int OnRender();
	LIBZHL_API int Restart();
	LIBZHL_API int constructor(int unk1, int unk2, int unk3, int unk4);
	LIBZHL_API double GetRefillSpeed();
	LIBZHL_API int ModifyRoomOxygen(int roomId, float oxygen);
	LIBZHL_API int SetRoomOxygen(int roomId, float oxygen);
	LIBZHL_API int ComputeAirLoss(int unk1, float unk2, bool unk3);
	LIBZHL_API int UpdateAirlock(int unk1, int unk2);
	LIBZHL_API int UpdateBreach(int unk1, int unk2, bool unk3);
	LIBZHL_API int EmptyOxygen(int roomId);
	LIBZHL_API int RedistributeOxygen();
	LIBZHL_API int OnLoop();
	
};

struct Door
{
};

struct ShipStatus;

struct ShipStatus
{
	LIBZHL_API int RenderHealth();
	LIBZHL_API int MouseMove(int x, int y);
	LIBZHL_API int OnRender();
	
	Point field_0;
	int field_8;
	int field_C;
	CombatControl *_combatControl;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	int field_88;
	int field_8C;
	int field_90;
	int field_94;
	int field_98;
	int field_9C;
	int field_A0;
	int field_A4;
	int field_A8;
	int field_AC;
	int field_B0;
	int field_B4;
	int field_B8;
	int field_BC;
	int field_C0;
	int field_C4;
	Point field_C8;
	int field_D0;
	int field_D4;
	int field_D8;
	Point field_DC;
	int field_E4;
	int field_E8;
	int field_EC;
	int field_F0;
	int field_F4;
	int field_F8;
	int field_FC;
	int field_100;
	int field_104;
	int field_108;
	int field_10C;
	int field_110;
	int field_114;
	int field_118;
	int field_11C;
	char field_120;
	char gap_121[3];
	int field_124;
	char field_128;
	char field_129;
	char field_12A;
	char gap_12B[1];
	int field_12C;
	int field_130;
	int field_134;
	int field_138;
	char field_13C;
	char gap_13D[3];
	int field_140;
	char field_144;
	char field_145;
	char field_146;
	char gap_147[1];
	int field_148;
	int field_14C;
	char field_150;
	char field_151;
	char gap_152[2];
	Point field_154;
	Point field_15C;
	Point field_164;
	Point field_16C;
};

struct SlideBar
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	char field_10;
	char field_11;
	char gap_12[2];
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	Point field_24;
	Point field_2C;
	int field_34;
	int field_38;
};

struct Drone
{
};

struct EventTemplate
{
	ResourcesTemplate field_0;
	std::string *field_78;
	char gap_7C;
	char gap_7D[3];
	std::string *field_80;
	char field_84;
	char field_85;
	char gap_86[2];
	std::string *field_88;
	char field_8C;
	char gap_8D[3];
	std::string *field_90;
	char gap_94[20];
	char field_A8;
	char field_A9;
	char field_AA;
	char gap_AB[13];
	int field_B8;
	std::string *field_BC;
	char gap_C0[12];
	char field_CC;
	char gap_CD[31];
	std::string *field_EC;
	std::string *field_F0;
	std::string *field_F4;
	std::string *field_F8;
	char gap_FC[8];
	char field_104;
	char bs_1;
	char bs_2;
	char bs_3;
};

struct ShipSystem
{
	static int NameToSystemId(char* a1)
	{
		int result;
		if (strcmp(a1, "shields"))
		{
			if (strcmp(a1, "teleporter"))
			{
				if (strcmp(a1, "sensors"))
				{
					if (strcmp(a1, "engines"))
					{
						if (strcmp(a1, "oxygen"))
						{
							if (strcmp(a1, "medbay"))
							{
								if (strcmp(a1, "pilot"))
								{
									if (strcmp(a1, "doors"))
									{
										if (strcmp(a1, "weapons"))
										{
											if (strcmp(a1, "drones"))
											{
												if (strcmp(a1, "reactor"))
												{
													if (strcmp(a1, "cloaking"))
													{
														if (strcmp(a1, "artillery"))
														{
															if (strcmp(a1, "random"))
															{
																if (strcmp(a1, "room"))
																{
																	if (strcmp(a1, "battery"))
																	{
																		if (strcmp(a1, "clonebay"))
																		{
																			if (strcmp(a1, "mind"))
																			{
																				if (strcmp(a1, "hacking"))
																				{
																					result = -1;
																					if (strcmp(a1, "all") == 0)
																						result = 16;
																				}
																				else
																				{
																					result = 15;
																				}
																			}
																			else
																			{
																				result = 14;
																			}
																		}
																		else
																		{
																			result = 13;
																		}
																	}
																	else
																	{
																		result = 12;
																	}
																}
																else
																{
																	result = 19;
																}
															}
															else
															{
																result = 18;
															}
														}
														else
														{
															result = 11;
														}
													}
													else
													{
														result = 10;
													}
												}
												else
												{
													result = 17;
												}
											}
											else
											{
												result = 4;
											}
										}
										else
										{
											result = 3;
										}
									}
									else
									{
										result = 8;
									}
								}
								else
								{
									result = 6;
								}
							}
							else
							{
								result = 5;
							}
						}
						else
						{
							result = 2;
						}
					}
					else
					{
						result = 1;
					}
				}
				else
				{
					result = 7;
				}
			}
			else
			{
				result = 9;
			}
		}
		else
		{
			result = 0;
		}
		return result;
	}

	LIBZHL_API bool SaveState(FileHelper *fileHelper);
	LIBZHL_API int LoadState(FileHelper *fileHelper);
	LIBZHL_API int GetPowerCap();
	LIBZHL_API void TriggerIonPulse();
	LIBZHL_API char **GetInteriorImageName(int ignore);
	LIBZHL_API int IsMannedBoost();
	LIBZHL_API int GetEffectivePower();
	LIBZHL_API int SetActiveManned(int manned);
	LIBZHL_API bool GetLocked();
	LIBZHL_API bool BlockedBoosted(bool blockedBoosted);
	LIBZHL_API void OnRenderFloor();
	LIBZHL_API int OnRender();
	LIBZHL_API int GetLockCount();
	LIBZHL_API float GetLockTimer(int ignore);
	LIBZHL_API void SetLockTimer(float timer);
	LIBZHL_API int UpgradeSystem(int unk);
	LIBZHL_API int SetRepairOverTime(float repairAmt);
	LIBZHL_API int OnLoop();
	LIBZHL_API static char *__stdcall SystemIdToName(int id);
	LIBZHL_API static int __stdcall NameToSystemId(std_string *name);
	LIBZHL_API int IonDamage(int dmg);
	
	char gap_0[44];
	int field_2C;
	char gap_30[1];
	char field_31;
	char gap_32[2];
	int field_34;
	char field_38;
	char gap_39[3];
	int _power;
	int _maxPower;
	char field_44[96];
	CachedRect field_A4;
	CachedRectOutline field_BC;
	int field_D8;
	int field_DC;
	int field_E0;
	int field_E4;
	char field_E8;
	char field_E9;
	char gap_EA[2];
	int _health;
	int field_F0;
	float field_F4;
	float field_F8;
	char field_FC;
	char field_FD;
	char gap_FE[2];
	int field_100;
	char field_104;
	char gap_105[3];
	int field_108;
	int field_10C;
	int field_110;
	int _lockCount;
	int _lockTimer;
	int field_11C;
	int field_120;
	int field_124;
	char field_128;
	char field_129;
	char gap_12A[2];
	char field_12C;
	char field_12D;
	char field_12E;
	char gap_12F[1];
	char *field_130;
	char gap_134[20];
	int _zoltanPower;
	int field_14C;
	Pointf field_150;
	int field_158;
	int field_15C;
	int field_160;
	char field_164;
	char gap_165[3];
	float field_168;
	char field_16C;
	char field_16D;
	char field_16E;
	char gap_16F[1];
	float field_170;
	int field_174;
	int field_178;
	int _batteryPower;
	int field_180;
	char field_184;
	char field_185;
	char field_186;
	char gap_187[1];
	int field_188;
	int field_18C;
	int field_190;
	int field_194;
	int field_198;
};

struct Shields : ShipSystem
{
	Point field_19C;
	Point field_1A4;
	float field_1AC;
	float field_1B0;
	int field_1B4;
	float field_1B8;
	int field_1BC;
	float field_1C0;
	int _shieldLayers;
	int _shieldMax;
	int _energyLayers;
	int field_1D0;
	float field_1D4;
	char field_1D8;
	char gap_1D9[3];
	int field_1DC;
	int field_1E0;
	int field_1E4;
	int field_1E8;
	int field_1EC;
	char field_1F0;
	char gap_1F1[3];
	float field_1F4;
	char field_1F8;
	char field_1F9;
	char field_1FA;
	char gap_1FB[1];
	float field_1FC;
	float field_200;
	char field_204;
	char gap_205[3];
	Pointf field_208;
	int field_210;
	int field_214;
	char field_218;
	char gap_219[3];
	float field_21C;
	char field_220;
	char field_221;
	char field_222;
	char gap_223[1];
	float field_224;
	int field_228;
	int field_22C;
	int field_230;
	int field_234;
	int field_238;
	int field_23C;
	int field_240;
	int field_244;
	char field_248;
	char gap_249[3];
	float field_24C;
	int field_250;
	int field_254;
	int field_258;
	int field_25C;
	char field_260;
	char gap_261[3];
	float field_264;
	char field_268;
	char field_269;
	char gap_26A[2];
	int field_26C;
	int field_270;
	Point field_274;
	int field_27C;
};

struct ControlsScreen
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	Button field_10;
	Button field_78;
	Button field_E0;
	Point field_148;
	Button field_150;
	Button field_1B8;
	int field_220;
	char field_224;
	char gap_225[3];
	int field_228;
};

struct AsteroidGenerator
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	float field_30;
	int field_34;
	int field_38;
	float field_3C;
	int field_40;
	int field_44;
	float field_48;
	int field_4C;
	int field_50;
	float field_54;
	int field_58;
	int field_5C;
	float field_60;
	int field_64;
	int field_68;
	float field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	char field_88;
	char gap_89[3];
	int field_8C;
};

struct CrewBox
{
};

struct Colorf
{
	float r;
	float g;
	float b;
	float a;
};

struct EventGenerator
{
};

struct Projectile
{
};

struct HackingSystem
{
};

struct OuterHull
{
};

struct NodeConnection
{
};

LIBZHL_API int __stdcall GetValue(int unk1, void *resource, int difficulty, int unk2);

extern LIBZHL_API float *__ptr_g_CloneSkillLossPercent;
#define g_CloneSkillLossPercent (*__ptr_g_CloneSkillLossPercent)

inline float Lerp(float c, float a, float b) {return (1.f-c)*a + c*b;}
inline float InverseLerp(float c, float a, float b) {return (c-a)/(b-a);}
inline float Clamp(float c, float a, float b) {return c<a ? a : (c>b ? b : c);}
inline float Remap(float x, float a1, float b1, float a2, float b2, bool clamp = false)
{
	return Lerp(clamp ? Clamp(InverseLerp(x, a1, b1), 0.f, 1.f) : InverseLerp(x, a1, b1), a2, b2);
}

inline float Round(float f)
{
	return f >= 0.f ? floor(f+0.5f) : ceil(f-0.5f);
}

inline float NormalizeAngle(float ang)
{
	while(ang >= 180.f) ang -= 360.f;
	while(ang < -180.f) ang += 360.f;
	return ang;
}

inline float LerpAngle(float c, float a, float b)
{
	return NormalizeAngle(a + c * NormalizeAngle(b - a));
}

inline float Approach(float c, float a, float b)
{
	if(fabs(b-a) <= c)
		return b;
	else if(b > a)
		return a + c;
	else
		return a - c;
}

inline float ApproachAngle(float c, float a, float b)
{
	float d = NormalizeAngle(b-a);
	if(fabs(d) <= c)
		return b;
	else if(d > 0)
		return NormalizeAngle(a+c);
	else
		return NormalizeAngle(a-c);
}

