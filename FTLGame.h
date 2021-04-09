#pragma once

#pragma warning( disable : 4722 )

#define LIBZHL_API 
#define LIBZHL_INTERFACE __declspec(novtable)

__declspec(noreturn) inline void __cdecl __NOP() {}
#define LIBZHL_PLACEHOLDER {__NOP();}


#include "zhl.h"
#include "rapidxml.hpp"
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <deque>
#include <stdarg.h>
#include <unordered_map>
#include <math.h>
#include <queue>
#undef LoadImage

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

struct CAchievement;
struct RandomAmount;
struct Point;

typedef std::pair<int, int> std_pair_int_int;
typedef std::pair<float, float> std_pair_float_float;
typedef std::pair<std::string, int> std_pair_std_string_int;
typedef std::pair<std::string, RandomAmount> std_pair_std_string_RandomAmount;
typedef std::pair<std::string, std::string> std_pair_std_string_std_string;
typedef std::pair<CAchievement*, Point> std_pair_CAchievement_ptr_Point;
typedef std::map<std::string, std::string> std_map_std_string_std_string;
typedef std::map<std::string, int> std_map_std_string_int;
typedef std::map<std::string, bool> std_map_std_string_bool;




struct RandomAmount
{
	int min;
	int max;
	float chanceNone;
};

struct Point
{
	Point(int xx, int yy) : x(xx), y(yy)  { }
	Point() { }
	
	friend bool operator==(const Point &a, const Point &b) {return a.x==b.x && a.y==b.y;}
	friend bool operator!=(const Point &a, const Point &b) {return a.x!=b.x || a.y!=b.y;}

	LIBZHL_API int RelativeDistance(Point other);
	LIBZHL_API int Distance(Point other);
	
	int x;
	int y;
};

struct GL_Texture;

struct GL_Primitive;

struct CachedPrimitive
{
	void *vptr;
	GL_Primitive *primitive;
};

struct CachedImage;

struct CachedImage : CachedPrimitive
{
	~CachedImage()
	{
		this->destructor();
	}

	enum Centered
	{
	  CENTERED = 0x0,
	};

	LIBZHL_API void destructor();
	LIBZHL_API void SetImagePath(const std::string &imagePath);
	
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

struct TextString;

struct TextLibrary;

struct TextLibrary
{
	std::string GetText(const std::string& name)
	{
		std::string ret = std::string();
		
		TextLibrary::GetText(ret, this, name, currentLanguage);
		
		return ret;
	}

	LIBZHL_API static std::string &__stdcall GetText(std::string &strRef, TextLibrary *textLibrary, const std::string &name, const std::string &lang);
	
	std::map<std::string, std::string> dictionary;
	std::map<std::string, std_map_std_string_std_string> languageDictionaries;
	std::string currentLanguage;
};

struct TextString
{
	TextString()
	{
		isLiteral = true;
	}

	std::string GetText()
	{
		std::string ret = std::string();
		
		TextString::GetText(ret, this);
		
		return ret;
	}

	LIBZHL_API static std::string &__stdcall GetText(std::string &ref, TextString *textString);
	
	std::string data;
	bool isLiteral;
	unsigned __int8 gap_ex[3];
};

struct CAchievement;

struct CAchievement
{
	CAchievement()
	{
		this->constructor();
	}

	LIBZHL_API void OnRender(Point pos, int selected, bool unk);
	LIBZHL_API void constructor();
	
	std::string name_id;
	std::pair<int, int> progress;
	bool unlocked;
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
	
enum TouchAction
{
  TOUCH_DOWN = 0x1,
  TOUCH_MOVE = 0x2,
  TOUCH_UP = 0x3,
  TOUCH_CANCEL = 0x4,
};

enum InputEventType
{
  INPUT_EVENT_JOYSTICK = 0x1,
  INPUT_EVENT_KEYBOARD = 0x2,
  INPUT_EVENT_MEMORY = 0x3,
  INPUT_EVENT_MOUSE = 0x4,
  INPUT_EVENT_TEXT = 0x5,
  INPUT_EVENT_TOUCH = 0x6,
};

enum InputEventDetail
{
  INPUT_JOYSTICK_CONNECTED = 0x1,
  INPUT_JOYSTICK_DISCONNECTED = 0x2,
  INPUT_JOYSTICK_BUTTON_DOWN = 0x3,
  INPUT_JOYSTICK_BUTTON_UP = 0x4,
  INPUT_JOYSTICK_DPAD_CHANGE = 0x5,
  INPUT_JOYSTICK_STICK_CHANGE = 0x6,
  INPUT_KEYBOARD_KEY_DOWN = 0x7,
  INPUT_KEYBOARD_KEY_UP = 0x8,
  INPUT_KEYBOARD_SYSTEM_KEY_DOWN = 0x9,
  INPUT_KEYBOARD_SYSTEM_KEY_UP = 0xA,
  INPUT_MEMORY_LOW = 0xB,
  INPUT_MOUSE_MOVE = 0xC,
  INPUT_MOUSE_LMB_DOWN = 0xD,
  INPUT_MOUSE_LMB_UP = 0xE,
  INPUT_MOUSE_MMB_DOWN = 0xF,
  INPUT_MOUSE_MMB_UP = 0x10,
  INPUT_MOUSE_RMB_DOWN = 0x11,
  INPUT_MOUSE_RMB_UP = 0x12,
  INPUT_MOUSE_SCROLL_H = 0x13,
  INPUT_MOUSE_SCROLL_V = 0x14,
  INPUT_TEXT_INPUT = 0x15,
  INPUT_TEXT_DONE = 0x16,
  INPUT_TEXT_CANCELLED = 0x17,
  INPUT_TEXT_CLEAR = 0x18,
  INPUT_TEXT_BACKSPACE = 0x19,
  INPUT_TEXT_DELETE = 0x1A,
  INPUT_TEXT_CURSOR_LEFT = 0x1B,
  INPUT_TEXT_CURSOR_RIGHT = 0x1C,
  INPUT_TEXT_CURSOR_HOME = 0x1D,
  INPUT_TEXT_CURSOR_END = 0x1E,
  INPUT_TOUCH_DOWN = 0x1F,
  INPUT_TOUCH_MOVE = 0x20,
  INPUT_TOUCH_UP = 0x21,
  INPUT_TOUCH_CANCEL = 0x22,
};

enum DeleteType
{
  BUFFER = 0x1,
  FRAMEBUFFER = 0x2,
  PROGRAM = 0x3,
  PROGRAM_PIPELINE = 0x4,
  RENDERBUFFER = 0x5,
  SHADER = 0x6,
  TEXTURE = 0x7,
  VERTEX_ARRAY = 0x8,
};

enum FontAlignment
{
  FONT_ALIGN_LEFT = 0x0,
  FONT_ALIGN_CENTER = 0x1,
  FONT_ALIGN_RIGHT = 0x2,
};

enum FramebufferColorType
{
  FBCOLOR_RGB8 = 0x1,
  FBCOLOR_RGBA8 = 0x2,
};

enum GL_StencilMode
{
  STENCIL_IGNORE = 0x0,
  STENCIL_SET = 0x1,
  STENCIL_USE = 0x2,
};

enum ResourceType
{
  RES_UNUSED = 0x0,
  RES_UNKNOWN = 0x1,
  RES_DATA = 0x2,
  RES_TEXTURE = 0x3,
  RES_FONT = 0x4,
  RES_SOUND = 0x5,
  RES_FILE = 0x6,
};


enum SDLKey
{
  SDLK_UNKNOWN = 0x0,
  SDLK_0 = 0x30,
  SDLK_1 = 0x31,
  SDLK_2 = 0x32,
  SDLK_3 = 0x33,
  SDLK_4 = 0x34,
  SDLK_5 = 0x35,
  SDLK_6 = 0x36,
  SDLK_7 = 0x37,
  SDLK_8 = 0x38,
  SDLK_9 = 0x39,
  SDLK_AT = 0x40,
  SDLK_AMPERSAND = 0x26,
  SDLK_ASTERISK = 0x2A,
  SDLK_BACKQUOTE = 0x60,
  SDLK_BACKSLASH = 0x5C,
  SDLK_BACKSPACE = 0x8,
  SDLK_BREAK = 0x13E,
  SDLK_CAPSLOCK = 0x12D,
  SDLK_CARET = 0x5E,
  SDLK_CLEAR = 0xC,
  SDLK_COLON = 0x3A,
  SDLK_COMMA = 0x2C,
  SDLK_COMPOSE = 0x13A,
  SDLK_DELETE = 0x7F,
  SDLK_DOLLAR = 0x24,
  SDLK_DOWN = 0x112,
  SDLK_END = 0x117,
  SDLK_EQUALS = 0x3D,
  SDLK_ESCAPE = 0x1B,
  SDLK_EURO = 0x141,
  SDLK_EXCLAIM = 0x21,
  SDLK_F1 = 0x11A,
  SDLK_F10 = 0x123,
  SDLK_F11 = 0x124,
  SDLK_F12 = 0x125,
  SDLK_F13 = 0x126,
  SDLK_F14 = 0x127,
  SDLK_F15 = 0x128,
  SDLK_F2 = 0x11B,
  SDLK_F3 = 0x11C,
  SDLK_F4 = 0x11D,
  SDLK_F5 = 0x11E,
  SDLK_F6 = 0x11F,
  SDLK_F7 = 0x120,
  SDLK_F8 = 0x121,
  SDLK_F9 = 0x122,
  SDLK_GREATER = 0x3E,
  SDLK_HASH = 0x24,
  SDLK_HELP = 0x13B,
  SDLK_HOME = 0x116,
  SDLK_INSERT = 0x115,
  SDLK_KP0 = 0x100,
  SDLK_KP1 = 0x101,
  SDLK_KP2 = 0x102,
  SDLK_KP3 = 0x103,
  SDLK_KP4 = 0x104,
  SDLK_KP5 = 0x105,
  SDLK_KP6 = 0x106,
  SDLK_KP7 = 0x107,
  SDLK_KP8 = 0x108,
  SDLK_KP9 = 0x109,
  SDLK_KP_PERIOD = 0x10A,
  SDLK_KP_DIVIDE = 0x10B,
  SDLK_KP_MULTIPLY = 0x10C,
  SDLK_KP_MINUS = 0x10D,
  SDLK_KP_PLUS = 0x10E,
  SDLK_KP_ENTER = 0x10F,
  SDLK_KP_EQUALS = 0x110,
  SDLK_LALT = 0x134,
  SDLK_LCTRL = 0x132,
  SDLK_LEFT = 0x114,
  SDLK_LEFTBRACKET = 0x5B,
  SDLK_LEFTPAREN = 0x28,
  SDLK_LESS = 0x3C,
  SDLK_LMETA = 0x136,
  SDLK_LSHIFT = 0x130,
  SDLK_LSUPER = 0x137,
  SDLK_MENU = 0x13F,
  SDLK_MINUS = 0x2D,
  SDLK_MODE = 0x139,
  SDLK_NUMLOCK = 0x12C,
  SDLK_PAGEDOWN = 0x119,
  SDLK_PAGEUP = 0x118,
  SDLK_PAUSE = 0x13,
  SDLK_PERIOD = 0x2E,
  SDLK_PLUS = 0x2B,
  SDLK_POWER = 0x140,
  SDLK_PRINTSCREEN = 0x13C,
  SDLK_QUESTION = 0x3F,
  SDLK_QUOTEDBL = 0x22,
  SDLK_QUOTE = 0x27,
  SDLK_RALT = 0x133,
  SDLK_RCTRL = 0x131,
  SDLK_RETURN = 0xD,
  SDLK_RIGHT = 0x113,
  SDLK_RIGHTBRACKET = 0x5D,
  SDLK_RIGHTPAREN = 0x29,
  SDLK_RMETA = 0x135,
  SDLK_RSHIFT = 0x12F,
  SDLK_RSUPER = 0x138,
  SDLK_SCROLLOCK = 0x12E,
  SDLK_SEMICOLON = 0x3B,
  SDLK_SLASH = 0x2F,
  SDLK_SPACE = 0x20,
  SDLK_SYSREQ = 0x13D,
  SDLK_TAB = 0x9,
  SDLK_UNDERSCORE = 0x5F,
  SDLK_UNDO = 0x142,
  SDLK_UP = 0x111,
  SDLK_a = 0x61,
  SDLK_b = 0x62,
  SDLK_c = 0x63,
  SDLK_d = 0x64,
  SDLK_e = 0x65,
  SDLK_f = 0x66,
  SDLK_g = 0x67,
  SDLK_h = 0x68,
  SDLK_i = 0x69,
  SDLK_j = 0x6A,
  SDLK_k = 0x6B,
  SDLK_l = 0x6C,
  SDLK_m = 0x6D,
  SDLK_n = 0x6E,
  SDLK_o = 0x6F,
  SDLK_p = 0x70,
  SDLK_q = 0x71,
  SDLK_r = 0x72,
  SDLK_s = 0x73,
  SDLK_t = 0x74,
  SDLK_u = 0x75,
  SDLK_v = 0x76,
  SDLK_w = 0x77,
  SDLK_x = 0x78,
  SDLK_y = 0x79,
  SDLK_z = 0x7A,
  SDLK_LAST = 0x143,
};

enum ShaderType
{
  SHADER_TYPE_VERTEX = 0x0,
  SHADER_TYPE_FRAGMENT = 0x1,
};

enum GraphicsPrimitiveType
{
  GRAPHICS_PRIMITIVE_POINTS = 0x1,
  GRAPHICS_PRIMITIVE_LINES = 0x2,
  GRAPHICS_PRIMITIVE_LINE_STRIP = 0x3,
  GRAPHICS_PRIMITIVE_TRIANGLES = 0x4,
  GRAPHICS_PRIMITIVE_TRIANGLE_STRIP = 0x5,
  GRAPHICS_PRIMITIVE_QUADS = 0x6,
  GRAPHICS_PRIMITIVE_QUAD_STRIP = 0x7,
};

enum GraphicsTextureColorType
{
  GRAPHICS_TEXCOLOR_NONE = 0x0,
  GRAPHICS_TEXCOLOR_RGBA = 0x1,
  GRAPHICS_TEXCOLOR_A = 0x2,
  GRAPHICS_TEXCOLOR_L = 0x3,
};

enum GraphicsComparisonType
{
  GRAPHICS_COMPARISON_FALSE = 0x0,
  GRAPHICS_COMPARISON_TRUE = 0x1,
  GRAPHICS_COMPARISON_EQUAL = 0x2,
  GRAPHICS_COMPARISON_NOT_EQUAL = 0x3,
  GRAPHICS_COMPARISON_LESS = 0x4,
  GRAPHICS_COMPARISON_LESS_EQUAL = 0x5,
  GRAPHICS_COMPARISON_GREATER_EQUAL = 0x6,
  GRAPHICS_COMPARISON_GREATER = 0x7,
};

typedef char *ShaderSourceCallback(GraphicsPrimitiveType, int, int, GraphicsTextureColorType, int, int, int, int, int, GraphicsComparisonType);

static DWORD GetBaseAddress()
{
	return (DWORD)GetModuleHandle(NULL);
}


struct BoardingGoal
{
	float fHealthLimit;
	int causedDamage;
	int targetsDestroyed;
	int target;
	int damageType;
};

struct BeamWeapon
{
};

struct GL_Color
{
	GL_Color(float rr, float gg, float bb, float aa) : r(rr), g(gg), b(bb), a(aa)
	{
		
	}
	
