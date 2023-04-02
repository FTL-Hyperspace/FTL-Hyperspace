#pragma once

#include "rapidxml.hpp"

// wrapper around xml_document
template<class Ch = char>
class xml_document : public rapidxml::xml_document<Ch>
{
private:
    Ch *s = nullptr; // the xml string being parsed
public:
    template<int Flags>
    void parse_string(const Ch *text);
    template<int Flags>
    void parse_file(const std::string &fileName);
    void clear();

    ~xml_document()
    {
        delete [] s;
    }
};
