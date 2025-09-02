#if defined (__APPLE__)
#include "Global.h"

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
