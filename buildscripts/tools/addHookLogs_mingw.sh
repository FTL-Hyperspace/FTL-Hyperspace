#! /bin/sh

"$(dirname "$0")/addHookLogs.sh" || exit 1
find "$(dirname "$0")/../../src/game" -name '*.cpp' -exec unix2dos {} +
