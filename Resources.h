#pragma once
#include "Global.h"
#include "rapidxml.hpp"

GL_Color& ParseColorNode(GL_Color& colorRef, rapidxml::xml_node<char>* node);
void InitializeResources(ResourceControl *resources);
