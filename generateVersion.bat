@echo off
FOR /F "delims=" %%A IN (
    'git describe --always --dirty --match "NOT A TAG"'
) DO (
    FOR /F "delims=" %%B IN (
        'git rev-parse --abbrev-ref HEAD'
    ) DO (
        echo #pragma once & echo #undef BUILD_IDENTIFIER_HASH & echo #define BUILD_IDENTIFIER_HASH "%%A" & echo #undef BUILD_BRANCH & echo #define BUILD_BRANCH "%%B" & echo:
    )
) > Version.autogen.hpp.temp

fc /L Version.autogen.hpp Version.autogen.hpp.temp
if %ERRORLEVEL% NEQ 0 (move /Y Version.autogen.hpp.temp Version.autogen.hpp)
del Version.autogen.hpp.temp