	static GL_Color FromHSV(float fH, float fS, float fV, float fA)
	{
		float fR, fB, fG;
		float fC = fV * fS; // Chroma
		float fHPrime = fmod(fH / 60.0, 6);
		float fX = fC * (1 - fabs(fmod(fHPrime, 2) - 1));
		float fM = fV - fC;
		
		if (0 <= fHPrime && fHPrime < 1) 
		{
			fR = fC;
			fG = fX;
			fB = 0;
		} 
		else if(1 <= fHPrime && fHPrime < 2) 
		{
			fR = fX;
			fG = fC;
			fB = 0;
		} 
		else if(2 <= fHPrime && fHPrime < 3) 
		{
			fR = 0;
			fG = fC;
			fB = fX;
		} 
		else if(3 <= fHPrime && fHPrime < 4) 
		{
			fR = 0;
			fG = fX;
			fB = fC;
		} 
		else if(4 <= fHPrime && fHPrime < 5) 
		{
			fR = fX;
			fG = 0;
			fB = fC;
		} 
		else if(5 <= fHPrime && fHPrime < 6) 
		{
			fR = fC;
			fG = 0;
			fB = fX;
		} 
		else 
		{
			fR = 0;
			fG = 0;
			fB = 0;
		}
		  
		fR += fM;
		fG += fM;
		fB += fM;
		
		return GL_Color(fR, fB, fG, fA);
	}
	
	GL_Color() {}

	float r;
	float g;
	float b;
	float a;
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

struct Damage
{
	Damage()
	{
	};

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

struct GenericButton;

struct AnimationTracker;

struct LIBZHL_INTERFACE AnimationTracker
{
	AnimationTracker()
	{
	
	}

	virtual ~AnimationTracker() {}
	LIBZHL_API virtual void Update();
	LIBZHL_API void SetLoop(bool loop, float loopDelay);
	LIBZHL_API void Stop(bool resetTime);
	LIBZHL_API void Start(float time);
	LIBZHL_API void StartReverse(float time);
	LIBZHL_API float Progress(float speed);
	LIBZHL_API void SetProgress(float time);
	LIBZHL_API float GetAlphaLevel(bool reverse);
	
	float time;
	bool loop;
	float current_time;
	bool running;
	bool reverse;
	bool done;
	float loopDelay;
	float currentDelay;
};

struct Pointf
{
	Pointf() : x(0.f), y(0.f) {}
	Pointf(float _x, float _y) : x(_x), y(_y) {}
	
	Pointf operator+(const Pointf& other)
	{
		return Pointf(x + other.x, y + other.y);
	}
	
	Pointf operator-(const Pointf& other)
	{		
		return Pointf(x - other.x, y - other.y);
	}
	
	Pointf operator/(float amount)
	{		
		return Pointf(x / amount, y / amount);
	}
	
	Pointf operator*(float amount)
	{		
		return Pointf(x * amount, y * amount);
	}


	LIBZHL_API void constructor(float x, float y);
	LIBZHL_API float RelativeDistance(Pointf other);
	
	float x;
	float y;
};

struct Globals
{
	struct Rect
	{
		int x;
		int y;
		int w;
		int h;
	};
	
	struct Ellipse
	{
		Point center;
		float a;
		float b;
	};
	
	LIBZHL_API static float __stdcall AimAhead(Pointf delta, Pointf vr, float muzzleV);
	LIBZHL_API static int __stdcall GetNextSpaceId();
	
};

struct LIBZHL_INTERFACE GenericButton
{
	virtual ~GenericButton() {}
	virtual void Reset() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void SetLocation(Point pos);
	virtual void SetHitBox(Globals::Rect rect) LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void SetActive(bool active);
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	virtual void OnRender() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void MouseMove(int x, int y, bool silent);
	LIBZHL_API virtual void OnClick();
	LIBZHL_API virtual void OnRightClick();
	virtual void OnTouch() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void ResetPrimitives();
	
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

struct Button;

struct Button : GenericButton
{
	Button()
	{
		this->constructor();
	}

	LIBZHL_API void SetLocation(const Point pos);
	LIBZHL_API void OnInit(const std::string &img, int x, int y);
	LIBZHL_API void constructor();
	LIBZHL_API void OnRender();
	LIBZHL_API void SetInactiveImage(GL_Texture *texture);
	LIBZHL_API void SetActiveImage(GL_Texture *texture);
	LIBZHL_API void SetImageBase(const std::string &imageBase);
	
	GL_Texture *images[3];
	GL_Primitive *primitives[3];
	Point imageSize;
	bool bMirror;
};

struct ShipManager;

struct ShipSystem;
struct TouchTooltip;

struct WarningMessage;

struct WarningMessage
{
	LIBZHL_API void Start();
	LIBZHL_API void OnRender();
	
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

struct LIBZHL_INTERFACE SystemBox
{
	virtual ~SystemBox() {}
	virtual void destroy() LIBZHL_PLACEHOLDER
	virtual bool HasButton() LIBZHL_PLACEHOLDER
	virtual int GetCooldownBarHeight() LIBZHL_PLACEHOLDER
	virtual int GetHeightModifier() LIBZHL_PLACEHOLDER
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void OnRender(bool ignoreStatus);
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

struct SystemCustomBox : SystemBox
{
	ShipManager *shipManager;
	Button button;
};

struct CombatControl;

struct CrewControl;
struct CrewBox;

struct Repairable;
struct CrewMember;

struct Door;

struct CrewControl
{
	LIBZHL_API void OnRender();
	LIBZHL_API void OnLoop();
	LIBZHL_API void UpdateCrewBoxes();
	LIBZHL_API void LinkShip(ShipManager *ship);
	LIBZHL_API void MouseMove(int mX, int mY, int wX, int wY);
	LIBZHL_API void LButton(int mX, int mY, int wX, int wY, bool shiftHeld);
	LIBZHL_API static void __stdcall ClearDeadCrew(std::vector<CrewMember*> crew);
	LIBZHL_API void ClearCrewBoxes();
	
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
	int _unk;
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
	int _unk2;
};

struct SpaceDrone;
struct ProjectileFactory;

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

struct ShipObject;

struct ShipObject
{
	std::vector<std::string> GetAugmentationList()
	{
		std::vector<std::string> vec = std::vector<std::string>();
		GetAugmentationList(vec, this);
		return vec;
	}

	LIBZHL_API int HasAugmentation(const std::string &augment);
	LIBZHL_API float GetAugmentationValue(const std::string &augment);
	LIBZHL_API void RemoveAugmentation(const std::string &augment);
	LIBZHL_API int HasEquipment(const std::string &equip);
	LIBZHL_API static std::map<std::string, int> &__stdcall GetAugmentationList(std::vector<std::string> &vec, ShipObject *shipObj);
	LIBZHL_API void AddAugmentation(const std::string &augment);
	LIBZHL_API static void __stdcall __DO_NOT_HOOK();
	LIBZHL_API int GetAugmentationCount();
	
	void *vptr;
	int iShipId;
};

struct CrewTarget : ShipObject
{
};

struct CommandGui;

struct Animation;

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

struct Animation
{
	~Animation()
	{
		this->destructor();
	}

	LIBZHL_API void OnRender(float opacity, GL_Color color, bool mirror);
	LIBZHL_API void Update();
	LIBZHL_API void SetCurrentFrame(int frame);
	LIBZHL_API void Start(bool reset);
	LIBZHL_API void AddSoundQueue(int unk, const std::string &sound);
	LIBZHL_API void SetAnimationId(GL_Texture *tex);
	LIBZHL_API void destructor();
	LIBZHL_API void StartReverse(bool reset);
	LIBZHL_API void SetProgress(float progress);
	
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
	std::vector<void*> soundQueue;
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

struct ArmamentControl;

struct ArmamentBox;

struct ArmamentControl
{
	LIBZHL_API bool Dragging();
	LIBZHL_API void SetPosition(int x, int y);
	
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

struct AugmentBlueprint;
struct InfoBox;

struct Description;

struct Description
{	
	~Description()
	{
		this->destructor();
	}

	LIBZHL_API Description &copy_assign_1(Description &&other);
	LIBZHL_API Description &copy_assign_2(const Description &other);
	LIBZHL_API void destructor();
	
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

struct WindowFrame;
struct WeaponBlueprint;
struct DroneBlueprint;
struct CrewBlueprint;
struct ItemBlueprint;

struct SystemBlueprint;

struct InfoBox
{
	InfoBox()
	{
		this->constructor();
	}

	enum ExpandDir
	{
	  EXPAND_UP = -1,
	  EXPAND_NONE = 0,
	  EXPAND_DOWN = 1,
	};


	LIBZHL_API void OnRender();
	LIBZHL_API int Clear();
	LIBZHL_API int SetDescription(Description *desc, int width, int height, InfoBox::ExpandDir dir);
	LIBZHL_API void SetText(const std::string &title, const std::string &text, int width, int height, InfoBox::ExpandDir dir);
	LIBZHL_API void SetBlueprintWeapon(const WeaponBlueprint *bp, int status, bool hasWeaponSystem, int yShift);
	LIBZHL_API void SetBlueprintDrone(const DroneBlueprint *bp, int status, bool hasDroneSystem, int yShift);
	LIBZHL_API void SetBlueprint(const ItemBlueprint *bp);
	LIBZHL_API void SetBlueprintCrew(const CrewBlueprint *bp, int yShift, bool detailedCrew);
	LIBZHL_API void SetBlueprintAugment(const AugmentBlueprint *bp);
	LIBZHL_API int CalcBoxHeight();
	LIBZHL_API bool IsEmpty();
	LIBZHL_API void constructor();
	
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

struct ShipSelect;

struct ShipButton;

struct TextButton;

struct TextButton : GenericButton
{
public:
	int GetSize()
	{
		int64_t ret = GetSizeX();
		int* ptr = (int*)&ret;
		return *ptr;
	}

	LIBZHL_API void ResetPrimitives();
	LIBZHL_API int GetIdealButtonWidth();
	LIBZHL_API static void __stdcall __DO_NOT_HOOK();
	LIBZHL_API void constructor();
	LIBZHL_API void OnInit(int x, int y, int w, int h, int cornerInset, TextString *buttonLabel, int font);
	LIBZHL_API void OnRender();
	LIBZHL_API void destructor();
	LIBZHL_API int64_t GetSizeX();
	LIBZHL_API void OnInitRect(Globals::Rect &rect, int cornerInset, TextString &buttonLabel, int font);
	
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

struct Blueprint;

struct LIBZHL_INTERFACE Blueprint
{
	virtual ~Blueprint() {}
	virtual void RenderIcon(float unk) LIBZHL_PLACEHOLDER
	virtual std::string *GetNameLong(Blueprint *bp) LIBZHL_PLACEHOLDER
	virtual std::string *GetNameShort(Blueprint *bp) LIBZHL_PLACEHOLDER
	virtual int GetType() LIBZHL_PLACEHOLDER
	std::string name;
	Description desc;
	int type;
};

struct CrewBlueprint : Blueprint
{
	~CrewBlueprint()
	{
		this->destructor();
	}

	LIBZHL_API void RandomSkills(int worldLevel);
	LIBZHL_API void RenderSkill(int x, int y, int length, int height, int skill);
	LIBZHL_API void RenderIcon(float opacity);
	LIBZHL_API void destructor();
	
	TextString crewName;
	TextString crewNameLong;
	std::vector<TextString> powers;
	bool male;
	std::vector<std_pair_int_int> skillLevel;
	std::vector<std::vector<GL_Color>> colorLayers;
	std::vector<int> colorChoices;
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

struct ChoiceBox;

struct FocusWindow
{
	void *vptr;
	bool bOpen;
	bool bFullFocus;
	Point close;
	bool bCloseButtonSelected;
	Point position;
};

struct ChoiceText
{
	ChoiceText(int _type, const std::string& _text, ResourceEvent _rewards) : 
	type(_type), text(_text), rewards(_rewards)
	{
	}

	int type;
	std::string text;
	ResourceEvent rewards;
};

struct ChoiceBox : FocusWindow
{
	LIBZHL_API void OnRender();
	LIBZHL_API void MouseMove(int x, int y);
	
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

struct UnlockArrow;

struct UnlockArrow
{
	LIBZHL_API void constructor(Point pos, int unk1, int unk2);
	LIBZHL_API bool MouseMove(int x, int y);
	LIBZHL_API void OnRender();
	
	int direction;
	int status;
	Globals::Rect shape;
};

struct ShipSelect
{
	LIBZHL_API void SelectShip(int shipType);
	LIBZHL_API void constructor();
	LIBZHL_API int ClearShipButtons();
	LIBZHL_API void MouseMove(int x, int y);
	LIBZHL_API void OnLoop();
	LIBZHL_API int KeyDown(SDLKey key);
	LIBZHL_API void MouseClick();
	LIBZHL_API void PreSelectShip(int shipType);
	LIBZHL_API void Close();
	LIBZHL_API int GetSelectedShip();
	LIBZHL_API void Open(int currentId, int currentType);
	LIBZHL_API void OnRender();
	
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

struct ScoreKeeper;

struct TopScore;

struct TopScore
{
	TopScore(const TopScore& other)
	{
		this->copy_constructor(other);
	}
	
	TopScore()
	{
	}

	LIBZHL_API void copy_constructor(const TopScore &other);
	
	std::string name;
	std::string blueprint;
	GL_Texture *image;
	int sector;
	int score;
	bool victory;
	int difficulty;
	bool advancedContent;
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

struct StatTracker
{
	int max;
	int total;
	int current;
	std::string desc_id;
	int sector;
};

struct ScoreKeeper
{
	std::string GetShipBlueprint(int type)
	{
		std::string ret = std::string();
		
		GetShipBlueprint(&ret, this, type);
		
		return ret;
	}
	
	std::pair<int, int> GetShipId(const std::string& blueprintName)
	{
		int variant = 0;
		
		if (blueprintName.find("_2") != std::string::npos)
		{
			variant = 1;
		}
		if (blueprintName.find("_3") != std::string::npos)
		{
			variant = 2;
		}
		
		int type = GetShipIdType(blueprintName);
		
		return std::pair<int, int>(type, variant);
	}

	LIBZHL_API char GetShipUnlocked(int shipId, int shipVariant);
	LIBZHL_API static std::string *__stdcall GetShipBlueprint(std::string *str, ScoreKeeper *scoreKeeper, int index);
	LIBZHL_API void OnInit();
	LIBZHL_API void Save(bool newHighScore);
	LIBZHL_API void OnRender(bool lastPlaythrough);
	LIBZHL_API void UnlockShip(int shipType, int shipVariant, bool save, bool hidePopup);
	LIBZHL_API void SetVictory(bool victory);
	LIBZHL_API void constructor();
	LIBZHL_API int GetShipIdType(const std::string &blueprintName);
	LIBZHL_API void LoadVersionFour(int file, int version);
	LIBZHL_API void WipeProfile(bool permanent);
	LIBZHL_API void MouseClick(int x, int y);
	LIBZHL_API void SetupTopShip(int variant);
	LIBZHL_API void CheckTypes();
	LIBZHL_API void AddTopScoreType(TopScore &topScore, int type);
	LIBZHL_API int AddTopScoreList(TopScore &score, std::vector<TopScore> &topScoreList);
	LIBZHL_API void RenderTopScores(const std::vector<TopScore> &topScoreList, Point position, int newHighScore);
	LIBZHL_API void CycleLeft();
	LIBZHL_API void CycleRight();
	LIBZHL_API void Open(bool fromGameOver);
	LIBZHL_API bool KeyDown(SDLKey key);
	LIBZHL_API void AddScrapCollected(int scrap);
	LIBZHL_API void SaveScores(int file, std::vector<TopScore> &topScores);
	
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

struct PowerProfile
{
};

struct ShipAI;

struct CrewTask
{
	int taskId;
	int room;
	int system;
};

struct CrewAI;

struct CrewAI
{
	LIBZHL_API void UpdateDrones();
	LIBZHL_API void AssignCrewmembers();
	LIBZHL_API int PrioritizeTask(CrewTask task, int crewId);
	LIBZHL_API void UpdateIntruders();
	LIBZHL_API int PrioritizeIntruderRoom(CrewMember *crew, int roomId, int target);
	LIBZHL_API void UpdateCrewMember(int crewId);
	LIBZHL_API void CheckForHealing();
	LIBZHL_API void OnLoop();
	LIBZHL_API void CheckForProblems();
	
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

struct ShipAI
{
	LIBZHL_API void constructor(bool unk);
	LIBZHL_API void SetStalemate(bool stalemate);
	
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

struct HackBox
{
};

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

struct MouseInputEvent
{
	float x;
	float y;
	float scroll;
};

struct BattleDrone;
struct RepairDrone;
struct CrewMemberFactory;
struct BoarderDrone;

struct CrewMemberFactory
{
	LIBZHL_API void destructor();
	LIBZHL_API void Restart();
	LIBZHL_API int CountCloneReadyCrew();
	LIBZHL_API int GetPlayerCrewCount();
	LIBZHL_API int GetEnemyCloneCount();
	LIBZHL_API int GetCrewCount(bool enemy);
	LIBZHL_API int GetEnemyCrewCount();
	LIBZHL_API static bool __stdcall IsRace(const std::string &species);
	LIBZHL_API std::pair<std::string, bool> &GetRandomFriendlyName(const std::string &unk);
	LIBZHL_API static std::vector<std::string> *__stdcall GetCrewNames(std::vector<std::string> &vec, CrewMemberFactory *factory);
	LIBZHL_API RepairDrone *CreateRepairDrone(int shipId, const DroneBlueprint *bp);
	LIBZHL_API void GetCrewPortraitList(std::vector<CrewMember*> *vec, int teamId);
	LIBZHL_API void GetCloneReadyList(std::vector<CrewMember*> &vec, bool unk);
	LIBZHL_API BattleDrone *CreateBattleDrone(int shipId, const DroneBlueprint *bp);
	LIBZHL_API void GetCrewList(std::vector<CrewMember*> *vec, int unk, bool unk2);
	LIBZHL_API BoarderDrone *CreateBoarderDrone(int shipId, const DroneBlueprint *bp);
	LIBZHL_API void OnLoop();
	LIBZHL_API void RemoveExcessCrew();
	LIBZHL_API CrewMember *CreateCrewMember(CrewBlueprint *bp, int shipId, bool intruder);
	
