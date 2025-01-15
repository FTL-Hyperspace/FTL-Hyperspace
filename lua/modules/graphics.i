/*** @module Graphics
*/
%module Graphics
%include "stl.i"

%{
#include "Global.h"
%}

void DrawTextWithGlow(const std::string& text, Point p, bool centered, GL_Color color, float alpha);

/*** Constants
@section constants
*/
/***
@tparam GL_StencilMode STENCIL_IGNORE
*/
/***
@tparam GL_StencilMode STENCIL_SET
*/
/***
@tparam GL_StencilMode STENCIL_USE
*/
enum GL_StencilMode
{
  STENCIL_IGNORE = 0x0,
  STENCIL_SET = 0x1,
  STENCIL_USE = 0x2,
};
/***
@section end
*/

/***
@type GL_Primitive
*/
struct GL_Primitive
{
    /*** Default Constructor
    @function GL_Primitive
    */

    /***
    @tfield int type
    */
	int type;
    /***
    @tfield float lineWidth
    */
	float lineWidth;
    /***
    @tfield bool hasTexture
    */
	bool hasTexture;
    /***
    @tfield GL_Texture* texture
    */
	GL_Texture *texture;
    /***
    @tfield bool textureAntialias
    */
	bool textureAntialias;
    /***
    @tfield bool hasColor
    */
	bool hasColor;
    /***
    @tfield GL_Color color
    */
	GL_Color color;
    /***
    @tfield int id
    */
	int id;
};

/***
@type GL_Texture
*/
%rename("%(regex:/^GL_Texture::(.*)_$/\\1/)s", regextarget=1, fullname=1) "GL_Texture::.*";
struct GL_Texture
{
    /*** Default Constructor
    @function GL_Texture
    */

    /***
    @tfield int id
    */
	int id_;
    /***
    @tfield int width
    */
	int width_;
    /***
    @tfield int height
    */
	int height_;
    /***
    @tfield bool isLogical
    */
	bool isLogical_;
    /***
    @tfield float u_base
    */
	float u_base_;
    /***
    @tfield float v_base
    */
	float v_base_;
    /***
    @tfield float u_size
    */
	float u_size_;
    /***
    @tfield float v_size
    */
	float v_size_;
};

%contract GL_Color::GL_Color(float rr, float gg, float bb, float aa) {
    require:
        rr >= 0.0;
        rr <= 1.0;
        gg >= 0.0;
        gg <= 1.0;
        bb >= 0.0;
        bb <= 1.0;
        aa >= 0.0;
        aa <= 1.0;
}
%contract GL_Color::FromHSV(float fH, float fS, float fV, float fA) {
    require:
        fH >= 0.0;
        fH <= 1.0;
        fS >= 0.0;
        fS <= 1.0;
        fV >= 0.0;
        fV <= 1.0;
        fA >= 0.0;
        fA <= 1.0;
}
/***
@type GL_Color
*/
struct GL_Color
{
    /***
    @function GL_Color
    @tparam float r Red value from 0 to 1
    @tparam float g Green value from 0 to 1
    @tparam float b Blue value from 0 to 1
    @tparam float a Alpha (opacity) value from 0 to 1
    */
    GL_Color(float rr, float gg, float bb, float aa) : r(rr), g(gg), b(bb), a(aa)
    {
    }

    /***
    @function FromHSV
    @treturn GL_Color
    @tparam float h Hue from 0 to 1
    @tparam float s Saturation from 0 to 1
    @tparam float v Luminance Value from 0 to 1
    @tparam float a Alpha (opacity) from 0 to 1
    @within functions
    */
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

    /*** Default Constructor
    @function GL_Color
    */
    GL_Color() {}

    /*** Red
    @tfield float r
    */
    float r;
    /*** Green
    @tfield float g
    */
    float g;
    /*** Blue
    @tfield float b
    */
    float b;
    /*** Alpha
    @tfield float a
    */
    float a;
};

/***
@type GL_ColorTexVertex
*/
struct GL_ColorTexVertex
{
    /*** Default Constructor
    @function GL_ColorTexVertex
    */

