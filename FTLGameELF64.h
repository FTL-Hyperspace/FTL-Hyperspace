#pragma once

#pragma warning( disable : 4722 )

#define LIBZHL_API 

#ifdef _WIN32
    #define LIBZHL_INTERFACE __declspec(novtable)
    __declspec(noreturn) inline void __cdecl __NOP() {}
    #define LIBZHL_PLACEHOLDER {__NOP();}
#elif defined(__linux__)
    #define LIBZHL_INTERFACE
    #define LIBZHL_PLACEHOLDER {\
        _Pragma("GCC diagnostic push") \
        _Pragma("GCC diagnostic ignored \"-Wreturn-type\"") \
        (void)0; } \
        _Pragma("GCC diagnostic pop")
    #define __stdcall
#endif


struct AchievementTracker;

struct AnimationTracker;

struct LIBZHL_INTERFACE AnimationTracker
{
	virtual ~AnimationTracker() {}
	virtual void Update() LIBZHL_PLACEHOLDER
	float time;
	bool loop;
	float current_time;
	bool running;
	bool reverse;
	bool done;
	float loopDelay;
	float currentDelay;
};

struct CAchievement;
struct GL_Primitive;

struct AchievementTracker
{
	LIBZHL_API void __stdcall DO_NOT_HOOK_1();
	LIBZHL_API bool GetFlag(const std::string &flagName);
	LIBZHL_API std::vector<CAchievement*> GetShipAchievements(const std::string &ship);
	LIBZHL_API int GetShipMarker(const std::string &baseName, const std::string &thisName);
	LIBZHL_API void LoadAchievementDescriptions();
	LIBZHL_API void LoadProfile(int file, int version);
	LIBZHL_API void OnLanguageChange();
	LIBZHL_API void ResetFlags();
	LIBZHL_API void SaveProfile(int file);
	LIBZHL_API void SetAchievement(const std::string &achievement, bool noPopup, bool sendToServer);
	LIBZHL_API void SetFlag(const std::string &flagName);
	LIBZHL_API void SetSectorEight();
	LIBZHL_API void SetTooltip(CAchievement *ach);
	LIBZHL_API void SetVictoryAchievement();
	LIBZHL_API void UnlockShip(int shipId, int shipType);
	
	std::vector<CAchievement*> recentlyUnlocked;
	std::vector<std::vector<CAchievement*>> shipUnlocks;
	std::vector<CAchievement*> achievements;
	std::map<std::string, int> gameFlags;
	AnimationTracker achievementPopup;
	GL_Primitive *popupBox;
	GL_Primitive *achievementBox[2];
	GL_Primitive *achievementOverlay[2];
	std::string currentShip;
};

struct Algae
{
};

struct AnaerobicAlien
{
};

struct AnaerobicAnimation
{
};

struct AnimationDescriptor
{
	int numFrames;
	int imageWidth;
	int imageHeight;
	int stripStartY;
	int stripStartX;
	int frameWidth;
	int frameHeight;
};

struct GL_Texture;

struct Pointf
{
	float x;
	float y;
};

struct Animation
{
	GL_Texture *animationStrip;
	AnimationDescriptor info;
	AnimationTracker tracker;
	Pointf position;
	std::string soundForward;
	std::string soundReverse;
	bool randomizeFrames;
	float fScale;
	float fYStretch;
	int currentFrame;
	bool bAlwaysMirror;
	std::vector<std::vector<std::string>> soundQueue;
	float fadeOut;
	float startFadeOut;
	std::string animName;
	int mask_x_pos;
	int mask_x_size;
	int mask_y_pos;
	int mask_y_size;
	GL_Primitive *primitive;
	GL_Primitive *mirroredPrimitive;
};

struct AnimationSheet
{
	int w;
	int h;
	int frameHeight;
	int frameWidth;
	GL_Texture *imageId;
};

struct CachedPrimitive
{
	void *vptr;
	GL_Primitive *primitive;
};

struct CachedImage : CachedPrimitive
{
	std::string imageName;
	GL_Texture *texture;
	int x;
	int y;
	float wScale;
	float hScale;
	float x_start;
	float y_start;
	float x_size;
	float y_size;
	float rotation;
	bool mirrored;
};

struct Point
{
	int x;
	int y;
};

struct WeaponMount
{
	Point position;
	bool mirror;
	bool rotate;
	int slide;
	int gib;
};

struct WeaponAnimation
{
	Animation anim;
	bool bFireShot;
	bool bFiring;
	float fChargeLevel;
	int iChargedFrame;
	int iFireFrame;
	bool bMirrored;
	bool bRotation;
	Point fireLocation;
	bool bPowered;
	Point mountPoint;
	Point renderPoint;
	Point fireMountVector;
	AnimationTracker slideTracker;
	int slideDirection;
	CachedImage iChargeImage;
	Animation explosionAnim;
	WeaponMount mount;
	float fDelayChargeTime;
	Animation boostAnim;
	int boostLevel;
	bool bShowCharge;
	float fActualChargeLevel;
	int iChargeOffset;
	int iChargeLevels;
	int currentOffset;
	CachedImage chargeBox;
	CachedImage chargeBar;
	int iHackLevel;
	Animation hackSparks;
	bool playerShip;
};

struct AnimationControl
{
	std::map<std::string, AnimationSheet> animSheets;
	std::map<std::string, Animation> animations;
	std::map<std::string, WeaponAnimation> weapAnimations;
};

struct GL_Color
{
	float r;
	float g;
	float b;
	float a;
};

struct GenericButton;

struct Globals
{
	struct Ellipse
	{
		Point center;
		float a;
		float b;
	};
	
	struct Rect
	{
		int x;
		int y;
		int w;
		int h;
	};
	
};

struct TouchTooltip;

struct ArmamentBox
{
	void *vptr;
	std::vector<GL_Primitive*> background;
	GL_Primitive *emptyBackground;
	GL_Primitive *hoverHighlight;
	GL_Primitive *outline;
	GL_Primitive *emptyOutline;
	GL_Primitive *powerBarGlow[4];
	GL_Primitive *iconBackground;
	GL_Primitive *iconInsetBackground;
	GL_Primitive *icon;
	GL_Primitive *iconDoubleSize;
	std::string iconName;
	std::string iconBackgroundName;
	Point lastIconPos;
	Point location;
	int xOffset;
	Point largeIconOffset;
	Point nameOffset;
	int nameWidth;
	bool mouseHover;
	bool touchHover;
	bool touchHighlight;
	bool selected;
	int hotKey;
	int activeTouch;
	TouchTooltip *touchTooltip;
	Animation hackAnimation;
	GL_Primitive *touchButtonBorder;
	Globals::Rect touchButtonBorderRect;
	float touchButtonSlidePos;
	std::vector<GenericButton*> touchButtons;
	Globals::Rect touchButtonHitbox;
	GL_Color iconColor;
	bool droneVariation;
	bool bIoned;
};

struct ArmamentBox;
struct CommandGui;

struct ShipManager;

struct ArmamentControl
{
	void *vptr;
	int systemId;
	CommandGui *gui;
	ShipManager *shipManager;
	std::vector<ArmamentBox*> boxes;
	Point location;
	Globals::Rect touchHitBox;
	GL_Texture *holderImage;
	GL_Primitive *holder;
	GL_Primitive *holderTab;
	std::vector<GL_Primitive*> smallBoxHolder;
	std::vector<Animation> smallBoxHackAnim;
	int smallBoxHolderTop;
	bool bOpen;
	Point lastMouse;
	Point currentMouse;
	int draggingBox;
	int draggingTouch;
	bool bDragging;
	int iLastSwapSlot;
	bool bTutorialFlash;
	int iFlashSlot;
	int activeTouch;
};

struct ArtillerySystem;

struct ShipSystem;
struct SystemBox;

struct TapBoxFrame
{
	Point location;
	bool useWideBox;
	int boxHeight;
	std::vector<int> buttonHeights;
	std::vector<GL_Primitive*> primitives;
	Globals::Rect hitBox;
};

struct TextString
{
	std::string data;
	bool isLiteral;
	uint8_t gap_ex[4];
};

struct WarningMessage
{
	void *vptr;
	AnimationTracker tracker;
	Point position;
	bool isImage;
	TextString text;
	bool centerText;
	GL_Color textColor;
	bool useWarningLine;
	CachedImage image;
	std::string imageName;
	bool flash;
	std::string sound;
	AnimationTracker flashTracker;
};

struct LIBZHL_INTERFACE SystemBox
{
	virtual ~SystemBox() {}
	virtual void destroy() LIBZHL_PLACEHOLDER
	virtual bool HasButton() LIBZHL_PLACEHOLDER
	virtual int GetCooldownBarHeight() LIBZHL_PLACEHOLDER
	virtual int GetHeightModifier() LIBZHL_PLACEHOLDER
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	virtual void OnRender(bool unk) LIBZHL_PLACEHOLDER
	virtual bool GetMouseHover() LIBZHL_PLACEHOLDER
	virtual bool MouseMove(int x, int y) LIBZHL_PLACEHOLDER
	virtual int MouseClick(bool unk) LIBZHL_PLACEHOLDER
	virtual int MouseRightClick(bool unk) LIBZHL_PLACEHOLDER
	virtual void OnTouch() LIBZHL_PLACEHOLDER
	virtual void CancelTouch() LIBZHL_PLACEHOLDER
	virtual void CloseTapBox() LIBZHL_PLACEHOLDER
	virtual void IsTouchTooltipOpen() LIBZHL_PLACEHOLDER
	virtual void IsTouchTooltipActive() LIBZHL_PLACEHOLDER
	virtual void CloseTouchTooltip(bool unk) LIBZHL_PLACEHOLDER
	virtual void KeyDown(int key, bool unk) LIBZHL_PLACEHOLDER
	Point location;
	GL_Primitive *timerCircle[10];
	GL_Primitive *timerLines;
	GL_Primitive *timerStencil;
	int lastTimerStencilCount;
	GL_Primitive *brokenIcon;
	GL_Primitive *lockIcon;
	GL_Primitive *hackIcon;
	ShipSystem *pSystem;
	bool bShowPower;
	float powerAlpha;
	bool mouseHover;
	int activeTouch;
	Point touchInitialOffset;
	bool tapped;
	bool draggingPower;
	int dragInitialPower;
	float lastDragSpeed;
	int lastDragY;
	double lastDragTime;
	WarningMessage warning;
	int topPower;
	Globals::Rect hitBox;
	int hitBoxTop;
	bool hitBoxTopWasSet;
	GL_Texture *wireImage;
	bool bSimplePower;
	bool bPlayerUI;
	bool useLargeTapIcon;
	Point largeTapIconOffset;
	std::vector<int> tapButtonHeights;
	int tapButtonOffsetY;
	int cooldownOffsetY;
	float keyPressed;
	TouchTooltip *touchTooltip;
	TapBoxFrame tapBoxFrame;
	bool lockedOpen;
};

struct CooldownSystemBox : SystemBox
{
	GL_Primitive *box[5];
	GL_Texture *bar[5];
	Point boxPosition;
	bool roundDown;
	GL_Primitive *barPrimitive;
	int lastBarHeight;
	int lastBarTop;
};

struct ArtilleryBox : CooldownSystemBox
{
	ArtillerySystem *artSystem;
	Point buttonOffset;
};

struct ProjectileFactory;

struct CachedRect : CachedPrimitive
{
	int x;
	int y;
	int w;
	int h;
};

struct CachedRectOutline : CachedPrimitive
{
	int x;
	int y;
	int w;
	int h;
	int thickness;
};

struct ShipObject
{
	void *vptr;
	int iShipId;
};

struct TimerHelper
{
	int maxTime;
	int minTime;
	float currTime;
	float currGoal;
	bool loop;
	bool running;
};

struct WeaponBlueprint;

struct LIBZHL_INTERFACE ShipSystem
{
	virtual ~ShipSystem() {}
	virtual void SetSelected(int selectedState) LIBZHL_PLACEHOLDER
	virtual int GetSelected() LIBZHL_PLACEHOLDER
	virtual bool CompletelyDestroyed() LIBZHL_PLACEHOLDER
	virtual std::string *GetName() LIBZHL_PLACEHOLDER
	virtual void SetName(std::string &name) LIBZHL_PLACEHOLDER
	virtual void Repair() LIBZHL_PLACEHOLDER
	virtual bool PartialRepair(float amount, bool unk) LIBZHL_PLACEHOLDER
	virtual bool PartialDamage(float damage) LIBZHL_PLACEHOLDER
	virtual bool NeedsRepairing() LIBZHL_PLACEHOLDER
	virtual bool Functioning() LIBZHL_PLACEHOLDER
	virtual bool CanBeSabotaged() LIBZHL_PLACEHOLDER
	virtual float GetDamage() LIBZHL_PLACEHOLDER
	virtual void *GetLocation() LIBZHL_PLACEHOLDER
	virtual void *GetGridLocation() LIBZHL_PLACEHOLDER
	virtual void SetDamage(float damage) LIBZHL_PLACEHOLDER
	virtual void SetMaxDamage(float maxDamage) LIBZHL_PLACEHOLDER
	virtual void SetLocation(Point pos) LIBZHL_PLACEHOLDER
	virtual void OnRenderHighlight() LIBZHL_PLACEHOLDER
	virtual int GetId() LIBZHL_PLACEHOLDER
	virtual bool IsRoomBased() LIBZHL_PLACEHOLDER
	virtual int GetRoomId() LIBZHL_PLACEHOLDER
	virtual bool Ioned() LIBZHL_PLACEHOLDER
	virtual void SetRoomId() LIBZHL_PLACEHOLDER
	virtual void SetHackingLevel(int level) LIBZHL_PLACEHOLDER
	virtual void ForceBatteryPower(int power) LIBZHL_PLACEHOLDER
	virtual void RemoveBatteryPower() LIBZHL_PLACEHOLDER
	virtual WeaponBlueprint *GetWeaponInfo() LIBZHL_PLACEHOLDER
	virtual std::string *GetOverrideTooltip() LIBZHL_PLACEHOLDER
	virtual void CheckMaxPower() LIBZHL_PLACEHOLDER
	virtual void SetBonusPower(int unk1, int unk2) LIBZHL_PLACEHOLDER
	virtual void AddDamage(int damage) LIBZHL_PLACEHOLDER
	virtual bool ForceDecreasePower(int power) LIBZHL_PLACEHOLDER
	virtual bool ForceIncreasePower(int power) LIBZHL_PLACEHOLDER
	virtual void StopHacking() LIBZHL_PLACEHOLDER
	virtual void OnRender() LIBZHL_PLACEHOLDER
	virtual void OnRenderFloor() LIBZHL_PLACEHOLDER
	virtual void OnRenderEffects() LIBZHL_PLACEHOLDER
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	virtual bool GetNeedsPower() LIBZHL_PLACEHOLDER
	virtual void Restart() LIBZHL_PLACEHOLDER
	virtual bool Clickable() LIBZHL_PLACEHOLDER
	virtual bool Powered() LIBZHL_PLACEHOLDER
	virtual void ShipDestroyed() LIBZHL_PLACEHOLDER
	int selectedState;
	ShipObject _shipObj;
	float fDamage;
	Point pLoc;
	float fMaxDamage;
	std::string name;
	int roomId;
	int iRepairCount;
	int iSystemType;
	bool bNeedsManned;
	bool bManned;
	uint8_t gap_ex_1[4];
	int iActiveManned;
	bool bBoostable;
	uint8_t gap_ex_2[4];
	std::pair<int, int> powerState;
	int iRequiredPower;
	GL_Texture *imageIcon;
	GL_Primitive *iconPrimitive;
	GL_Primitive *iconBorderPrimitive;
	GL_Primitive *iconPrimitives[20];
	CachedRect partialDamageRect;
	CachedRectOutline lockOutline;
	Globals::Rect roomShape;
	bool bOnFire;
	bool bBreached;
	std::pair<int, int> healthState;
	float fDamageOverTime;
	float fRepairOverTime;
	bool damagedLastFrame;
	bool repairedLastFrame;
	int originalPower;
	bool bNeedsPower;
	int iTempPowerCap;
	int iTempPowerLoss;
	int iTempDividePower;
	int iLockCount;
	TimerHelper lockTimer;
	bool bExploded;
	bool bOccupied;
	bool bFriendlies;
	std::string interiorImageName;
	GL_Primitive *interiorImage;
	GL_Primitive *interiorImageOn;
	GL_Primitive *interiorImageManned;
	GL_Primitive *interiorImageMannedFancy;
	int lastUserPower;
	int iBonusPower;
	int iLastBonusPower;
	Pointf location;
	int bpCost;
	AnimationTracker flashTracker;
	int maxLevel;
	int iBatteryPower;
	int iHackEffect;
	bool bUnderAttack;
	bool bLevelBoostable;
	bool bTriggerIon;
	std::vector<Animation> damagingEffects;
	int computerLevel;
};