	int playerCrew;
	int enemyCrew;
	int enemyCloneCount;
	std::vector<CrewMember*> crewMembers;
	std::vector<CrewMember*> lostMembers;
};

struct GL_FrameBuffer
{
};

struct CloakingSystem;
struct WeaponSystem;

struct CachedRectOutline : CachedPrimitive
{
	int x;
	int y;
	int w;
	int h;
	int thickness;
};

struct CachedRect : CachedPrimitive
{
	int x;
	int y;
	int w;
	int h;
};

struct TimerHelper;

struct TimerHelper
{
	TimerHelper(bool isLoop=false) : loop(isLoop) { }

	LIBZHL_API void Start(int goal);
	LIBZHL_API bool Running();
	LIBZHL_API void ResetMinMax(int min, int max);
	LIBZHL_API void SetMaxTime(float max);
	LIBZHL_API void Stop();
	LIBZHL_API void Update();
	LIBZHL_API bool Done();
	
	int maxTime;
	int minTime;
	float currTime;
	float currGoal;
	bool loop;
	bool running;
};

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
	LIBZHL_API virtual bool PartialDamage(float amount);
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
	LIBZHL_API virtual void SetBonusPower(int amount, int permanentPower);
	virtual void AddDamage(int damage) LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void ForceDecreasePower(int powerLoss);
	virtual bool ForceIncreasePower(int power) LIBZHL_PLACEHOLDER
	virtual void StopHacking() LIBZHL_PLACEHOLDER
	virtual void OnRender() LIBZHL_PLACEHOLDER
	virtual void OnRenderFloor() LIBZHL_PLACEHOLDER
	virtual void OnRenderEffects() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void OnLoop();
	virtual bool GetNeedsPower() LIBZHL_PLACEHOLDER
	virtual void Restart() LIBZHL_PLACEHOLDER
	virtual bool Clickable() LIBZHL_PLACEHOLDER
	virtual bool Powered() LIBZHL_PLACEHOLDER
	virtual void ShipDestroyed() LIBZHL_PLACEHOLDER
	LIBZHL_API char DamageOverTime(float unk);
	LIBZHL_API void CheckForRepower();
	LIBZHL_API static int __stdcall NameToSystemId(const std::string &name);
	LIBZHL_API int IsMannedBoost();
	LIBZHL_API static std::string &__stdcall SystemIdToName(std::string &strRef, int systemId);
	LIBZHL_API bool Ioned(int num);
	LIBZHL_API int SetPowerLoss(int power);
	LIBZHL_API void constructor(int systemId, int roomId, int shipId, int startingPower);
	LIBZHL_API int GetPowerCap();
	LIBZHL_API void SetPowerCap(int cap);
	LIBZHL_API void LockSystem(int lock);
	LIBZHL_API int GetEffectivePower();
	LIBZHL_API int GetMaxPower();
	LIBZHL_API static void __DO_NOT_HOOK();
	LIBZHL_API static bool __stdcall IsSubsystem(int systemType);
	LIBZHL_API void ClearStatus();
	
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
	unsigned __int8 gap_ex_1[2];
	int iActiveManned;
	bool bBoostable;
	unsigned __int8 gap_ex_2[2];
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

struct WeaponSystem : ShipSystem
{
	LIBZHL_API void RemoveWeapon(int slot);
	LIBZHL_API virtual void SetBonusPower(int amount, int permanentPower);
	
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

struct RewardDesc
{
	std::string reward;
	int level;
};

struct CloneSystem
{
};

struct BoardingEvent
{
	std::string type;
	int min;
	int max;
	int amount;
	bool breach;
};

struct AugmentBlueprint : Blueprint
{
	float value;
	bool stacking;
};

struct BlueprintManager;

struct ShipBlueprint;

struct ShipBlueprint : Blueprint
{
	~ShipBlueprint()
	{
		this->destructor();
	}

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
	
	LIBZHL_API void destructor();
	
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

struct EffectsBlueprint
{
	EffectsBlueprint& operator=(const EffectsBlueprint& other)
	{
		launchSounds = other.launchSounds;
		hitShipSounds = other.hitShipSounds;
		hitShieldSounds = other.hitShieldSounds;
		missSounds = other.missSounds;
		image = other.image;
	}

	std::vector<std::string> launchSounds;
	std::vector<std::string> hitShipSounds;
	std::vector<std::string> hitShieldSounds;
	std::vector<std::string> missSounds;
	std::string image;
};

struct WeaponBlueprint : Blueprint
{
	WeaponBlueprint()
	{
		this->constructor();
	}

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
	
	LIBZHL_API static void __stdcall __DO_NOT_HOOK();
	LIBZHL_API void constructor();
	LIBZHL_API void destructor();
	LIBZHL_API static void __stdcall GetDescription(std::string &strRef, WeaponBlueprint *_this, bool tooltip);
	
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

struct DroneBlueprint : Blueprint
{
	LIBZHL_API void RenderIcon(float scale);
	
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

struct EffectsBlueprint;

struct ItemBlueprint : Blueprint
{
};

struct SystemBlueprint
{
};

struct BlueprintManager
{
	Description* ProcessDescription(rapidxml::xml_node<char>* node)
	{
		Description* desc = new Description;
		
		return ProcessDescription(desc, this, node);
	}
	
	EffectsBlueprint* ProcessEffectsBlueprint(rapidxml::xml_node<char>* node)
	{
		EffectsBlueprint* effects = new EffectsBlueprint;
		
		return ProcessEffectsBlueprint(effects, this, node);
	}
	
	CrewBlueprint* GetCrewBlueprint(const std::string& name)
	{
		CrewBlueprint* bp = new CrewBlueprint;
		
		return GetCrewBlueprint(bp, this, name);
	}
	
	

	LIBZHL_API static std::vector<std::string> &__stdcall GetBlueprintList(std::vector<std::string> &vec, BlueprintManager *bpM, const std::string &str);
	LIBZHL_API ShipBlueprint *GetShipBlueprint(const std::string &name, int sector);
	LIBZHL_API DroneBlueprint *GetDroneBlueprint(const std::string &name);
	LIBZHL_API float GetAugmentValue(const std::string &name);
	LIBZHL_API AugmentBlueprint *GetAugmentBlueprint(const std::string &name);
	LIBZHL_API ItemBlueprint *GetItemBlueprint(const std::string &name);
	LIBZHL_API static WeaponBlueprint *__stdcall ProcessWeaponBlueprint(WeaponBlueprint *bp, BlueprintManager *bpM, rapidxml::xml_node<char> *node);
	LIBZHL_API static Description *__stdcall ProcessDescription(Description *desc, BlueprintManager *bpM, rapidxml::xml_node<char> *node);
	LIBZHL_API static EffectsBlueprint *__stdcall ProcessEffectsBlueprint(EffectsBlueprint *bp, BlueprintManager *bpM, rapidxml::xml_node<char> *node);
	LIBZHL_API static CrewBlueprint *__stdcall GetCrewBlueprint(CrewBlueprint *bp, BlueprintManager *bpM, const std::string &name);
	LIBZHL_API static AugmentBlueprint *__stdcall GetRandomAugment(AugmentBlueprint *bp, BlueprintManager *bpM);
	
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

struct MainMenu;

struct CreditScreen;

struct CreditScreen
{
	LIBZHL_API void OnRender();
	LIBZHL_API void constructor();
	LIBZHL_API void Start(const std::string &shipName, const std::vector<std::string> &crewNames);
	LIBZHL_API bool Done();
	
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

struct ConfirmWindow;

struct ConfirmWindow : FocusWindow
{
	ConfirmWindow()
	{
		this->constructor();
	}

	LIBZHL_API void SetText(const TextString &text_, int minWidth, bool autoCenter, const TextString &yesText_, const TextString &noText_);
	LIBZHL_API void OnRender();
	LIBZHL_API void SetPosition(Point pos);
	LIBZHL_API void Open();
	LIBZHL_API void MouseClick(int mX, int mY);
	LIBZHL_API void MouseMove(int mX, int mY);
	LIBZHL_API void constructor();
	
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

struct ControlButton
{
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

struct LanguageChooser : FocusWindow
{
	std::vector<TextButton*> buttons;
	int iChoice;
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

struct EquipmentBox;
struct CrewCustomizeBox;

struct SystemCustomBox;

struct ShipBuilder;

struct InputEvent;
struct CEvent;

struct CEvent
{
	enum TextEvent
	{
	  TEXT_CONFIRM = 0x0,
	  TEXT_CANCEL = 0x1,
	  TEXT_CLEAR = 0x2,
	  TEXT_BACKSPACE = 0x3,
	  TEXT_DELETE = 0x4,
	  TEXT_LEFT = 0x5,
	  TEXT_RIGHT = 0x6,
	  TEXT_HOME = 0x7,
	  TEXT_END = 0x8,
	};

	LIBZHL_API void OnEvent(const InputEvent *event);
	
	void *vptr;
};

struct TextInput;

struct TextInput
{
	enum AllowedCharType
	{
	  ALLOW_ASCII = 0x0,
	  ALLOW_LANGUAGE = 0x1,
	  ALLOW_ANY = 0x2,
	};
	
	TextInput()
	{
	}

	TextInput(int maxChars, TextInput::AllowedCharType allowedCharType, const std::string& prompt)
	{
		this->constructor(maxChars, allowedCharType, prompt);
	};

	LIBZHL_API void constructor(int maxChars, TextInput::AllowedCharType allowedCharType, const std::string &prompt);
	LIBZHL_API void OnRender(int font, Point pos);
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnTextEvent(CEvent::TextEvent event);
	LIBZHL_API bool GetActive();
	LIBZHL_API static std::string &__stdcall GetText(std::string &strRef, TextInput *textInput);
	LIBZHL_API void Start();
	LIBZHL_API void Stop();
	LIBZHL_API int SetText(const std::string &text);
	LIBZHL_API void OnTextInput(int asciiChar);
	
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

struct ShipAchievementInfo
{
	CAchievement *achievement;
	Point position;
	int dimension;
};

struct ShipBuilder
{
	LIBZHL_API void *CheckTypes();
	LIBZHL_API void MouseClick(int x, int y);
	LIBZHL_API void SwitchShip(int shipType, int shipVariant);
	LIBZHL_API void CreateEquipmentBoxes();
	LIBZHL_API void CreateSystemBoxes();
	LIBZHL_API void SetupShipAchievements();
	LIBZHL_API void ClearShipAchievements();
	LIBZHL_API int SwapType(int variant);
	LIBZHL_API void CycleShipNext();
	LIBZHL_API void CycleShipPrevious();
	LIBZHL_API void Open();
	LIBZHL_API void OnRender();
	LIBZHL_API void OnLoop();
	LIBZHL_API void constructor();
	LIBZHL_API void MouseMove(int x, int y);
	LIBZHL_API void OnKeyDown(SDLKey key);
	
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
	LIBZHL_API void OnRender();
	LIBZHL_API void Open();
	LIBZHL_API void OnLoop();
	LIBZHL_API void constructor();
	LIBZHL_API void MouseClick(int x, int y);
	LIBZHL_API void MouseMove(int x, int y);
	
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
	bool itbButtonActive;
	Button itbButton;
	Animation *itbAnim;
	std::vector<Button*> buttons;
	int finalChoice;
	ShipBuilder shipBuilder;
	bool bScoreScreen;
	OptionsScreen optionScreen;
	bool bSelectSave;
	ConfirmWindow confirmNewGame;
	ChoiceBox changelog;
	bool bCreditScreen;
	char _unk[4];
	CreditScreen credits;
	bool bChangedLogin;
	std::vector<CrewMember*> testCrew;
	bool bChangedScreen;
	std::string error;
	char gap34A4[3];
	char _unk2;
};

struct ResourceManager
{
};

struct CrewAnimation;

struct Drone
{
	void *vptr;
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

struct CrewDrone;

struct Path
{
	Point start;
	std::vector<Door*> doors;
	Point finish;
	float distance;
};

struct Ship;

struct CrewTarget;

struct CrewLaser
{
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
	CrewAnimation()
	{
	}

	CrewAnimation(int _shipId, const std::string& _race, Pointf _unk, char _hostile)
	{
		this->constructor(_shipId, _race, _unk, _hostile);
	}

	virtual ~CrewAnimation() {}
	LIBZHL_API virtual void OnRender(float scale, int selectedState, bool outlineOnly);
	LIBZHL_API virtual void OnRenderProps();
	virtual void OnUpdateEffects() LIBZHL_PLACEHOLDER
	virtual void UpdateFiring() LIBZHL_PLACEHOLDER
	virtual void UpdateShooting() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual bool FireShot();
	LIBZHL_API virtual int GetFiringFrame();
	virtual std::string *GetShootingSound(CrewAnimation *anim) LIBZHL_PLACEHOLDER
	virtual std::string *GetDeathSound(CrewAnimation *anim) LIBZHL_PLACEHOLDER
	virtual void Restart() LIBZHL_PLACEHOLDER
	virtual bool CustomDeath() LIBZHL_PLACEHOLDER
	LIBZHL_API void constructor(int shipId, const std::string &race, Pointf unk, bool hostile);
	LIBZHL_API static std::string &__stdcall GetDeathSound(std::string &strRef, CrewAnimation *anim);
	LIBZHL_API static std::string &__stdcall GetShootingSound(std::string &strRef, CrewAnimation *anim);
	LIBZHL_API void OnInit(const std::string &name, Pointf position, bool enemy);
	LIBZHL_API void SetupStrips();
	LIBZHL_API void OnUpdate(Pointf position, bool moving, bool fighting, bool repairing, bool dying, bool onFire);
	LIBZHL_API void destructor();
	
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
	unsigned __int8 gap_ex_1[2];
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
	unsigned __int8 gap_ex_2[2];
	std::vector<GL_Color> layerColors;
	int forcedAnimation;
	int forcedDirection;
	GL_Color projectileColor;
	bool bStunned;
	bool bDoorTarget;
	bool uniqueBool1;
	bool uniqueBool2;
};

struct Damage;

struct SCrewStats
{
	std::vector<int> stat;
	std::string species;
	std::string name;
	bool male;
};

struct Slot
{
	int roomId;
	int slotId;
	Point worldLocation;
};

struct LIBZHL_INTERFACE CrewMember
{
	CrewMember()
	{

	}

