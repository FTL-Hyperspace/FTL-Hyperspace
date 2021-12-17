#include "Global.h"

/*
static int shaderCounter = 0;
char* shader;

HOOK_STATIC(CSurface, generate_fragment_shader_source, (GraphicsPrimitiveType primitive_type, int position_count, int texcoord_count, GraphicsTextureColorType texcolor_type, int tex_offset, int color_count, int color_uniform, int fog, int alpha_test, GraphicsComparisonType alpha_comparison) -> char*)
{
    LOG_HOOK("HOOK_STATIC -> CSurface::generate_fragment_shader_source -> Begin (Shaders.cpp)\n")

    char* ret = super(primitive_type, position_count, texcoord_count, texcolor_type, tex_offset, color_count, color_uniform, fog, alpha_test, alpha_comparison);

    if (texcolor_type == GRAPHICS_TEXCOLOR_RGBA && tex_offset == 1)
    {
        shaderCounter++;
        return shader;
    }


    shaderCounter++;


    return ret;
}

HOOK_METHOD(CApp, OnInit, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnInit -> Begin (Shaders.cpp)\n")
    shader = G_->GetResources()->LoadFile("data/shaders/default.fs");

    super();
}

HOOK_METHOD(CApp, OnKeyDown, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnKeyDown -> Begin (Shaders.cpp)\n")
    if (key == SDLKey::SDLK_KP_MINUS)
    {
    }
    if (key == SDLKey::SDLK_KP_PLUS)
    {
    }

    super(key);
}
*/