struct Targetable;

struct ArtillerySystem : ShipSystem
{
	ProjectileFactory *projectileFactory;
	Targetable *target;
	bool bCloaked;
};

struct Collideable
{
	void *vptr;
};

struct Damage
{
	int iDamage;
	int iShieldPiercing;
	int fireChance;
	int breachChance;
	int stunChance;
	int iIonDamage;
	int iSystemDamage;
	int iPersDamage;
	bool bHullBuster;
	int ownerId;
	int selfId;
	bool bLockdown;
	bool crystalShard;
	bool bFriendlyFire;
	int iStun;
};

struct DamageParameter
{
	int iDamage;
	int iShieldPiercing;
	int fireChance;
	int breachChance;
	int stunChance;
	int iIonDamage;
	int iSystemDamage;
	int iPersDamage;
	int hullBusterMask;
	int ownerId;
	int selfId;
	int lockdownShardFriendlyFireMask;
	int iStun;
};

struct ShieldPower
{
	int first;
	int second;
	std::pair<int, int> super;
};

struct LIBZHL_INTERFACE Targetable
{
	virtual ~Targetable() {}
	virtual Pointf GetWorldCenterPoint() LIBZHL_PLACEHOLDER
	virtual Pointf GetRandomTargettingPoint(bool unk) LIBZHL_PLACEHOLDER
	virtual std::vector<Pointf> GetAllTargettingPoints() LIBZHL_PLACEHOLDER
	virtual Globals::Ellipse GetShieldShape() LIBZHL_PLACEHOLDER
	virtual ShieldPower GetShieldPower() LIBZHL_PLACEHOLDER
	virtual int GetSpaceId() LIBZHL_PLACEHOLDER
	virtual Pointf GetSpeed() LIBZHL_PLACEHOLDER
	virtual int GetOwnerId() LIBZHL_PLACEHOLDER
	virtual int GetSelfId() LIBZHL_PLACEHOLDER
	virtual bool IsCloaked() LIBZHL_PLACEHOLDER
	virtual void DamageTarget(Pointf pos, DamageParameter damage) LIBZHL_PLACEHOLDER
	virtual bool GetIsDying() LIBZHL_PLACEHOLDER
	virtual bool GetIsJumping() LIBZHL_PLACEHOLDER
	virtual bool ValidTarget() LIBZHL_PLACEHOLDER
	virtual Globals::Rect GetShape() LIBZHL_PLACEHOLDER
	int type;
	bool hostile;
	bool targeted;
};

struct Projectile : Collideable
{
	Targetable _targetable;
	Pointf position;
	Pointf last_position;
	float speed_magnitude;
	Pointf target;
	float heading;
	int ownerId;
	unsigned int selfId;
	Damage damage;
	float lifespan;
	int destinationSpace;
	int currentSpace;
	int targetId;
	bool dead;
	uint8_t gap_ex_1[4];
	Animation death_animation;
	Animation flight_animation;
	Pointf speed;
	bool missed;
	bool hitTarget;
	uint8_t gap_ex_2[4];
	std::string hitSolidSound;
	std::string hitShieldSound;
	std::string missSound;
	float entryAngle;
	bool startedDeath;
	bool passedTarget;
	bool bBroadcastTarget;
	AnimationTracker flashTracker;
	GL_Color color;
};

struct Asteroid : Projectile
{
	GL_Texture *imageId;
	float angle;
};

struct Projectile;

struct RandomAmount
{
	int min;
	int max;
	float chanceNone;
};

struct AsteroidGenerator
{
	std::queue<Projectile*> asteroidQueue;
	RandomAmount spawnRate[3];
	RandomAmount stateLength[3];
	int numberOfShips;
	int iState;
	int currentSpace;
	int iNextDirection;
	float fStateTimer;
	float timer;
	bool bRunning;
	int initShields;
};

struct Blueprint;

struct Description
{
	TextString title;
	TextString shortTitle;
	TextString description;
	int cost;
	int rarity;
	int baseRarity;
	int bp;
	bool locked;
	TextString tooltip;
	std::string tip;
};

struct LIBZHL_INTERFACE Blueprint
{
	virtual ~Blueprint() {}
	virtual void RenderIcon(float unk) LIBZHL_PLACEHOLDER
	virtual std::string GetNameLong() LIBZHL_PLACEHOLDER
	virtual std::string GetNameShort() LIBZHL_PLACEHOLDER
	virtual int GetType() LIBZHL_PLACEHOLDER
	std::string name;
	Description desc;
	int type;
};

struct AugmentBlueprint : Blueprint
{
	float value;
	bool stacking;
};

struct DroneSystem;
struct EquipmentBox;

struct AugmentBlueprint;
struct CrewMember;
struct Drone;

struct EquipmentBoxItem
{
	ProjectileFactory *pWeapon;
	Drone *pDrone;
	CrewMember *pCrew;
	const AugmentBlueprint *augment;
};

struct WeaponSystem;

struct LIBZHL_INTERFACE EquipmentBox
{
	virtual ~EquipmentBox() {}
	virtual void SetPosition(Point pos) LIBZHL_PLACEHOLDER
	virtual void OnRender(bool empty) LIBZHL_PLACEHOLDER
	virtual void RenderLabels(bool empty) LIBZHL_PLACEHOLDER
	virtual void RenderIcon(bool empty) LIBZHL_PLACEHOLDER
	virtual void SetShipManager(ShipManager *ship) LIBZHL_PLACEHOLDER
	virtual void MouseMove(int x, int y) LIBZHL_PLACEHOLDER
	virtual void OnTouch() LIBZHL_PLACEHOLDER
	virtual void UpdateBoxImage(bool unk) LIBZHL_PLACEHOLDER
	virtual void Restart() LIBZHL_PLACEHOLDER
	virtual void AddItem(EquipmentBoxItem item) LIBZHL_PLACEHOLDER
	virtual void RemoveItem() LIBZHL_PLACEHOLDER
	virtual char CanHoldWeapon() LIBZHL_PLACEHOLDER
	virtual char CanHoldDrone() LIBZHL_PLACEHOLDER
	virtual char CanHoldAugment() LIBZHL_PLACEHOLDER
	virtual void CheckContents() LIBZHL_PLACEHOLDER
	virtual int GetType(bool unk) LIBZHL_PLACEHOLDER
	virtual char IsCargoBox() LIBZHL_PLACEHOLDER
	virtual char CanHoldCrew() LIBZHL_PLACEHOLDER
	virtual char CanDoJob() LIBZHL_PLACEHOLDER
	GL_Primitive *blocked_overlay;
	GL_Color overlayColor;
	std::string imageName;
	GL_Primitive *empty;
	GL_Primitive *full;
	GL_Primitive *selected_empty;
	GL_Primitive *selected_full;
	WeaponSystem *weaponSys;
	DroneSystem *droneSys;
	Point location;
	Globals::Rect hitBox;
	EquipmentBoxItem item;
	bool bMouseHovering;
	bool bGlow;
	bool bBlocked;
	int slot;
	bool bLocked;
	int value;
	bool bPermanentLock;
	bool blockDetailed;
};

struct AugmentEquipBox : EquipmentBox
{
	ShipManager *ship;
};

struct LIBZHL_INTERFACE GenericButton
{
	virtual ~GenericButton() {}
	virtual void Reset() LIBZHL_PLACEHOLDER
	virtual void SetLocation(Point pos) LIBZHL_PLACEHOLDER
	virtual void SetHitBox(Globals::Rect rect) LIBZHL_PLACEHOLDER
	virtual void SetActive(bool active) LIBZHL_PLACEHOLDER
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	virtual void OnRender() LIBZHL_PLACEHOLDER
	virtual bool MouseMove(int x, int y, bool silent) LIBZHL_PLACEHOLDER
	virtual void OnClick() LIBZHL_PLACEHOLDER
	virtual void OnRightClick() LIBZHL_PLACEHOLDER
	virtual void OnTouch() LIBZHL_PLACEHOLDER
	virtual void ResetPrimitives() LIBZHL_PLACEHOLDER
	Point position;
	Globals::Rect hitbox;
	bool allowAnyTouch;
	bool touchSelectable;
	bool bRenderOff;
	bool bRenderSelected;
	bool bFlashing;
	AnimationTracker flashing;
	bool bActive;
	bool bHover;
	bool bActivated;
	bool bSelected;
	int activeTouch;
};

struct Button : GenericButton
{
	GL_Texture *images[3];
	GL_Primitive *primitives[3];
	Point imageSize;
	bool bMirror;
};

struct Equipment;
struct InfoBox;

struct StoreBox;

struct LIBZHL_INTERFACE StoreBox
{
	virtual ~StoreBox() {}
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	virtual void OnRender() LIBZHL_PLACEHOLDER
	virtual void MouseMove(int, int) LIBZHL_PLACEHOLDER
	virtual void MouseClick(int, int) LIBZHL_PLACEHOLDER
	virtual void OnTouch() LIBZHL_PLACEHOLDER
	virtual void Activate() LIBZHL_PLACEHOLDER
	virtual void Purchase() LIBZHL_PLACEHOLDER
	virtual int SetInfoBox(InfoBox&, int) LIBZHL_PLACEHOLDER
	virtual bool CanHold() LIBZHL_PLACEHOLDER
	virtual bool RequiresConfirm() LIBZHL_PLACEHOLDER
	virtual void Confirm(bool) LIBZHL_PLACEHOLDER
	virtual TextString GetConfirmText() LIBZHL_PLACEHOLDER
	virtual int GetExtraData() LIBZHL_PLACEHOLDER
	virtual void SetExtraData(int) LIBZHL_PLACEHOLDER
	int itemId;
	int itemBox;
	std::string buttonImage;
	Button button;
	GL_Primitive *symbol;
	Description desc;
	int count;
	int cost_position;
	ShipManager *shopper;
	Equipment *equipScreen;
	Blueprint *pBlueprint;
	bool bEquipmentBox;
	float fIconScale;
	Point pushIcon;
};

struct AugmentStoreBox : StoreBox
{
	AugmentBlueprint *blueprint;
};

struct BatterySystem;

struct BatteryBox : CooldownSystemBox
{
	BatterySystem *batterySystem;
	Button batteryButton;
	Point buttonOffset;
};

struct BatterySystem : ShipSystem
{
	bool bTurnedOn;
	TimerHelper timer;
	std::string soundeffect;
};

struct BoardingGoal
{
	float fHealthLimit;
	int causedDamage;
	int targetsDestroyed;
	int target;
	int damageType;
};

struct CrewAnimation;

struct CrewBlueprint : Blueprint
{
	TextString crewName;
	TextString crewNameLong;
	std::vector<TextString> powers;
	bool male;
	std::vector<std_pair_int_int> skillLevel;
	std::vector<std::vector<GL_Color>> colorLayers;
	std::vector<int> colorChoices;
};

struct CrewTarget;

struct CrewTask
{
	int taskId;
	int room;
	int system;
};

struct Door;

struct Path
{
	Point start;
	std::vector<Door*> doors;
	Point finish;
	float distance;
};

struct Repairable;

struct SCrewStats
{
	std::vector<int> stat;
	std::string species;
	std::string name;
	bool male;
};

struct Ship;

struct Slot
{
	int roomId;
	int slotId;
	Point worldLocation;
};

struct LIBZHL_INTERFACE CrewMember
{
	virtual ~CrewMember() {}
	virtual Point GetPosition() LIBZHL_PLACEHOLDER
	virtual float PositionShift() LIBZHL_PLACEHOLDER
	virtual bool InsideRoom(int roomId) LIBZHL_PLACEHOLDER
	virtual bool ApplyDamage(float damage) LIBZHL_PLACEHOLDER
	virtual int GetPriority() LIBZHL_PLACEHOLDER
	virtual bool ValidTarget(int unk) LIBZHL_PLACEHOLDER
	virtual bool MultiShots() LIBZHL_PLACEHOLDER
	virtual bool ExactTarget() LIBZHL_PLACEHOLDER
	virtual bool IsCrew() LIBZHL_PLACEHOLDER
	virtual bool IsCloned() LIBZHL_PLACEHOLDER
	virtual bool IsDrone() LIBZHL_PLACEHOLDER
	virtual void Jump() LIBZHL_PLACEHOLDER
	virtual bool NeedsIntruderSlot() LIBZHL_PLACEHOLDER
	virtual void SaveState(int fileHelper) LIBZHL_PLACEHOLDER
	virtual void LoadState(int fileHelper) LIBZHL_PLACEHOLDER
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	virtual void OnRender(bool unk) LIBZHL_PLACEHOLDER
	virtual bool OutOfGame() LIBZHL_PLACEHOLDER
	virtual void SetOutOfGame() LIBZHL_PLACEHOLDER
	virtual bool Functional() LIBZHL_PLACEHOLDER
	virtual bool CountForVictory() LIBZHL_PLACEHOLDER
	virtual bool GetControllable() LIBZHL_PLACEHOLDER
	virtual bool ReadyToFight() LIBZHL_PLACEHOLDER
	virtual bool CanFight() LIBZHL_PLACEHOLDER
	virtual bool CanRepair() LIBZHL_PLACEHOLDER
	virtual bool CanSabotage() LIBZHL_PLACEHOLDER
	virtual bool CanMan() LIBZHL_PLACEHOLDER
	virtual bool CanTeleport() LIBZHL_PLACEHOLDER
	virtual bool CanHeal() LIBZHL_PLACEHOLDER
	virtual bool CanSuffocate() LIBZHL_PLACEHOLDER
	virtual bool CanBurn() LIBZHL_PLACEHOLDER
	virtual int GetMaxHealth() LIBZHL_PLACEHOLDER
	virtual bool IsDead() LIBZHL_PLACEHOLDER
	virtual bool PermanentDeath() LIBZHL_PLACEHOLDER
	virtual bool ShipDamage(float damage) LIBZHL_PLACEHOLDER
	virtual bool FireFightingSoundEffect() LIBZHL_PLACEHOLDER
	virtual std::string GetUniqueRepairing() LIBZHL_PLACEHOLDER
	virtual bool ProvidesVision() LIBZHL_PLACEHOLDER
	virtual float GetMoveSpeedMultiplier() LIBZHL_PLACEHOLDER
	virtual float GetRepairSpeed() LIBZHL_PLACEHOLDER
	virtual float GetDamageMultiplier() LIBZHL_PLACEHOLDER
	virtual bool ProvidesPower() LIBZHL_PLACEHOLDER
	virtual std::string GetSpecies() LIBZHL_PLACEHOLDER
	virtual float GetFireRepairMultiplier() LIBZHL_PLACEHOLDER
	virtual bool IsTelepathic() LIBZHL_PLACEHOLDER
	virtual std::pair<float, float> GetPowerCooldown() LIBZHL_PLACEHOLDER
	virtual bool PowerReady() LIBZHL_PLACEHOLDER
	virtual void ActivatePower() LIBZHL_PLACEHOLDER
	virtual bool HasSpecialPower() LIBZHL_PLACEHOLDER
	virtual void ResetPower() LIBZHL_PLACEHOLDER
	virtual float GetSuffocationMultiplier() LIBZHL_PLACEHOLDER
	virtual int BlockRoom() LIBZHL_PLACEHOLDER
	virtual Damage GetRoomDamage() LIBZHL_PLACEHOLDER
	virtual bool IsAnaerobic() LIBZHL_PLACEHOLDER
	virtual void UpdateRepair() LIBZHL_PLACEHOLDER
	virtual bool CanStim() LIBZHL_PLACEHOLDER
	int iShipId;
	float x;
	float y;
	float size;
	float scale;
	float goal_x;
	float goal_y;
	int width;
	int height;
	std::pair<float, float> health;
	float speed_x;
	float speed_y;
	Path path;
	bool new_path;
	float x_destination;
	float y_destination;
	Door *last_door;
	Repairable *currentRepair;
	bool bSuffocating;
	int moveGoal;
	int selectionState;
	int iRoomId;
	int iManningId;
	int iRepairId;
	int iStackId;
	Slot currentSlot;
	bool intruder;
	bool bFighting;
	bool bSharedSpot;
	CrewAnimation *crewAnim;
	GL_Texture *selectionImage;
	CachedImage healthBox;
	CachedImage healthBoxRed;
	CachedRect healthBar;
	float fMedbay;
	float lastDamageTimer;
	float lastHealthChange;
	int currentShipId;
	AnimationTracker flashHealthTracker;
	Pointf currentTarget;
	CrewTarget *crewTarget;
	BoardingGoal boardingGoal;
	bool bFrozen;
	bool bFrozenLocation;
	CrewTask task;
	std::string type;
	Ship *ship;
	Slot finalGoal;
	Door *blockingDoor;
	bool bOutOfGame;
	std::string species;
	bool bDead;
	uint8_t gap_ex_1[4];
	int iOnFire;
	bool bActiveManning;
	ShipSystem *currentSystem;
	int usingSkill;
	CrewBlueprint blueprint;
	Animation healing;
	Animation stunned;
	AnimationTracker levelUp;
	int lastLevelUp;
	SCrewStats stats;
	std::vector<std::vector<bool>> skillsEarned;
	bool clone_ready;
	bool bMindControlled;
	int iDeathNumber;
	Animation mindControlled;
	Animation stunIcon;
	std::vector<std::vector<AnimationTracker>> skillUp;
	int healthBoost;
	float fMindDamageBoost;
	float fCloneDying;
	bool bResisted;
	uint8_t gap_ex_2[4];
	Slot savedPosition;
	float fStunTime;
	CachedImage movementTarget;
	bool bCloned;
};

