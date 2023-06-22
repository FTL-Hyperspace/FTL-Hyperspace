#!/usr/bin/python3

import os
import zipfile

if __name__ == '__main__':
    archiveName = 'Hyperspace.ftl'
    archiveDir = 'Mod Files/'
    with zipfile.ZipFile(archiveName, 'w', zipfile.ZIP_DEFLATED) as modZip:
        for root, dirs, files in os.walk(archiveDir):
            for file in files:
                fname = os.path.basename(file)
                if not (fname == archiveName or fname == os.path.basename(__file__)):
                    filePath = os.path.join(root, file)
                    archPath = os.path.relpath(filePath[len(archiveDir):], os.path.join(archiveDir, '..'))
                    modZip.write(filePath, archPath)
    os.replace(archiveName, archiveDir + archiveName)
