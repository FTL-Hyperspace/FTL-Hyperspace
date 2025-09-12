#include "Global.h"
#include "Shaders.h"

#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>
#include <boost/format.hpp>
/*
    OPENGL FUNCTION LOADING SECTION
    TODO: Possibly replace with a linking library or other method but this is how ftl does it
*/
#define INIT_FUNC_PTR(name) decltype(name)* p ## name = nullptr;
INIT_FUNC_PTR(glDeleteProgram)
INIT_FUNC_PTR(glDeleteShader)
INIT_FUNC_PTR(glCreateProgram)
INIT_FUNC_PTR(glCreateShader)
INIT_FUNC_PTR(glShaderSource)
INIT_FUNC_PTR(glCompileShader)
INIT_FUNC_PTR(glGetShaderiv)
INIT_FUNC_PTR(glGetShaderInfoLog)
INIT_FUNC_PTR(glAttachShader)
INIT_FUNC_PTR(glDetachShader)
INIT_FUNC_PTR(glLinkProgram)
INIT_FUNC_PTR(glGetProgramiv)
INIT_FUNC_PTR(glGetProgramInfoLog)
INIT_FUNC_PTR(glUseProgram)
INIT_FUNC_PTR(glGetUniformLocation)
INIT_FUNC_PTR(glBindAttribLocation)
INIT_FUNC_PTR(glUniformMatrix4fv)
INIT_FUNC_PTR(glUniform1i)
INIT_FUNC_PTR(glUniform1f)
INIT_FUNC_PTR(glUniform2fv)
INIT_FUNC_PTR(glUniform4fv)
INIT_FUNC_PTR(glGetActiveUniform)

INIT_FUNC_PTR(glGetAttachedShaders)
INIT_FUNC_PTR(glGetShaderSource)

void glDeleteProgram(GLuint program)
{
    if (pglDeleteProgram) pglDeleteProgram(program);
}
void glDeleteShader(GLuint shader)
{
    if (pglDeleteShader) pglDeleteShader(shader);
}
GLuint glCreateProgram()
{
    if (pglCreateProgram) return pglCreateProgram();
    return 0;
}
GLuint glCreateShader(GLenum type)
{
    if (pglCreateShader) return pglCreateShader(type);
    return 0;
}
void glShaderSource(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length)
{
    if (pglShaderSource) pglShaderSource(shader, count, string, length);
}
void glCompileShader(GLuint shader)
{
    if (pglCompileShader) pglCompileShader(shader);
}
void glGetShaderiv(GLuint shader, GLenum pname, GLint *params)
{
    if (pglGetShaderiv) pglGetShaderiv(shader, pname, params);
}
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
    if (pglGetShaderInfoLog) pglGetShaderInfoLog(shader, bufSize, length, infoLog);
}
void glAttachShader(GLuint program, GLuint shader)
{
    if (pglAttachShader) pglAttachShader(program, shader);
}
void glDetachShader(GLuint program, GLuint shader)
{
    if (pglDetachShader) pglDetachShader(program, shader);
}
void glLinkProgram(GLuint program)
{
    if (pglLinkProgram) pglLinkProgram(program);
}
void glGetProgramiv(GLuint program, GLenum pname, GLint *params)
{
    if (pglGetProgramiv) pglGetProgramiv(program, pname, params);
}
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
    if (pglGetProgramInfoLog) pglGetProgramInfoLog(program, bufSize, length, infoLog);
}
void glUseProgram(GLuint program)
{
    if (pglUseProgram) pglUseProgram(program);
}
GLint glGetUniformLocation(GLuint program, const GLchar *name)
{
    if (pglGetUniformLocation) return pglGetUniformLocation(program, name);
    return -1;
}
void glBindAttribLocation(GLuint program, GLuint index, const GLchar *name)
{
    if (pglBindAttribLocation) pglBindAttribLocation(program, index, name);
}
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    if (pglUniformMatrix4fv) pglUniformMatrix4fv(location, count, transpose, value);
}
void glUniform1i(GLint location, GLint v0)
{
    if (pglUniform1i) pglUniform1i(location, v0);
}
void glUniform1f(GLint location, GLfloat v0)
{
    if (pglUniform1f) pglUniform1f(location, v0);
}
void glUniform2fv(GLint location, GLsizei count, const GLfloat *value)
{
    if (pglUniform2fv) pglUniform2fv(location, count, value);
}
void glUniform4fv(GLint location, GLsizei count, const GLfloat *value)
{
    if (pglUniform4fv) pglUniform4fv(location, count, value);
}
void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
{
    if (pglGetActiveUniform) pglGetActiveUniform(program, index, bufSize, length, size, type, name);
}