	CrewMember(CrewBlueprint& bp, int shipId, bool enemy, CrewAnimation *animation)
	{

		this->constructor(bp, shipId, enemy, animation);
	}
	
	ShipObject* GetShipObject()
	{
		return (ShipObject*)(this);
	}


	virtual ~CrewMember() {}
	virtual void *GetPosition() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual float PositionShift();
	LIBZHL_API virtual bool InsideRoom(int roomId);
	LIBZHL_API virtual bool ApplyDamage(float damage);
	virtual int GetPriority() LIBZHL_PLACEHOLDER
	virtual bool ValidTarget(int unk) LIBZHL_PLACEHOLDER
	virtual bool MultiShots() LIBZHL_PLACEHOLDER
	virtual bool ExactTarget() LIBZHL_PLACEHOLDER
	virtual bool IsCrew() LIBZHL_PLACEHOLDER
	virtual bool IsCloned() LIBZHL_PLACEHOLDER
	virtual bool IsDrone() LIBZHL_PLACEHOLDER
	virtual void Jump() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual bool NeedsIntruderSlot();
	LIBZHL_API virtual void SaveState(int fileHelper);
	LIBZHL_API virtual void LoadState(int fileHelper);
	LIBZHL_API virtual void OnLoop();
	LIBZHL_API virtual void OnRender(bool outlineOnly);
	virtual bool OutOfGame() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void SetOutOfGame();
	LIBZHL_API virtual bool Functional();
	virtual bool CountForVictory() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual bool GetControllable();
	virtual bool ReadyToFight() LIBZHL_PLACEHOLDER
	virtual bool CanFight() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual bool CanRepair();
	LIBZHL_API virtual bool CanSabotage();
	LIBZHL_API virtual bool CanMan();
	LIBZHL_API virtual bool CanTeleport();
	LIBZHL_API virtual bool CanHeal();
	virtual bool CanSuffocate() LIBZHL_PLACEHOLDER
	virtual bool CanBurn() LIBZHL_PLACEHOLDER
	virtual int GetMaxHealth() LIBZHL_PLACEHOLDER
	virtual bool IsDead() LIBZHL_PLACEHOLDER
	virtual bool PermanentDeath() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual bool ShipDamage(float damage);
	virtual bool FireFightingSoundEffect() LIBZHL_PLACEHOLDER
	virtual std::string *GetUniqueRepairing() LIBZHL_PLACEHOLDER
	virtual bool ProvidesVision() LIBZHL_PLACEHOLDER
	virtual float GetMoveSpeedMultiplier() LIBZHL_PLACEHOLDER
	virtual float GetRepairSpeed() LIBZHL_PLACEHOLDER
	virtual float GetDamageMultiplier() LIBZHL_PLACEHOLDER
	virtual bool ProvidesPower() LIBZHL_PLACEHOLDER
	virtual std::string *GetSpecies(std::string &str) LIBZHL_PLACEHOLDER
	virtual float GetFireRepairMultiplier() LIBZHL_PLACEHOLDER
	virtual bool IsTelepathic() LIBZHL_PLACEHOLDER
	virtual std::pair<float, float> GetPowerCooldown() LIBZHL_PLACEHOLDER
	virtual bool PowerReady() LIBZHL_PLACEHOLDER
	virtual void ActivatePower() LIBZHL_PLACEHOLDER
	virtual bool HasSpecialPower() LIBZHL_PLACEHOLDER
	virtual void ResetPower() LIBZHL_PLACEHOLDER
	virtual float GetSuffocationMultiplier() LIBZHL_PLACEHOLDER
	virtual int BlockRoom() LIBZHL_PLACEHOLDER
	virtual Damage *GetRoomDamage(CrewMember *crew) LIBZHL_PLACEHOLDER
	virtual bool IsAnaerobic() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void UpdateRepair();
	virtual bool CanStim() LIBZHL_PLACEHOLDER
	LIBZHL_API static Damage *__stdcall GetRoomDamage(Damage *dmg, CrewMember *crew);
	LIBZHL_API void constructor(CrewBlueprint &blueprint, int shipId, bool intruder, CrewAnimation *animation);
	LIBZHL_API void Jump(bool outlineOnly);
	LIBZHL_API void destructor();
	LIBZHL_API void Cleanup();
	LIBZHL_API void SetCurrentSystem(ShipSystem *sys);
	LIBZHL_API bool IsManningArtillery();
	LIBZHL_API void IncreaseSkill(int skillId);
	LIBZHL_API void CheckSkills();
	LIBZHL_API void MasterSkill(int skillId);
	LIBZHL_API static int __stdcall GetSkillFromSystem(int systemId);
	LIBZHL_API void SetResisted(bool resisted);
	LIBZHL_API bool GetResisted();
	LIBZHL_API void SetSkillProgress(int skillId, int skillLevel);
	LIBZHL_API int GetSkillLevel(int skillId);
	LIBZHL_API std::pair<int, int> GetSkillProgress(int skillId);
	LIBZHL_API void GetSkillModifier(int skillId);
	LIBZHL_API bool BadAtCombat();
	LIBZHL_API void EmptySlot();
	LIBZHL_API bool NeedsSlot();
	LIBZHL_API void DirectModifyHealth(float health);
	LIBZHL_API void ModifyHealth(float health);
	LIBZHL_API bool RepairingSystem();
	LIBZHL_API bool Sabotaging();
	LIBZHL_API bool RepairingFire();
	LIBZHL_API void *SelectSabotageTarget();
	LIBZHL_API void SavePosition();
	LIBZHL_API void ClearPosition();
	LIBZHL_API static void __stdcall GetSavedPosition(Slot *ret, CrewMember *crew);
	LIBZHL_API void SetSavePosition(Slot position);
	LIBZHL_API void StopRepairing();
	LIBZHL_API bool Repairing();
	LIBZHL_API void SetFrozen(bool frozen);
	LIBZHL_API void SetFrozenLocation(bool frozenLocation);
	LIBZHL_API void SetCrewTask(CrewTask task);
	LIBZHL_API Slot *FindSlot(int unk1, int roomId, bool unk2);
	LIBZHL_API bool CheckRoomPath(int roomId);
	LIBZHL_API void SetPosition(Point pos);
	LIBZHL_API void ClearTask();
	LIBZHL_API void ClearPath();
	LIBZHL_API void SetRoom(int roomId);
	LIBZHL_API bool IsBusy();
	LIBZHL_API bool OnInit();
	LIBZHL_API void *GetFinalGoal();
	LIBZHL_API void *GetNextGoal();
	LIBZHL_API void CloseDoorBehind(Door *door);
	LIBZHL_API float GetMoveSpeed();
	LIBZHL_API void Restart();
	LIBZHL_API void SetDamageBoost(float damageBoost);
	LIBZHL_API void SetHealthBoost(int healthBoost);
	LIBZHL_API void InitializeSkills();
	LIBZHL_API void SetCloneReady(bool cloneReady);
	LIBZHL_API void Kill();
	LIBZHL_API bool NeedFrozenLocation();
	LIBZHL_API void SetCurrentShip(int shipId);
	LIBZHL_API void CheckFighting();
	LIBZHL_API void SetDeathNumber(int deathNum);
	LIBZHL_API void ForceMindControl(bool force);
	LIBZHL_API void RenderSkillUpAnimation(Point pos);
	LIBZHL_API void Clone();
	LIBZHL_API void UpdateHealth();
	LIBZHL_API void OnRenderPath();
	LIBZHL_API bool SetPath();
	LIBZHL_API void SetRoomPath(int roomId, int slotId);
	LIBZHL_API void *GetLocation();
	LIBZHL_API bool AtGoal();
	LIBZHL_API bool AtFinalGoal();
	LIBZHL_API void OnRenderHealth();
	LIBZHL_API int GetIntegerHealth();
	LIBZHL_API int GetRepairingId();
	LIBZHL_API bool WithinRect(int x, int y, int w, int h);
	LIBZHL_API static std::string &__stdcall GetLongName(std::string &str, CrewMember *crew);
	LIBZHL_API void SetName(TextString name, bool force);
	LIBZHL_API static std::string &__stdcall GetName(std::string &str, CrewMember *crew);
	LIBZHL_API void SetCurrentTarget(CrewTarget *target, bool unk);
	LIBZHL_API void CheckForTeleport();
	LIBZHL_API char GetNewGoal();
	LIBZHL_API bool MoveToRoom(int roomId, int slotId, bool forceMove);
	LIBZHL_API void SetMindControl(bool controlled);
	LIBZHL_API bool RestorePosition();
	LIBZHL_API bool ContainsPoint(int x, int y);
	LIBZHL_API void SetMedbay(float health);
	LIBZHL_API void StartTeleport();
	LIBZHL_API void StartTeleportArrive();
	LIBZHL_API void StartRepair(Repairable *toRepair);
	LIBZHL_API void UpdateMovement();
	LIBZHL_API void SetSex(bool male);
	LIBZHL_API void CycleColorLayer(int unk);
	LIBZHL_API static std::string &__stdcall GetUniqueRepairing(std::string &strRef, CrewMember *crew);
	LIBZHL_API void SetTask(CrewTask task);
	
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
	unsigned __int8 gap_ex_1[2];
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
	unsigned __int8 gap_ex_2[2];
	Slot savedPosition;
	float fStunTime;
	CachedImage movementTarget;
	bool bCloned;
};

struct CrewDrone : CrewMember
{
	virtual ~CrewDrone()
	{
		this->destructor();
	}

	CrewDrone()
	{
	}

	CrewDrone(const std::string& type, const std::string& name, int shipId, const DroneBlueprint* blueprint, CrewAnimation *anim)
	{
		this->constructor(type, name, shipId, blueprint, anim);
	}

	LIBZHL_API void constructor(const std::string &type, const std::string &name, int shipId, const DroneBlueprint *blueprint, CrewAnimation *anim);
	LIBZHL_API virtual void OnLoop();
	LIBZHL_API virtual bool ProvidesVision();
	LIBZHL_API void SetCurrentShip(int shipId);
	LIBZHL_API void destructor();
	
	Drone _drone;
	int droneRoom;
	Animation powerUp;
	Animation powerDown;
	GL_Texture *lightLayer;
	GL_Texture *baseLayer;
};

struct RepairDrone : CrewDrone
{
};

struct WindowFrame
{
	WindowFrame(int _x, int _y, int _w, int _h) 
	{
		this->constructor(_x, _y, _w, _h);
	}
	
	~WindowFrame()
	{
		this->destructor();
	}


	LIBZHL_API void Draw(int x, int y);
	LIBZHL_API void DrawMask(int unk);
	LIBZHL_API void constructor(int x, int y, int w, int h);
	LIBZHL_API void destructor();
	
	Globals::Rect rect;
	GL_Primitive *outline;
	GL_Primitive *mask;
	GL_Primitive *pattern;
};

struct StoreBox;
struct Equipment;

struct Store;

struct Store : FocusWindow
{
	LIBZHL_API void OnInit(ShipManager *shopper, Equipment *equip, int worldLevel);
	LIBZHL_API void CreateStoreBoxes(int type, Equipment *equip);
	
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
	StoreBox *confirmBuy;
	int forceSystemInfoWidth;
};

struct Selectable
{
	void *vptr;
	int selectedState;
};

struct Room;

struct Room : Selectable
{
	Point GetIntoRoom(Point pos)
	{
		int posX = pos.x;
		int posY = pos.y;
		
		int rectY = this->rect.y;
		int rectH = this->rect.h;
		
		int rectX = this->rect.x;
		int rectW = this->rect.w;
		
		//printf("%d %d %d %d %d %d\n", posX, posY, rectX, rectW, rectY, rectH);
		
		if (rectY + rectH - posY > 15 && posY - rectY > 15)
		{
			if (rectW + rectX - posX > 15 && posX - rectX > 15)
			{
				return Point(-1, -1);
			}
		}
		
		
		
		
		Point center = Point(rectX + rectW / 2, rectY + rectH / 2);
		
		Point toGrid = Point((posX + 2 * (center.x > posX) - 1) / 35, (posY + 2 * (center.y > posY) - 1) / 35);
		Point fromGrid = Point(toGrid.x * 35, toGrid.y * 35);
		
		return Point(fromGrid.x + 17, fromGrid.y + 17);
	}

	Globals::Rect GetRect() 
	{
		return this->rect;
	}

	LIBZHL_API int GetEmptySlots(bool intruder);
	LIBZHL_API void constructor(int iShipId, int x, int y, int w, int h, int roomId);
	LIBZHL_API void OnRenderFloor(float alpha, bool experimental);
	LIBZHL_API void OnRenderWalls(float alpha);
	LIBZHL_API static void __stdcall __DO_NOT_HOOK();
	LIBZHL_API void destructor();
	
	ShipObject _shipObject;
	Globals::Rect rect;
	int iRoomId;
	bool bBlackedOut;
	unsigned __int8 gap_ex_1[2];
	std::vector<int> filledSlots;
	std::vector<std::vector<bool>> slots;
	bool bWarningLight;
	unsigned __int8 gap_ex_2[2];
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

struct Slot;
struct ShipGraph;

struct ShipGraph
{
	Slot* GetClosestSlot(Point pos, int shipId, bool intruder)
	{
		Slot* slot = nullptr;
		ShipGraph::GetClosestSlot(slot, this, pos, shipId, intruder);
		return slot;
	}
	
	static Point TranslateFromGrid(int xx, int yy)
	{
		return Point(xx * 35, yy * 35);
	}
	
	static Point TranslateToGrid(int xx, int yy)
	{
		return Point(xx / 35, yy / 35);
	}
	
	Point GetIntoRoom(int roomId, Point pos)
	{
		Point ret;
		if (roomId >= 0 && roomId < this->rooms.size())
		{
			auto room = this->rooms[roomId];
			ret = room->GetIntoRoom(pos);
		}
		else
		{
			ret = Point(-1, -1);
		}
		
		return ret;
	}
	
	Pointf GetRoomCenter(int roomId) 
	{
		auto rooms = this->rooms;
		float xx = -1;
		float yy = -1;
		
		for (auto const& x: rooms)
		{
			if (roomId == x->iRoomId)
			{
				auto rect = x->GetRect();
				
				xx = rect.x + rect.w / 2;
				yy = rect.y + rect.h / 2;
				break;
			}
		}
		
		return Pointf(xx, yy);
	}
	
	Point GetSlotWorldPosition(int roomId, int slotId)
	{
		Globals::Rect rect = rooms[roomId]->rect;
		return Point(rect.x + 35 * (slotId % (rect.w / 35)) + 17, rect.y + 35 * (slotId / (rect.h / 35)) + 17);
	}
	