struct DroneBlueprint;

struct Slot;

struct LIBZHL_INTERFACE Drone
{
	virtual ~Drone() {}
	virtual void OnInit() LIBZHL_PLACEHOLDER
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	virtual void OnDestroy() LIBZHL_PLACEHOLDER
	virtual void SetPowered(bool _powered) LIBZHL_PLACEHOLDER
	virtual void SetInstantPowered() LIBZHL_PLACEHOLDER
	virtual bool GetPowered() LIBZHL_PLACEHOLDER
	virtual void SetCurrentShip(int shipId) LIBZHL_PLACEHOLDER
	virtual void SetDeployed(bool _deployed) LIBZHL_PLACEHOLDER
	virtual void SetDestroyed(bool dead, bool setTimer) LIBZHL_PLACEHOLDER
	virtual void SetHacked(int level) LIBZHL_PLACEHOLDER
	virtual bool GetDeployed() LIBZHL_PLACEHOLDER
	virtual bool NeedsRoom() LIBZHL_PLACEHOLDER
	virtual void SetSlot(int room, int slot) LIBZHL_PLACEHOLDER
	virtual bool Destroyed() LIBZHL_PLACEHOLDER
	virtual Point GetWorldLocation() LIBZHL_PLACEHOLDER
	virtual void SetWorldLocation(Point point) LIBZHL_PLACEHOLDER
	virtual Slot *GetDroneSlot(Drone *drone) LIBZHL_PLACEHOLDER
	virtual int GetDroneHealth() LIBZHL_PLACEHOLDER
	virtual int GetRequiredPower() LIBZHL_PLACEHOLDER
	virtual void RenderIcon() LIBZHL_PLACEHOLDER
	virtual std::string *GetName(Drone *drone) LIBZHL_PLACEHOLDER
	virtual bool CanBeDeployed() LIBZHL_PLACEHOLDER
	virtual bool RecallOnJump() LIBZHL_PLACEHOLDER
	virtual bool CanBeRecovered() LIBZHL_PLACEHOLDER
	virtual void SaveState(int fh) LIBZHL_PLACEHOLDER
	virtual void LoadState(int fh) LIBZHL_PLACEHOLDER
	virtual void BlowUp(bool silent) LIBZHL_PLACEHOLDER
	virtual bool GetStunned() LIBZHL_PLACEHOLDER
	int iShipId;
	int selfId;
	bool powered;
	int powerRequired;
	bool deployed;
	int type;
	const DroneBlueprint *blueprint;
	bool bDead;
	int iBonusPower;
	bool poweredAtLocation;
	float destroyedTimer;
	int iHackLevel;
	float hackTime;
};

struct CrewDrone : CrewMember
{
	Drone _drone;
	int droneRoom;
	Animation powerUp;
	Animation powerDown;
	GL_Texture *lightLayer;
	GL_Texture *baseLayer;
};

struct BattleDrone : CrewDrone
{
};

struct CollisionResponse
{
	int collision_type;
	Pointf point;
	int damage;
	int superDamage;
};

struct WeaponAnimation;

struct BeamWeapon : Projectile
{
	Pointf sub_end;
	Pointf sub_start;
	Pointf shield_end;
	Pointf final_end;
	Pointf target2;
	Pointf target1;
	float lifespan;
	float length;
	float dh;
	CollisionResponse last_collision;
	int soundChannel;
	std::vector<Animation> contactAnimations;
	float animationTimer;
	int lastDamage;
	Targetable *movingTarget;
	float start_heading;
	float timer;
	WeaponAnimation *weapAnimation;
	bool piercedShield;
	bool oneSpace;
	bool bDamageSuperShield;
	int movingTargetId;
	bool checkedCollision;
	std::vector<Animation> smokeAnims;
	Pointf lastSmokeAnim;
};

struct DroneBlueprint : Blueprint
{
	std::string typeName;
	int level;
	int targetType;
	int power;
	float cooldown;
	int speed;
	int dodge;
	std::string weaponBlueprint;
	std::string droneImage;
	std::string combatIcon;
};

struct ItemBlueprint : Blueprint
{
};

struct ShipBlueprint : Blueprint
{
	struct SystemTemplate
	{
		int systemId;
		int powerLevel;
		std::vector<int> location;
		int bp;
		int maxPower;
		std::string image;
		int slot;
		int direction;
		std::vector<std::string> weapon;
	};
	
	Description desc;
	std::string blueprintName;
	TextString name;
	TextString shipClass;
	std::string layoutFile;
	std::string imgFile;
	std::string cloakFile;
	std::string shieldFile;
	std::string floorFile;
	std::map<int, SystemTemplate> systemInfo;
	std::vector<int> systems;
	int droneCount;
	int originalDroneCount;
	int droneSlots;
	std::string loadDrones;
	std::vector<std::string> drones;
	std::vector<std::string> augments;
	int weaponCount;
	int originalWeaponCount;
	int weaponSlots;
	std::string loadWeapons;
	std::vector<std::string> weapons;
	int missiles;
	int drone_count;
	int health;
	int originalCrewCount;
	std::vector<std::string> defaultCrew;
	std::vector<CrewBlueprint> customCrew;
	int maxPower;
	int boardingAI;
	int bp_count;
	int maxCrew;
	int maxSector;
	int minSector;
	TextString unlock;
};

struct SystemBlueprint : Blueprint
{
	int maxPower;
	int startPower;
	std::vector<int> upgradeCosts;
};

struct EffectsBlueprint
{
	std::vector<std::string> launchSounds;
	std::vector<std::string> hitShipSounds;
	std::vector<std::string> hitShieldSounds;
	std::vector<std::string> missSounds;
	std::string image;
};

struct WeaponBlueprint : Blueprint
{
	struct BoostPower
	{
		int type;
		float amount;
		int count;
	};
	
	struct MiniProjectile
	{
		std::string image;
		bool fake;
	};
	
	std::string typeName;
	Damage damage;
	int shots;
	int missiles;
	float cooldown;
	int power;
	int length;
	float speed;
	int miniCount;
	EffectsBlueprint effects;
	std::string weaponArt;
	std::string combatIcon;
	std::string explosion;
	int radius;
	std::vector<MiniProjectile> miniProjectiles;
	BoostPower boostPower;
	int drone_targetable;
	int spin;
	int chargeLevels;
	TextString flavorType;
	GL_Color color;
};

struct BlueprintManager
{
	int rarityTotal;
	std::map<std::string, ShipBlueprint> shipBlueprints;
	std::map<std::string, WeaponBlueprint> weaponBlueprints;
	std::map<std::string, DroneBlueprint> droneBlueprints;
	std::map<std::string, AugmentBlueprint> augmentBlueprints;
	std::map<std::string, CrewBlueprint> crewBlueprints;
	std::map<std::string, bool> nameList;
	std::map<std::string, std::string> shortNames;
	std::map<std::string, std_map_std_string_bool> languageNameLists;
	std::map<std::string, ItemBlueprint> itemBlueprints;
	std::map<std::string, SystemBlueprint> systemBlueprints;
	std::map<std::string, std::vector<std::string>> blueprintLists;
	std::vector<std::string> currentNames;
};

struct BoarderDrone : CrewDrone
{
};

struct BoarderDrone;

struct CollisionResponse;
struct DamageMessage;

struct SpaceDrone;

struct LIBZHL_INTERFACE SpaceDrone : Drone
{
	virtual void PickDestination() LIBZHL_PLACEHOLDER
	virtual void PickTarget() LIBZHL_PLACEHOLDER
	virtual bool HasTarget() LIBZHL_PLACEHOLDER
	virtual bool ValidTarget() LIBZHL_PLACEHOLDER
	virtual float GetWeaponCooldown() LIBZHL_PLACEHOLDER
	virtual void RandomizeStartingPosition() LIBZHL_PLACEHOLDER
	virtual bool HideUnderOwner() LIBZHL_PLACEHOLDER
	virtual Projectile *GetNextProjectile() LIBZHL_PLACEHOLDER
	virtual void SetMovementTarget(Targetable &target) LIBZHL_PLACEHOLDER
	virtual void SetWeaponTarget(Targetable &target) LIBZHL_PLACEHOLDER
	virtual bool ValidTargetObject(Targetable &target) LIBZHL_PLACEHOLDER
	virtual void OnRender(int space) LIBZHL_PLACEHOLDER
	virtual void RenderDrone() LIBZHL_PLACEHOLDER
	virtual std::string *GetTooltip(SpaceDrone *drone) LIBZHL_PLACEHOLDER
	virtual Pointf GetWorldCenterPoint() LIBZHL_PLACEHOLDER
	virtual void SetCurrentLocation(Pointf pos) LIBZHL_PLACEHOLDER
	virtual void MouseMove(int mX, int mY) LIBZHL_PLACEHOLDER
	virtual Pointf GetRandomTargettingPoint(bool unk) LIBZHL_PLACEHOLDER
	virtual Globals::Ellipse *GetShieldShape(SpaceDrone *drone) LIBZHL_PLACEHOLDER
	virtual int GetSpaceId() LIBZHL_PLACEHOLDER
	virtual Pointf GetSpeed() LIBZHL_PLACEHOLDER
	virtual int GetOwnerId() LIBZHL_PLACEHOLDER
	virtual int GetSelfId() LIBZHL_PLACEHOLDER
	virtual CollisionResponse *CollisionMoving(SpaceDrone *drone, Pointf pos1, Pointf pos2, DamageParameter damage, bool unk) LIBZHL_PLACEHOLDER
	virtual bool DamageBeam(Pointf pos1, Pointf pos2, DamageParameter damage) LIBZHL_PLACEHOLDER
	virtual void DamageArea(Pointf pos, DamageParameter damage, bool unk) LIBZHL_PLACEHOLDER
	virtual BoarderDrone *GetBoardingDrone() LIBZHL_PLACEHOLDER
	Targetable _targetable;
	Collideable _collideable;
	int currentSpace;
	int destinationSpace;
	Pointf currentLocation;
	Pointf lastLocation;
	Pointf destinationLocation;
	Pointf pointTarget;
	Animation explosion;
	Targetable *weaponTarget;
	Pointf targetLocation;
	Pointf targetSpeed;
	Targetable *movementTarget;
	Pointf speedVector;
	bool poweredLastFrame;
	bool deployedLastFrame;
	bool bFire;
	float pause;
	float additionalPause;
	float weaponCooldown;
	float current_angle;
	float aimingAngle;
	float lastAimingAngle;
	float desiredAimingAngle;
	DamageMessage *message;
	Animation weapon_animation;
	const WeaponBlueprint *weaponBlueprint;
	int lifespan;
	bool bLoadedPosition;
	bool bDisrupted;
	float hackAngle;
	float ionStun;
	Pointf beamCurrentTarget;
	Pointf beamFinalTarget;
	float beamSpeed;
	Animation hackSparks;
};

struct BoarderPodDrone : SpaceDrone
{
	GL_Texture *baseSheet;
	GL_Texture *colorSheet;
	Pointf startingPosition;
	Animation droneImage;
	CachedImage flame;
	BoarderDrone *boarderDrone;
	bool bDeliveredDrone;
	bool diedInSpace;
};

struct BoardingEvent
{
	std::string type;
	int min;
	int max;
	int amount;
	bool breach;
};

struct BombProjectile : Projectile
{
	bool bMissed;
	DamageMessage *missMessage;
	float explosiveDelay;
	bool bSuperShield;
	bool superShieldBypass;
};

struct CompleteShip;

struct CombatAI
{
	ShipManager *target;
	std::vector<ProjectileFactory*> weapons;
	std::vector<SpaceDrone*> drones;
	int stance;
	std::vector<int> system_targets;
	bool bFiringWhileCloaked;
	ShipManager *self;
};

struct CrewAI
{
	ShipManager *ship;
	bool bAIon;
	bool bAirlockRequested;
	bool bMedbayRequested;
	bool bHurtCrew;
	bool bCalmShip;
	std::vector<CrewMember*> crewList;
	std::vector<CrewMember*> intruderList;
	std::vector<Repairable*> hullBreaches;
	std::vector<CrewTask> desiredTaskList;
	std::vector<CrewTask> bonusTaskList;
	std::vector<bool> breachedRooms;
	int iTeleportRequest;
	bool bUrgentTeleport;
	int startingCrewCount;
	bool bMultiracialCrew;
	bool bOverrideRace;
};

struct PowerProfile
{
};

struct ShipAI
{
	ShipManager *ship;
	ShipManager *target;
	CrewAI crewAI;
	CombatAI combatAI;
	bool playerShip;
	bool surrendered;
	bool escaping;
	bool destroyed;
	int surrenderThreshold;
	int escapeThreshold;
	float escapeTimer;
	int lastMaxPower;
	std::map<std::string, PowerProfile> powerProfiles;
	int boardingProfile;
	int iTeleportRequest;
	int iTeleportTarget;
	int brokenSystems;
	int boardingAi;
	int iCrewNeeded;
	bool bStalemateTrigger;
	char field_ED[3];
	float fStalemateTimer;
	int lastHealth;
	bool bBoss;
	char field_F9[3];
	int iTimesTeleported;
};

struct SpaceManager;

struct LIBZHL_INTERFACE CompleteShip
{
	virtual ~CompleteShip() {}
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	virtual void PauseLoop() LIBZHL_PLACEHOLDER
	virtual bool IsBoss() LIBZHL_PLACEHOLDER
	virtual void Restart() LIBZHL_PLACEHOLDER
	virtual bool IncomingFire() LIBZHL_PLACEHOLDER
	int iShipId;
	ShipManager *shipManager;
	SpaceManager *spaceManager;
	CompleteShip *enemyShip;
	bool bPlayerShip;
	ShipAI shipAI;
	std::vector<CrewMember*> arrivingParty;
	std::vector<CrewMember*> leavingParty;
	int teleTargetRoom;
};

