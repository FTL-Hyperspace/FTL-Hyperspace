import subprocess
import sys

# Creates a new tag and pushes it to the remote repository
# After that the release ci will automatically create a new release on github
# Usage: python tag_release.py <new_version> (e.g. python tag_release.py 1.2.3)
def main(new_version):
    if new_version[0] == 'v':
        new_version = new_version[1:]
    subprocess.run(['git', 'tag', f'v{new_version}'], check=True)
    subprocess.run(['git', 'push', 'origin', f'v{new_version}'], check=True)

if __name__ == '__main__':
    if len(sys.argv) > 1:
        main(sys.argv[1])
    else:
        main(input(f'enter new version(e.g. 1.2.3)>>>'))