 #! /bin/sh

 sed -i '/^    LOG_HOOK(/d' *.cpp
 gawk -i inplace 'match($0, /^(HOOK_METHOD|HOOK_METHOD_PRIORITY|HOOK_STATIC|HOOK_STATIC_PRIORITY)\(([A-Za-z_]+),[ ]?([A-Za-z0-9_]+),/, a),/\{/{if($0 ~ /HOOK/) { print } else { print;print "    LOG_HOOK(\"" a[1] " -> " a[2] "::" a[3] " -> Begin (" FILENAME ")\\n\")" } next}1' *.cpp
 gawk -i inplace 'match($0, /^(HOOK_GLOBAL|HOOK_GLOBAL_PRIORITY)\(([A-Za-z0-9_]+),/, a),/\{/{if($0 ~ /HOOK/) { print } else { print;print "    LOG_HOOK(\"" a[1] " -> " a[2] " -> Begin (" FILENAME ")\\n\")" } next}1' *.cpp
 unix2dos *.cpp
