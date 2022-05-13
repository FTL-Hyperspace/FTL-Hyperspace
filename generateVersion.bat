@echo off
FOR /F "delims=" %%A IN (
    'git describe --always --dirty --match "NOT A TAG"'
) DO (
    FOR /F "delims=" %%B IN (
        'git rev-parse --abbrev-ref HEAD'
    ) DO (
        echo #pragma once & echo #undef BUILD_IDENTIFIER_HASH & echo #define BUILD_IDENTIFIER_HASH "%%A" & echo #undef BUILD_BRANCH & echo #define BUILD_BRANCH "%%B" & echo:
    )
) > Version.autogen.hpp
