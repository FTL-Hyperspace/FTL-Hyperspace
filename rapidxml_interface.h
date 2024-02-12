#pragma once

#include "rapidxml.hpp"

// wrapper around xml_document
template<class Ch = char>
class xml_document : public rapidxml::xml_document<Ch>
{
private:
    Ch *s; // the xml string being parsed

    // make rapidxml::xml_document methods private (but keep the node methods, etc., public)
    using rapidxml::xml_document<Ch>::parse;
    using rapidxml::xml_document<Ch>::clear;
public:
    // Copies string to s and then parses it
    template<int Flags>
    void parse_string(const Ch *text);

    // Reads file from FTL resources and puts the result in s, then parses it
    template<int Flags>
    void parse_file(const std::string &fileName);

    // Clears the document and the string
    void clear();

    // Derived constructor
    xml_document()
        : rapidxml::xml_document<Ch>()
        , s{nullptr}
    {
    }

    // Constructor that calls parse_file
    xml_document(const std::string &fileName)
        : xml_document()
    {
        this->parse_file<rapidxml::parse_default>(fileName);
    }

    // Destructor
    ~xml_document()
    {
        delete [] s;
    }
};
