#include "Global.h"

#if defined (__APPLE__)
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
