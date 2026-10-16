#include "Global.h"

#ifdef HS_APPLE_GAME
std::string TextString::GetText()
{
    if (!this->isLiteral)
    {
        return G_->GetTextLibrary()->GetText(this->data);
    }
    else
    {
        return this->data;
    }
}
#endif

void TextString::operator+=(const std::string &other)
{
    this->data = GetText() + other;
}
