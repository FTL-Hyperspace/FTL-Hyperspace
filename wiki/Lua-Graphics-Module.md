Contains methods for rendering graphical objects to the screen and properties related to graphics.

All calls are under `Graphics`

---

## GL_Primitive

type `GL_Primitive`

### Properties

| Type         | Name               |
| ------------ | ------------------ |
| `int`        | `type`             |
| `float`      | `lineWidth`        |
| `bool`       | `hasTexture`       |
| `GL_Texture` | `texture`          |
| `bool`       | `textureAntialias` |
| `bool`       | `hasColor`         |
| `GL_Color`   | `color`            |
| `int`        | `id`               |

## GL_Texture

type `GL_Texture`

### Properties

| Type    | Name         |
| ------- | ------------ |
| `int`   | `id_`        |
| `int`   | `width_`     |
| `int`   | `height_`    |
| `bool`  | `isLogical_` |
| `float` | `u_base_`    |
| `float` | `v_base_`    |
| `float` | `u_size_`    |
| `float` | `v_size_`    |

## GL_Color

type `GL_Color`

### Constructor

`GL_Color(float rr, float gg, float bb, float aa)`

- `float rr` -- Red value from 0 to 1
- `float gg` -- Green value from 0 to 1
- `float bb` -- Blue value from 0 to 1
- `float aa` -- Alpha (opacity) value from 0 to 1

### Methods

`static GL_Color FromHSV(float fH, float fS, float fV, float fA)`

- `float h` -- Hue from 0 to 1
- `float s` -- Saturation from 0 to 1
- `float v` -- Luminance Value from 0 to 1
- `float a` -- Alpha (opacity) from 0 to 1
- `returns` -- GL_Color

### Properties

| Type    | Name |
| ------- | ---- |
| `float` | `r`  |
| `float` | `g`  |
| `float` | `b`  |
| `float` | `a`  |

## GL_ColorTexVertex

type `GL_ColorTexVertex`

### Properties

| Type    | Name |
| ------- | ---- |
| `float` | `x`  |
| `float` | `y`  |
| `float` | `u`  |
| `float` | `v`  |
| `float` | `r`  |
| `float` | `g`  |
| `float` | `b`  |
| `float` | `a`  |

## GL_Line

type `GL_Line`

### Constructor

`GL_Line(float x1, float y1, float x2, float y2)`

- `float x1, float y1` -- starting point
- `float x2, float y2` -- end point

### Properties

| Type     | Name    |
| -------- | ------- |
| `Pointf` | `start` |
| `Pointf` | `end`   |

## GL_TexVertex

type `GL_TexVertex`

### Properties

| Type    | Name |
| ------- | ---- |
| `float` | `x`  |
| `float` | `y`  |
| `float` | `u`  |
| `float` | `v`  |

## CSurface

Contains graphical functions  
All below methods are static, so they are to be called with the `.` operator.

### Methods

- `void AddTexVertices(std::vector<GL_TexVertex> *vec, float x1, float y1, float u1, float v1, float x2, float y2, float u2, float v2)`

  - **Warning**: operations with `std::vector` are not yet implemented

- `bool GL_BlitImage(GL_Texture *tex, float x, float y, float x2, float y2, float rotation, GL_Color color, bool mirror)`

  - Renders an image texture
  - `float x, float y` -- starting point (top-left corner)
  - `float x2, float y2` -- width and length

- `bool GL_BlitImagePartial(GL_Texture *tex, float x, float y, float size_x, float size_y, float start_x, float end_x, float start_y, float end_y, float alpha, GL_Color color, bool mirror)`

  - Renders a portion of an image texture
  - `float x, float y` -- starting point (top-left corner)
  - `float x2, float y2` -- width and length

- `void GL_BlitMultiColorImage(GL_Texture *tex, const std::vector<GL_ColorTexVertex> &texVertices, bool antialias)`

- `void GL_BlitMultiImage(GL_Texture *tex, const std::vector<GL_TexVertex> &texVertices, bool antialias)`

- `bool GL_BlitPixelImage(GL_Texture *tex, float x, float y, float x2, float y2, float rotation, GL_Color color, bool mirror)`

- `bool GL_BlitPixelImageWide(GL_Texture *tex, float x, float y, int x2, int y2, float opacity, GL_Color color, bool mirror)`

- `void GL_ClearAll()`

  - Remove everything that has been drawn.

- `void GL_ClearColor()`

- `GL_Primitive* GL_CreateImagePrimitive(GL_Texture *tex, float x, float y, float size_x, float size_y, float rotate, GL_Color color)`

- `GL_Primitive* GL_CreateMultiImagePrimitive(GL_Texture *tex, std::vector<GL_TexVertex> *vec, GL_Color color)`

