%module RapidXML
%include "stl.i"
%{
    #include "rapidxml.hpp"
    #include "rapidxml_interface.h"
    #include "Global.h"

    template<int Flags>
    void xml_document::parse_string(const char *text)
    {
        delete [] s;
        if (text)
        {
            s = new char[strlen(text)+1];
            strcpy(s, text);
        }
        else
        {
            s = nullptr;
        }

        parse<Flags>(s);
    }
    template<int Flags>
    void xml_document::parse_file(const std::string &fileName)
    {
        delete [] s;
        s = G_->GetResources()->LoadFile(fileName);

        parse<Flags>(s);
    }
    void xml_document::clear()
    {
        this->rapidxml::xml_document<char>::clear();
        delete [] s;
        s = nullptr;
    }
%}
%include "rapidxml.hpp"
%include "rapidxml_interface.h"
namespace rapidxml
{
    %ignore memory_pool;
    %ignore xml_document;

    %template(memory_pool) memory_pool<char>;
    %template(xml_base) xml_base<char>;
    %template(xml_node) xml_node<char>;
    %template(xml_attribute) xml_attribute<char>;
    //%template(xml_document) xml_document<char>;



    //%extend xml_document<char> {
    //    %template(parse) parse<parse_default>;
    //};
}

%ignore xml_document::parse;
%extend xml_document {
    %template(parse_string) parse_string<rapidxml::parse_default>;
    %template(parse_file) parse_file<rapidxml::parse_default>;
}
