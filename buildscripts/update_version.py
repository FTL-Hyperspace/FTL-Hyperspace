import os
import sys
import re

def update_version(major, minor, patch):
    # Define the absolute file paths
    hs_version_file = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "HSVersion.h")
    hyperspace_xml_file = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "Mod Files", "data", "hyperspace.xml")
    text_de_xml_file = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "Mod Files", "data", "text-de.xml.append")
    text_misc_xml_file = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "Mod Files", "data", "text_misc.xml.append")
    metadata_xml_file = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "Mod Files", "mod-appendix", "metadata.xml")

    # Update HSVersion.h
    with open(hs_version_file, "r") as file:
        content = file.read()
    content = re.sub(r'#define HS_VER_MAJOR \d+', f'#define HS_VER_MAJOR {major}', content)
    content = re.sub(r'#define HS_VER_MINOR \d+', f'#define HS_VER_MINOR {minor}', content)
    content = re.sub(r'#define HS_VER_PATCH \d+', f'#define HS_VER_PATCH {patch}', content)
    with open(hs_version_file, "w") as file:
        file.write(content)

    # Update hyperspace.xml
    with open(hyperspace_xml_file, "r") as file:
        lines = file.readlines()
    for i, line in enumerate(lines):
        if "<version>^" in line and line.strip().endswith("</version>"):
            lines[i] = f"<version>^{major}.{minor}.{patch}</version>\n"
            break
    with open(hyperspace_xml_file, "w") as file:
        file.writelines(lines)

    # Update text-de.xml.append
    with open(text_de_xml_file, "r") as file:
        content = file.read()
    content = re.sub(r'Hyperspace \d+\.\d+\.\d+', f'Hyperspace {major}.{minor}.{patch}', content)
    with open(text_de_xml_file, "w") as file:
        file.write(content)

    # Update text_misc.xml.append
    with open(text_misc_xml_file, "r") as file:
        content = file.read()
    content = re.sub(r'Hyperspace \d+\.\d+\.\d+', f'Hyperspace {major}.{minor}.{patch}', content)
    with open(text_misc_xml_file, "w") as file:
        file.write(content)

    # Update metadata.xml
    with open(metadata_xml_file, "r") as file:
        content = file.read()
    content = re.sub(r'<version><!\[CDATA\[ \d+\.\d+\.\d+ \]\]></version>', f'<version><![CDATA[ {major}.{minor}.{patch} ]]></version>', content)
    with open(metadata_xml_file, "w") as file:
        file.write(content)

    print(f"Version updated to {major}.{minor}.{patch}")

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python update_version.py <major> <minor> <patch>")
        sys.exit(1)

    major = int(sys.argv[1])
    minor = int(sys.argv[2])
    patch = int(sys.argv[3])

    update_version(major, minor, patch)