    /*** Position X
    @tfield float x
    */
	float x;
    /*** Position Y
    @tfield float y
    */
	float y;
    /***
    @tfield float u
    */
	float u;
    /***
    @tfield float v
    */
	float v;
    /*** Red
    @tfield float r
    */
	float r;
    /*** Green
    @tfield float g
    */
	float g;
    /*** Blue
    @tfield float b
    */
	float b;
    /*** Alpha
    @tfield float a
    */
	float a;
};

/***
@type GL_Line
*/
%rename("c_end") GL_Line::end;
%nodefaultctor;
struct GL_Line
{
    /***
    @function GL_Line
    @tparam float x1
    @tparam float y1
    @tparam float x2
    @tparam float y2
    */
	GL_Line(float x1, float y1, float x2, float y2)
	{
        start = Pointf(x1, y1);
        end = Pointf(x2, y2);
	}

    /***
    @function GL_Line
    @tparam Pointf start Starting point
    @tparam Pointf end Ending point
    */
    GL_Line(Pointf _start, Pointf _end) : start(_start), end(_end)
	{
	}

    %immutable;
    /***
    @tfield Pointf start
    */
    Pointf start;
    /***
    @tfield Pointf c_end
    */
    Pointf end;
    %mutable;
};
%clearnodefaultctor;

/***
@type GL_TexVertex
*/
struct GL_TexVertex
{
    /*** Default Constructor
    @function GL_TexVertex
    */

    /***
    @tfield float x
    */
	float x;
    /***
    @tfield float y
    */
	float y;
    /***
    @tfield float u
    */
	float u;
    /***
    @tfield float v
    */
	float v;
};

