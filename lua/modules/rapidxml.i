%module RapidXML
%include "stl.i"
%{
    #include "rapidxml.hpp"
    #include "rapidxml_interface.h"
    #include "Global.h"

    template<class Ch>
    template<int Flags>
    void xml_document<Ch>::parse_string(const Ch *text)
    {
        delete [] s;
        if (text)
        {
            s = new Ch[strlen(text)+1];
            strcpy(s, text);
        }
        else
        {
            s = nullptr;
        }

        this->template parse<Flags>(s);
    }

    template<class Ch>
    template<int Flags>
    void xml_document<Ch>::parse_file(const std::string &fileName)
    {
        delete [] s;
        s = G_->GetResources()->LoadFile(fileName);

        this->template parse<Flags>(s);
    }

    template<class Ch>
    void xml_document<Ch>::clear()
    {
        this->rapidxml::xml_document<Ch>::clear();
        delete [] s;
        s = nullptr;
    }
%}
%include "rapidxml.hpp"
%include "rapidxml_interface.h"
namespace rapidxml
{
    %ignore memory_pool;

    // ignore all the methods in xml_document<char>
    %ignore xml_document<char>::parse;
    %ignore xml_document<char>::clear;
    %ignore xml_document<char>::xml_document;
    %nodefaultctor xml_document<char>;
    %nodefaultdtor xml_document<char>;

    %template(memory_pool) memory_pool<char>;
    %template(xml_base) xml_base<char>;
    %template(xml_node) xml_node<char>;
    %template(xml_attribute) xml_attribute<char>;

    // this needs to be exposed and not ignored for inheritance to work
    %template(__xml_document) xml_document<char>;
}

%template(xml_document) xml_document<char>;
%extend xml_document<char> {
    %template(parse_string) parse_string<rapidxml::parse_default>;
    %template(parse_file) parse_file<rapidxml::parse_default>;
}