	LIBZHL_API static ShipGraph *__stdcall GetShipInfo(int shipId);
	LIBZHL_API Point GetSlotRenderPosition(int x, int y, char unk);
	LIBZHL_API int DoorCount(int unk);
	LIBZHL_API std::vector<Door*> &GetDoors(int unk);
	LIBZHL_API int IsRoomConnected(int room1, int room2);
	LIBZHL_API int ConnectingDoor(int x1, int y1, int x2, int y2);
	LIBZHL_API int ConnectedGridSquares(int x1, int y1, int x2, int y2);
	LIBZHL_API int ConnectedGridSquaresPoint(Point p1, Point p2);
	LIBZHL_API int ConnectingDoor(Point p1, Point p2);
	LIBZHL_API int GetNumSlots(int room);
	LIBZHL_API static int __stdcall PopClosestDoor(std::vector<int> &unk, std::vector<float> &unk2);
	LIBZHL_API int Dijkstra(Point p1, Point p2, int unk);
	LIBZHL_API int FindPath(Point p1, Point p2, int unk);
	LIBZHL_API float ConvertToWorldAngle(float ang);
	LIBZHL_API float ConvertToLocalAngle(float ang);
	LIBZHL_API int64_t ConvertToWorldPosition(Pointf p);
	LIBZHL_API Pointf ConvertToLocalPosition(Pointf p, char unk);
	LIBZHL_API int ComputeCenter();
	LIBZHL_API bool ContainsPoint(int x, int y);
	LIBZHL_API int GetSelectedRoom(int x, int y, bool unk);
	LIBZHL_API int RoomCount();
	LIBZHL_API Globals::Rect *GetRoomShape(int room);
	LIBZHL_API float GetRoomOxygen(int room);
	LIBZHL_API bool GetRoomBlackedOut(int room);
	LIBZHL_API static Slot *__stdcall GetClosestSlot(Slot *slot, ShipGraph *graph, Point pos, int shipId, bool intruder);
	
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

struct Fire
{
};

struct Spreader_Fire : ShipObject
{
	int count;
	std::vector<int> roomCount;
	std::vector<std::vector<Fire>> grid;
};

struct AugmentEquipBox;

struct DroneSystem;

struct Drone;

struct EquipmentBoxItem
{
	ProjectileFactory *pWeapon;
	Drone *pDrone;
	CrewMember *pCrew;
	const AugmentBlueprint *augment;
};

struct LIBZHL_INTERFACE EquipmentBox
{
	bool IsEmpty()
	{
		return !item.pWeapon && !item.pDrone && (!item.augment || item.augment->name.empty()) && !item.pCrew;
	}

	LIBZHL_API virtual ~EquipmentBox();
	LIBZHL_API virtual void SetPosition(Point pos);
	LIBZHL_API virtual void OnRender(bool isEmpty);
	LIBZHL_API virtual void RenderLabels(bool unk);
	virtual void RenderIcon(bool empty) LIBZHL_PLACEHOLDER
	virtual void SetShipManager(ShipManager *ship) LIBZHL_PLACEHOLDER
	LIBZHL_API virtual int MouseMove(int x, int y);
	virtual void OnTouch() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void UpdateBoxImage(bool unk);
	LIBZHL_API virtual void Restart();
	LIBZHL_API virtual void AddItem(EquipmentBoxItem item);
	virtual void RemoveItem() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual bool CanHoldWeapon();
	LIBZHL_API virtual bool CanHoldDrone();
	virtual char CanHoldAugment() LIBZHL_PLACEHOLDER
	virtual void CheckContents() LIBZHL_PLACEHOLDER
	virtual int GetType(bool unk) LIBZHL_PLACEHOLDER
	virtual char IsCargoBox() LIBZHL_PLACEHOLDER
	virtual char CanHoldCrew() LIBZHL_PLACEHOLDER
	virtual char CanDoJob() LIBZHL_PLACEHOLDER
	LIBZHL_API void constructor(Point pos, int slot);
	LIBZHL_API Blueprint *GetBlueprint();
	LIBZHL_API void SetBlueprint(InfoBox *infoBox, bool detailedBox);
	LIBZHL_API virtual int GetType();
	LIBZHL_API int GetItemValue();
	
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
	LIBZHL_API void RenderIcon();
	LIBZHL_API void CheckContents();
	LIBZHL_API void RemoveItem();
	
	ShipManager *ship;
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

struct LockdownShard
{
};

struct OuterHull;

struct Ship : ShipObject
{
	Pointf GetRoomCenter(int room)
	{
		auto graph = ShipGraph::GetShipInfo(this->iShipId);
		return graph->GetRoomCenter(room);
	}
	
	enum DoorStateType
	{
	  DOOR_CLOSED = 0x0,
	  DOOR_OPEN = 0x1,
	  DOOR_OPEN_FORCED = 0x2,
	  DOOR_HIT = 0x3,
	  DOOR_ANIMATING = 0x4,
	};


	struct DoorState
	{
		DoorStateType state;
		bool hacked;
		int level;
	};
	
	LIBZHL_API int GetSelectedRoomId(int x, int y, bool unk);
	LIBZHL_API void LockdownRoom(int roomId, Pointf pos);
	LIBZHL_API bool RoomLocked(int roomId);
	LIBZHL_API bool FullRoom(int roomId, bool intruder);
	LIBZHL_API int EmptySlots(int roomId);
	LIBZHL_API int GetAvailableRoomSlot(int roomId, bool intruder);
	LIBZHL_API void OnRenderBreaches();
	LIBZHL_API void OnRenderWalls(bool forceView, bool doorControlMode);
	LIBZHL_API void OnInit(ShipBlueprint &bp);
	LIBZHL_API void OnRenderSparks();
	LIBZHL_API void SetRoomBlackout(int roomId, bool blackout);
	LIBZHL_API void OnRenderBase(bool unk);
	LIBZHL_API void OnRenderFloor();
	
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

struct Targetable;

struct WeaponControl;

struct WeaponControl : ArmamentControl
{
	LIBZHL_API void Fire(std::vector<Pointf> &points, int target, bool autoFire);
	LIBZHL_API void OnRender();
	LIBZHL_API void LButton(int x, int y);
	LIBZHL_API void MouseMove(int x, int y);
	LIBZHL_API void LinkShip(ShipManager *ship);
	LIBZHL_API void constructor();
	LIBZHL_API void SetAutofiring(bool on, bool simple);
	LIBZHL_API void KeyDown(SDLKey key);
	
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

struct Projectile;

struct AsteroidGenerator;

struct AsteroidGenerator
{
	LIBZHL_API void constructor();
	LIBZHL_API float Initialize(int numberOfShips, int shieldCount, bool unk);
	LIBZHL_API void SetNumShips(int ships);
	LIBZHL_API Projectile *GetNextAsteroid();
	LIBZHL_API void OnLoop();
	LIBZHL_API float GetNextState();
	LIBZHL_API void UpdateState();
	LIBZHL_API bool SaveAsteroids(void *file);
	LIBZHL_API void LoadAsteroids(void *file);
	
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

struct TouchInputEvent
{
	unsigned int id;
	float x;
	float y;
	float initial_x;
	float initial_y;
};

struct BatteryBox
{
};

struct BossShip;

struct SpaceManager;

struct CompleteShip;

struct LIBZHL_INTERFACE CompleteShip
{
	virtual ~CompleteShip() {}
	LIBZHL_API virtual void OnLoop();
	LIBZHL_API virtual void PauseLoop();
	virtual bool IsBoss() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void Restart();
	virtual bool IncomingFire() LIBZHL_PLACEHOLDER
	LIBZHL_API void constructor(SpaceManager *space, bool unk, int unk2);
	LIBZHL_API void SetShip(ShipManager *ship);
	LIBZHL_API void OnInit(const ShipBlueprint *blueprint, int unk);
	LIBZHL_API void AddBoarders(int amount, const std::string &race, bool unk2);
	LIBZHL_API CrewMember *AddCrewMember(const CrewBlueprint *blueprint, bool hostile);
	LIBZHL_API CrewMember *AddCrewMember1(const std::string &race, const std::string &name, bool hostile);
	LIBZHL_API Drone *AddDrone(const DroneBlueprint *blueprint, int unk);
	LIBZHL_API CrewMember *AddCrewMember2(CrewMember *member, int unk);
	LIBZHL_API char SaveState(int unk);
	LIBZHL_API void LoadState(int unk);
	LIBZHL_API int InitiateTeleport(int room, int shipId);
	LIBZHL_API void GetTeleportingParty();
	LIBZHL_API CrewMember *KillRandomCrew();
	LIBZHL_API int CountCrew(bool boarders);
	LIBZHL_API CrewMember **Jump();
	LIBZHL_API void SetEnemyShip(CompleteShip *other);
	LIBZHL_API bool DeadCrew();
	LIBZHL_API void TeleportCrew(ShipManager *other, int room, bool comingBack);
	LIBZHL_API void OnRender();
	LIBZHL_API void OnRenderSpace();
	LIBZHL_API void OnRenderShip(bool unk1, bool unk2);
	
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

struct LocationEvent;

struct BossShip : CompleteShip
{
	LIBZHL_API void Restart();
	LIBZHL_API bool IncomingFire();
	LIBZHL_API void constructor(SpaceManager *space);
	LIBZHL_API void SaveBoss(void *file);
	LIBZHL_API int LoadBoss(void *file);
	LIBZHL_API int ClearLocation();
	LIBZHL_API char Defeated();
	LIBZHL_API int GetSubEvent();
	LIBZHL_API void StartStage();
	LIBZHL_API LocationEvent *GetEvent();
	LIBZHL_API void OnLoop();
	
	int currentStage;
	TimerHelper powerTimer;
	int powerCount;
	std::vector<int> crewCounts;
	bool bDeathBegan;
	int nextStage;
};

struct AnaerobicAnimation
{
};

struct DebugHelper
{
	LIBZHL_API static int __stdcall CrashCatcher(void *exception_pointers);
	
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

struct TabbedWindow;
struct Upgrades;
struct SystemControl;
struct TutorialManager;

struct TutorialManager
{
	LIBZHL_API void constructor();
	LIBZHL_API bool Running();
	LIBZHL_API void OnInit(ShipManager *ship, CommandGui *gui, CrewControl *crewControl, Upgrades *upgradesScreen, CombatControl *combatControl, SystemControl *sysControl, TabbedWindow *unk);
	
};

struct AnimationSheet
{
	int w;
	int h;
	int frameHeight;
	int frameWidth;
	GL_Texture *imageId;
};

struct DroneControl : ArmamentControl
{
	WarningMessage droneMessage;
	WarningMessage noTargetMessage;
	WarningMessage systemMessage;
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

struct AchievementTracker;

struct AchievementTracker
{
	LIBZHL_API void LoadAchievementDescriptions();
	LIBZHL_API static void *__stdcall GetShipAchievements(void *unk, AchievementTracker *tracker, const std::string &name);
	LIBZHL_API void SetAchievement(const std::string &achievement, bool noPopup, bool sendToServer);
	LIBZHL_API void UnlockShip(int shipId, int shipType);
	LIBZHL_API void SetSectorEight();
	LIBZHL_API int GetShipMarker(const std::string &baseName, const std::string &thisName);
	LIBZHL_API void SetFlag(const std::string &flagName);
	LIBZHL_API bool GetFlag(const std::string &flagName);
	LIBZHL_API void SaveProfile(int file);
	LIBZHL_API void LoadProfile(int file, int version);
	LIBZHL_API void SetVictoryAchievement();
	
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

struct EngineSystem;
struct DamageMessage;

struct Shields;

struct Targetable
{
	void *vptr;
	int type;
	bool hostile;
	bool targeted;
};

struct HackingSystem;
struct BatterySystem;
struct ParticleEmitter;

struct Collideable
{
	void *vptr;
};

struct MedbaySystem;
struct OxygenSystem;

struct ArtillerySystem;

struct ArtillerySystem
{
	LIBZHL_API void OnLoop();
	
};

struct MindSystem;

struct CloneSystem;
struct TeleportSystem;

struct ShipManager : ShipObject
{
	ShipManager(int shipId) 
	{
		this->constructor(shipId);
	}
	
	Pointf GetRandomRoomCenter()
	{
		auto rng = rand();
		auto graph = ShipGraph::GetShipInfo(this->iShipId);
		auto rooms = graph->rooms.size();
		return this->ship.GetRoomCenter(rng % rooms);
	}
	
	Pointf GetRoomCenter(int roomId)
	{
		return ship.GetRoomCenter(roomId);
	}
	
	std::vector<ProjectileFactory*> GetWeaponList()
	{
		std::vector<ProjectileFactory*> vec = std::vector<ProjectileFactory*>();
		ShipManager::GetWeaponList(vec, this);
		return vec;
	}
	
	~ShipManager()
	{
		this->destructor2();
	}
	


	LIBZHL_API int constructor(int shipId);
	LIBZHL_API void AddInitialCrew(std::vector<CrewBlueprint> &blueprints);
	LIBZHL_API int GetDodgeFactor();
	LIBZHL_API void OnRender(char showInterior, char doorControlMode);
	LIBZHL_API int CountCrew(char boarders);
	LIBZHL_API static std::vector<CrewMember*> *__stdcall TeleportCrew(std::vector<CrewMember*> *crewList, ShipManager *ship, int roomId, bool intruders);
	LIBZHL_API int OnInit(ShipBlueprint *bp, int shipLevel);
	LIBZHL_API char HasSystem(int systemId);
	LIBZHL_API ShipSystem *GetSystemInRoom(int roomId);
	LIBZHL_API void OnLoop();
	LIBZHL_API void SetSystemPowerLoss(int systemId, int powerLoss);
	LIBZHL_API int CreateSystems();
	LIBZHL_API int AddSystem(int systemId);
	LIBZHL_API void UpdateCrewMembers();
	LIBZHL_API void UpdateEnvironment();
	LIBZHL_API CrewMember *AddCrewMemberFromBlueprint(CrewBlueprint *bp, int slot, bool init, int roomId, bool intruder);
	LIBZHL_API CrewMember *AddCrewMemberFromString(const std::string &name, const std::string &race, char intruder, int roomId, char init, char male);
	LIBZHL_API int GetOxygenPercentage();
	LIBZHL_API char DamageCrew(CrewMember *crew, int iDamage, int iShieldPiercing, int fireChance, int breachChance, int stunChance, int iIonDamage, int iSystemDamage, int iPersDamage, char bHullBuster, int ownerId, int selfId, int bLockdown, int iStun);
	LIBZHL_API void RemoveItem(const std::string &name);
	LIBZHL_API char DamageArea(Pointf location, int iDamage, int iShieldPiercing, int fireChance, int breachChance, int stunChance, int iIonDamage, int iSystemDamage, int iPersDamage, char bHullBuster, int ownerId, int selfId, int bLockdown, int iStun, char forceHit);
	LIBZHL_API static CrewBlueprint *__stdcall SelectRandomCrew(CrewBlueprint &bp, ShipManager *ship, int seed, const std::string &unk);
	LIBZHL_API void ClearStatusAll();
	LIBZHL_API void PrepareSuperDrones();
	LIBZHL_API void JumpLeave();
	LIBZHL_API void ModifyScrapCount(int scrap, bool income);
	LIBZHL_API bool DoSensorsProvide(int vision);
	LIBZHL_API bool IsCrewFull();
	LIBZHL_API bool IsCrewOverFull();
	LIBZHL_API CrewDrone *CreateCrewDrone(const DroneBlueprint *bp);
	LIBZHL_API SpaceDrone *CreateSpaceDrone(const DroneBlueprint *bp);
	LIBZHL_API bool CommandCrewMoveRoom(CrewMember *crew, int roomId);
	LIBZHL_API int GetSystemRoom(int sysId);
	LIBZHL_API static std::vector<ProjectileFactory*> &__stdcall GetWeaponList(std::vector<ProjectileFactory*> &wepList, ShipManager *ship);
	LIBZHL_API Drone *AddDrone(const DroneBlueprint *bp, int slot);
	LIBZHL_API void Restart();
	LIBZHL_API int GetSystemPower(int systemId);
	LIBZHL_API int CountCrewShipId(int roomId, int shipId);
	LIBZHL_API ShipSystem *GetSystem(int systemId);
	LIBZHL_API void ExportShip(int file);
	LIBZHL_API void destructor();
	LIBZHL_API void destructor2();
	LIBZHL_API void ImportShip(int file);
	LIBZHL_API void CheckVision();
	LIBZHL_API bool IsSystemHacked(int systemId);
	LIBZHL_API CrewMember *GetSelectedCrewPoint(int x, int y, bool intruder);
	LIBZHL_API void RenderWeapons();
	LIBZHL_API void DamageSystem(int roomId, int iDamage, int iShieldPiercing, int fireChance, int breachChance, int stunChance, int iIonDamage, int iSystemDamage, int iPersDamage, char bHullBuster, int ownerId, int selfId, int bLockdown, int iStun);
	LIBZHL_API void ClearStatusSystem(int system);
	LIBZHL_API void ResetScrapLevel();
	
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
	unsigned __int8 gap_ex_1[2];
	Shields *shieldSystem;
	WeaponSystem *weaponSystem;
	DroneSystem *droneSystem;
	EngineSystem *engineSystem;
	MedbaySystem *medbaySystem;
	std::vector<ArtillerySystem> artillerySystems;
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
	unsigned __int8 gap_ex_2[2];
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

struct SpaceDrone : Drone
{
	LIBZHL_API float UpdateAimingAngle(Pointf location, float percentage, float forceDesired);
	LIBZHL_API void SetDeployed(bool deployed);
	LIBZHL_API void SetMovementTarget(Targetable *target);
	
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

struct BoarderPodDrone;

struct BoarderPodDrone : SpaceDrone
{
	LIBZHL_API void constructor(int _iShipId, int _selfId, const DroneBlueprint &_bp);
	LIBZHL_API void SetMovementTarget(Targetable *target);
	