/***
@type CSurface
*/
%newobject CSurface::GL_CreateImagePrimitive;
%newobject CSurface::GL_CreateMultiImagePrimitive;
%newobject CSurface::GL_CreateMultiLinePrimitive;
%newobject CSurface::GL_CreateMultiRectPrimitive;
%newobject CSurface::GL_CreatePixelImagePrimitive;
%newobject CSurface::GL_CreateRectOutlinePrimitive;
%newobject CSurface::GL_CreateRectPrimitive;
%delobject CSurface::GL_DestroyPrimitive;
%extend GL_Primitive
{
    ~GL_Primitive() {
        CSurface::GL_DestroyPrimitive($self);
    }
};
%nodefaultctor;
%nodefaultdtor;
%immutable;
struct CSurface
{
    /***
    @function CSurface_AddTexVertices
    @tparam std_vector__GL_TextVertex* vector
    @tparam float x1
    @tparam float y1
    @tparam float u1
    @tparam float v1
    @tparam float x2
    @tparam float y2
    @tparam float u2
    @tparam float v2
    @within functions
    */
    static void AddTexVertices(std::vector<GL_TexVertex> *vec, float x1, float y1, float u1, float v1, float x2, float y2, float u2, float v2);
    /***
    @function CSurface_GL_BlitImage
    @tparam GL_Texture* texture
    @tparam float x
    @tparam float y
    @tparam float x2
    @tparam float y2
    @tparam float rotation
    @tparam GL_Color color
    @tparam bool mirror
    @treturn bool
    @within functions
    */
    static bool GL_BlitImage(GL_Texture *tex, float x, float y, float x2, float y2, float rotation, GL_Color color, bool mirror);
    /***
    @function CSurface_GL_BlitImagePartial
    @tparam GL_Texture* texture
    @tparam float x
    @tparam float y
    @tparam float size_x
    @tparam float size_y
    @tparam float start_x
    @tparam float end_x
    @tparam float start_y
    @tparam float end_y
    @tparam float alpha
    @tparam GL_Color color
    @tparam bool mirror
    @treturn bool
    @within functions
    */
    static bool GL_BlitImagePartial(GL_Texture *tex, float x, float y, float size_x, float size_y, float start_x, float end_x, float start_y, float end_y, float alpha, GL_Color color, bool mirror);
    /***
    @function CSurface_GL_BlitMultiColorImage
    @tparam GL_Texture* texture
    @tparam std_vector__GL_ColorTexVertex* textureVerticies
    @tparam bool antialias
    @within functions
    */
    static void GL_BlitMultiColorImage(GL_Texture *tex, const std::vector<GL_ColorTexVertex> &texVertices, bool antialias);
    /***
    @function CSurface_GL_BlitMultiImage
    @tparam GL_Texture* texture
    @tparam std_vector__GL_ColorTexVertex* textureVerticies
    @tparam bool antialias
    @within functions
    */
    static void GL_BlitMultiImage(GL_Texture *tex, const std::vector<GL_TexVertex> &texVertices, bool antialias);
    /***
    @function CSurface_GL_BlitPixelImage
    @tparam GL_Texture* texture
    @tparam float x
    @tparam float y
    @tparam float x2
    @tparam float y2
    @tparam float rotation
    @tparam GL_Color color
    @tparam bool mirror
    @treturn bool
    @within functions
    */
    static bool GL_BlitPixelImage(GL_Texture *tex, float x, float y, float x2, float y2, float rotation, GL_Color color, bool mirror);
    /***
    @function CSurface_GL_BlitPixelImageWide
    @tparam GL_Texture* texture
    @tparam float x
    @tparam float y
    @tparam float x2
    @tparam float y2
    @tparam float opacity
    @tparam GL_Color color
    @tparam bool mirror
    @treturn bool
    @within functions
    */
    static bool GL_BlitPixelImageWide(GL_Texture *tex, float x, float y, int x2, int y2, float opacity, GL_Color color, bool mirror);
    /***
    @function CSurface_GL_ClearAll
    @within functions
    */
    static void GL_ClearAll();
    /***
    @function CSurface_GL_ClearColor
    @within functions
    */
    static void GL_ClearColor();
    /***
    @function CSurface_GL_CreateImagePrimitive
    @tparam GL_Texture* texture
    @tparam float x
    @tparam float y
    @tparam float size_x
    @tparam float size_y
    @tparam float rotate
    @tparam GL_Color color
    @treturn GL_Primitive*
    @within functions
    */
    static GL_Primitive* GL_CreateImagePrimitive(GL_Texture *tex, float x, float y, float size_x, float size_y, float rotate, GL_Color color);
    /***
    @function CSurface_GL_CreateMultiImagePrimitive
    @tparam GL_Texture* texture
    @tparam std_vector__GL_TexVertex* vector
    @tparam GL_Color color
    @treturn GL_Primitive*
    @within functions
    */
    static GL_Primitive* GL_CreateMultiImagePrimitive(GL_Texture *tex, std::vector<GL_TexVertex> *vec, GL_Color color);
    /***
    @function CSurface_GL_CreateMultiLinePrimitive
    @tparam std_vector__GL_Line* vector
    @tparam GL_Color color
    @tparam float thickness
    @treturn GL_Primitive*
    @within functions
    */
    static GL_Primitive* GL_CreateMultiLinePrimitive(std::vector<GL_Line> &vec, GL_Color color, float thickness);
    /***
    @function CSurface_GL_CreateMultiRectPrimitive
    @tparam std_vector__Globals_Rect* vector
    @tparam GL_Color color
    @treturn GL_Primitive*
    @within functions
    */
    static GL_Primitive* GL_CreateMultiRectPrimitive(std::vector<Globals::Rect> &vec, GL_Color color);
    /***
    @function CSurface_GL_CreatePixelImagePrimitive
    @tparam GL_Texture* texture
    @tparam float x
    @tparam float y
    @tparam float size_x
    @tparam float size_y
    @tparam float rotate
    @tparam GL_Color color
    @tparam bool unknown
    @treturn GL_Primitive*
    @within functions
    */
    static GL_Primitive* GL_CreatePixelImagePrimitive(GL_Texture *tex, float x, float y, float size_x, float size_y, float rotate, GL_Color color, bool unk);
    /***
    @function CSurface_GL_CreateRectOutlinePrimitive
    @tparam int x
    @tparam int y
    @tparam int w
    @tparam int h
    @tparam GL_Color color
    @tparam float lineWidth
    @treturn GL_Primitive*
    @within functions
    */
    static GL_Primitive* GL_CreateRectOutlinePrimitive(int x, int y, int w, int h, GL_Color color, float lineWidth);
    /***
    @function CSurface_GL_CreateRectPrimitive
    @tparam float x
    @tparam float y
    @tparam float w
    @tparam float h
    @tparam GL_Color color
    @treturn GL_Primitive*
    @within functions
    */
    static GL_Primitive* GL_CreateRectPrimitive(float x, float y, float w, float h, GL_Color color);
    /***
    @function CSurface_GL_DestroyPrimitive
    @tparam GL_Primitive* primitive
    @within functions
    */
    static void GL_DestroyPrimitive(GL_Primitive *primitive);
    /***
    @function CSurface_GL_DisableBlend
    @treturn bool
    @within functions
    */
    static bool GL_DisableBlend();
    /***
    @function CSurface_GL_DrawCircle
    @tparam float x
    @tparam float y
    @tparam float radius
    @tparam GL_Color color
    @treturn bool
    @within functions
    */
    static bool GL_DrawCircle(float x, float y, float radius, GL_Color color);
    /***
    @function CSurface_GL_DrawLine
    @tparam float x1
    @tparam float y1
    @tparam float x2
    @tparam float y2
    @tparam float lineWidth
    @tparam GL_Color color
    @treturn bool
    @within functions
    */
    static bool GL_DrawLine(float x1, float y1, float x2, float y2, float lineWidth, GL_Color color);
    /***
    @function CSurface_GL_DrawRect
    @tparam float x1
    @tparam float y1
    @tparam float x2
    @tparam float y2
    @tparam GL_Color color
    @treturn bool
    @within functions
    */
    static bool GL_DrawRect(float x1, float y1, float x2, float y2, GL_Color color);
    /***
    @function CSurface_GL_DrawRectOutline
    @tparam int x1
    @tparam int y1
    @tparam int x2
    @tparam int y2
    @tparam GL_Color color
    @tparam float lineWidth
    @treturn bool
    @within functions
    */
    static bool GL_DrawRectOutline(int x1, int y1, int x2, int y2, GL_Color color, float lineWidth);
    /***
    @function CSurface_GL_DrawShield
    @tparam int x
    @tparam int y
    @tparam float a1
    @tparam float b1
    @tparam int angle1
    @tparam int angle2
    @tparam GL_Color color
    @tparam float thickness
    @treturn bool
    @within functions
    */
    static bool GL_DrawShield(int x, int y, float a1, float b1, int angle1, int angle2, GL_Color color, float thickness);
    /***
    @function CSurface_GL_DrawLaser
    @tparam int x
    @tparam int y
    @tparam int w
    @tparam int h
    @tparam GL_Color color
    @treturn bool
    @within functions
    */
    static bool GL_DrawLaser(int x, int y, int w, int h, GL_Color color);
    /***
    @function CSurface_GL_DrawTriangle
    @tparam Point vertex1
    @tparam Point vertex2
    @tparam Point vertex3
    @tparam GL_Color color
    @treturn bool
    @within functions
    */
    static bool GL_DrawTriangle(Point vertex1, Point vertex2, Point vertex3, GL_Color color);
    /***
    @function CSurface_GL_EnableBlend
    @treturn bool
    @within functions
    */
    static bool GL_EnableBlend();
    /***
    @function CSurface_GL_GetColor
    @treturn GL_Color
    @within functions
    */
    static GL_Color GL_GetColor();
    /***
    @function CSurface_GL_LoadIdentity
    @treturn int
    @within functions
    */
    static int GL_LoadIdentity();
    /***
    @function CSurface_GL_OrthoProjection
    @tparam float mx1
    @tparam float mx2
    @tparam float mx3
    @tparam float mx4
    @tparam float mx5
    @tparam float mx6
    @treturn int
    @within functions
    */
    static int GL_OrthoProjection(float mx1, float mx2, float mx3, float mx4, float mx5, float mx6);
    /***
    @function CSurface_GL_PopMatrix
    @treturn int
    @within functions
    */
    static int GL_PopMatrix();
    /***
    @function CSurface_GL_PopScissor
    @within functions
    */
    static void GL_PopScissor();
    /***
    @function CSurface_GL_PopStencilMode
    @within functions
    */
    static void GL_PopStencilMode();
    /***
    @function CSurface_GL_PushMatrix
    @treturn int
    @within functions
    */
    static int GL_PushMatrix();
    /***
    @function CSurface_GL_PushStencilMode
    @within functions
    */
    static void GL_PushStencilMode();
    /***
    @function CSurface_GL_RemoveColorTint
    @within functions
    */
    static void GL_RemoveColorTint();
    /***
    @function CSurface_GL_RenderPrimitive
    @tparam GL_Primitive* primitive
    @within functions
    */
    static void GL_RenderPrimitive(GL_Primitive *primitive);
    /***
    @function CSurface_GL_RenderPrimitiveWithAlpha
    @tparam GL_Primitive* primitive
    @tparam float alpha
    @within functions
    */
    static void GL_RenderPrimitiveWithAlpha(GL_Primitive *primitive, float alpha);
    /***
    @function CSurface_GL_RenderPrimitiveWithColor
    @tparam GL_Primitive* primitive
    @tparam GL_Color color
    @within functions
    */
    static void GL_RenderPrimitiveWithColor(GL_Primitive *primitive, GL_Color color);
    /***
    @function CSurface_GL_Rotate
    @tparam float angle
    @tparam float x
    @tparam float y
    @tparam float z (optional, default 1.0)
    @within functions
    */
    static void GL_Rotate(float angle, float x, float y, float z = 1.f);
    /***
    @function CSurface_GL_Scale
    @tparam float x
    @tparam float y
    @tparam float z
    @within functions
    */
    static void GL_Scale(float x, float y, float z);
    /***
    @function CSurface_GL_SetColor
    @tparam GL_Color color
    @treturn int
    @within functions
    */
    static int GL_SetColor(GL_Color color);
    /***
    @function CSurface_GL_SetColorTint
    @tparam GL_Color color
    @within functions
    */
    static void GL_SetColorTint(GL_Color color);
    /***
    @function CSurface_GL_SetStencilMode
    @tparam GL_StencilMode stencilMode
    @tparam int ref
    @tparam int mask
    @within functions
    @see STENCIL_IGNORE, STENCIL_SET, STENCIL_USE
    */
    static void GL_SetStencilMode(GL_StencilMode stencilMode, int ref, int mask);
    /***
    @function CSurface_GL_Translate
    @tparam float x
    @tparam float y
    @tparam float z (optional, default 0.0)
    @treturn bool
    @within functions
    */
    static bool GL_Translate(float x, float y, float z = 0.f);
    /***
    @function CSurface_GetColorTint
    @treturn GL_Color current color tint
    @within functions
    */
    static GL_Color GetColorTint();
};
%clearnodefaultctor;
%clearnodefaultdtor;
%mutable;

%nodefaultctor freetype;
%nodefaultdtor freetype;
struct freetype
{
	static Pointf easy_measurePrintLines(int fontSize, float x, float y, int line_length, const std::string &text);
	static int easy_measureWidth(int fontSize, const std::string &text);
	static Pointf easy_print(int fontSize, float x, float y, const std::string &text);
	static Pointf easy_printAutoNewlines(int fontSize, float x, float y, int line_length, const std::string &text);
	static void easy_printAutoShrink(int fontId, float x, float y, int maxWidth, bool centered, const std::string &text);
	static Pointf easy_printCenter(int fontSize, float x, float y, const std::string &text);
	static Pointf easy_printNewlinesCentered(int fontSize, float x, float y, int line_length, const std::string &text);
	static Pointf easy_printRightAlign(int fontSize, float x, float y, const std::string &text);
};
