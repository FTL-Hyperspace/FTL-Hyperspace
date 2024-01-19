%module Defines
%include "stl.i"

%nodefaultctor SDL;
%nodefaultdtor SDL;
%nodefaultctor InternalEvents;
%nodefaultdtor InternalEvents;
%nodefaultctor RenderEvents;
%nodefaultdtor RenderEvents;

%{
#include "LuaInternalEvents.h"
#include "LuaRenderEvents.h"
#include "luaDefines.h"
%}
%include "LuaInternalEvents.h"
%include "LuaRenderEvents.h"
%include "luaDefines.h"
