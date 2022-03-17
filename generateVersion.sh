#!/bin/bash
version=$(git describe --always --dirty --match 'NOT A TAG')
printf "#pragma once\n#undef BUILD_IDENTIFIER_HASH\n#define BUILD_IDENTIFIER_HASH \"$version\"\n" > Version.autogen.hpp