	GL_Texture *baseSheet;
	GL_Texture *colorSheet;
	Pointf startingPosition;
	Animation droneImage;
	CachedImage flame;
	BoarderDrone *boarderDrone;
	bool bDeliveredDrone;
	bool diedInSpace;
};

struct TeleportBox
{
};

struct TextButton0 : GenericButton
{
	GL_Primitive *primitives[3];
	GL_Texture *baseImage;
	Point baseImageOffset;
	GL_Primitive *basePrimitive;
	bool colorsSet;
	char gap65[3];
	GL_Color colors[3];
	GL_Color textColor;
	Point buttonSize;
	int cornerInset;
	bool autoWidth;
	char gapB5[3];
	int autoWidthMargin;
	int autoWidthMin;
	bool autoRightAlign;
	char gapC1[3];
	TextString label;
	int font;
	int lineHeight;
	int textYOffset;
	char autoShrink;
	char ready;
};

struct FTLButton : TextButton0
{
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

struct DropBox;

struct DropBox
{
	LIBZHL_API void OnRender();
	LIBZHL_API int GetHeight();
	
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

struct KeyboardInputEvent
{
	int key;
	int system_key;
	unsigned int modifiers;
	char is_repeat;
};

struct EventGenerator;

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

struct EventGenerator
{
	SectorDescription *GetSpecificSector(const std::string& name)
	{
		SectorDescription *desc = new SectorDescription();
		EventGenerator::GetSpecificSector(desc, this, name);
		
		return desc;
	}
	
	std::string GetImageFromList(const std::string& listName)
	{
		std::string ret = std::string();
		
		GetImageFromList(ret, this, listName);
		
		return ret;
	}

	LIBZHL_API LocationEvent *GetBaseEvent(const std::string &name, int worldLevel, char ignoreUnique, int seed);
	LIBZHL_API LocationEvent *CreateEvent1(const std::string &name, int worldLevel);
	LIBZHL_API static Sector *__stdcall GetSpecificSector(SectorDescription *desc, EventGenerator *eventGenerator, const std::string &name);
	LIBZHL_API static void __stdcall GetImageFromList(std::string &ret, EventGenerator *eventGenerator, const std::string &listName);
	
};

struct BombProjectile
{
};

struct StoreBox
{
	void *vptr;
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
	const Blueprint *pBlueprint;
	bool bEquipmentBox;
	float fIconScale;
	Point pushIcon;
};

struct ItemStoreBox
{
};

struct CrewEquipBox;

struct CrewEquipBox : EquipmentBox
{
	CrewEquipBox(Point pos_, ShipManager *ship_, int slot_)
	{
		this->constructor(pos_, ship_, slot_);
	}

	LIBZHL_API void RemoveItem();
	LIBZHL_API void constructor(Point pos, ShipManager *ship, int slot);
	LIBZHL_API bool GetConfirmDelete();
	LIBZHL_API void RenderLabels(bool dragging, bool isNew);
	LIBZHL_API void OnRender(bool unk);
	LIBZHL_API void OnTextInput(SDLKey key);
	LIBZHL_API void OnTextEvent(CEvent::TextEvent event);
	LIBZHL_API void MouseClick(int mX, int mY);
	LIBZHL_API void CloseRename();
	
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

struct HotkeyDesc
{
	std::string name;
	int key;
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

struct EventDamage
{
	int system;
	int amount;
	int effect;
};

struct AugmentStoreBox
{
};

struct StatusEffect;

struct StatusEffect
{
	LIBZHL_API static StatusEffect *__stdcall GetNebulaEffect();
	
	int type;
	int system;
	int amount;
	int target;
};

struct RockAlien
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

struct ShipTemplate
{
	std::string shipEventName;
	bool hostile;
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

struct WeaponEquipBox : EquipmentBox
{
};

struct JoystickInputEvent
{
	int device;
	int index;
	float x;
	float y;
};

struct Projectile : Collideable
{
	LIBZHL_API void CollisionCheck(Collideable *other);
	LIBZHL_API void constructor(Pointf position, int ownerId, int targetId, Pointf target);
	
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
	unsigned __int8 gap_ex_1[2];
	Animation death_animation;
	Animation flight_animation;
	Pointf speed;
	bool missed;
	bool hitTarget;
	unsigned __int8 gap_ex_2[2];
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

struct MenuScreen;

struct MenuScreen : FocusWindow
{
	LIBZHL_API void OnRender();
	LIBZHL_API void constructor();
	
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

struct CrewManifest;

struct CrewManifest : FocusWindow
{
	LIBZHL_API void OnInit(ShipManager *ship);
	LIBZHL_API void OnRender();
	LIBZHL_API void constructor();
	LIBZHL_API void Update();
	LIBZHL_API void OnKeyDown(SDLKey key);
	LIBZHL_API void OnKeyUp(SDLKey key);
	LIBZHL_API void OnTextInput(SDLKey key);
	LIBZHL_API void OnTextEvent(CEvent::TextEvent event);
	LIBZHL_API void Close();
	LIBZHL_API void MouseClick(int mX, int mY);
	LIBZHL_API void MouseMove(int mX, int mY);
	
	GL_Primitive *box;
	DropBox overBox;
	ShipManager *shipManager;
	std::vector<CrewEquipBox*> crewBoxes;
	InfoBox infoBox;
	int confirmingDelete;
	ConfirmWindow deleteDialog;
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

struct AnimationControl;

struct AnimationControl
{
	Animation* GetAnimation(const std::string& animName)
	{
		Animation* animRef = new Animation();
		
		AnimationControl::GetAnimation(*animRef, this, animName);
		
		return animRef;
	}

	LIBZHL_API static Animation *__stdcall GetAnimation(Animation &animRef, AnimationControl *animControl, const std::string &animName);
	
	std::map<std::string, AnimationSheet> animSheets;
	std::map<std::string, Animation> animations;
	std::map<std::string, WeaponAnimation> weapAnimations;
};

struct Spreadable
{
};

struct MantisAlien
{
};

struct DefenseDrone;

struct DefenseDrone : SpaceDrone
{
	LIBZHL_API bool ValidTargetObject(Targetable *other);
	LIBZHL_API void PickTarget();
	
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

struct ShipEvent;

struct CrewDesc
{
};

struct ShipEvent
{
	LIBZHL_API void __stdcall constructor(const ShipEvent &event);
	
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

struct LocationEvent
{
	struct Choice
	{
		LocationEvent *event;
		TextString text;
		ChoiceReq requirement;
		bool hiddenReward;
	};
	
	LIBZHL_API void ClearEvent(bool force);
	
	TextString text;
	ShipEvent ship;
	ResourceEvent stuff;
	int environment;
	int environmentTarget;
	bool store;
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

struct FileHelper
{
	static std::string readString(int file)
	{
		std::string data = std::string();
		
		readString(data, file);
		
		return data;
	}

	LIBZHL_API static void __stdcall deleteFile(const std::string &fileName);
	LIBZHL_API static std::string &__stdcall getResourceFile(const std::string &str);
	LIBZHL_API static std::string &__stdcall getUserFolder(std::string &str);
	LIBZHL_API static std::string &__stdcall getSaveFile(std::string &str);
	LIBZHL_API static void __stdcall initFileHelper();
	LIBZHL_API static int __stdcall fileLength(int file);
	LIBZHL_API static bool __stdcall fileExists(const std::string &fileName);
	LIBZHL_API static void __stdcall renameFile(const std::string &fileName, const std::string &newName);
	LIBZHL_API static int __stdcall createBinaryFile(const std::string &fileName);
	LIBZHL_API static int __stdcall createSaveFile();
	LIBZHL_API static int __stdcall createStatsFile();
	LIBZHL_API static void __stdcall deleteSaveFile();
	LIBZHL_API static void __stdcall deleteAllSaveFiles();
	LIBZHL_API static int __stdcall getPosition(int file);
	LIBZHL_API static int __stdcall readBinaryFile(const std::string &fileName);
	LIBZHL_API static void __stdcall closeBinaryFile(int file);
	LIBZHL_API static std::string &__stdcall readString(const std::string &str, int file);
	LIBZHL_API static float __stdcall readFloat(int file);
	LIBZHL_API static int __stdcall readInteger(int file);
	LIBZHL_API static bool __stdcall seekPosition(int file, int pos);
	LIBZHL_API static char *__stdcall readBuffer(int file, int len, bool unk);
	LIBZHL_API static void __stdcall readData(int file, void *data, int len);
	LIBZHL_API static bool __stdcall writeData(int file, void *data, int len);
	LIBZHL_API static int __stdcall readSaveFile();
	LIBZHL_API static int __stdcall readStatsFile();
	LIBZHL_API static bool __stdcall saveFileExists();
	LIBZHL_API static bool __stdcall writeFloat(int file, float data);
	LIBZHL_API static bool __stdcall writeString(int file, const std::string &data);
	LIBZHL_API static bool __stdcall writeInt(int file, int data);
	
};

struct RockAnimation;

struct RockAnimation : CrewAnimation
{
    RockAnimation(const std::string& subRace, int shipId, Pointf position, bool enemy) : CrewAnimation(shipId, subRace, position, enemy)
	{
		this->constructor(subRace, shipId, position, enemy);
	}

	LIBZHL_API void constructor(const std::string &subRace, int iShipId, Pointf position, bool enemy);
	LIBZHL_API static void __stdcall __DO_NOT_HOOK();
	LIBZHL_API static void __stdcall __DO_NOT_HOOK2();
	LIBZHL_API static std::string &__stdcall GetShootingSound(std::string &strRef, RockAnimation *anim);
	LIBZHL_API static void __stdcall __DO_NOT_HOOK3();
	LIBZHL_API static void __stdcall __DO_NOT_HOOK4();
	LIBZHL_API static std::string &__stdcall GetDeathSound(std::string &strRef, RockAnimation *anim);
	
};

struct TeleportSystem : ShipSystem
{
	LIBZHL_API void SetHackingLevel(int hackingLevel);
	LIBZHL_API void OnRenderFloor();
	LIBZHL_API void constructor(int systemId, int roomId, int shipId, int startingPower);
	LIBZHL_API float GetChargedPercent();
	LIBZHL_API bool Charged();
	LIBZHL_API void ClearCrewLocations();
	LIBZHL_API void UpdateCrewLocation(int unk);
	LIBZHL_API void SetArmed(int armed);
	LIBZHL_API void ForceReady();
	LIBZHL_API bool CanSend();
	LIBZHL_API bool CanReceive();
	LIBZHL_API void InitiateTeleport();
	LIBZHL_API void OnLoop();
	LIBZHL_API void Jump();
	
	float chargeLevel;
	bool bCanSend;
	bool bCanReceive;
	int iArmed;
	std::vector<bool> crewSlots;
	char unk[8];
	int iPreparedCrew;
	int iNumSlots;
	bool bSuperShields;
};

struct ShipButton : Button
{
	ShipButton(int x, int y)
	{
		this->constructor(x, y);
	}

	LIBZHL_API void constructor(int shipType, int shipVariant);
	LIBZHL_API void OnInit(const std::string &imgName, Point pos);
	LIBZHL_API bool MouseMove(int x, int y);
	LIBZHL_API void OnRender();
	
	GL_Texture *iShipImage;
	bool bShipLocked;
	bool bLayoutLocked;
	bool bNoExist;
	std::vector<CAchievement*> achievements;
	int iSelectedAch;
	bool bSelected;
};

struct TextInputEvent
{
	int32_t ch;
};

struct DroneBox
{
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

struct CombatControl
{
	LIBZHL_API void RenderTarget();
	LIBZHL_API ShipManager *GetCurrentTarget();
	LIBZHL_API char CurrentTargetIsBoss();
	LIBZHL_API char CanTargetSelf();
	LIBZHL_API void OnRenderCombat();
	LIBZHL_API void AddEnemyShip(CompleteShip *ship);
	LIBZHL_API void UpdateAiming();
	LIBZHL_API bool UpdateTarget();
	LIBZHL_API void DrawHostileBox(GL_Color color, int stencilBit);
	LIBZHL_API void OnInit(Point pos);
	LIBZHL_API void OnLoop();
	
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

struct UpgradeBox
{
};

struct SystemControl
{
	LIBZHL_API void CreateSystemBoxes();
	LIBZHL_API SystemBox *GetSystemBox(int systemId);
	LIBZHL_API void RenderPowerBar();
	
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

struct SoundControl;

struct SoundControl
{
	LIBZHL_API int PlaySoundMix(const std::string &soundName, float volume, char loop);
	LIBZHL_API void StopPlaylist(int fadeOut);
	
};

struct StarMap;

struct ShipStatus;

struct WarningWithLines;

struct ShipStatus
{
	LIBZHL_API void RenderHealth(bool unk);
	LIBZHL_API void OnInit(Point unk, float unk2);
	LIBZHL_API void RenderEvadeOxygen(bool unk);
	
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

struct FocusWindow;

struct GameOver;

struct GameOver : FocusWindow
{
	LIBZHL_API void OpenText(const std::string &text);
	LIBZHL_API void OnRender();
	
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

struct Equipment : FocusWindow
{
	LIBZHL_API void OnInit(ShipManager *ship);
	LIBZHL_API void OnLoop();
	LIBZHL_API void MouseClick(int mX, int mY);
	LIBZHL_API void MouseUp(int mX, int mY);
	
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

struct UpgradeBox;

struct ReactorButton : Button
{
	int tempUpgrade;
	ShipManager *ship;
	bool selected;
};

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

struct Location;

struct CommandGui
{
	LIBZHL_API void RunCommand(std::string &command);
	LIBZHL_API Store *CreateNewStore(int sectorNumber);
	LIBZHL_API void *GetWorldCoordinates(Point point, bool fromTarget);
	LIBZHL_API void KeyDown(SDLKey key, bool shiftHeld);
	LIBZHL_API void RenderStatic();
	LIBZHL_API void constructor();
	LIBZHL_API void AddEnemyShip(CompleteShip *ship);
	LIBZHL_API void Victory();
	LIBZHL_API void OnInit();
	LIBZHL_API void MouseMove(int mX, int mY);
	LIBZHL_API void LButtonDown(int mX, int mY, bool shiftHeld);
	LIBZHL_API void OnLoop();
	LIBZHL_API void CheckGameover();
	LIBZHL_API bool IsGameOver();
	
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

struct DroneEquipBox : EquipmentBox
{
};

struct LaserBlast;

struct LaserBlast : Projectile
{
	LIBZHL_API void OnUpdate();
	
	Targetable *movingTarget;
	float spinAngle;
	float spinSpeed;
};

struct PDSFire : LaserBlast
{
	Pointf startPoint;
	bool passedTarget;
	float currentScale;
	bool missed;
	Animation explosionAnimation;
};

struct IonDrone;

struct BoarderDrone : CrewDrone
{
	BoarderDrone() 
	{
	}

