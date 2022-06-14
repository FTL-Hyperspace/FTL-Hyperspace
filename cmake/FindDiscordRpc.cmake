# discord-rpc is a rare case where vcpkg doesn't provide a proper mean to find_package() out-of-the-box.
# As the project itself is discontinued there's no hope for PR #345 to be merged
# so we're stuck at manually finding libraries.

set(DiscordRpc_ROOT_DIR "${DiscordRpc_ROOT_DIR}" CACHE PATH "Path to discord-rpc.")
find_library(DiscordRpc_LIBRARY NAMES discord-rpc PATHS "${DiscordRpc_ROOT_DIR}" PATH_SUFFIXES lib)
find_path(DiscordRpc_INCLUDE_DIR NAMES discord_rpc.h PATHS "${DiscordRpc_ROOT_DIR}" PATH_SUFFIXES include)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
    DiscordRpc DEFAULT_MSG
    DiscordRpc_LIBRARY
    DiscordRpc_INCLUDE_DIR
)

if(DiscordRpc_FOUND)
    add_library(DiscordRpc::DiscordRpc STATIC IMPORTED)
    set_target_properties(DiscordRpc::DiscordRpc PROPERTIES IMPORTED_LOCATION ${DiscordRpc_LIBRARY})
    set(DiscordRpc_LIBRARIES DiscordRpc::DiscordRpc)
    set(DiscordRpc_INCLUDE_DIRS ${DiscordRpc_INCLUDE_DIR})
endif()

mark_as_advanced(DiscordRpc_LIBRARY DiscordRpc_INCLUDE_DIR)

if(DiscordRpc_FOUND)
    mark_as_advanced(DiscordRpc_ROOT_DIR)
endif()
