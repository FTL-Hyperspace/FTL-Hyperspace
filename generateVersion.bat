@echo off
FOR /F "delims=" %A IN (
    'git describe --always --dirty --match "NOT A TAG"`
) DO (
    echo #pragma once & echo #undef BUILD_IDENTIFIER_HASH & echo #define BUILD_IDENTIFIER_HASH "%A" & echo:
) > Version.autogen.hpp
