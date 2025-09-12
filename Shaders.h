#pragma once
#include "Global.h"

#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>

template<typename ResourceTraits>
class ResourceWrapper
{
    const static typename ResourceTraits::handle_t NULL_RESOURCE_VAL = 0;
public:
    ResourceWrapper& operator=(ResourceWrapper&& other)
    {
        handle = other.handle;
        other.handle = NULL_RESOURCE_VAL;
        return *this;
    };
    ResourceWrapper(ResourceWrapper&& other) : handle(other.handle)
    {
        other.handle = NULL_RESOURCE_VAL;
    }
    ~ResourceWrapper()
    {
        ResourceTraits::Delete(handle);
    };

    operator typename ResourceTraits::handle_t()
    {
        return handle;
    }

    ResourceWrapper(typename ResourceTraits::handle_t h) : handle(h) {};

    ResourceWrapper(const ResourceWrapper&) = delete;
    ResourceWrapper& operator=(const ResourceWrapper&) = delete;
private:
    typename ResourceTraits::handle_t handle;
};

struct OpenGLProgramTraits
{
    typedef GLuint handle_t;
    static void Delete(handle_t handle) {glDeleteProgram(handle);}
};

struct OpenGLShaderTraits
{
    typedef GLuint handle_t;
    static void Delete(handle_t handle) {glDeleteShader(handle);}
};

typedef ResourceWrapper<OpenGLProgramTraits> ProgramWrapper;
typedef ResourceWrapper<OpenGLShaderTraits> ShaderWrapper;

enum Uniforms
{
    UNIFORM_TRANSFORM = 0,
    UNIFORM_TEXTURE = 1,
    UNIFORM_TEX_OFFSET = 2,
    UNIFORM_FIXED_COLOR = 3,
    UNIFORM_FOG_PARAMS = 4,
    UNIFORM_FOG_TRANSFORM = 5,
    UNIFORM_FOG_COLOR = 6,
    UNIFORM_ALPHA_REF = 7,
    UNIFORM_POINT_SIZE = 8,
};

class CustomOpenGLShader
{
public:
    //For use by Lua
    CustomOpenGLShader(const char* vertexShaderSource, const char* fragmentShaderSource);
    void SetFloatUniform(const GLchar *name, GLfloat value);
    void SetIntUniform(const GLchar *name, GLint value);


    //Internal to Hyperspace
    void Use();
    static void ClearActiveShader();
    static void SetActiveShader(CustomOpenGLShader* shader);
    static CustomOpenGLShader* GetActiveShader();
    ~CustomOpenGLShader();
    static void ResetNativeShader();
private:
    static ShaderWrapper Compile(const char* shaderSource, GLenum shaderType);
    static CustomOpenGLShader* activeShader;
    ProgramWrapper program;
    GLint uniforms[9];
    void CheckUniforms();
};

class FrameBufferManager
{
public:
    const static int MAX_STACK_SIZE = 16;
    //For use by Lua
    static void StartFrameBuffer();
    static void EndFrameBuffer(CustomOpenGLShader* shader);
    //Internal to Hyperspace
    static void Init(GL_FrameBuffer* nativeBuffer_);
private:
    static GL_FrameBuffer* frameBuffers[MAX_STACK_SIZE];
    static GL_FrameBuffer* nativeBuffer;
    static int currentFrameBuffer;
}; 