	BoarderDrone(const std::string& _type, const std::string& _name, int _shipId, const DroneBlueprint* _blueprint, CrewAnimation *_anim)
	{
		this->constructor(_type, _name, _shipId, _blueprint, _anim);
	}

};

struct IonDrone : BoarderDrone
{
	LIBZHL_API static Damage *__stdcall GetRoomDamage(Damage *dmg, IonDrone *crew);
	
	int lastRoom;
};

struct MedbaySystem
{
};

struct ProjectileFactory : ShipObject
{
	LIBZHL_API void constructor(const WeaponBlueprint *bp, int shipId);
	LIBZHL_API int SelectChargeGoal();
	LIBZHL_API bool IsChargedGoal();
	LIBZHL_API void SetHacked(int hacked);
	LIBZHL_API void SetCurrentShip(Targetable *ship);
	LIBZHL_API void SetCooldownModifier(float mod);
	LIBZHL_API void ForceCoolup();
	LIBZHL_API void RenderChargeBar(float unk);
	LIBZHL_API static int __stdcall StringToWeapon(const std::string &str);
	LIBZHL_API void Fire(std::vector<Pointf> &points, int target);
	LIBZHL_API char FireNextShot();
	LIBZHL_API int SpendMissiles();
	LIBZHL_API void OnRender(float alpha, bool forceVisual);
	LIBZHL_API int NumTargetsRequired();
	
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

struct GL_Line
{
	GL_Line(float x1, float y1, float x2, float y2)
	{
		start = Pointf(x1, y1);
		end = Pointf(x2, y2);
	}
	
	GL_Line(Pointf _start, Pointf _end) : start(_start), end(_end)
	{
	}		

	Pointf start;
	Pointf end;
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

struct ArtilleryBox
{
};

struct DroneSystem : ShipSystem
{
	LIBZHL_API void RemoveDrone(int slot);
	LIBZHL_API void UpdateBonusPower();
	LIBZHL_API virtual void SetBonusPower(int amount, int permanentPower);
	
	std::vector<Drone*> drones;
	int drone_count;
	int drone_start;
	Targetable *targetShip;
	std::vector<bool> userPowered;
	int slot_count;
	int iStartingBatteryPower;
	std::vector<bool> repowerList;
};

struct WorldManager;

struct DistressButton : TextButton
{
	TextString labels[2];
	bool state;
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
	
	LIBZHL_API void SetPosition(Point unk0);
	LIBZHL_API void KeyDown(int unk0);
	LIBZHL_API int GetNextDangerMove();
	LIBZHL_API void Open();
	LIBZHL_API void Close();
	LIBZHL_API void SetOpen(bool unk0);
	LIBZHL_API void InitMapTitle();
	LIBZHL_API void InitNoFuelText();
	LIBZHL_API void InitBossMessageBox();
	LIBZHL_API void OnLanguageChange();
	LIBZHL_API int GetRandomSectorChoice();
	LIBZHL_API void NeighboringSector(int unk0);
	LIBZHL_API void GetSelectedSector(int unk0, int unk1, int unk2);
	LIBZHL_API void StartSecretSector();
	LIBZHL_API void ReachSector(Sector *unk0);
	LIBZHL_API void UpdateSectorMap(Sector *unk0);
	LIBZHL_API void SaveGame(int file);
	LIBZHL_API void InitStatistics();
	LIBZHL_API void PrintStatistics();
	LIBZHL_API void AnalyzeMap();
	LIBZHL_API void ModifyPursuit(int unk0);
	LIBZHL_API void AtBeacon();
	LIBZHL_API void GetWaitLocation();
	LIBZHL_API void StartBeacon();
	LIBZHL_API void LocationsConnected(Location *unk0, Location *unk1);
	LIBZHL_API void PointToGrid(float unk0, float unk1);
	LIBZHL_API void TravelToLocation(Location *unk0);
	LIBZHL_API void ForceExitBeacon();
	LIBZHL_API void OnRenderFogEffect();
	LIBZHL_API void LocationHasBoss(Location *unk0);
	LIBZHL_API void LocationHasStore(Location *unk0);
	LIBZHL_API void LocationHasShip(Location *unk0);
	LIBZHL_API void AdvanceWorldLevel();
	LIBZHL_API void ReverseBossPath();
	LIBZHL_API void ForceBossJump();
	LIBZHL_API void ClearBoss();
	LIBZHL_API void SetBossStage(int stage);
	LIBZHL_API void CheckGameOver();
	LIBZHL_API void RenderLabels();
	LIBZHL_API void DeleteMap();
	LIBZHL_API void MouseClick(int unk0, int unk1);
	LIBZHL_API void AddSectorColumn();
	LIBZHL_API void PushSectorColumn();
	LIBZHL_API void SelectNewSector(int unk0);
	LIBZHL_API void GenerateSectorMap();
	LIBZHL_API void constructor();
	LIBZHL_API void RenderSectorName(Sector *unk0, GL_Color unk1);
	LIBZHL_API void UpdateDangerZone();
	LIBZHL_API void GetNewLocation();
	LIBZHL_API void OnLoop();
	LIBZHL_API void UpdateBoss();
	LIBZHL_API void GenerateEvents(bool tutorial);
	LIBZHL_API void AddConnections(Location *unk0);
	LIBZHL_API void MapConnected();
	LIBZHL_API void ConnectLocations(Point unk0, Point unk1);
	LIBZHL_API void PopulateGrid(Point unk0);
	LIBZHL_API Location *PopClosestLoc(std::vector<Location*> &vec, std::map<Location*, int> &map);
	LIBZHL_API static void __stdcall Dijkstra0(std::vector<Location*> &ref, StarMap *starMap, Location *start, Location *finish, bool include_unknown);
	LIBZHL_API bool AddQuest(const std::string &questEvent, bool force);
	LIBZHL_API Location *GenerateMap(bool tutorial, bool seed);
	LIBZHL_API Location *NewGame(bool unk0);
	LIBZHL_API static void __stdcall Dijkstra1(std::vector<Location*> &ref, StarMap *starMap, Location *start, Location *finish, bool include_unknown);
	LIBZHL_API void MouseMove(int x, int y);
	LIBZHL_API void OnTouch(TouchAction unk0, int unk1, int unk2, int unk3, int unk4, int unk5);
	LIBZHL_API Location *LoadGame(int fileHelper);
	LIBZHL_API void RenderLeftInsetButton(float unk0, float unk1, bool unk2);
	LIBZHL_API void RenderDistressButtons();
	LIBZHL_API void OnRender();
	LIBZHL_API void DrawConnection(const Pointf &pos1, const Pointf &pos2, const GL_Color *color);
	LIBZHL_API void TurnIntoFleetLocation(Location *loc);
	LIBZHL_API static std::string &__stdcall GetLocationText(std::string &strRef, StarMap *starMap, const Location *loc);
	LIBZHL_API void SetupNoFuel(int seed, const std::string &forceEscape);
	LIBZHL_API void GenerateNebulas(const std::vector<std::string> &names);
	
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

struct GL_Color;

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

struct SpaceManager
{
	ImageDesc* SwitchBackground(const std::string& name)
	{
		ImageDesc* ret = new ImageDesc;
		SwitchBackground(ret, this, name);
		
		return ret;
	}

	struct FleetShip
	{
		GL_Texture *image;
		Point location;
	};
	
	LIBZHL_API void constructor();
	LIBZHL_API int GetScreenShake();
	LIBZHL_API void SaveSpace(void *fileHelper);
	LIBZHL_API void SwitchBeacon();
	LIBZHL_API ImageDesc *SwitchPlanet(const std::string &name);
	LIBZHL_API void UpdatePlanetImage();
	LIBZHL_API void SwitchImages(ImageDesc planet, ImageDesc unk1, ImageDesc unk2);
	LIBZHL_API static void __stdcall SwitchBackground(ImageDesc *ret, SpaceManager *space, const std::string &name);
	LIBZHL_API void StartAsteroids(int shieldCount, bool unk);
	LIBZHL_API void SetPlanetaryDefense(char state, int target);
	LIBZHL_API void SetPulsarLevel(bool pulsarLevel);
	LIBZHL_API bool DangerousEnvironment();
	LIBZHL_API void MouseMove(int x, int y, int unk);
	LIBZHL_API SpaceDrone *GetSelectedDrone(int x, int y, int unk);
	LIBZHL_API float GetFlashOpacity();
	LIBZHL_API GL_Color *GetColorTint();
	LIBZHL_API void OnRenderBackground();
	LIBZHL_API void OnRenderFleet();
	LIBZHL_API void OnRenderForeground();
	LIBZHL_API void SetDangerZone(int fleetType);
	LIBZHL_API void OnRenderAsteroids(int fieldLayers, float unk2);
	LIBZHL_API void OnRenderProjectiles(int unk1, int unk2);
	LIBZHL_API void OnInit();
	LIBZHL_API void Restart();
	LIBZHL_API void ClearEnvironment();
	LIBZHL_API void Clear();
	LIBZHL_API void ClearProjectiles();
	LIBZHL_API void UpdateProjectile(Projectile *proj);
	LIBZHL_API void TransferProjectile(Projectile *proj);
	LIBZHL_API void AddShip(ShipManager *ship);
	LIBZHL_API void AddProjectile(Projectile *proj);
	LIBZHL_API void LoadSpace(int fileHelper);
	LIBZHL_API void UpdatePDS();
	LIBZHL_API void OnLoopNebulas();
	LIBZHL_API void OnLoop();
	LIBZHL_API void SetNebula(bool state);
	LIBZHL_API void SetStorm(bool state);
	LIBZHL_API void SetFireLevel(bool state);
	
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

struct WorldManager
{
	LIBZHL_API void constructor();
	LIBZHL_API int OnInit();
	LIBZHL_API CompleteShip *__stdcall CreateShip(ShipEvent *shipEvent, bool boss);
	LIBZHL_API void CreateLocation(Location *loc);
	LIBZHL_API void SaveGame();
	LIBZHL_API void CreateChoiceBox(LocationEvent *event);
	LIBZHL_API void UpdateLocation(LocationEvent *event);
	LIBZHL_API LocationEvent *ModifyResources(LocationEvent *event);
	LIBZHL_API void ModifyEnvironment(int envFlag, int envTarget);
	LIBZHL_API void CheckStatusEffects(std::vector<StatusEffect> &vec);
	LIBZHL_API void StartGame(ShipManager *ship);
	LIBZHL_API void Restart();
	LIBZHL_API void LoadGame(const std::string &fileName);
	LIBZHL_API void OnLoop();
	LIBZHL_API void CreateNewGame();
	LIBZHL_API bool HostileEnvironment();
	
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

struct PowerManager
{
};

struct DoorBox
{
};

struct InputEventUnion
{
	char eventData[20];
};

struct MemoryInputEvent
{
	int64_t used_bytes;
	int64_t free_bytes;
};

struct GL_TexVertex
{
	float x;
	float y;
	float u;
	float v;
};

struct HackingDrone;

struct HackingDrone : SpaceDrone
{
	LIBZHL_API void OnLoop();
	
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

struct ShipGenerator
{
	LIBZHL_API static ShipManager *__stdcall CreateShip(const std::string &name, int sector, ShipEvent &event);
	
};

struct CloneBox
{
};

struct CrystalAnimation
{
};

struct SlugAnimation
{
};

struct EngiAnimation
{
};

struct ToggleButton
{
};

struct WeaponStoreBox
{
};

struct DroneStoreBox
{
};

struct HackingSystem : ShipSystem
{
	LIBZHL_API void BlowHackingDrone();
	LIBZHL_API void OnLoop();
	
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

struct SlugAlien
{
};

struct EngiAlien
{
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

struct Missile
{
};

struct Ghost
{
};

struct Asteroid
{
};

struct RepairAnimation
{
};

struct EnergyAnimation
{
};

struct CombatDrone;

struct CombatDrone : SpaceDrone
{
	CombatDrone(int shipId, int self, const DroneBlueprint* bp)
	{
		this->constructor(shipId, self, bp);
	}

	LIBZHL_API void constructor(int iShipId, int selfId, const DroneBlueprint *bp);
	LIBZHL_API void SetWeaponTarget(Targetable *target);
	
	Pointf lastDestination;
	float progressToDestination;
	float heading;
	float oldHeading;
	CachedImage drone_image_off;
	CachedImage drone_image_charging;
	CachedImage drone_image_on;
	CachedImage engine_image;
};

struct SystemStoreBox;

struct SystemStoreBox : StoreBox
{
	LIBZHL_API void SetExtraData(int droneChoice);
	LIBZHL_API void constructor(ShipManager *shopper, Equipment *equip, int sys);
	
	SystemBlueprint *blueprint;
	int type;
	bool bConfirming;
	std::string confirmString;
	std::string freeBlueprint;
	int droneChoice;
};

struct CloakingBox
{
};

struct CrystalAlien : CrewMember
{
	std::pair<float, float> powerCooldown;
};

struct BattleDrone : CrewDrone
{
};

struct OxygenSystem : ShipSystem
{
	LIBZHL_API void UpdateBreach(int roomId, int hasBreach, bool unk3);
	LIBZHL_API void UpdateAirlock(int roomId, int unk);
	LIBZHL_API void EmptyOxygen(int roomId);
	LIBZHL_API void ModifyRoomOxygen(int roomId, float value);
	LIBZHL_API void ComputeAirLoss(int roomId, float value, bool unk);
	LIBZHL_API float GetRefillSpeed();
	LIBZHL_API void constructor(int numRooms, int roomId, int shipId, int startingPower);
	
	float max_oxygen;
	std::vector<float> oxygenLevels;
	float fTotalOxygen;
	bool bLeakingO2;
};

struct Algae
{
};

struct EventSystem;

struct EventSystem
{
	LIBZHL_API void AddEvent(int id);
	
};

struct PackageModuleInfo
{
};

struct CSurface
{
	/*
	static void GL_ApplyShader(int pipeline)
	{
		shader_pipeline_apply(pipeline);
	}
	
	static void GL_DestroyShader(int pipeline)
	{
		shader_pipeline_destroy(pipeline);
	}
	
	static int GL_CreateShaderPipeline(int vertex_shader, int fragment_shader)
	{
		return shader_pipeline_create(vertex_shader, fragment_shader);
	}
	
	static int GL_CreateShader(ShaderType type, const char* source)
	{
		return shader_create_from_source(type, source, -1);
	}
	*/
	
	static GL_Color GetColorTint()
	{
		GL_Color* color = new GL_Color();
		
		GetColorTint(color);
		
		return *color;
	}
	

