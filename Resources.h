#pragma once
#include "Global.h"
#include "rapidxml.hpp"

GL_Color& ParseColorNode(GL_Color& colorRef, rapidxml::xml_node<char>* node, bool divide=true);
void InitializeResources(ResourceControl *resources);
