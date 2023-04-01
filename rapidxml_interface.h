#pragma once

#include "rapidxml.hpp"

// wrapper around xml_document
class xml_document : rapidxml::xml_document<char>
{
private:
    char *s = nullptr; // the xml string being parsed
public:
    template<int Flags>
    void parse_string(const char *text);
    template<int Flags>
    void parse_file(const std::string &fileName);
    void clear();

    ~xml_document()
    {
        delete [] s;
    }
};