struct BossShip : CompleteShip
{
	int currentStage;
	TimerHelper powerTimer;
	int powerCount;
	std::vector<int> crewCounts;
	bool bDeathBegan;
	int nextStage;
};

struct CAchievement
{
	std::string name_id;
	std::pair<int, int> progress;
	bool unlocked;
	int8_t gap_ex_custom;
	TextString name;
	TextString description;
	TextString header;
	bool newAchievement;
	bool multiDifficulty;
	int difficulty;
	std::string ship;
	int shipDifficulties[3];
	int dimension;
	CachedImage icon;
	CachedImage miniIcon;
	CachedImage miniIconLocked;
	CachedImage lockImage;
	CachedImage dotOn;
	CachedImage dotOff;
	GL_Primitive *outline;
	GL_Primitive *mini_outline;
	GL_Primitive *lockOverlay;
};

struct CEvent
{
	void *vptr;
};

struct GL_FrameBuffer;

struct FocusWindow
{
	void *vptr;
	bool bOpen;
	bool bFullFocus;
	uint8_t gap_ex_fw[4];
	Point close;
	bool bCloseButtonSelected;
	Point position;
};

struct TextButton;

struct LanguageChooser : FocusWindow
{
	std::vector<TextButton*> buttons;
	int iChoice;
};

struct ResourceEvent
{
	int missiles;
	int fuel;
	int drones;
	int scrap;
	int crew;
	bool traitor;
	bool cloneable;
	TextString cloneText;
	std::string crewType;
	const WeaponBlueprint *weapon;
	const DroneBlueprint *drone;
	const AugmentBlueprint *augment;
	CrewBlueprint crewBlue;
	int systemId;
	int weaponCount;
	int droneCount;
	bool steal;
	bool intruders;
	int fleetDelay;
	int hullDamage;
	int upgradeAmount;
	int upgradeId;
	int upgradeSuccessFlag;
	std::string removeItem;
};

struct ChoiceText
{
	int type;
	std::string text;
	ResourceEvent rewards;
};

struct WindowFrame;

struct ChoiceBox : FocusWindow
{
	GL_Texture *textBox;
	WindowFrame *box;
	std::string mainText;
	std::vector<ChoiceText> choices;
	unsigned int columnSize;
	std::vector<Globals::Rect> choiceBoxes;
	int potentialChoice;
	int selectedChoice;
	int fontSize;
	bool centered;
	int gap_size;
	float openTime;
	ResourceEvent rewards;
	GL_Color currentTextColor;
	Pointf lastChoice;
};

struct TextButton : GenericButton
{
	GL_Primitive *primitives[3];
	GL_Texture *baseImage;
	Point baseImageOffset;
	GL_Primitive *basePrimitive;
	bool colorsSet;
	GL_Color colors[3];
	GL_Color textColor;
	Point buttonSize;
	int cornerInset;
	bool autoWidth;
	int autoWidthMargin;
	int autoWidthMin;
	bool autoRightAlign;
	TextString label;
	int font;
	int lineHeight;
	int textYOffset;
	bool autoShrink;
};

struct ConfirmWindow : FocusWindow
{
	TextString text;
	int textHeight;
	int minWidth;
	int windowWidth;
	TextString yesText;
	TextString noText;
	bool autoCenter;
	GL_Texture *windowImage;
	GL_Primitive *window;
	TextButton yesButton;
	TextButton noButton;
	bool result;
};

struct CreditScreen
{
	float scroll;
	std::string shipName;
	std::string crewString;
	float pausing;
	GL_Texture *bg;
	std::vector<std::string> creditNames;
	int lastValidCredit;
	int touchesDown;
	double touchDownTime;
	float skipMessageTimer;
	char gap5C[3];
	char _unk;
};

struct ControlButton
{
	Globals::Rect rect;
	std::string value;
	TextString desc;
	std::string key;
	int state;
	int descLength;
};

struct ControlsScreen
{
	std::vector<ControlButton> buttons[4];
	int selectedButton;
	TextButton defaultButton;
	ConfirmWindow resetDialog;
	Button pageButtons[4];
	int currentPage;
	WindowFrame *customBox;
};

struct SlideBar
{
	Globals::Rect box;
	bool hovering;
	bool holding;
	Globals::Rect marker;
	Point mouseStart;
	Point rectStart;
	std::pair<int, int> minMax;
};

struct OptionsScreen : ChoiceBox
{
	Point position;
	Point wipeProfilePosition;
	SlideBar soundVolume;
	SlideBar musicVolume;
	bool bCustomizeControls;
	ControlsScreen controls;
	TextButton closeButton;
	TextButton wipeProfileButton;
	int choiceFullscreen;
	int choiceVSync;
	int choiceFrameLimit;
	int choiceLowend;
	int choiceColorblind;
	int choiceLanguage;
	int choiceDialogKeys;
	int choiceShowPaths;
	int choiceAchievementPopups;
	int choiceAutoPause;
	int choiceTouchAutoPause;
	int choiceControls;
	int lastFullScreen;
	bool isSoundTouch;
	bool isMusicTouch;
	LanguageChooser langChooser;
	bool showWipeButton;
	ConfirmWindow wipeProfileDialog;
	ChoiceBox restartRequiredDialog;
};

struct CrewCustomizeBox;

struct CrewBlueprint;

struct SystemBlueprint;

struct InfoBox
{
	Point location;
	const SystemBlueprint *blueprint;
	Description desc;
	int tempUpgrade;
	int powerLevel;
	int maxPower;
	int systemId;
	int systemWidth;
	int yShift;
	Point descBoxSize;
	const CrewBlueprint *pCrewBlueprint;
	std::string warning;
	bool bDetailed;
	std::string additionalTip;
	std::string additionalWarning;
	WindowFrame *primaryBox;
	int primaryBoxOffset;
	WindowFrame *secondaryBox;
	std::string droneBlueprint;
};

struct ShipAchievementInfo
{
	CAchievement *achievement;
	Point position;
	int dimension;
};

struct ShipBlueprint;

struct ShipButton;

struct UnlockArrow
{
	int direction;
	int status;
	Globals::Rect shape;
};

struct ShipSelect
{
	Point position;
	Point titlePos;
	std::vector<GL_Primitive*> shipListBase;
	std::vector<ShipButton*> shipButtons;
	std::vector<UnlockArrow> arrows;
	bool bOpen;
	int selectedShip;
	InfoBox infoBox;
	int currentType;
	TextButton typeA;
	TextButton typeB;
	TextButton typeC;
	TextButton confirm;
	bool bConfirmed;
	int activeTouch;
	ChoiceBox tutorial;
	int tutorialPage;
};

struct SystemCustomBox;

struct TextInput
{
	std::string prompt;
	std::vector<int> text;
	std::vector<int> oldText;
	int pos;
	int lastPos;
	bool bActive;
	int allowedChars;
	int maxChars;
	TimerHelper blinker;
};

struct ShipBuilder
{
	ShipManager *currentShip;
	GL_Primitive *nameBoxPrimitive;
	GL_Primitive *enableAdvancedPrimitive;
	Button resetButton;
	Button clearButton;
	TextButton startButton;
	TextButton backButton;
	TextButton renameButton;
	Button leftButton;
	Button rightButton;
	TextButton listButton;
	TextButton showButton;
	TextButton easyButton;
	TextButton normalButton;
	TextButton hardButton;
	TextButton typeA;
	TextButton typeB;
	TextButton typeC;
	Point typeALoc;
	Point typeBLoc;
	Point typeCLoc;
	TextButton randomButton;
	TextButton advancedOffButton;
	TextButton advancedOnButton;
	std::vector<GenericButton*> buttons;
	std::vector<Animation> animations;
	std::vector<CrewCustomizeBox*> vCrewBoxes;
	bool bOpen;
	GL_Primitive *baseImage;
	GL_Primitive *shipSelectBox;
	GL_Primitive *shipAchBox;
	GL_Primitive *shipEquipBox;
	GL_Primitive *startButtonBox;
	GL_Primitive *advancedButtonBox;
	int typeAOffset;
	int typeBOffset;
	int typeCOffset;
	int shipAchPadding;
	int advancedTitleOffset;
	std::vector<EquipmentBox*> vEquipmentBoxes;
	InfoBox infoBox;
	std::vector<SystemCustomBox*> sysBoxes;
	int shoppingId;
	int currentSlot;
	int currentBox;
	bool bDone;
	const ShipBlueprint *ships[30];
	int currentShipId;
	int storeIds[4];
	bool bRenaming;
	std::string currentName;
	bool bShowRooms;
	bool bCustomizingCrew;
	Animation walkingMan;
	Pointf walkingManPos;
	ShipSelect shipSelect;
	ChoiceBox introScreen;
	bool bShowedIntro;
	int currentType;
	TextInput nameInput;
	int activeTouch;
	bool activeTouchIsShip;
	bool shipDragActive;
	bool shipDragVertical;
	Point shipDragOffset;
	std::vector<ShipAchievementInfo> shipAchievements;
	int selectedAch;
	GL_Texture *arrow;
	WindowFrame *descBox;
	AnimationTracker tracker;
	bool encourageShipList;
};

struct MainMenu
{
	bool bOpen;
	int activeTouch;
	GL_Texture *background;
	GL_Texture *glowy;
	AnimationTracker glowTracker;
	Button continueButton;
	Button startButton;
	Button helpButton;
	Button statButton;
	Button optionsButton;
	Button creditsButton;
	Button quitButton;
	std::vector<Button*> buttons;
	int finalChoice;
	ShipBuilder shipBuilder;
	bool bScoreScreen;
	OptionsScreen optionScreen;
	bool bSelectSave;
	ConfirmWindow confirmNewGame;
	ChoiceBox changelog;
	bool bCreditScreen;
	CreditScreen credits;
	bool bChangedLogin;
	std::vector<CrewMember*> testCrew;
	bool bChangedScreen;
	char gap34A4[7];
	std::string error;
};

struct WorldManager;

struct CApp : CEvent
{
	bool Running;
	bool shift_held;
	CommandGui *gui;
	WorldManager *world;
	MainMenu menu;
	LanguageChooser langChooser;
	int screen_x;
	int screen_y;
	int modifier_x;
	int modifier_y;
	bool fullScreenLastState;
	bool minimized;
	bool minLastState;
	bool focus;
	bool focusLastState;
	bool steamOverlay;
	bool steamOverlayLastState;
	bool rendering;
	bool gameLogic;
	float mouseModifier_x;
	float mouseModifier_y;
	GL_FrameBuffer *framebuffer;
	bool fboSupport;
	int x_bar;
	int y_bar;
	bool lCtrl;
	bool useFrameBuffer;
	bool manualResolutionError;
	int manualResErrorX;
	int manualResErrorY;
	bool nativeFullScreenError;
	bool fbStretchError;
	char __NULL[2];
	std::string lastLanguage;
	char inputFocus;
};

struct CFPS
{
	float RunningTime;
	double OldTime;
	double LastTime;
	float SpeedFactor;
	int NumFrames;
	int Frames;
	int speedLevel;
};

struct CSurface
{
};

struct ChoiceReq
{
	std::string object;
	int min_level;
	int max_level;
	int max_group;
	bool blue;
};

struct Button;
struct CloakingSystem;

struct CloakingBox : CooldownSystemBox
{
	std::vector<Button*> buttons;
	Button *currentButton;
	CloakingSystem *cloakSystem;
	Point buttonOffset;
};

struct CloakingSystem : ShipSystem
{
	bool bTurnedOn;
	TimerHelper timer;
	std::string soundeffect;
	AnimationTracker glowTracker;
	GL_Primitive *glowImage;
};

struct CloneSystem;

struct WarningMessage;

struct CloneBox : CooldownSystemBox
{
	CloneSystem *cloneSys;
	GL_Texture *pipe[3];
	GL_Texture *boxBottom;
	GL_Texture *boxMiddle;
	GL_Texture *boxTop;
	GL_Texture *boxSolo;
	GL_Texture *boxFill;
	WarningMessage *dyingCrewWarning;
};

struct CloneSystem : ShipSystem
{
	float fTimeToClone;
	CrewMember *clone;
	float fTimeGoal;
	float fDeathTime;
	GL_Texture *bottom;
	GL_Texture *top;
	GL_Texture *gas;
	int slot;
	Animation *currentCloneAnimation;
	std::map<std::string, Animation> cloneAnimations;
};

struct DroneControl : ArmamentControl
{
	WarningMessage droneMessage;
	WarningMessage noTargetMessage;
	WarningMessage systemMessage;
};

struct HandAnimation
{
	GL_Texture *hand;
	Point start;
	Point finish;
	Pointf location;
	bool bRunning;
	float pause;
};

struct WeaponControl : ArmamentControl
{
	Targetable *currentTarget;
	ProjectileFactory *armedWeapon;
	bool autoFiring;
	TextButton autoFireButton;
	GL_Primitive *autoFireBase;
	GL_Primitive *targetIcon[4];
	GL_Primitive *targetIconYellow[4];
	Pointf autoFireFocus;
	WarningMessage missileMessage;
	WarningMessage systemMessage;
	int armedSlot;
};

struct CombatControl
{
	CommandGui *gui;
	ShipManager *shipManager;
	Point playerShipPosition;
	SpaceManager *space;
	WeaponControl weapControl;
	DroneControl droneControl;
	std::vector<SystemBox*> sysBoxes;
	std::vector<CompleteShip*> enemyShips;
	CompleteShip *currentTarget;
	SpaceDrone *currentDrone;
	Point position;
	int selectedRoom;
	int selectedSelfRoom;
	Point targetPosition;
	Point boxPosition;
	WindowFrame *hostileBoxFrame;
	CachedImage healthMask;
	CachedImage shieldCircleCharged[5];
	CachedImage shieldCircleUncharged[5];
	CachedImage shieldCircleHacked[5];
	CachedImage shieldCircleHackedCharged[5];
	CachedImage shieldChargeBox;
	CachedImage superShieldBox5;
	CachedImage superShieldBox12;
	bool open;
	float shipIconSize;
	Pointf potentialAiming;
	std::vector<Pointf> aimingPoints;
	Pointf lastMouse;
	bool mouseDown;
	bool isAimingTouch;
	bool movingBeam;
	Point beamMoveLast;
	bool invalidBeamTouch;
	Point screenReposition;
	std::pair<int, int> teleportCommand;
	int iTeleportArmed;
	CachedImage teleportTarget_send;
	CachedImage teleportTarget_return;
	CachedImage hackTarget;
	CachedImage mindTarget;
	AnimationTracker ftl_timer;
	WarningMessage ftlWarning;
	AnimationTracker hacking_timer;
	std::vector<std::string> hackingMessages;
	bool boss_visual;
	bool bTeachingBeam;
	WindowFrame *tipBox;
	HandAnimation hand;
};

struct CombatDrone : SpaceDrone
{
	Pointf lastDestination;
	float progressToDestination;
	float heading;
	float oldHeading;
	CachedImage drone_image_off;
	CachedImage drone_image_charging;
	CachedImage drone_image_on;
	CachedImage engine_image;
};

struct CombatControl;
struct CrewBox;

struct CrewControl
{
	ShipManager *shipManager;
	std::vector<CrewMember*> selectedCrew;
	std::vector<CrewMember*> potentialSelectedCrew;
	Door *selectedDoor;
	Repairable *selectedRepair;
	Point selectedGrid;
	int selectedRoom;
	bool selectedPlayerShip;
	Point availablePosition;
	std::vector<CrewBox*> crewBoxes;
	Point firstMouse;
	Point currentMouse;
	Point worldFirstMouse;
	Point worldCurrentMouse;
	bool mouseDown;
	bool bUpdated;
	int activeTouch;
	char selectingCrew;
	char selectingCrewOnPlayerShip;
	double selectingCrewStartTime;
	bool doorControlMode;
	bool doorControlOpen;
	bool doorControlOpenSet;
	CombatControl *combatControl;
	unsigned int selectedCrewBox;
	AnimationTracker crewMessage;
	std::string message;
	Button saveStations;
	Button returnStations;
	GL_Primitive *saveStationsBase;
	GL_Primitive *returnStationsBase;
	int stationsLastY;
};

