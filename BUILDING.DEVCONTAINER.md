## Building on vscode devcontainer 

Open the directory using vscode w/ Remote Container extension enabled and active.

Use `CMake: Select a Kit` for platform target, and `CMake: Select a Variant` for Debug/Release configuration.
Then use `CMake: Build` to build it.

Currently support for debugging is incomplete. IntelliSense should only work when you're building Linux targets.

## Manually building without vscode

Requires Docker.

1. Ensure that your current working directory is the repository's root directory.
     - For example, if your repository is at `/home/$USER`, then your current working directory should be `/home/$USER/FTL-Hyperspace`
2. `docker run -it --rm -v $PWD:/ftl ghcr.io/ftl-hyperspace/hs-devcontainer`
  * (`$PWD` may vary by your shell, e.g. if it's cmd then use `%cd%` instead)
  * If you want to build the image by yourself (e.g., changed the .devcontainer directory),
    build and run the image using following command:
    ```
    docker buildx build --load --build-arg BUILDKIT_INLINE_CACHE=1 -f .devcontainer/Dockerfile-actual -t my-hs-devcontainer .devcontainer
    docker run -it --rm -v $PWD:/ftl my-hs-devcontainer
    ```

3. `cd /ftl`

4. Configure with CMake. The exact command should depend on what build you're targeting. For example, Linux Release build for FTL 1.6.13 is:
```
cmake -DCMAKE_TOOLCHAIN_FILE=/vcpkg/scripts/buildsystems/vcpkg.cmake \
    -DVCPKG_HOST_TRIPLET=amd64-linux-ftl \
    -DVCPKG_TARGET_TRIPLET=amd64-linux-ftl \
    -DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=/vcpkg/scripts/toolchains/amd64-linux-ftl.cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DSTEAM_1_6_13_BUILD=ON \
    -S . -B build -G Ninja
```
  * Change `amd64-linux-ftl` to `x86-windows-ftl` and `amd64-linux-ftl.cmake` to `x86-windows-ftl.cmake` to configure a Windows build.
  * (Linux only) `-DSTEAM_1_6_13_BUILD=ON` if the target binary is FTL 1.6.13. Use `-DSTEAM_1_6_13_BUILD=OFF` instead to target FTL 1.6.12. On Windows this option does nothing and can be omitted.
  * `-DCMAKE_BUILD_TYPE=Release` controls if it's a `Debug` or a `Release` build. Theoretically you may specify `RelWithDebInfo` or `MinSizeRel` as in standard CMake, but these options are not tested.
  * This command line can be inferred from the `.vscode/cmake-kits.json` file.

5. `ninja -C build`

## Utility scripts

There are number of support shell scripts:
* `buildscripts/buildall.sh`: Use it inside the container. Build every variants at once.
* `buildscripts/buildall-from-docker.bat/sh`: Use it from the host. Spawns the container and automatically runs `buildall.sh`.

## Rebuilding steps

On changing source code or CMakeFiles.txt, just redo the build.
* vscode: re-run `CMake: Build`.
* manually: redo from step 5 (`ninja`)

On changing the build target (like changing to linux build or debug build), delete `build/` directory for clean rebuild, and then redo the build.
* vscode: delete `build/` then re-run `CMake: Build`.
* manually: delete `build/` then redo from step 5 (`ninja`)

On changing the compiler toolchain files in the .devcontainer folder, you need to (re)build your container image (may take several hours). And also you delete `build/` directory for clean rebuild.
* vscode: Open `.devcontainer/devcontainer.json` then change `build.dockerfile` from `Dockerfile` to `Dockerfile-actual`. Then run `Dev Containers: Rebuild Container` command.
* manually: see additional instruction from step 2.
