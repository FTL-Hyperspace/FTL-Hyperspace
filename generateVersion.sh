#!/bin/bash
version=$(git describe --always --dirty --match 'NOT A TAG')
branch=$(git rev-parse --abbrev-ref HEAD)
printf "#pragma once\n#undef BUILD_IDENTIFIER_HASH\n#define BUILD_IDENTIFIER_HASH \"$version\"\n#undef BUILD_BRANCH\n#define BUILD_BRANCH \"$branch\"\n" > Version.autogen.hpp.temp
cmp Version.autogen.hpp Version.autogen.hpp.temp && rm Version.autogen.hpp.temp || mv -f Version.autogen.hpp.temp Version.autogen.hpp
