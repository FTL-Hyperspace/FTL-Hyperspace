#! /bin/sh

"$(dirname "$0")/addHookLogs.sh" || exit 1
unix2dos "$(dirname "$0")"/../../src/game/*.cpp