void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders)
{
    if (pglGetAttachedShaders) pglGetAttachedShaders(program, maxCount, count, shaders);
}

void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source)
{
    if (pglGetShaderSource) pglGetShaderSource(shader, bufSize, length, source);
}


#define LOAD_GL_FUNC(name) p ## name = reinterpret_cast<decltype(p ## name)>(func(#name));
HOOK_GLOBAL(dyngl_init, (lookup_func func) -> void)
{
    LOG_HOOK("HOOK_GLOBAL -> dyngl_init -> Begin (Shaders.cpp)\n")
    super(func);
    
    LOAD_GL_FUNC(glDeleteProgram)
    LOAD_GL_FUNC(glDeleteShader)
    LOAD_GL_FUNC(glCreateProgram)
    LOAD_GL_FUNC(glCreateShader)
    LOAD_GL_FUNC(glShaderSource)
    LOAD_GL_FUNC(glCompileShader)
    LOAD_GL_FUNC(glGetShaderiv)
    LOAD_GL_FUNC(glGetShaderInfoLog)
    LOAD_GL_FUNC(glAttachShader)
    LOAD_GL_FUNC(glDetachShader)
    LOAD_GL_FUNC(glLinkProgram)
    LOAD_GL_FUNC(glGetProgramiv)
    LOAD_GL_FUNC(glGetProgramInfoLog)
    LOAD_GL_FUNC(glUseProgram)
    LOAD_GL_FUNC(glGetUniformLocation)
    LOAD_GL_FUNC(glUniformMatrix4fv)
    LOAD_GL_FUNC(glUniform1i)
    LOAD_GL_FUNC(glUniform1f)
    LOAD_GL_FUNC(glUniform2fv)
    LOAD_GL_FUNC(glUniform4fv)
    LOAD_GL_FUNC(glBindAttribLocation)
    LOAD_GL_FUNC(glGetActiveUniform)

    LOAD_GL_FUNC(glGetAttachedShaders)
    LOAD_GL_FUNC(glGetShaderSource)
};

/*
    CUSTOM SHADER CLASS IMPLEMENTATION
*/


CustomOpenGLShader* CustomOpenGLShader::activeShader = nullptr;
ShaderWrapper CustomOpenGLShader::Compile(const char* shaderSource, GLenum shaderType)
{
    ShaderWrapper shader = glCreateShader(shaderType);
    if (shader == 0) throw std::runtime_error("Failure to create shader!");
    glShaderSource(shader, 1, &shaderSource, nullptr);
    glCompileShader(shader);
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (success != GL_TRUE)
    {
        GLchar message[1024];
        glGetShaderInfoLog(shader, sizeof(message), nullptr, message);
        std::string error = (boost::format("Compilation of shader:\n\n%s\n\nFailed with error:\n%s\n")
                        % shaderSource
                        % message).str();
        throw std::invalid_argument(error);
    }
    return shader;
}

