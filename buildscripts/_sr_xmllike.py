import re
import sys

'''
USAGE: _sr_xmllike search replace filename...
Search & replace on XML-like text (not need to be valid) except for the comment sections.
'''

COMMENT_RE = r'<!--(?:.|\n)*?-->'
PATTERN, REPLACE = sys.argv[1], sys.argv[2]
FILES = sys.argv[3:]

for file in FILES:
    with open(file, encoding='utf-8') as fr:
        content = fr.read()

    new_content = ""
    ptr = 0

    for match in re.finditer(COMMENT_RE, content):
        s, e = match.span()
        new_content += re.sub(PATTERN, REPLACE, content[ptr:s])
        new_content += match.group(0)
        ptr = e
    new_content += re.sub(PATTERN, REPLACE, content[ptr:])

    with open(file, 'w', encoding='utf-8') as fr:
        fr.write(new_content)
