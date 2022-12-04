cmake -DCMAKE_TOOLCHAIN_FILE=/vcpkg/scripts/buildsystems/vcpkg.cmake \
    -DVCPKG_HOST_TRIPLET=amd64-linux-ftl \
    -DVCPKG_TARGET_TRIPLET=amd64-linux-ftl \
    -DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=/vcpkg/scripts/toolchains/amd64-linux-ftl.cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -S . -B build-amd64-linux-ftl -G Ninja

cmake -DCMAKE_TOOLCHAIN_FILE=/vcpkg/scripts/buildsystems/vcpkg.cmake \
    -DVCPKG_HOST_TRIPLET=x86-windows-ftl \
    -DVCPKG_TARGET_TRIPLET=x86-windows-ftl \
    -DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=/vcpkg/scripts/toolchains/x86-windows-ftl.cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -S . -B build-x86-windows-ftl -G Ninja