	LIBZHL_API static GL_Color &__stdcall GL_GetColor();
	LIBZHL_API static void __stdcall GL_SetColorTint(GL_Color color);
	LIBZHL_API static void __stdcall GL_SetColorTint(float r, float g, float b, float a);
	LIBZHL_API static void __stdcall GL_Rotate2(float angle, float x, float y, float z = 0.f);
	LIBZHL_API static bool __stdcall IsFrameBufferSupported();
	LIBZHL_API static void __stdcall StartFrame();
	LIBZHL_API static void __stdcall FinishFrame();
	LIBZHL_API static void __stdcall GL_ClearAll();
	LIBZHL_API static void __stdcall GL_ClearColor();
	LIBZHL_API static int __stdcall SetViewPort(int left, int bottom, int h, int w);
	LIBZHL_API static void __stdcall GL_PopScissor();
	LIBZHL_API static void __stdcall GL_SetStencilMode(GL_StencilMode stencilMode, int ref, int mask);
	LIBZHL_API static void __stdcall GL_PopStencilMode();
	LIBZHL_API static int __stdcall GL_OrthoProjection(float mx1, float mx2, float mx3, float mx4, float mx5, float mx6);
	LIBZHL_API static int __stdcall GL_LoadIdentity();
	LIBZHL_API static int __stdcall GL_PushMatrix();
	LIBZHL_API static int __stdcall GL_PopMatrix();
	LIBZHL_API static void __stdcall GL_Rotate(float angle, float x, float y, float z = 0.f);
	LIBZHL_API static void __stdcall GL_Scale(float x, float y, float z);
	LIBZHL_API static bool __stdcall GL_Translate(float x, float y, float z = 0.f);
	LIBZHL_API static int __stdcall GL_SetColor(GL_Color color);
	LIBZHL_API static int __stdcall GL_SetColor(float r, float g, float b, float a);
	LIBZHL_API static void __stdcall GL_RemoveColorTint();
	LIBZHL_API static GL_Color &__stdcall GetColorTint(GL_Color *ref);
	LIBZHL_API static bool __stdcall GL_EnableBlend();
	LIBZHL_API static bool __stdcall GL_DisableBlend();
	LIBZHL_API static bool __stdcall GL_ForceAntialias();
	LIBZHL_API static bool __stdcall GL_DrawLine(float x1, float y1, float x2, float y2, float lineWidth, GL_Color color);
	LIBZHL_API static bool __stdcall GL_DrawTriangle(Point vertex1, Point vertex2, Point vertex3, GL_Color color);
	LIBZHL_API static bool __stdcall GL_DrawRect(float x1, float y1, float x2, float y2, GL_Color color);
	LIBZHL_API static bool __stdcall GL_DrawRectOutline(int x1, int y1, int x2, int y2, GL_Color color, float lineWidth);
	LIBZHL_API static bool __stdcall GL_BlitImage(GL_Texture *tex, float x, float y, float x2, float y2, float rotation, GL_Color color, bool mirror);
	LIBZHL_API static bool __stdcall GL_BlitPixelImage(GL_Texture *tex, float x, float y, float x2, float y2, float rotation, GL_Color color, bool mirror);
	LIBZHL_API static bool __stdcall GL_BlitImagePartial(GL_Texture *tex, float x, float y, float size_x, float size_y, float start_x, float end_x, float start_y, float end_y, float alpha, GL_Color color, bool mirror);
	LIBZHL_API static bool __stdcall GL_BlitPixelImageWide(GL_Texture *tex, float x, float y, int x2, int y2, float opacity, GL_Color color, bool mirror);
	LIBZHL_API static void __stdcall GL_RenderPrimitive(GL_Primitive *primitive);
	LIBZHL_API static void __stdcall GL_RenderPrimitiveWithAlpha(GL_Primitive *primitive, float alpha);
	LIBZHL_API static void __stdcall GL_RenderPrimitiveWithColor(GL_Primitive *primitive, GL_Color color);
	LIBZHL_API static void __stdcall GL_DestroyPrimitive(GL_Primitive *primitive);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateRectPrimitive(float x, float y, float w, float h, GL_Color color);
	LIBZHL_API static void __stdcall AddTexVertices(std::vector<GL_TexVertex> *vec, float x1, float y1, float u1, float v1, float x2, float y2, float u2, float v2);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateMultiImagePrimitive(GL_Texture *tex, std::vector<GL_TexVertex> *vec, GL_Color color);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateImagePrimitive(GL_Texture *tex, float x, float y, float size_x, float size_y, float rotate, GL_Color color);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateMultiLinePrimitive(std::vector<GL_Line> &vec, GL_Color color, float thickness);
	
};

struct EventsParser;
struct ResourcesTemplate;
struct EventTemplate;
struct RandomAmount;
struct ShipTemplate;

struct EventsParser
{
	static bool ParseBoolean(const std::string& str)
	{
		return str == "true" || str == "TRUE" || str == "True";
	}

	LIBZHL_API RandomAmount *PullMinMax(rapidxml::xml_node<char> *node, const std::string &name);
	LIBZHL_API void **ProcessEvent(rapidxml::xml_node<char> *node, const std::string &event, EventTemplate &eventref);
	LIBZHL_API static ShipTemplate *__stdcall ProcessShipEvent(ShipTemplate *event, EventsParser *parser, rapidxml::xml_node<char> *node);
	LIBZHL_API ResourcesTemplate *ProcessModifyItem(ResourcesTemplate &resources, rapidxml::xml_node<char> *node, const std::string &unk);
	LIBZHL_API void AddAllEvents();
	LIBZHL_API void AddEvents(EventGenerator &generator, char *file, const std::string &fileName);
	
	std::unordered_map<std::string, EventTemplate*> eventTemplates;
	std::vector<EventTemplate*> trashList;
	std::unordered_map<std::string, ShipEvent> shipTemplates;
};

struct Shields
{
	LIBZHL_API void *CollisionReal(float x, float y, Damage damage, bool unk);
	
};

struct Settings
{
	LIBZHL_API static char __stdcall GetCommandConsole();
	LIBZHL_API static bool __stdcall GetDlcEnabled();
	LIBZHL_API static std::string &__stdcall GetHotkeyName(std::string &strRef, const std::string &name);
	LIBZHL_API static SDLKey __stdcall GetHotkey(const std::string &hotkeyName);
	
};

struct DamageMessage
{

	enum MessageType
	{
	  MISS = 0x0,
	  RESIST = 0x1,
	};

	DamageMessage(float length, Pointf pos, MessageType type)
	{
		constructor(length, pos, type);
	}

	LIBZHL_API void constructor(float length, Pointf pos, DamageMessage::MessageType type);
	
	AnimationTracker tracker;
	Pointf position;
	GL_Color color;
	bool bFloatDown;
	std::vector<GL_Primitive*> primitives;
};

struct freetype
{
	//struct font_data;
	
	//static Pointf easy_measurePrintLines(int fontType, float x, float y, int width, const std::string& text);
	//static Pointf measurePrintLines(font_data &fontData, const std::string& str);

	struct font_data
	{
		float h;
		int font;
		float fontsize;
		float baseline;
		float lineHeight;
	};
	
	LIBZHL_API static double __stdcall easy_measurePrintLines(int fontData, float x, float y, int width, const std::string &text);
	LIBZHL_API static int __stdcall easy_print(int fontData, float x, float y, const std::string &text);
	LIBZHL_API static int __stdcall easy_printRightAlign(int fontData, float x, float y, const std::string &text);
	LIBZHL_API static int __stdcall easy_printNewlinesCentered(int fontData, float x, float y, int width, const std::string &text);
	LIBZHL_API static int __stdcall easy_printAutoNewlines(int fontData, float x, float y, int width, const std::string &text);
	LIBZHL_API static double __stdcall easy_printCenter(int fontData, float x, float y, const std::string &text);
	LIBZHL_API static int __stdcall easy_printAutoShrink(int fontData, float x, float y, int width, char unk, const std::string &text);
	
};

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

struct TouchTooltip
{
};

struct MindBox
{
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

struct MouseControl;

struct MouseControl
{
	LIBZHL_API std::string &SetTooltip(const std::string &tooltip);
	LIBZHL_API Point MeasureTooltip(int unk);
	LIBZHL_API void QueueStaticTooltip(Point pos);
	LIBZHL_API void OnLoop();
	LIBZHL_API void InstantTooltip();
	
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

struct WeaponSystemBox
{
};

struct InputEvent
{
	InputEventType type;
	InputEventDetail detail;
	double timestamp;
	InputEventUnion event;
};

struct MantisAnimation;

struct MantisAnimation : CrewAnimation
{


	LIBZHL_API static void __stdcall __DO_NOT_HOOK();
	LIBZHL_API static std::string &__stdcall GetShootingSound(std::string &strRef, MantisAnimation *anim);
	LIBZHL_API static void __stdcall __DO_NOT_HOOK2();
	LIBZHL_API static std::string &__stdcall GetDeathSound(std::string &strRef, MantisAnimation *anim);
	LIBZHL_API bool FireShot();
	
};

struct RepairStoreBox
{
};

struct EngineSystem
{
};

struct EnergyAlien;

struct LIBZHL_INTERFACE EnergyAlien
{
	virtual ~EnergyAlien() {}
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
	virtual void Jump() LIBZHL_PLACEHOLDER
	virtual bool NeedsIntruderSlot() LIBZHL_PLACEHOLDER
	virtual void SaveState(int fileHelper) LIBZHL_PLACEHOLDER
	virtual void LoadState(int fileHelper) LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void OnLoop();
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
	virtual std::string *GetUniqueRepairing() LIBZHL_PLACEHOLDER
	virtual bool ProvidesVision() LIBZHL_PLACEHOLDER
	virtual float GetMoveSpeedMultiplier() LIBZHL_PLACEHOLDER
	virtual float GetRepairSpeed() LIBZHL_PLACEHOLDER
	virtual float GetDamageMultiplier() LIBZHL_PLACEHOLDER
	virtual bool ProvidesPower() LIBZHL_PLACEHOLDER
	virtual std::string *GetSpecies(std::string &str) LIBZHL_PLACEHOLDER
	virtual float GetFireRepairMultiplier() LIBZHL_PLACEHOLDER
	virtual bool IsTelepathic() LIBZHL_PLACEHOLDER
	virtual std::pair<float, float> GetPowerCooldown() LIBZHL_PLACEHOLDER
	virtual bool PowerReady() LIBZHL_PLACEHOLDER
	virtual void ActivatePower() LIBZHL_PLACEHOLDER
	virtual bool HasSpecialPower() LIBZHL_PLACEHOLDER
	virtual void ResetPower() LIBZHL_PLACEHOLDER
	virtual float GetSuffocationMultiplier() LIBZHL_PLACEHOLDER
	virtual int BlockRoom() LIBZHL_PLACEHOLDER
	virtual Damage *GetRoomDamage(CrewMember *crew) LIBZHL_PLACEHOLDER
	virtual bool IsAnaerobic() LIBZHL_PLACEHOLDER
	virtual void UpdateRepair() LIBZHL_PLACEHOLDER
	virtual bool CanStim() LIBZHL_PLACEHOLDER
	LIBZHL_API static Damage *__stdcall GetRoomDamage(Damage *dmg, EnergyAlien *crew);
	
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
	unsigned __int8 gap_ex_1[2];
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
	unsigned __int8 gap_ex_2[2];
	Slot savedPosition;
	float fStunTime;
	CachedImage movementTarget;
	bool bCloned;
	bool bTriggerExplosion;
	bool bExploded;
};

struct AnaerobicAlien
{
};

struct Moddable
{
};

struct SuperShieldDrone
{
};

struct CloakingSystem : ShipSystem
{
	bool bTurnedOn;
	TimerHelper timer;
	std::string soundeffect;
	AnimationTracker glowTracker;
	GL_Primitive *glowImage;
};

struct ShipInfo;

struct ShipInfo
{
	LIBZHL_API char AddAugmentation(const std::string &augment);
	LIBZHL_API bool HasAugmentation(const std::string &augment);
	LIBZHL_API float GetAugmentationValue(const std::string &augment);
	
	std::map<std::string, int> augList;
	std::map<std::string, int> equipList;
	int augCount;
};

struct GL_FrameBuffer;

struct CApp;

struct CApp : CEvent
{
	LIBZHL_API int OnInputFocus();
	LIBZHL_API int OnInputBlur();
	LIBZHL_API int OnExit();
	LIBZHL_API void OnMButtonDown(int x, int y);
	LIBZHL_API void OnTextEvent(CEvent::TextEvent textEvent);
	LIBZHL_API void OnTextInput(int unk);
	LIBZHL_API int OnRequestExit();
	LIBZHL_API int OnMouseMove(int x, int y, int xdiff, int ydiff, bool holdingLMB, bool holdingRMB, bool holdingMMB);
	LIBZHL_API void OnRButtonUp(int x, int y);
	LIBZHL_API void OnLButtonUp(int x, int y);
	LIBZHL_API void OnRButtonDown(int x, int y);
	LIBZHL_API void OnLButtonDown(int x, int y);
	LIBZHL_API void OnLanguageChange();
	LIBZHL_API void OnKeyUp(SDLKey key);
	LIBZHL_API void OnKeyDown(SDLKey key);
	LIBZHL_API void constructor();
	LIBZHL_API void ParseArgs(int unk, const char **args);
	LIBZHL_API void OnLoop();
	LIBZHL_API int SetupWindow();
	LIBZHL_API void OnCleanup();
	LIBZHL_API void GenInputEvents();
	LIBZHL_API void OnSuspend();
	LIBZHL_API void OnResume();
	LIBZHL_API Pointf TranslateMouse(int x, int y);
	LIBZHL_API void UpdateFullScreen();
	LIBZHL_API int UpdateWindowSettings();
	LIBZHL_API void OnRender();
	LIBZHL_API int OnInit();
	LIBZHL_API int OnExecute();
	LIBZHL_API void OnEvent(const InputEvent *inputEvent);
	
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
	char lastLanguage[24];
	char inputFocus;
	char useDirect3D;
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

struct ResourceControl;

struct PackageModuleInfo;
struct ResourceManager;

struct ResourceControl
{
	enum ImageSwappingMode
	{
	  SWAP_NONE = 0x0,
	  SWAP_SHIP_SETS = 0x1,
	  SWAP_DYNAMIC_SHIPS = 0x2,
	};

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
	
	LIBZHL_API void constructor();
	LIBZHL_API GL_Primitive *CreateImagePrimitive(GL_Texture *tex, int unk1, int unk2, int unk3, GL_Color color, float alpha, bool mirror);
	LIBZHL_API void OnInit(int imageSwappingMode);
	LIBZHL_API char *LoadFile(const std::string &fileName);
	LIBZHL_API GL_Texture *GetImageId(const std::string &dir);
	LIBZHL_API int RenderImage(GL_Texture *tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror);
	LIBZHL_API int RenderImageString(std::string &tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror);
	LIBZHL_API GL_Primitive *CreateImagePrimitiveString(const std::string &tex, int x, int y, int rotation, GL_Color color, float alpha, bool mirror);
	LIBZHL_API freetype::font_data &GetFontData(int fontType, bool unk);
	
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

struct CFPS;

struct CFPS
{
	LIBZHL_API float GetSpeedFactor();
	LIBZHL_API void OnLoop();
	
	float RunningTime;
	char _unk[4];
	double OldTime;
	double LastTime;
	float SpeedFactor;
	int NumFrames;
	int Frames;
	int speedLevel;
};

struct ShipRepairDrone
{
};

struct Door : CrewTarget
{
public:
	Point GetCenterPoint()
	{
		Point ret = Point(this->x, this->y);
		return ret;
	}
	Point GetEntryWay(int room)
	{
		Point pos1 = Point(this->x, this->y);
		Point pos2;

		if (this->bVertical)
		{
			pos2 = Point(pos1.x + 17, pos1.y);
			pos1 = Point(this->x - 17, pos1.y);
		}
		else
		{
			pos2 = Point(this->x, pos1.y + 17);
			pos1 = Point(this->x, this->y - 18);
		}

		auto shipInfo = ShipGraph::GetShipInfo(this->iShipId);

		if (room == shipInfo->GetSelectedRoom(pos2.x, pos2.y, false))
		{
			return pos2;
		}
		else
		{
			return pos1;
		}
	}

	LIBZHL_API void FakeClose();
	LIBZHL_API bool IsSealed(int shipId);
	LIBZHL_API void FakeOpen();
	
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

struct CrewStoreBox;

struct CrewStoreBox : StoreBox
{
	LIBZHL_API void Purchase();
	
	std::string name;
	Animation crewPortrait;
	CrewBlueprint blueprint;
};

struct BatterySystem
{
};

struct CrewBox
{
	CrewBox(Point pos_, CrewMember *crew_, int number_)
	{
		this->constructor(pos_, crew_, number_);
	}

	LIBZHL_API void constructor(Point pos, CrewMember *crew, int number);
	LIBZHL_API void OnRender();
	LIBZHL_API CrewMember *GetSelected(int mouseX, int mouseY);
	LIBZHL_API void OnLoop(bool selected);
	LIBZHL_API void OnRenderSkillLevel();
	
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

struct OuterHull : Repairable
{
	Animation breach;
	Animation heal;
};

LIBZHL_API float __stdcall font_text_width(freetype::font_data &fontData, const char *str, float size);
LIBZHL_API int __stdcall random32();
LIBZHL_API void __stdcall srandom32(unsigned int seed);
LIBZHL_API float __stdcall getSkillBonus(int skill, int level);



