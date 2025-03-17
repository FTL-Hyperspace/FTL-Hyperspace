import subprocess
import sys

def main(new_version):
    subprocess.run(['git', 'tag', f'v{new_version}'], check=True)
    subprocess.run(['git', 'push', 'origin', f'v{new_version}'], check=True)

if __name__ == '__main__':
    if len(sys.argv) > 1:
        main(sys.argv[1])
    else:
        main(input(f'enter new version(without prefix "v". e.g. 1.2.3)>>>'))