struct CrewEquipBox;

struct DropBox
{
	Point position;
	bool isSellBox;
	GL_Texture *boxImage[2];
	int selectedImage;
	TextString titleText;
	TextString bodyText;
	int bodySpace;
	TextString lowerText;
	TextString sellText;
	std::string sellCostText;
	int textWidth;
	int insertHeight;
	int titleInsert;
};

struct CrewManifest : FocusWindow
{
	GL_Primitive *box;
	DropBox overBox;
	ShipManager *shipManager;
	std::vector<CrewEquipBox*> crewBoxes;
	InfoBox infoBox;
	int confirmingDelete;
	ConfirmWindow deleteDialog;
};

struct AugmentEquipBox;

struct Equipment : FocusWindow
{
	GL_Texture *box;
	GL_Texture *storeBox;
	DropBox overBox;
	DropBox overAugImage;
	DropBox sellBox;
	bool bSellingItem;
	ShipManager *shipManager;
	std::vector<EquipmentBox*> vEquipmentBoxes;
	std::vector<ProjectileFactory*> weaponsTrashList;
	EquipmentBox *overcapacityBox;
	AugmentEquipBox *overAugBox;
	int selectedEquipBox;
	int draggingEquipBox;
	int potentialDraggingBox;
	bool bDragging;
	Point firstMouse;
	Point currentMouse;
	Point dragBoxCenter;
	Point dragBoxOffset;
	InfoBox infoBox;
	std::string sellCostText;
	bool bOverCapacity;
	bool bOverAugCapacity;
	bool bStoreMode;
	int cargoId;
	Point infoBoxLoc;
};

struct TextButton0 : GenericButton
{
	GL_Primitive *primitives[3];
	GL_Texture *baseImage;
	Point baseImageOffset;
	GL_Primitive *basePrimitive;
	bool colorsSet;
	unsigned char gap65[3];
	GL_Color colors[3];
	GL_Color textColor;
	Point buttonSize;
	int cornerInset;
	bool autoWidth;
	unsigned char gapB5[3];
	int autoWidthMargin;
	int autoWidthMin;
	bool autoRightAlign;
	unsigned char gapC1[3];
	TextString label;
	int font;
	int lineHeight;
	int textYOffset;
	bool autoShrink;
};

struct FTLButton : TextButton0
{
	bool autoShrinkText;
	bool ready;
	float ftl_blink;
	float ftl_blink_dx;
	float pullout;
	ShipManager *ship;
	GL_Primitive *baseImage;
	GL_Primitive *baseImageRed;
	GL_Primitive *pulloutBase;
	GL_Primitive *pulloutBaseRed;
	GL_Primitive *pilotOn;
	GL_Primitive *pilotOff1;
	GL_Primitive *pilotOff2;
	GL_Primitive *enginesOn;
	GL_Primitive *enginesOff1;
	GL_Primitive *enginesOff2;
	GL_Texture *FTL_loadingbars;
	GL_Texture *FTL_loadingbars_off;
	GL_Primitive *loadingBars;
	GL_Primitive *loadingBarsOff;
	int lastBarsWidth;
	WarningMessage *enginesDown;
	bool bOutOfFuel;
	bool bBossFight;
	bool bHoverRaw;
	bool bHoverPilot;
	bool bHoverEngine;
};

struct FocusWindow;

struct GameOver : FocusWindow
{
	std::vector<TextButton*> buttons;
	GL_Primitive *box;
	int boxWidth;
	int command;
	std::vector<int> commands;
	bool bShowStats;
	Point position;
	std::string gameoverText;
	bool bVictory;
	float openedTimer;
	CreditScreen credits;
	bool bShowingCredits;
};

struct InputBox : FocusWindow
{
	WindowFrame *textBox;
	std::string mainText;
	bool bDone;
	bool bInvertCaps;
	std::string inputText;
	std::vector<std::string> lastInputs;
	int lastInputIndex;
};

struct Location;

struct MenuScreen : FocusWindow
{
	GL_Texture *mainImage;
	GL_Primitive *menuPrimitive;
	int menuWidth;
	std::vector<TextButton*> buttons;
	int command;
	std::vector<int> commands;
	Point position;
	ConfirmWindow confirmDialog;
	int tempCommand;
	GenericButton *saveQuit;
	bool bShowControls;
	Point statusPosition;
	GL_Texture *difficultyBox;
	int difficultyWidth;
	std::string difficultyLabel;
	std::string difficultyText;
	GL_Texture *dlcBox;
	int dlcWidth;
	std::string dlcLabel;
	std::string dlcText;
	GL_Texture *achBox;
	GL_Primitive *achBoxPrimitive;
	int achWidth;
	std::string achLabel;
	std::vector<ShipAchievementInfo> shipAchievements;
	int selectedAch;
	InfoBox info;
};

struct WarningWithLines;

struct ShipStatus
{
	Point location;
	float size;
	ShipManager *ship;
	CombatControl *combat;
	GL_Primitive *hullBox;
	GL_Primitive *hullBox_Red;
	GL_Primitive *shieldBox_On;
	GL_Primitive *shieldBox_Off;
	GL_Primitive *shieldBox_Red;
	GL_Primitive *shieldCircleCharged[4];
	GL_Primitive *shieldCircleUncharged[4];
	GL_Primitive *shieldCircleHacked[4];
	GL_Primitive *shieldCircleHackedCharged[4];
	GL_Primitive *energyShieldBox;
	GL_Primitive *energyShieldBar[5];
	GL_Texture *hullLabel;
	GL_Texture *hullLabel_Red;
	GL_Primitive *shieldBoxPurple;
	GL_Primitive *oxygenPurple;
	GL_Primitive *evadePurple;
	GL_Primitive *evadeOxygenBox;
	GL_Primitive *evadeOxygenBox_topRed;
	GL_Primitive *evadeOxygenBox_bottomRed;
	GL_Primitive *evadeOxygenBox_bothRed;
	GL_Primitive *fuelIcon;
	GL_Primitive *missilesIcon;
	GL_Primitive *dronesIcon;
	GL_Primitive *scrapIcon;
	GL_Primitive *fuelIcon_red;
	GL_Primitive *missilesIcon_red;
	GL_Primitive *dronesIcon_red;
	GL_Primitive *scrapIcon_red;
	GL_Primitive *healthMask;
	GL_Texture *healthMaskTexture;
	int lastHealth;
	Globals::Ellipse baseShield;
	int currentHover;
	Point evadeOxygenBoxLocation;
	int lastFuel;
	int lastDrones;
	int lastScrap;
	int lastMissiles;
	int lastHull;
	WarningWithLines *hullMessage;
	WarningMessage *shieldMessage;
	WarningMessage *oxygenMessage;
	WarningMessage *boardingMessage;
	std::vector<DamageMessage*> resourceMessages;
	AnimationTracker noMoneyTracker;
	AnimationTracker flashTracker;
	bool bBossFight;
	bool bEnemyShip;
	Point noShipShift;
	Point intruderShift;
	Point energyShieldPos;
	Point intruderPos;
};

struct SpaceStatus
{
	GL_Primitive *warningImages[10];
	WarningMessage *warningMessage;
	WarningMessage *incomingFire;
	Globals::Rect hitbox;
	Globals::Rect hitbox2;
	int currentEffect;
	int currentEffect2;
	SpaceManager *space;
	Point position;
	int touchedTooltip;
};

struct StarMap;
struct Store;

struct SystemControl
{
	struct PowerBars
	{
		GL_Primitive *normal[30];
		GL_Primitive *tiny[30];
		GL_Primitive *empty[30];
		GL_Primitive *damaged[30];
	};
	
	ShipManager *shipManager;
	CombatControl *combatControl;
	std::vector<SystemBox*> sysBoxes;
	Globals::Rect SystemPower;
	bool bSystemPowerHover;
	Point position;
	Point systemPowerPosition;
	Point subSystemPosition;
	GL_Primitive *wiresImage;
	GL_Primitive *wiresMask;
	GL_Primitive *noButton;
	GL_Primitive *button;
	GL_Primitive *noButton_cap;
	GL_Primitive *button_cap;
	GL_Primitive *drone;
	GL_Primitive *drone3;
	GL_Primitive *drone2;
	GL_Primitive *sub_box;
	int sub_spacing;
	WarningMessage *notEnoughPower;
	AnimationTracker flashBatteryPower;
	AnimationTracker flashTracker;
};

struct TabbedWindow : FocusWindow
{
	std::vector<Button*> buttons;
	std::vector<FocusWindow*> windows;
	std::vector<std::string> names;
	unsigned int currentTab;
	int buttonType;
	TextButton doneButton;
	Point move;
	bool bBlockClose;
	bool bTutorialMode;
	bool bWindowLock;
};

struct ReactorButton : Button
{
	int tempUpgrade;
	ShipManager *ship;
	bool selected;
};

struct UpgradeBox;

struct Upgrades : FocusWindow
{
	GL_Texture *box;
	std::vector<UpgradeBox*> vUpgradeBoxes;
	ShipManager *shipManager;
	TextButton undoButton;
	ReactorButton reactorButton;
	InfoBox infoBox;
	Point infoBoxLoc;
	int systemCount;
	int forceSystemInfoWidth;
};

struct CommandGui
{
	ShipStatus shipStatus;
	CrewControl crewControl;
	SystemControl sysControl;
	CombatControl combatControl;
	FTLButton ftlButton;
	SpaceStatus spaceStatus;
	StarMap *starMap;
	CompleteShip *shipComplete;
	std::vector<FocusWindow*> focusWindows;
	Point pauseTextLoc;
	GL_Primitive *pauseImage;
	GL_Primitive *pauseImage2;
	GL_Primitive *pauseImageAuto;
	GL_Primitive *pauseCrewImage;
	GL_Primitive *pauseDoorsImage;
	GL_Primitive *pauseHackingImage;
	GL_Primitive *pauseMindImage;
	GL_Primitive *pauseRoomImage;
	GL_Primitive *pauseTargetImage;
	GL_Primitive *pauseTargetBeamImage;
	GL_Primitive *pauseTeleportLeaveImage;
	GL_Primitive *pauseTeleportArriveImage;
	GL_Primitive *flareImage;
	Point shipPosition;
	std::string locationText;
	std::string loadEvent;
	int loadSector;
	ChoiceBox choiceBox;
	bool gameover;
	bool alreadyWon;
	bool outOfFuel;
	MenuScreen menuBox;
	GameOver gameOverScreen;
	OptionsScreen optionsBox;
	bool bPaused;
	bool bAutoPaused;
	bool menu_pause;
	bool event_pause;
	bool touch_pause;
	int touchPauseReason;
	InputBox inputBox;
	float fShakeTimer;
	TabbedWindow shipScreens;
	TabbedWindow storeScreens;
	Upgrades upgradeScreen;
	CrewManifest crewScreen;
	Equipment equipScreen;
	Location *newLocation;
	SpaceManager *space;
	Button upgradeButton;
	WarningMessage upgradeWarning;
	TextButton storeButton;
	Button optionsButton;
	const float pause_anim_time;
	float pause_animation;
	std::vector<Store*> storeTrash;
	TimerHelper flickerTimer;
	TimerHelper showTimer;
	bool bHideUI;
	CompleteShip *enemyShip;
	bool waitLocation;
	bool lastLocationWait;
	bool dangerLocation;
	std::vector<int> commandKey;
	bool jumpComplete;
	int mapId;
	ConfirmWindow leaveCrewDialog;
	bool secretSector;
	int activeTouch;
	bool activeTouchIsButton;
	bool activeTouchIsCrewBox;
	bool activeTouchIsShip;
	bool activeTouchIsNull;
	std::vector<int> extraTouches;
	bool bTutorialWasRunning;
	bool focusAteMouse;
	bool choiceBoxOpen;
	int systemDetailsWidth;
	ChoiceBox writeErrorDialog;
	bool suppressWriteError;
};

struct CrewLaser : Projectile
{
	int r;
	int g;
	int b;
};

struct Particle
{
	float position_x;
	float position_y;
	float speed_x;
	float speed_y;
	float acceleration_x;
	float acceleration_y;
	float lifespan;
	bool alive;
};

struct ParticleEmitter
{
	Particle particles[64];
	float birthRate;
	float birthCounter;
	float lifespan;
	float speedMag;
	float position_x;
	float position_y;
	float max_dx;
	float min_dx;
	float max_dy;
	float min_dy;
	int image_x;
	int image_y;
	GL_Primitive *primitive;
	float emitAngle;
	bool randAngle;
	bool running;
	float maxAlpha;
	float minSize;
	float maxSize;
	int currentCount;
};

struct LIBZHL_INTERFACE CrewAnimation
{
	virtual ~CrewAnimation() {}
	virtual void OnRender(float unk1, int unk2, bool unk3) LIBZHL_PLACEHOLDER
	virtual void OnRenderProps() LIBZHL_PLACEHOLDER
	virtual void OnUpdateEffects() LIBZHL_PLACEHOLDER
	virtual void UpdateFiring() LIBZHL_PLACEHOLDER
	virtual void UpdateShooting() LIBZHL_PLACEHOLDER
	virtual bool FireShot() LIBZHL_PLACEHOLDER
	virtual int GetFiringFrame() LIBZHL_PLACEHOLDER
	virtual std::string GetShootingSound() LIBZHL_PLACEHOLDER
	virtual std::string GetDeathSound() LIBZHL_PLACEHOLDER
	virtual void Restart() LIBZHL_PLACEHOLDER
	virtual bool CustomDeath() LIBZHL_PLACEHOLDER
	int iShipId;
	std::vector<std::vector<Animation>> anims;
	GL_Texture *baseStrip;
	GL_Texture *colorStrip;
	std::vector<GL_Texture*> layerStrips;
	Pointf lastPosition;
	int direction;
	int sub_direction;
	int status;
	int moveDirection;
	ParticleEmitter smokeEmitter;
	bool bSharedSpot;
	uint8_t gap_ex_1[4];
	std::vector<CrewLaser> shots;
	TimerHelper shootTimer;
	TimerHelper punchTimer;
	Pointf target;
	float fDamageDone;
	bool bPlayer;
	bool bFrozen;
	bool bDrone;
	bool bGhost;
	bool bExactShooting;
	Animation projectile;
	bool bTyping;
	std::string race;
	int currentShip;
	bool bMale;
	bool colorblind;
	uint8_t gap_ex_2[4];
	std::vector<GL_Color> layerColors;
	int forcedAnimation;
	int forcedDirection;
	GL_Color projectileColor;
	bool bStunned;
	bool bDoorTarget;
	bool uniqueBool1;
	bool uniqueBool2;
};

struct CrewBox
{
	Globals::Rect box;
	Globals::Rect skillBox;
	CrewMember *pCrew;
	bool mouseHover;
	TextButton powerButton;
	int number;
	bool bSelectable;
	AnimationTracker flashHealthTracker;
	GL_Primitive *boxBackground;
	GL_Primitive *boxOutline;
	GL_Primitive *skillBoxBackground;
	GL_Primitive *skillBoxOutline;
	GL_Primitive *cooldownBar;
	CachedImage healthWarning;
	int lastCooldownHeight;
	GL_Primitive *healthBar;
	int lastHealthWidth;
	Animation mindControlled;
	Animation stunned;
	bool hideExtra;
	std::string sTooltip;
};

struct CrewEquipBox : EquipmentBox
{
	ShipManager *ship;
	bool bDead;
	TextButton deleteButton;
	TextButton renameButton;
	bool bShowDelete;
	bool bShowRename;
	bool bQuickRenaming;
	TextInput nameInput;
	GL_Primitive *box;
	GL_Primitive *box_on;
	bool bConfirmDelete;
};