CustomOpenGLShader::CustomOpenGLShader(const char* vertexShaderSource, const char* fragmentShaderSource) : program(glCreateProgram())
{
    if (*window_is_d3d) throw std::runtime_error("Cannot create OpenGL shader when running in Direct3D mode!");
    if (program == 0) throw std::runtime_error("Failure to create shader program!");
    ShaderWrapper vertexShader = Compile(vertexShaderSource, GL_VERTEX_SHADER);
    ShaderWrapper fragmentShader = Compile(fragmentShaderSource, GL_FRAGMENT_SHADER);
    glBindAttribLocation(program, 0, "position");
    glBindAttribLocation(program, 1, "texcoord");
    glBindAttribLocation(program, 2, "color");

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    //Shaders can be discarded after linking
    glDetachShader(program, vertexShader);
    glDetachShader(program, fragmentShader);

    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (success != GL_TRUE)
    {
        GLchar message[1024];
        glGetProgramInfoLog(program, sizeof(message), nullptr, message);
        std::string error = (boost::format("Failure to link program with vertex shader:\n\n%s\n\nAnd fragment shader:\n\n%s\n\nWith error:\n%s\n")
                        % vertexShaderSource
                        % fragmentShaderSource
                        % message).str();
        throw std::invalid_argument(error);
    }
    CheckUniforms();
    
}
//TODO: Determine which uniforms will actually be needed
//Texure uniform will be needed but we may not need to init it
//Transform uniform will be needed for vertex shaders
//Other uniforms are probably not needed because custom shaders will only be applied to framebuffer draws
void CustomOpenGLShader::CheckUniforms()
{
    GLint num_uniforms = 0;
    glGetProgramiv(program, GL_ACTIVE_UNIFORMS, &num_uniforms);
    for (GLint uniform_index = 0; uniform_index < num_uniforms; ++uniform_index)
    {
        GLchar name[256];
        GLint size = 0;
        GLenum type = 0;
        glGetActiveUniform(program, uniform_index, sizeof(name), nullptr, &size, &type, name);

        std::string error;
        if (strcmp(name, "transform") == 0 && type != GL_FLOAT_MAT4)
        {   
            error = "Incorrect type for built-in uniform 'transform', expected a mat4";
        }
        else if (strcmp(name, "texture") == 0 && type != GL_SAMPLER_2D)
        {
            error = "Incorrect type for built-in uniform 'texture', expected a sampler2D";
        }
        else if (strcmp(name, "tex_offset") == 0 && type != GL_FLOAT_VEC2)
        {
            error = "Incorrect type for built-in uniform 'tex_offset', expected a vec2";
        }
        else if (strcmp(name, "fixed_color") == 0 && type != GL_FLOAT_VEC4)
        {
            error = "Incorrect type for built-in uniform 'fixed_color', expected a vec4";
        }
        else if (strcmp(name, "fog_params") == 0 && type != GL_FLOAT_VEC2)
        {
            error = "Incorrect type for built-in uniform 'fog_params', expected a vec2";
        }
        else if (strcmp(name, "fog_transform") == 0 && type != GL_FLOAT_VEC4)
        {
            error = "Incorrect type for built-in uniform 'fog_transform', expected a vec4";
        }
        else if (strcmp(name, "fog_color") == 0 && type != GL_FLOAT_VEC4)
        {
            error = "Incorrect type for built-in uniform 'fog_color', expected a vec4";
        }
        else if (strcmp(name, "alpha_ref") == 0 && type != GL_FLOAT)
        {
            error = "Incorrect type for built-in uniform 'alpha_ref', expected a float";
        }
        else if (strcmp(name, "point_size") == 0 && type != GL_FLOAT)
        {
            error = "Incorrect type for built-in uniform 'point_size', expected a float";
        }

        if (!error.empty()) throw std::invalid_argument(error);
    }
    uniforms[UNIFORM_TRANSFORM] = glGetUniformLocation(program, "transform");
    uniforms[UNIFORM_TEXTURE] = glGetUniformLocation(program, "texture");
    uniforms[UNIFORM_TEX_OFFSET] = glGetUniformLocation(program, "tex_offset");
    uniforms[UNIFORM_FIXED_COLOR] = glGetUniformLocation(program, "fixed_color");
    uniforms[UNIFORM_FOG_PARAMS] = glGetUniformLocation(program, "fog_params");
    uniforms[UNIFORM_FOG_TRANSFORM] = glGetUniformLocation(program, "fog_transform");
    uniforms[UNIFORM_FOG_COLOR] = glGetUniformLocation(program, "fog_color");
    uniforms[UNIFORM_ALPHA_REF] = glGetUniformLocation(program, "alpha_ref");
    uniforms[UNIFORM_POINT_SIZE] = glGetUniformLocation(program, "point_size");
}

