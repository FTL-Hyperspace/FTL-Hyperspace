project = "FTL Hyperspace Lua API"
dir = "docs/ldoc"
description = [[
    Lua API description and documentation for FTL Hyperspace
]]
format = "discount"
not_luadoc = true
readme = { 'lua/readme_docs' }
add_language_extension('lc', 'c')
file = { 'lua', exclude = { 'lua/linit.c', 'lua/LuaScriptInit.h' }}
use_markdown_titles = true
