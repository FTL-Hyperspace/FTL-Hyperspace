#!/bin/bash
# On pull request CI uses a detached head so workflow needs to provide
# HS_BUILD_HASH and HS_BUILD_BRANCH env variables in order for us to stamp the version
if [ -n "$HS_BUILD_HASH" ]; then
    version="${HS_BUILD_HASH:0:8}"
else
    version=$(git describe --always --dirty --match 'NOT A TAG')
fi

if [ -n "$HS_BUILD_BRANCH" ]; then
    branch="$HS_BUILD_BRANCH"
else
    branch=$(git rev-parse --abbrev-ref HEAD)
fi

printf "#pragma once\n#undef BUILD_IDENTIFIER_HASH\n#define BUILD_IDENTIFIER_HASH \"$version\"\n#undef BUILD_BRANCH\n#define BUILD_BRANCH \"$branch\"\n" > Version.autogen.hpp.temp
# -s because the file is missing on a clean build and cmp reports that as an error
if cmp -s Version.autogen.hpp Version.autogen.hpp.temp; then
    rm Version.autogen.hpp.temp
else
    mv -f Version.autogen.hpp.temp Version.autogen.hpp
fi