struct CrewCustomizeBox : CrewEquipBox
{
	TextButton customizeButton;
	bool bCustomizing;
	Point customizeLocation;
	TextButton acceptButton;
	TextButton bigRenameButton;
	Button leftButton;
	Button rightButton;
	bool bRenaming;
	bool haveCustomizeTouch;
	bool customizeActivated;
	GL_Primitive *box;
	GL_Primitive *box_on;
	GL_Texture *bigBox;
};

struct CrewDesc
{
	std::string type;
	float prop;
	int amount;
};

struct CrewMemberFactory
{
	int playerCrew;
	int enemyCrew;
	int enemyCloneCount;
	std::vector<CrewMember*> crewMembers;
	std::vector<CrewMember*> lostMembers;
};

struct CrewStatTracker
{
	int max;
	std::string name;
	std::string species;
	bool male;
	std::string title_id;
	bool newStat;
};

struct CrewStoreBox : StoreBox
{
	std::string name;
	Animation crewPortrait;
	CrewBlueprint blueprint;
};

struct LIBZHL_INTERFACE CrewTarget
{
	virtual ~CrewTarget() {}
	virtual void *GetPosition() LIBZHL_PLACEHOLDER
	virtual float PositionShift() LIBZHL_PLACEHOLDER
	virtual bool InsideRoom(int roomId) LIBZHL_PLACEHOLDER
	virtual bool ApplyDamage(float damage) LIBZHL_PLACEHOLDER
	virtual int GetPriority() LIBZHL_PLACEHOLDER
	virtual bool ValidTarget(int unk) LIBZHL_PLACEHOLDER
	virtual bool MultiShots() LIBZHL_PLACEHOLDER
	virtual bool ExactTarget() LIBZHL_PLACEHOLDER
	virtual bool IsCrew() LIBZHL_PLACEHOLDER
	virtual bool IsCloned() LIBZHL_PLACEHOLDER
	virtual bool IsDrone() LIBZHL_PLACEHOLDER
	int iShipId;
};

struct CrystalAlien : CrewMember
{
	std::pair<float, float> powerCooldown;
};

struct CrystalAnimation
{
};

struct DamageMessage
{
	AnimationTracker tracker;
	Pointf position;
	GL_Color color;
	bool bFloatDown;
	std::vector<GL_Primitive*> primitives;
};

struct DebugHelper
{
};

struct DefenseDrone : SpaceDrone
{
	int currentTargetId;
	int shotAtTargetId;
	float currentSpeed;
	CachedImage drone_image;
	CachedImage gun_image_off;
	CachedImage gun_image_charging;
	CachedImage gun_image_on;
	CachedImage engine_image;
	int currentTargetType;
};

struct DistressButton : TextButton
{
	TextString labels[2];
	bool state;
};

struct Selectable
{
	void *vptr;
	int selectedState;
};

struct Door : CrewTarget
{
	Selectable _selectable;
	int iRoom1;
	int iRoom2;
	bool bOpen;
	int iBlast;
	bool bFakeOpen;
	int width;
	int height;
	GL_Primitive *outlinePrimitive;
	GL_Primitive *highlightPrimitive;
	Animation doorAnim;
	Animation doorAnimLarge;
	int iDoorId;
	int baseHealth;
	int health;
	AnimationTracker forcedOpen;
	AnimationTracker gotHit;
	int doorLevel;
	bool bIoned;
	float fakeOpenTimer;
	AnimationTracker lockedDown;
	float lastbase;
	int iHacked;
	int x;
	int y;
	bool bVertical;
};

struct DoorBox : SystemBox
{
	GL_Texture *box;
	Button openDoors;
	Button closeDoors;
	ShipManager *ship;
	Point buttonOffset;
};

struct DroneBox
{
};

struct DroneEquipBox : EquipmentBox
{
};

struct DroneStoreBox : StoreBox
{
	DroneBlueprint *blueprint;
};

struct DroneSystem : ShipSystem
{
	std::vector<Drone*> drones;
	int drone_count;
	int drone_start;
	Targetable *targetShip;
	std::vector<bool> userPowered;
	int slot_count;
	int iStartingBatteryPower;
	std::vector<bool> repowerList;
};

struct LIBZHL_INTERFACE EnergyAlien
{
	virtual ~EnergyAlien() {}
	virtual Point GetPosition() LIBZHL_PLACEHOLDER
	virtual float PositionShift() LIBZHL_PLACEHOLDER
	virtual bool InsideRoom(int roomId) LIBZHL_PLACEHOLDER
	virtual bool ApplyDamage(float damage) LIBZHL_PLACEHOLDER
	virtual int GetPriority() LIBZHL_PLACEHOLDER
	virtual bool ValidTarget(int unk) LIBZHL_PLACEHOLDER
	virtual bool MultiShots() LIBZHL_PLACEHOLDER
	virtual bool ExactTarget() LIBZHL_PLACEHOLDER
	virtual bool IsCrew() LIBZHL_PLACEHOLDER
	virtual bool IsCloned() LIBZHL_PLACEHOLDER
	virtual bool IsDrone() LIBZHL_PLACEHOLDER
	virtual void Jump() LIBZHL_PLACEHOLDER
	virtual bool NeedsIntruderSlot() LIBZHL_PLACEHOLDER
	virtual void SaveState(int fileHelper) LIBZHL_PLACEHOLDER
	virtual void LoadState(int fileHelper) LIBZHL_PLACEHOLDER
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	virtual void OnRender(bool unk) LIBZHL_PLACEHOLDER
	virtual bool OutOfGame() LIBZHL_PLACEHOLDER
	virtual void SetOutOfGame() LIBZHL_PLACEHOLDER
	virtual bool Functional() LIBZHL_PLACEHOLDER
	virtual bool CountForVictory() LIBZHL_PLACEHOLDER
	virtual bool GetControllable() LIBZHL_PLACEHOLDER
	virtual bool ReadyToFight() LIBZHL_PLACEHOLDER
	virtual bool CanFight() LIBZHL_PLACEHOLDER
	virtual bool CanRepair() LIBZHL_PLACEHOLDER
	virtual bool CanSabotage() LIBZHL_PLACEHOLDER
	virtual bool CanMan() LIBZHL_PLACEHOLDER
	virtual bool CanTeleport() LIBZHL_PLACEHOLDER
	virtual bool CanHeal() LIBZHL_PLACEHOLDER
	virtual bool CanSuffocate() LIBZHL_PLACEHOLDER
	virtual bool CanBurn() LIBZHL_PLACEHOLDER
	virtual int GetMaxHealth() LIBZHL_PLACEHOLDER
	virtual bool IsDead() LIBZHL_PLACEHOLDER
	virtual bool PermanentDeath() LIBZHL_PLACEHOLDER
	virtual bool ShipDamage(float damage) LIBZHL_PLACEHOLDER
	virtual bool FireFightingSoundEffect() LIBZHL_PLACEHOLDER
	virtual std::string GetUniqueRepairing() LIBZHL_PLACEHOLDER
	virtual bool ProvidesVision() LIBZHL_PLACEHOLDER
	virtual float GetMoveSpeedMultiplier() LIBZHL_PLACEHOLDER
	virtual float GetRepairSpeed() LIBZHL_PLACEHOLDER
	virtual float GetDamageMultiplier() LIBZHL_PLACEHOLDER
	virtual bool ProvidesPower() LIBZHL_PLACEHOLDER
	virtual std::string GetSpecies() LIBZHL_PLACEHOLDER
	virtual float GetFireRepairMultiplier() LIBZHL_PLACEHOLDER
	virtual bool IsTelepathic() LIBZHL_PLACEHOLDER
	virtual std::pair<float, float> GetPowerCooldown() LIBZHL_PLACEHOLDER
	virtual bool PowerReady() LIBZHL_PLACEHOLDER
	virtual void ActivatePower() LIBZHL_PLACEHOLDER
	virtual bool HasSpecialPower() LIBZHL_PLACEHOLDER
	virtual void ResetPower() LIBZHL_PLACEHOLDER
	virtual float GetSuffocationMultiplier() LIBZHL_PLACEHOLDER
	virtual int BlockRoom() LIBZHL_PLACEHOLDER
	virtual Damage GetRoomDamage() LIBZHL_PLACEHOLDER
	virtual bool IsAnaerobic() LIBZHL_PLACEHOLDER
	virtual void UpdateRepair() LIBZHL_PLACEHOLDER
	virtual bool CanStim() LIBZHL_PLACEHOLDER
	int iShipId;
	float x;
	float y;
	float size;
	float scale;
	float goal_x;
	float goal_y;
	int width;
	int height;
	std::pair<float, float> health;
	float speed_x;
	float speed_y;
	Path path;
	bool new_path;
	float x_destination;
	float y_destination;
	Door *last_door;
	Repairable *currentRepair;
	bool bSuffocating;
	int moveGoal;
	int selectionState;
	int iRoomId;
	int iManningId;
	int iRepairId;
	int iStackId;
	Slot currentSlot;
	bool intruder;
	bool bFighting;
	bool bSharedSpot;
	CrewAnimation *crewAnim;
	GL_Texture *selectionImage;
	CachedImage healthBox;
	CachedImage healthBoxRed;
	CachedRect healthBar;
	float fMedbay;
	float lastDamageTimer;
	float lastHealthChange;
	int currentShipId;
	AnimationTracker flashHealthTracker;
	Pointf currentTarget;
	CrewTarget *crewTarget;
	BoardingGoal boardingGoal;
	bool bFrozen;
	bool bFrozenLocation;
	CrewTask task;
	std::string type;
	Ship *ship;
	Slot finalGoal;
	Door *blockingDoor;
	bool bOutOfGame;
	std::string species;
	bool bDead;
	uint8_t gap_ex_1[4];
	int iOnFire;
	bool bActiveManning;
	ShipSystem *currentSystem;
	int usingSkill;
	CrewBlueprint blueprint;
	Animation healing;
	Animation stunned;
	AnimationTracker levelUp;
	int lastLevelUp;
	SCrewStats stats;
	std::vector<std::vector<bool>> skillsEarned;
	bool clone_ready;
	bool bMindControlled;
	int iDeathNumber;
	Animation mindControlled;
	Animation stunIcon;
	std::vector<std::vector<AnimationTracker>> skillUp;
	int healthBoost;
	float fMindDamageBoost;
	float fCloneDying;
	bool bResisted;
	uint8_t gap_ex_2[4];
	Slot savedPosition;
	float fStunTime;
	CachedImage movementTarget;
	bool bCloned;
	bool bTriggerExplosion;
	bool bExploded;
};

struct EnergyAnimation
{
};

struct EngiAlien
{
};

struct EngiAnimation
{
};

struct EngineSystem
{
};

struct EventDamage
{
	int system;
	int amount;
	int effect;
};

struct EventTemplate;

struct EventText
{
	TextString text;
	std::string planet;
	std::string back;
};

struct LocationEvent;

struct SectorDescription
{
	std::vector<std_pair_std_string_RandomAmount> eventCounts;
	std::vector<std_pair_std_string_int> rarities;
	bool unique;
	std::vector<TextString> names;
	std::vector<TextString> shortNames;
	std::vector<std::string> musicTracks;
	std::string type;
	TextString name;
	TextString shortName;
	int minSector;
	bool used;
	std::string firstEvent;
};

struct ShipEvent
{
	bool present;
	std::string name;
	std::string blueprint;
	std::string auto_blueprint;
	std::vector<std::string> blueprintList;
	ShipBlueprint actualBlueprint;
	bool hostile;
	std::string surrender;
	std::string escape;
	std::string destroyed;
	std::string deadCrew;
	std::string gotaway;
	int escapeTimer;
	RandomAmount surrenderThreshold;
	RandomAmount escapeThreshold;
	std::vector<CrewDesc> crewOverride;
	std::vector<std::string> weaponOverride;
	int weaponOverCount;
	std::vector<std::string> droneOverride;
	int droneOverCount;
	int shipSeed;
};

struct EventGenerator
{
	std::vector<std::string> baseEvents;
	std::unordered_map<std::string, SectorDescription> sectors;
	std::unordered_map<std::string, std::vector<std::string>> baseSectors;
	std::unordered_map<std::string, std::vector<std::string>> eventLists;
	std::unordered_map<std::string, EventTemplate*> events;
	std::unordered_map<std::string, EventTemplate*> usedEvents;
	std::unordered_map<std::string, std::vector<EventText>> textLists;
	std::unordered_map<std::string, std::vector<EventText>> usedTextLists;
	std::unordered_map<std::string, std::vector<std::string>> shipTemplateLists;
	std::unordered_map<std::string, ShipEvent> shipTemplates;
	std::unordered_map<std::string, std::vector<std::string>> imageLists;
	std::vector<LocationEvent*> trashList;
	std::unordered_map<std::string, ResourceEvent> resourcesCollected;
	std::unordered_map<std::string, int> eventTypesCreated;
	int shipsCreated;
	bool shiplessEvent;
	bool creatingShipEvent;
	int forceRandomIndex;
};

struct EventSystem
{
	std::vector<int> lastEvents;
	std::vector<int> newEvents;
};

struct ResourcesTemplate
{
	RandomAmount fuel;
	RandomAmount drones;
	RandomAmount missiles;
	RandomAmount scrap;
	RandomAmount items;
	int crew;
	std::string crewType;
	TextString crewName;
	bool cloneable;
	TextString cloneText;
	std::vector<std_pair_int_int> crewSkills;
	std::string weapon;
	std::string drone;
	std::string augment;
	std::string system;
	bool steal;
	int upgradeAmount;
	int upgradeId;
	std::string removeItem;
};

struct RewardDesc
{
	std::string reward;
	int level;
};

struct ShipTemplate
{
	std::string shipEventName;
	bool hostile;
};

struct StatusEffect
{
	int type;
	int system;
	int amount;
	int target;
};

struct EventTemplate
{
	struct ChoiceTemplate
	{
		TextString text;
		bool loadText;
		std::string eventName;
		bool hiddenReward;
		ChoiceReq requirement;
	};
	
	ResourcesTemplate resources;
	RewardDesc reward;
	TextString text;
	bool loadText;
	bool unique;
	ShipTemplate shipTemplate;
	std::string eventName;
	std::vector<EventDamage> damage;
	int environmentFlag;
	int environmentTarget;
	bool store;
	bool repair;
	bool reveal_map;
	std::vector<StatusEffect> statusEffects;
	bool distressBeacon;
	BoardingEvent boarders;
	int modifyPursuit;
	std::vector<ChoiceTemplate> choices;
	std::vector<std_pair_std_string_std_string> nameDefinitions;
	std::string imageBackground;
	std::string imagePlanet;
	std::string quest;
	TextString unlockShipText;
	int unlockShip;
	int fleet;
	bool secretSector;
};

struct EventsParser
{
	std::unordered_map<std::string, EventTemplate*> eventTemplates;
	std::vector<EventTemplate*> trashList;
	std::unordered_map<std::string, ShipEvent> shipTemplates;
};

struct GL_Texture
{
	int id_;
	int width_;
	int height_;
	bool isLogical_;
	float u_base_;
	float v_base_;
	float u_size_;
	float v_size_;
};

struct ExplosionAnimation : AnimationTracker
{
	ShipObject shipObj;
	std::vector<Animation> explosions;
	std::vector<GL_Texture> pieces;
	std::vector<std::string> pieceNames;
	std::vector<float> rotationSpeed;
	std::vector<float> rotation;
	std::vector<std_pair_float_float> rotationSpeedMinMax;
	std::vector<Pointf> movementVector;
	std::vector<Pointf> position;
	std::vector<Pointf> startingPosition;
	float explosionTimer;
	float soundTimer;
	bool bFinalBoom;
	bool bJumpOut;
	std::vector<WeaponAnimation> weaponAnims;
	Point pos;
};

struct FileHelper
{
};

struct Repairable : Selectable
{
	ShipObject shipObj;
	float fDamage;
	Point pLoc;
	float fMaxDamage;
	std::string name;
	int roomId;
	int iRepairCount;
};

struct Spreadable : Repairable
{
	std::string soundName;
};