void CustomOpenGLShader::Use()
{
    //These uniforms are just the uniforms assigned by the native engine, but lua won't be replacing individual shaders unless there's really a need for that
    //Most are not important for framebuffer renders anyway
    glUseProgram(program);
    glUniformMatrix4fv(uniforms[UNIFORM_TRANSFORM], 1, true, &transformation_matrix->_11);
    glUniform1i(uniforms[UNIFORM_TEXTURE], 0); //This might not be necessary because of how texture units work (https://stackoverflow.com/questions/54931941/correspondance-between-texture-units-and-sampler-uniforms-in-opengl), native generated shaders use uninitialized uniform "tex" anyway
    glUniform2fv(uniforms[UNIFORM_TEX_OFFSET], 1, &texture_offset->x);
    glUniform4fv(uniforms[UNIFORM_FIXED_COLOR], 1, &opengl_primitive_color->x);
    //Inlined function update_fog_params
    fog_params->x = 1.0 / (*fog_end - *fog_start);
    fog_params->y = *fog_start / (*fog_end - *fog_start);
    glUniform2fv(uniforms[UNIFORM_FOG_PARAMS], 1, &fog_params->x);
    glUniform4fv(uniforms[UNIFORM_FOG_TRANSFORM], 1, &fog_transform->x);
    glUniform4fv(uniforms[UNIFORM_FOG_COLOR], 1, &fog_color->x);
    glUniform1f(uniforms[UNIFORM_ALPHA_REF], *alpha_test_reference);
    glUniform1f(uniforms[UNIFORM_POINT_SIZE], *point_size);
    ResetNativeShader(); //Make sure the game knows that the shader has been changed so that it doesn't make bad assumptions regarding uniforms
}

void CustomOpenGLShader::SetFloatUniform(const GLchar* name, GLfloat value)
{
    GLint location = glGetUniformLocation(program, name);
    if (location == -1) throw std::invalid_argument(std::string("Uniform not found: ") + name);
    glUseProgram(program);
    glUniform1f(location, value);
    if (*current_shader != nullptr) glUseProgram((*current_shader)->program); //Restore the previous shader program if there was one
    if (glGetError() == GL_INVALID_OPERATION) throw std::invalid_argument(std::string("Error setting uniform, possibly wrong type in shader: ") + name);
}
void CustomOpenGLShader::SetIntUniform(const GLchar* name, GLint value)
{
    GLint location = glGetUniformLocation(program, name);
    if (location == -1) throw std::invalid_argument(std::string("Uniform not found: ") + name);
    glUseProgram(program);
    glUniform1i(location, value);
    if (*current_shader != nullptr) glUseProgram((*current_shader)->program); //Restore the previous shader program if there was one
    if (glGetError() == GL_INVALID_OPERATION) throw std::invalid_argument(std::string("Error setting uniform, possibly wrong type in shader: ") + name);
}

void CustomOpenGLShader::ResetNativeShader()
{
    *current_shader = nullptr;
}

void CustomOpenGLShader::ClearActiveShader() 
{
    ResetNativeShader();
    if (activeShader != nullptr) glUseProgram(0);
    activeShader = nullptr;
};
void CustomOpenGLShader::SetActiveShader(CustomOpenGLShader* shader) 
{
    ResetNativeShader();
    activeShader = shader;
}
CustomOpenGLShader* CustomOpenGLShader::GetActiveShader() 
{
    return activeShader;
};
CustomOpenGLShader::~CustomOpenGLShader() 
{
    if (activeShader == this) ClearActiveShader();
};