- `GL_Primitive* GL_CreateMultiLinePrimitive(std::vector<GL_Line> &vec, GL_Color color, float thickness)`

- `GL_Primitive* GL_CreateMultiRectPrimitive(std::vector<Globals::Rect> &vec, GL_Color color)`

- `GL_Primitive* GL_CreatePixelImagePrimitive(GL_Texture *tex, float x, float y, float size_x, float size_y, float rotate, GL_Color color, bool unk)`

- `GL_Primitive* GL_CreateRectOutlinePrimitive(int x, int y, int w, int h, GL_Color color, float lineWidth)`

- `GL_Primitive* GL_CreateRectPrimitive(float x, float y, float w, float h, GL_Color color)`

- `void GL_DestroyPrimitive(GL_Primitive *primitive)`

- `bool GL_DisableBlend()`

- `bool GL_DrawLine(float x1, float y1, float x2, float y2, float lineWidth, GL_Color color)`

  - Renders a line
  - `float x1, float y1` -- starting point
  - `float x2, float y2` -- end point

- `bool GL_DrawRect(float x1, float y1, float x2, float y2, GL_Color color)`

  - Renders a rectangle
  - `float x1, float y1` -- starting point (top-left corner)
  - `float x2, float y2` -- width and length

- `bool GL_DrawRectOutline(int x1, int y1, int x2, int y2, GL_Color color, float lineWidth)`

  - Renders a rectange, no fill
  - `float x1, float y1` -- starting point (top-left corner)
  - `float x2, float y2` -- width and length

- `bool GL_DrawShield(int x, int y, float a1, float b1, int angle1, int angle2, GL_Color color, float thickness)`

  - Renders a gradient shield effect. (like how a portion of the shield turns white when a beam hits it)
  - `int x, int y` -- center point
  - `float a1, float b1` -- radius X, radius Y
  - `int angle1, int angle2` -- start direction, end direction

- `bool GL_DrawLaser(int x, int y, int w, int h, GL_Color color)`

  - Renders a beam.
  - `int x, int y` -- origin point
  - `int w` -- beam length
  - `int h` -- beam thickness

- `bool GL_DrawTriangle(Point vertex1, Point vertex2, Point vertex3, GL_Color color)`

  - Renders a triangle. The verticies are constructed with `Hyperspace.Point(x, y)`

- `bool GL_EnableBlend()`

- `GL_Color GL_GetColor()`

- `int GL_LoadIdentity()`

- `int GL_OrthoProjection(float mx1, float mx2, float mx3, float mx4, float mx5, float mx6)`

- `int GL_PopMatrix()`

  - Remove the current graphic from the selected stack.

- `void GL_PopScissor()`

- `void GL_PopStencilMode()`

- `int GL_PushMatrix()`

  - Push the current graphic, that is about to be drawn, onto the selected stack. Which can later be modified with other `CSurface` methods.

- `void GL_PushStencilMode()`

- `void GL_RemoveColorTint()`

- `void GL_RenderPrimitive(GL_Primitive *primitive)`

- `void GL_RenderPrimitiveWithAlpha(GL_Primitive *primitive, float alpha)`

- `void GL_RenderPrimitiveWithColor(GL_Primitive *primitive, GL_Color color)`

- `void GL_Rotate(float angle, float x, float y, float z = 1.f)`

- `void GL_Scale(float x, float y, float z)`

- `int GL_SetColor(GL_Color color)`

- `void GL_SetColorTint(GL_Color color)`

- `void GL_SetStencilMode(GL_StencilMode stencilMode, int ref, int mask)`

- `bool GL_Translate(float x, float y, float z = 0.f)`

- `GL_Color GetColorTint()`

## freetype

Contains functions for writing text to the screen

**Note**: The `fontSize` argument is not the literal font size, it needs to be a font ID.  
See `fonts.png` inside the hyperspace zip folder

### Methods
- `Pointf easy_measurePrintLines(int fontSize, float x, float y, int line_length, const std::string &text)`

- `int easy_measureWidth(int fontSize, const std::string &text)`

- `Pointf easy_print(int fontSize, float x, float y, const std::string &text)`

- `Pointf easy_printAutoNewlines(int fontSize, float x, float y, int line_length, const std::string &text)`

- `void easy_printAutoShrink(int fontId, float x, float y, int maxWidth, bool centered, const std::string &text)`

- `Pointf easy_printCenter(int fontSize, float x, float y, const std::string &text)`

- `Pointf easy_printNewlinesCentered(int fontSize, float x, float y, int line_length, const std::string &text)`

- `Pointf easy_printRightAlign(int fontSize, float x, float y, const std::string &text)`