%module RapidXML
%include "stl.i"
%{
    #include "rapidxml.hpp"
%}
%include "rapidxml.hpp"
namespace rapidxml
{
    %ignore memory_pool;

    %template(memory_pool) memory_pool<char>;
    %template(xml_base) xml_base<char>;
    %template(xml_node) xml_node<char>;
    %template(xml_attribute) xml_attribute<char>;
    %template(xml_document) xml_document<char>;
    
    

    %extend xml_document<char> {
        %template(parse) parse<parse_default>;
    };
}