/*
    NATIVE SHADER NOTES:
    There is some code in the native engine relating to shader pipelines but as far as I can tell it does not work on windows 1.6.9. Custom shaders will need to be reworked or this feature will need to be forced off when porting to Linux
    Variables relating to shader pipelines:
    features_avail: a global variable that represents a set of flags. The flag 0x80000 represents if shader pipeline objects are supported. This is set in opengl_init if the OpenGL version is at least 4.1 or if the "GL_ARB_separate_shader_objects" extension is available. This also requires dyngl_has_separate_shaders to return true, which will not happen on Windows 1.6.9.
    opengl_shader_objects_enabled: a global variable that is set to true if shader pipeline objects are enabled. This is set by graphics_use_shader_objects, which is never called in the native engine on windows 1.6.9.
    has_separate_shaders and dyngl_has_separate_shaders: A global variable and its getter function. On windows 1.6.9, it is set to false at the end of dyngl_init.
    
    When rendering an OpenGLSysPrimitive, the function opengl_sys_graphics_draw_primitive (sys_graphics_draw_primitive on linux where all rendering is always opengl)
    is called.
    
    This calls opengl_apply_shader. The native code in opengl_apply_shader calls opengl_select_shader, which determines the appropriate shader to use. If the appropriate shader does not exist, the source text is generated and the shader is compiled and cached.
    The vertex and fragment shader are generated by generate_vertex_shader_source and generate_fragment_shader_source respectively (although this is done via a callback function set by graphics_set_shader_generator so these could really be any functions if you wanted)
    The source code is then prepended with some headers in opengl_compile_shader, which are determined based on some system-specific conditions and available opengl features. This may be important when considering compatibility with different platforms.

    Information regarding uniform positions are also cached. opengl_select_shader then uses the current program object.

    opengl_apply_shader then sets the uniforms for the shader if the shader is different from the last shader used and the uniform values were different.

*/

HOOK_GLOBAL(opengl_apply_shader, (OpenGLSysPrimitive *primitive) -> int)
{
    LOG_HOOK("HOOK_GLOBAL -> opengl_apply_shader -> Begin (Shaders.cpp)\n")
    CustomOpenGLShader* activeShader = CustomOpenGLShader::GetActiveShader();
    if (activeShader != nullptr)
    {
        activeShader->Use();
        return 1;
    }
    return super(primitive);
}

//Framebuffers for postprocessing
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
GL_FrameBuffer* FrameBufferManager::frameBuffers[FrameBufferManager::MAX_STACK_SIZE] = { nullptr };
GL_FrameBuffer* FrameBufferManager::nativeBuffer = nullptr;
int FrameBufferManager::currentFrameBuffer = -1;
void FrameBufferManager::Init(GL_FrameBuffer* nativeBuffer_)
{
    nativeBuffer = nativeBuffer_;
    for (int i = 0; i < MAX_STACK_SIZE; ++i)
    {
        frameBuffers[i] = CSurface::GL_CreateFrameBuffer(SCREEN_WIDTH, SCREEN_HEIGHT);
    }
    currentFrameBuffer = -1;
}
void FrameBufferManager::StartFrameBuffer()
{
    ++currentFrameBuffer;
    if (currentFrameBuffer >= MAX_STACK_SIZE)
    {
        hs_log_file("Framebuffer stack overflow!\n");
        return;
    }
    CSurface::GL_BindFrameBuffer(frameBuffers[currentFrameBuffer]);
    CSurface::GL_OrthoProjection(0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, -50.0, 50.0);
    CSurface::GL_ClearAll();
    CustomOpenGLShader::ResetNativeShader();
}
//TODO: Things drawn to a temporary framebuffer have their alpha blended incorrectly to the next buffer
void FrameBufferManager::EndFrameBuffer(CustomOpenGLShader* shader)
{
    if (currentFrameBuffer < 0)
    {
        hs_log_file("Framebuffer stack underflow!\n");
        return;
    }
    CSurface::GL_BindFrameBuffer(currentFrameBuffer == 0 ? nativeBuffer : frameBuffers[currentFrameBuffer - 1]);
    CustomOpenGLShader::SetActiveShader(shader);
    CSurface::GL_PushMatrix();
    CSurface::GL_LoadIdentity();
    graphics_set_blend(GRAPHICS_BLEND_ADD, GRAPHICS_BLEND_ONE, GRAPHICS_BLEND_INV_SRC_ALPHA);
    CSurface::GL_BlitFrameBuffer(frameBuffers[currentFrameBuffer], SCREEN_WIDTH, SCREEN_HEIGHT, false);
    CSurface::GL_EnableBlend();
    CSurface::GL_PopMatrix();
    CustomOpenGLShader::ClearActiveShader();
    --currentFrameBuffer;
}

