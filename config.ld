project = "FTL Hyperspace Lua API"
dir = "docs/ldoc"
description = [[
    Lua API description and documentation for FTL Hyperspace
]]
format = "markdown"
not_luadoc = true
add_language_extension('lc', 'c')
file = { '', exclude = { 'detours.h', 'hde.cpp', 'hde.h', 'libzhlgen', 'lua/luajit', 'linit.c', 'LuaScriptInit.h' }}
