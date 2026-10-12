#! /bin/sh

cd "$(dirname "$0")/../../src/game" || exit 1

# Run inside each folder so FILENAME in the log lines stays the bare file name
find . -type d | while read -r dir; do
    (
        cd "$dir" || exit 1
        ls *.cpp > /dev/null 2>&1 || exit 0
        sed -i '/^    LOG_HOOK(/d' *.cpp
        gawk -i inplace 'match($0, /^(HOOK_METHOD|HOOK_METHOD_PRIORITY|HOOK_STATIC|HOOK_STATIC_PRIORITY)\(([A-Za-z_]+),[ ]?([A-Za-z0-9_]+),/, a),/\{/{if($0 ~ /HOOK/) { print } else { print;print "    LOG_HOOK(\"" a[1] " -> " a[2] "::" a[3] " -> Begin (" FILENAME ")\\n\")" } next}1' *.cpp
        gawk -i inplace 'match($0, /^(HOOK_GLOBAL|HOOK_GLOBAL_PRIORITY)\(([A-Za-z0-9_]+),/, a),/\{/{if($0 ~ /HOOK/) { print } else { print;print "    LOG_HOOK(\"" a[1] " -> " a[2] " -> Begin (" FILENAME ")\\n\")" } next}1' *.cpp
    )
done