HOOK_METHOD(CApp, OnInit, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnInit -> Begin (Shaders.cpp)\n")

    int ret = super();
    if (fboSupport) FrameBufferManager::Init(framebuffer);
    else ErrorMessage("Framebuffers are not supported on this system! Shader features may not work properly.");
    return ret;
}

HOOK_METHOD_PRIORITY(CApp, OnRender, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnRender -> Begin (Shaders.cpp)\n")
    UpdateFullScreen();
    CSurface::StartFrame();
    screen_x = graphics_display_width();
    screen_y = graphics_display_height();
    UpdateWindowSettings();
    if (useFrameBuffer)
    {
        CSurface::GL_BindFrameBuffer(framebuffer);
        CSurface::GL_SetViewPort(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        CSurface::GL_OrthoProjection(0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, -50.0, 50.0);
    }
    else
    {
        CSurface::GL_SetViewPort(0, 0, screen_x, screen_y);
        CSurface::GL_OrthoProjection(0.0, screen_x, screen_y, 0.0, -50.0, 50.0);
    }
    CSurface::GL_ClearAll();
    CSurface::GL_LoadIdentity();
    CSurface::GL_Translate(modifier_x, modifier_y, 0.0);
    CSurface::GL_SetScissor(modifier_x, modifier_y, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (rendering)
    {
        if (langChooser.bOpen)
        {
            std::string text = G_->GetTextLibrary()->GetText("choose_language");
            freetype::easy_printCenter(12, 640.0, 165.0, text);
            langChooser.OnRender();
        }
        else if (menu.bOpen)
        {
            menu.OnRender();
        }
        else
        {
            gui->RenderStatic();
        }
    }
    G_->GetAchievementTracker()->OnRender();
    CSurface::GL_SetScissor(0, 0, 0, 0);
    G_->GetMouseControl()->OnRender();
    //G_->GetCFPS()->OnRender(); Empty function
    if (useFrameBuffer)
    {
        CSurface::GL_BindFrameBuffer(nullptr);
        CSurface::GL_SetViewPort(x_bar, y_bar, screen_x +  x_bar * -2, screen_y + y_bar * -2);
        if (x_bar != 0 || y_bar != 0) CSurface::GL_ClearColor();
        CSurface::GL_DisableBlend();
        CSurface::GL_LoadIdentity();
        bool antiAlias = screen_x != (screen_x / SCREEN_WIDTH) * SCREEN_WIDTH || screen_y != (screen_y / SCREEN_HEIGHT) * SCREEN_HEIGHT;
        CSurface::GL_BlitFrameBuffer(framebuffer, SCREEN_WIDTH, SCREEN_HEIGHT, antiAlias);
        CSurface::GL_EnableBlend();
    }
    CSurface::FinishFrame();
}