struct Fire : Spreadable
{
	float fDeathTimer;
	float fStartTimer;
	float fOxygen;
	Animation fireAnimation;
	Animation smokeAnimation;
	bool bWasOnFire;
};

struct GL_ColorTexVertex
{
	float x;
	float y;
	float u;
	float v;
	float r;
	float g;
	float b;
	float a;
};

struct GL_FrameBuffer
{
};

struct GL_Line
{
	Pointf start;
	Pointf end;
};

struct GL_Primitive
{
	int type;
	float lineWidth;
	bool hasTexture;
	GL_Texture *texture;
	bool textureAntialias;
	bool hasColor;
	GL_Color color;
	int id;
};

struct GL_TexVertex
{
	float x;
	float y;
	float u;
	float v;
};

struct Ghost
{
};

struct HackingSystem;

struct HackBox : CooldownSystemBox
{
	HackingSystem *hackSys;
	std::vector<Button*> buttons;
	Button *currentButton;
	Point buttonOffset;
	GL_Texture *box;
	GL_Texture *box2;
	Button hackButton;
	Button overlayButton;
	ShipManager *shipManager;
	AnimationTracker flashTracker;
	WarningMessage *superShieldWarning;
};

struct HackingDrone : SpaceDrone
{
	Pointf startingPosition;
	GL_Texture *droneImage_on;
	GL_Texture *droneImage_off;
	GL_Texture *lightImage;
	Pointf finalDestination;
	bool arrived;
	bool finishedSetup;
	AnimationTracker flashTracker;
	Animation flying;
	Animation extending;
	Animation explosion;
	int prefRoom;
};

struct HackingSystem : ShipSystem
{
	bool bHacking;
	HackingDrone drone;
	bool bBlocked;
	bool bArmed;
	ShipSystem *currentSystem;
	std::pair<float, float> effectTimer;
	bool bCanHack;
	ShipSystem *queuedSystem;
	int spendDrone;
};

struct HotkeyDesc
{
	std::string name;
	int key;
};

struct ImageDesc
{
	GL_Texture *tex;
	int resId;
	int w;
	int h;
	int x;
	int y;
	int rot;
};

struct InputEventUnion
{
	char eventData[20];
};

struct InputEvent
{
	InputEventType type;
	InputEventDetail detail;
	double timestamp;
	InputEventUnion event;
};

struct IonDrone : BoarderDrone
{
	int lastRoom;
};

struct IonDroneAnimation : CrewAnimation
{
	Animation ionExplosion;
	Animation ionAnimation;
	Animation doorAnimations[4];
	Animation ionGlow;
	float ionEffect;
	bool damagedDoor;
};

struct ItemBlueprint;

struct ItemStoreBox : StoreBox
{
	ItemBlueprint *blueprint;
};

struct JoystickInputEvent
{
	int device;
	int index;
	float x;
	float y;
};

struct KeyboardInputEvent
{
	int key;
	int system_key;
	unsigned int modifiers;
	char is_repeat;
};

struct LaserBlast : Projectile
{
	Targetable *movingTarget;
	float spinAngle;
	float spinSpeed;
};

struct Location
{
	Pointf loc;
	std::vector<Location*> connectedLocations;
	bool beacon;
	bool known;
	int visited;
	bool dangerZone;
	bool newSector;
	bool nebula;
	bool boss;
	LocationEvent *event;
	ImageDesc planet;
	ImageDesc space;
	ImageDesc beaconImage;
	GL_Texture *imageId;
	bool questLoc;
	AnimationTracker flashTracker;
	bool fleetChanging;
	std::string planetImage;
	std::string spaceImage;
};

struct LocationEvent
{
	struct Choice
	{
		LocationEvent *event;
		TextString text;
		ChoiceReq requirement;
		bool hiddenReward;
	};
	
	TextString text;
	ShipEvent ship;
	ResourceEvent stuff;
	int environment;
	int environmentTarget;
	bool store;
	bool gap_ex_cleared;
	int fleetPosition;
	bool beacon;
	bool reveal_map;
	bool distressBeacon;
	bool repair;
	int modifyPursuit;
	Store *pStore;
	std::vector<EventDamage> damage;
	std::string quest;
	std::vector<StatusEffect> statusEffects;
	std::vector<std_pair_std_string_std_string> nameDefinitions;
	std::string spaceImage;
	std::string planetImage;
	std::string eventName;
	ResourceEvent reward;
	BoardingEvent boarders;
	std::vector<Choice> choices;
	int unlockShip;
	TextString unlockShipText;
	bool secretSector;
};

struct LockdownShard
{
	Animation shard;
	Pointf position;
	Pointf goal;
	float speed;
	bool bArrived;
	bool bDone;
	float lifeTime;
	bool superFreeze;
	int lockingRoom;
};

struct MantisAlien
{
};

struct MantisAnimation : CrewAnimation
{
};

struct MedbaySystem
{
};

struct MemoryInputEvent
{
	int64_t used_bytes;
	int64_t free_bytes;
};

struct MindSystem;

struct MindBox : CooldownSystemBox
{
	MindSystem *mindSystem;
	Button mindControl;
	Point buttonOffset;
	WarningMessage *superShieldWarning;
};

struct MindSystem : ShipSystem
{
	std::pair<float, float> controlTimer;
	bool bCanUse;
	int iArmed;
	std::vector<CrewMember*> controlledCrew;
	bool bSuperShields;
	bool bBlocked;
	int iQueuedTarget;
	int iQueuedShip;
	std::vector<CrewMember*> queuedCrew;
};

struct Missile : Projectile
{
};

struct Moddable
{
};

struct MouseControl
{
	Point position;
	Point lastPosition;
	int aiming_required;
	int iTeleporting;
	int iMindControlling;
	bool bSellingStuff;
	bool valid;
	bool newHover;
	bool lastValid;
	int animateDoor;
	GL_Texture *validPointer;
	GL_Texture *invalidPointer;
	GL_Texture *selling;
	Animation openDoor;
	int tooltipFont;
	std::string tooltip;
	float tooltipTimer;
	bool bMoving;
	bool bHideMouse;
	GL_Texture *lastIcon;
	GL_Texture *lastAddition;
	bool bForceTooltip;
	std::string tooltipTitle;
	std::string lastTooltipText;
	int iHacking;
	int overrideTooltipWidth;
	Point staticTooltip;
};

struct MouseInputEvent
{
	float x;
	float y;
	float scroll;
};

struct NebulaCloud
{
	Point pos;
	float currAlpha;
	float currScale;
	float deltaAlpha;
	float deltaScale;
	float newTrigger;
	bool newCloud;
	bool bLightning;
	AnimationTracker lightningFlash;
	float flashTimer;
	float lightningRotation;
};

struct OuterHull : Repairable
{
	Animation breach;
	Animation heal;
};

struct OxygenSystem : ShipSystem
{
	float max_oxygen;
	std::vector<float> oxygenLevels;
	float fTotalOxygen;
	bool bLeakingO2;
};

struct PDSFire : LaserBlast
{
	Pointf startPoint;
	bool passedTarget;
	float currentScale;
	bool missed;
	Animation explosionAnimation;
};

struct PackageModuleInfo
{
};

struct PowerManager
{
	std::pair<int, int> currentPower;
	int over_powered;
	float fFuel;
	bool failedPowerup;
	int iTempPowerCap;
	int iTempPowerLoss;
	int iTempDividePower;
	int iHacked;
	std::pair<int, int> batteryPower;
};

struct ProjectileFactory : ShipObject
{
	std::pair<float, float> cooldown;
	std::pair<float, float> subCooldown;
	float baseCooldown;
	const WeaponBlueprint *blueprint;
	Point localPosition;
	Animation flight_animation;
	bool autoFiring;
	bool fireWhenReady;
	bool powered;
	int requiredPower;
	std::vector<Pointf> targets;
	std::vector<Pointf> lastTargets;
	int targetId;
	int iAmmo;
	std::string name;
	int numShots;
	float currentFiringAngle;
	float currentEntryAngle;
	Targetable *currentShipTarget;
	CloakingSystem *cloakingSystem;
	WeaponAnimation weaponVisual;
	WeaponMount mount;
	std::vector<Projectile*> queuedProjectiles;
	int iBonusPower;
	bool bFiredOnce;
	int iSpendMissile;
	float cooldownModifier;
	int shotsFiredAtTarget;
	int radius;
	int boostLevel;
	int lastProjectileId;
	int chargeLevel;
	int iHackLevel;
	int goalChargeLevel;
	bool isArtillery;
};

struct RepairAnimation
{
};

struct RepairDrone : CrewDrone
{
};

struct RepairStoreBox : StoreBox
{
	bool repairAll;
	int repairCost;
	TextString buttonText;
};

struct PackageModuleInfo;

struct ResourceManager;

struct freetype
{
	struct font_data
	{
		float h;
		int font;
		float fontsize;
		float baseline;
		float lineHeight;
	};
	
};

struct ResourceControl
{
	struct DynamicImageInfo
	{
		std::string name;
		int resid;
	};
	
	struct LogicalTexInfo
	{
		std::string physName;
		int x;
		int y;
		int w;
		int h;
	};
	
	std::unordered_map<std::string, GL_Texture*> images;
	std::unordered_map<int, freetype::font_data> fonts;
	std::unordered_map<GL_Texture*, ImageDesc> imageData;
	std::pair<int, int> preLoadProgress;
	std::string nextImageLoaded;
	int imageSwappingMode;
	std::vector<std::string> playerShipImages;
	std::vector<std::string> hangarShipImages;
	std::vector<std::string> enemyShipImages;
	std::vector<DynamicImageInfo> dynamicImages;
	int dynamicLoadMark;
	std::unordered_map<std::string, LogicalTexInfo> atlasData;
	ResourceManager *resmgr;
	PackageModuleInfo *package;
	GL_Texture *loading_box;
	GL_Texture *loading_bar;
	int screenWidth;
	int screenHeight;
	int renderPointX;
	int renderPointY;
	GL_FrameBuffer *frameBuffer;
	int fbViewportX;
	int fbViewportY;
	int fbViewportW;
	int fbViewportH;
};

struct ResourceManager
{
};

struct RockAlien
{
};

struct RockAnimation : CrewAnimation
{
};

struct Room : Selectable
{
	ShipObject _shipObject;
	Globals::Rect rect;
	int iRoomId;
	bool bBlackedOut;
	uint8_t gap_ex_1[4];
	std::vector<int> filledSlots;
	std::vector<std::vector<bool>> slots;
	bool bWarningLight;
	uint8_t gap_ex_2[4];
	AnimationTracker lightTracker;
	int iFireCount;
	std::vector<Animation> fires;
	int primarySlot;
	int primaryDirection;
	float lastO2;
	GL_Primitive *floorPrimitive;
	GL_Primitive *blackoutPrimitive;
	GL_Primitive *highlightPrimitive;
	GL_Primitive *highlightPrimitive2;
	GL_Primitive *o2LowPrimitive;
	GL_Primitive *computerPrimitive;
	GL_Primitive *computerGlowPrimitive;
	GL_Primitive *computerGlowYellowPrimitive;
	GL_Primitive *lightPrimitive;
	GL_Primitive *lightGlowPrimitive;
	Animation stunSparks;
	Animation consoleSparks;
	bool bStunning;
	float fHacked;
	int currentSparkRotation;
	std::vector<Animation> sparks;
	float sparkTimer;
	int sparkCount;
	int iHackLevel;
	Animation roomTapped;
};

struct StatTracker
{
	int max;
	int total;
	int current;
	std::string desc_id;
	int sector;
};

struct TopScore
{
	std::string name;
	std::string blueprint;
	GL_Texture *image;
	int sector;
	int score;
	bool victory;
	int difficulty;
	bool advancedContent;
};

struct ScoreKeeper
{
	StatTracker stats[4];
	CrewStatTracker crewStats[5];
	int gamesPlayed;
	int victories;
	TopScore currentScore;
	std::vector<std::vector<bool>> unlocked;
	bool firstRun;
	std::vector<TopScore> topScores;
	std::vector<std::vector<std::vector<TopScore>>> shipScores;
	bool bSavedScore;
	int newestHighScore;
	int newestShipBest;
	int newestShipType;
	int newestShipLayout;
	std::vector<std_pair_CAchievement_ptr_Point> achievements;
	std::vector<std_pair_CAchievement_ptr_Point> shipAchievements;
	GL_Texture *rightBox[2];
	GL_Texture *leftBox[2];
	Button rightButtons[2];
	Button leftButtons[2];
	bool activatedRight;
	bool activatedLeft;
	GL_Texture *lockIcon;
	InfoBox infoBox;
	TextButton closeButton;
	TextButton typeA;
	TextButton typeB;
	TextButton typeC;
	Button leftButton;
	Button rightButton;
	TextButton listButton;
	std::vector<GenericButton*> buttons;
	int selectedShip;
	int selectedLayout;
	int selectedAch;
	int selectedShipAch;
	ShipSelect shipSelect;
	int activeTouch;
	bool forceUnlockAll;
	bool gotCloseEvent;
	int loadingGameVersion;
	Point shipListCenter;
	Point typeALoc;
	Point typeBLoc;
	Point typeCLoc;
};

struct Scroller
{
	GL_Texture *imageId;
	int size_x;
	int size_y;
	int image_x;
	int image_y;
	float fSpeed;
	float current_x;
	bool bInitialized;
};

struct Sector;

struct Sector
{
	int type;
	bool visited;
	bool reachable;
	std::vector<Sector*> neighbors;
	Point location;
	int level;
	SectorDescription description;
};

struct SettingValues
{
	int fullscreen;
	int currentFullscreen;
	int lastFullscreen;
	int sound;
	int music;
	int difficulty;
	bool commandConsole;
	bool altPause;
	bool touchAutoPause;
	bool lowend;
	bool fbError;
	std::string language;
	bool languageSet;
	Point screenResolution;
	int dialogKeys;
	bool logging;
	bool bShowChangelog;
	int loadingSaveVersion;
	bool achPopups;
	bool vsync;
	bool frameLimit;
	bool manualResolution;
	bool manualWindowed;
	bool manualStretched;
	bool showPaths;
	bool swapTextureType;
	bool colorblind;
	std::array<std::vector<HotkeyDesc>, 4> hotkeys;
	bool holdingModifier;
	bool bDlcEnabled;
	int openedList;
	bool beamTutorial;
};

struct Settings
{
};

struct Shields : ShipSystem
{
	struct Shield
	{
		float charger;
		ShieldPower power;
		float superTimer;
	};
	
	struct ShieldAnimation
	{
		Pointf location;
		float current_size;
		float end_size;
		float current_thickness;
		float end_thickness;
		float length;
		float dx;
		int side;
		int ownerId;
		int damage;
	};
	
	float ellipseRatio;
	Point center;
	Globals::Ellipse baseShield;
	int iHighlightedSide;
	float debug_x;
	float debug_y;
	Shield shields;
	bool shields_shutdown;
	std::vector<ShieldAnimation> shieldHits;
	AnimationTracker shieldsDown;
	bool superShieldDown;
	Pointf shieldsDownPoint;
	AnimationTracker shieldsUp;
	GL_Texture *shieldImage;
	GL_Primitive *shieldPrimitive;
	std::string shieldImageName;
	bool bEnemyPresent;
	std::vector<DamageMessage*> damMessages;
	bool bBarrierMode;
	float lastHitTimer;
	float chargeTime;
	int lastHitShieldLevel;
	AnimationTracker superShieldUp;
	Point superUpLoc;
	bool bExcessChargeHack;
};

struct OuterHull;

struct Room;

struct Ship : ShipObject
{
	struct DoorState
	{
		DoorStateType state;
		bool hacked;
		int level;
	};
	
