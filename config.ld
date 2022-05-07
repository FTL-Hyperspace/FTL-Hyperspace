project = "FTL Hyperspace Lua API"
dir = "docs/ldoc"
description = [[
    Lua API description and documentation for FTL Hyperspace
]]
format = "discount"
not_luadoc = true
readme = { 'lua/readme_docs' }
add_language_extension('lc', 'c')
file = { 'lua', exclude = { 'lua/linit.c', 'lua/LuaScriptInit.h', 'lua/builtin/io.lua', 'lua/builtin/debug.lua', 'lua/builtin/coroutine.lua', 'lua/builtin/lpeg.lua', 'lua/builtin/lfs.lua', 'lua/builtin/package.lua', 'lua/builtin/os.lua' }}
use_markdown_titles = true
new_type("globalDefine", "Globals", true)
custom_tags={ {'removed', hidden = true }, {'remark', title = 'Remarks' } }
merge = true
custom_display_name_handler = function(item, default_handler)
    if item.type == 'function' and item.tags.removed then
        return item.name .. ' [Disabled]'
    end
    return default_handler(item)
end
