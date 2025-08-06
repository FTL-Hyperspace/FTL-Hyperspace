#include "Colors.h"


GL_Color COLOR_BUTTON_TEXT = GL_Color(25 / 255.f, 49 / 255.f, 51 / 255.f, 1.f);
GL_Color COLOR_BUTTON_ON = GL_Color(235 / 255.f, 245 / 255.f, 229 / 255.f, 1.f);
GL_Color COLOR_TINT = GL_Color(0.5f, 0.5f, 0.5f, 1.f);
GL_Color COLOR_WHITE = GL_Color(1.f, 1.f, 1.f, 1.f);
GL_Color COLOR_YELLOW = GL_Color(1.f, 1.f, 0.196f, 1.f);

void GL_Color::SaveState(int fd)
{
    FileHelper::writeFloat(fd, r);
    FileHelper::writeFloat(fd, g);
    FileHelper::writeFloat(fd, b);
    FileHelper::writeFloat(fd, a);
}

void GL_Color::LoadState(int fd)
{
    r = FileHelper::readFloat(fd);
    g = FileHelper::readFloat(fd);
    b = FileHelper::readFloat(fd);
    a = FileHelper::readFloat(fd);
}