	std::vector<Room*> vRoomList;
	std::vector<Door*> vDoorList;
	std::vector<OuterHull*> vOuterWalls;
	std::vector<Door*> vOuterAirlocks;
	std::pair<int, int> hullIntegrity;
	std::vector<WeaponMount> weaponMounts;
	std::string floorImageName;
	ImageDesc shipFloor;
	GL_Primitive *floorPrimitive;
	std::string shipImageName;
	ImageDesc shipImage;
	Point glowOffset;
	GL_Primitive *shipImagePrimitive;
	std::string cloakImageName;
	ImageDesc shipImageCloak;
	GL_Primitive *cloakPrimitive;
	GL_Primitive *gridPrimitive;
	GL_Primitive *wallsPrimitive;
	GL_Primitive *doorsPrimitive;
	std::vector<DoorState> doorState;
	bool lastDoorControlMode;
	GL_Texture *thrustersImage;
	GL_Texture *jumpGlare;
	int vertical_shift;
	int horizontal_shift;
	std::string shipName;
	ExplosionAnimation explosion;
	bool bDestroyed;
	Globals::Ellipse baseEllipse;
	Animation engineAnim[2];
	AnimationTracker cloakingTracker;
	bool bCloaked;
	bool bExperiment;
	bool bShowEngines;
	std::vector<LockdownShard> lockdowns;
};

struct ShipButton : Button
{
	GL_Texture *iShipImage;
	bool bShipLocked;
	bool bLayoutLocked;
	bool bNoExist;
	std::vector<CAchievement*> achievements;
	int iSelectedAch;
	bool bSelected;
};

struct ShipGenerator
{
};

struct ShipGraph
{
	std::vector<Room*> rooms;
	std::vector<Door*> doors;
	std::vector<int> doorCounts;
	Point center;
	Pointf worldPosition;
	float worldHeading;
	Pointf lastWorldPosition;
	float lastWorldHeading;
	Globals::Rect shipBox;
	std::string shipName;
};

struct ShipInfo
{
	std::map<std::string, int> augList;
	std::map<std::string, int> equipList;
	int augCount;
};

struct EngineSystem;
struct MedbaySystem;
struct OxygenSystem;
struct ParticleEmitter;
struct Shields;

struct Spreader_Fire : ShipObject
{
	int count;
	std::vector<int> roomCount;
	std::vector<std::vector<Fire>> grid;
};

struct TeleportSystem;

struct ShipManager : ShipObject
{
	Targetable _targetable;
	Collideable _collideable;
	std::vector<ShipSystem*> vSystemList;
	OxygenSystem *oxygenSystem;
	TeleportSystem *teleportSystem;
	CloakingSystem *cloakSystem;
	BatterySystem *batterySystem;
	MindSystem *mindSystem;
	CloneSystem *cloneSystem;
	HackingSystem *hackingSystem;
	bool showNetwork;
	bool addedSystem;
	uint8_t gap_ex_1[4];
	Shields *shieldSystem;
	WeaponSystem *weaponSystem;
	DroneSystem *droneSystem;
	EngineSystem *engineSystem;
	MedbaySystem *medbaySystem;
	std::vector<ArtillerySystem*> artillerySystems;
	std::vector<CrewMember*> vCrewList;
	Spreader_Fire fireSpreader;
	Ship ship;
	char statusMessages[40];
	bool bGameOver;
	ShipManager *current_target;
	std::pair<float, float> jump_timer;
	int fuel_count;
	bool hostile_ship;
	bool bDestroyed;
	int iLastDamage;
	AnimationTracker jumpAnimation;
	std::vector<DamageMessage*> damMessages;
	std::vector<int> systemKey;
	int currentScrap;
	bool bJumping;
	bool bAutomated;
	uint8_t gap_ex_2[4];
	int shipLevel;
	ShipBlueprint myBlueprint;
	bool lastEngineStatus;
	bool lastJumpReady;
	bool bContainsPlayerCrew;
	int iIntruderCount;
	std::vector<std::vector<int>> crewCounts;
	int tempDroneCount;
	int tempMissileCount;
	std::vector<Animation> explosions;
	std::vector<bool> tempVision;
	bool bHighlightCrew;
	std::vector<Drone*> droneTrash;
	std::vector<SpaceDrone*> spaceDrones;
	std::vector<SpaceDrone*> newDroneArrivals;
	int bpCount;
	int iCustomizeMode;
	bool bShowRoom;
	std::vector<Projectile*> superBarrage;
	bool bInvincible;
	std::vector<SpaceDrone*> superDrones;
	GL_Primitive *highlight;
	int failedDodgeCounter;
	std::vector<float> hitByBeam;
	bool enemyDamagedUncloaked;
	int damageCloaked;
	std::map<int, int> killedByBeam;
	int minBeaconHealth;
	std::vector<ParticleEmitter*> fireExtinguishers;
	bool bWasSafe;
};

struct ShipRepair
{
};

struct ShipRepairDrone
{
};

struct SlugAlien
{
};

struct SlugAnimation
{
};

struct SoundControl
{
};

struct SpaceManager
{
	struct FleetShip
	{
		GL_Texture *image;
		Point location;
	};
	
	std::vector<Projectile*> projectiles;
	AsteroidGenerator asteroidGenerator;
	std::vector<ShipManager*> ships;
	std::vector<SpaceDrone*> drones;
	bool dangerZone;
	GL_Texture *currentBack;
	ImageDesc currentPlanet;
	CachedImage planetImage;
	ImageDesc fleetShip;
	GL_Texture *shipIds[8];
	FleetShip fleetShips[9];
	Scroller asteroidScroller[3];
	GL_Texture *sunImage;
	GL_Texture *sunGlow;
	AnimationTracker sunGlow1;
	AnimationTracker sunGlow2;
	AnimationTracker sunGlow3;
	bool sunLevel;
	bool pulsarLevel;
	GL_Texture *pulsarFront;
	GL_Texture *pulsarBack;
	GL_Texture *lowendPulsar;
	bool bPDS;
	int envTarget;
	Point shipPosition;
	float randomPDSTimer;
	std::vector<Projectile*> pdsQueue;
	TimerHelper flashTimer;
	AnimationTracker flashTracker;
	ImageDesc currentBeacon;
	ImageDesc currentBeaconFlash;
	AnimationTracker beaconTracker;
	bool flashSound;
	bool bNebula;
	bool bStorm;
	std::vector<NebulaCloud> nebulaClouds;
	GL_Texture *lowendNebula;
	GL_Texture *lowendStorm;
	GL_Texture *lowendSun;
	GL_Texture *lowendAsteroids;
	float shipHealth;
	bool gamePaused;
	TimerHelper pdsFireTimer;
	int pdsCountdown;
	std::vector<Animation> pdsSmokeAnims;
	bool queueScreenShake;
	bool playerShipInFront;
};

struct WindowFrame
{
	Globals::Rect rect;
	GL_Primitive *outline;
	GL_Primitive *mask;
	GL_Primitive *pattern;
};

struct StarMap : FocusWindow
{
	struct NebulaInfo
	{
		GL_Primitive *primitive;
		int x;
		int y;
		int w;
		int h;
	};
	
	float visual_size;
	std::vector<Location*> locations;
	std::map<Point, Location*> locations_grid;
	std::vector<Location*> temp_path;
	Location *currentLoc;
	Location *potentialLoc;
	Location *hoverLoc;
	Point position;
	int iPopulatedTiles;
	int iLocationCount;
	int iEmptyTiles;
	bool bInitializedDisplay;
	Pointf translation;
	bool readyToTravel;
	Point dangerZone;
	float dangerZoneRadius;
	float shipRotation[2];
	TextButton endButton;
	TextButton waitButton;
	DistressButton distressButton;
	TextButton jumpButton;
	int worldLevel;
	bool bMapRevealed;
	int pursuitDelay;
	int sectorNameFont;
	WindowFrame mapBorder;
	GL_Primitive *mapBorderTitle;
	GL_Primitive *mapBorderTitleMask;
	GL_Texture *mapBorderSector;
	GL_Texture *mapInsetTextLeft;
	GL_Texture *mapInsetTextMiddle;
	GL_Texture *mapInsetTextRight;
	GL_Texture *mapInsetTextJump;
	GL_Texture *mapInsetWaitDistress;
	GL_Primitive *redLight;
	GL_Primitive *fuelMessage;
	GL_Primitive *waitingMessage;
	GL_Primitive *unexplored;
	GL_Primitive *explored;
	GL_Primitive *danger;
	GL_Primitive *warning;
	GL_Primitive *yellow_warning;
	GL_Primitive *warning_circle;
	GL_Primitive *nebula_circle;
	GL_Texture *boxGreen[3];
	GL_Texture *boxPurple[3];
	GL_Texture *boxWhite[3];
	GL_Primitive *ship;
	GL_Primitive *shipNoFuel;
	GL_Primitive *bossShip;
	GL_Primitive *dangerZoneEdge;
	GL_Texture *dangerZoneTile;
	GL_Primitive *dangerZoneAdvance;
	GL_Primitive *targetBox;
	GL_Primitive *sectorTargetBox_green;
	GL_Primitive *sectorTargetBox_yellow;
	AnimationTracker targetBoxTimer;
	TextButton closeButton;
	WindowFrame *descBox;
	GL_Primitive *shadow;
	GL_Primitive *warning_shadow;
	GL_Primitive *fuelOverlay;
	GL_Primitive *dangerFlash;
	GL_Primitive *mapsBottom[3];
	GL_Texture *dottedLine;
	GL_Texture *cross;
	GL_Texture *boss_jumps_box;
	std::vector<ImageDesc> smallNebula;
	std::vector<ImageDesc> largeNebula;
	std::vector<NebulaInfo> currentNebulas;
	ShipManager *shipManager;
	bool outOfFuel;
	AnimationTracker waiting;
	int dangerWaitStart;
	AnimationTracker distressAnim;
	bool bTutorialGenerated;
	std::vector<std::string> delayedQuests;
	std::vector<Sector*> sectors;
	Sector *currentSector;
	Sector *secretSector;
	bool bChoosingNewSector;
	bool bSecretSector;
	Location dummyNewSector;
	int mapsAnalyzed;
	int locationsCreated;
	int shipsCreated;
	std::map<std::string, int> scrapCollected;
	std::map<std::string, int> dronesCollected;
	std::map<std::string, int> fuelCollected;
	std::map<std::string, int> weaponFound;
	std::map<std::string, int> droneFound;
	int bossLoc;
	int arrivedAtBase;
	bool reversedPath;
	bool bossJumping;
	std::vector<Location*> boss_path;
	bool bossLevel;
	bool boss_wait;
	Pointf bossPosition;
	std::string forceSectorChoice;
	bool bEnemyShip;
	bool bNebulaMap;
	bool bInfiniteMode;
	std::vector<Sector*> lastSectors;
	TextButton closeSectorButton;
	int sectorMapSeed;
	int currentSectorSeed;
	int fuelEventSeed;
	std::string lastEscapeEvent;
	bool waitedLast;
	std::vector<Store*> storeTrash;
	std::vector<std_pair_std_string_int> addedQuests;
	int bossStage;
	TextString bossMessage;
	WarningMessage *bossJumpingWarning;
	bool crystalAlienFound;
	std::map<Location*, bool> foundMap;
	Point sectorMapOffset;
	int potentialSectorChoice;
	int finalSectorChoice;
	std::vector<Globals::Rect> sectorHitBoxes;
};

struct Store : FocusWindow
{
	GL_Texture *box;
	TextString headingTitle[4];
	Button page1;
	Button page2;
	ConfirmWindow confirmDialog;
	Button *currentButton;
	Description currentDescription;
	std::string unavailable;
	std::vector<StoreBox*> vStoreBoxes;
	std::vector<StoreBox*> vItemBoxes;
	ShipManager *shopper;
	int selectedWeapon;
	int selectedDrone;
	InfoBox infoBox;
	Point infoBoxLoc;
	Button exitButton;
	int worldLevel;
	int sectionCount;
	int types[4];
	bool bShowPage2;
	uint8_t gap_ex_2[4];
	StoreBox *confirmBuy;
	int forceSystemInfoWidth;
};

struct SuperShieldDrone
{
};

struct SystemCustomBox : SystemBox
{
	ShipManager *shipManager;
	Button button;
};

struct SystemStoreBox : StoreBox
{
	SystemBlueprint *blueprint;
	int type;
	bool bConfirming;
	std::string confirmString;
	std::string freeBlueprint;
	int droneChoice;
};

struct TeleportBox : SystemBox
{
	GL_Texture *box;
	Button teleportLeave;
	Button teleportArrive;
	TeleportSystem *teleSystem;
	Point buttonOffset;
	WarningMessage superShieldWarning;
};

struct TeleportSystem : ShipSystem
{
	float chargeLevel;
	bool bCanSend;
	bool bCanReceive;
	int iArmed;
	std::vector<bool> crewSlots;
	int iPreparedCrew;
	int iNumSlots;
	bool bSuperShields;
};

struct TextInputEvent
{
	int32_t ch;
};

struct TextLibrary
{
	std::map<std::string, std::string> dictionary;
	std::map<std::string, std_map_std_string_std_string> languageDictionaries;
	std::string currentLanguage;
};

struct ToggleButton
{
};

struct TouchInputEvent
{
	unsigned int id;
	float x;
	float y;
	float initial_x;
	float initial_y;
};

struct TouchTooltip
{
};

struct TutorialManager
{
};

struct UpgradeBox
{
	ShipSystem *system;
	ShipManager *ship;
	const SystemBlueprint *blueprint;
	Point location;
	int tempUpgrade;
	Button *currentButton;
	std::string buttonBaseName;
	Button maxButton;
	Button boxButton;
	bool subsystem;
	bool isDummy;
	GL_Primitive *dummyBox;
};

struct WarningWithLines : WarningMessage
{
	GL_Primitive *linePrimitive;
	Point textOrigin;
	TextString topText;
	TextString bottomText;
	int topTextLimit;
	int bottomTextLimit;
};

struct WeaponBox : ArmamentBox
{
	ProjectileFactory *pWeapon;
	bool armed;
	bool armedForAutofire;
	float cooldownMax;
	float cooldownModifier;
	Point cooldownPoint;
	int cooldownWidth;
	int cooldownHeight;
	std::vector<GL_Primitive*> cooldownBox;
	GL_Primitive *cooldownBar;
	std::vector<CachedImage> chargeIcons;
	bool defaultAutofire;
	bool wasCharged;
};

struct WeaponEquipBox : EquipmentBox
{
};

struct WeaponStoreBox : StoreBox
{
	WeaponBlueprint *blueprint;
};

struct WeaponSystem : ShipSystem
{
	Pointf target;
	std::vector<ProjectileFactory*> weapons;
	std::vector<ProjectileFactory*> weaponsTrashList;
	float shot_timer;
	int shot_count;
	int missile_count;
	int missile_start;
	CloakingSystem *cloakingSystem;
	std::vector<bool> userPowered;
	int slot_count;
	int iStartingBatteryPower;
	std::vector<bool> repowerList;
};

struct WeaponControl;

struct WeaponSystemBox : SystemBox
{
	WeaponControl *weapControl;
	TextButton autofireButton;
	Point buttonOffset;
	TouchTooltip *autofireTouchTooltip;
	bool touchTipWasOpen;
	bool autofireTipWasOpen;
};

struct BossShip;

struct WorldManager
{
	CompleteShip *playerShip;
	BossShip *bossShip;
	SpaceManager space;
	int currentDifficulty;
	std::vector<CompleteShip*> ships;
	StarMap starMap;
	CommandGui *commandGui;
	LocationEvent *baseLocationEvent;
	LocationEvent *lastLocationEvent;
	ShipEvent currentShipEvent;
	std::vector<StatusEffect> currentEffects;
	std::string startingText;
	Location *newLocation;
	bool bStartedGame;
	bool bLoadingGame;
	bool vAutoSaved;
	bool bExtraChoice;
	std::vector<int> choiceHistory;
	std::string generatedEvent;
	TextString lastMainText;
	int playerCrewCount;
	int killedCrew;
	int playerHull;
	std::vector<int> blueRaceChoices;
	int lastSelectedCrewSeed;
	bool testingBlueprints;
	std::vector<LocationEvent::Choice> originalChoiceList;
};

extern LIBZHL_API AchievementTracker *Global_AchievementTracker_Tracker;
