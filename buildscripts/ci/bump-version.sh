#!/bin/bash
set -e
set +H

sr_xmllike() {
    python3 $SCRIPT_DIR/../_sr_xmllike.py "$@"
}

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
VERSION="$1"

[[ $VERSION =~ ([0-9]+).([0-9]+).([0-9]+)(.*) ]]
VERSION_MAJOR=${BASH_REMATCH[1]}
VERSION_MINOR=${BASH_REMATCH[2]}
VERSION_PATCH=${BASH_REMATCH[3]}

pushd $SCRIPT_DIR/../..

sr_xmllike "<version>.*</version>" "<version>^$VERSION</version>" Mod\ Files/data/hyperspace.xml
sr_xmllike "(<mod:findName\\b.*?\\bname=\"version\".*?>(?:\\n|\\s)+<mod:setValue>\\\\1\\s+\\(.*?)[^\\s]+(\\)</mod:setValue>\\n</mod:findName>)" "\\g<1>$VERSION\\g<2>" Mod\ Files/data/text*.xml*
sr_xmllike "(<version><!\\[CDATA\\[ ).*?( \\]\\]></version>)" "\\g<1>$VERSION\\g<2>" Mod\ Files/mod-appendix/metadata.xml

sed -E -i \
    -e "s/#define\\s+HS_VER_MAJOR\\s+.*/#define HS_VER_MAJOR $VERSION_MAJOR/g" \
    -e "s/#define\\s+HS_VER_MINOR\\s+.*/#define HS_VER_MINOR $VERSION_MINOR/g" \
    -e "s/#define\\s+HS_VER_PATCH\\s+.*/#define HS_VER_PATCH $VERSION_PATCH/g" \
    HSVersion.h

popd
