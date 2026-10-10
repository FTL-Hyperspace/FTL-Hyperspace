# Building on macOS

## Setup

From the repository root, run once:

```sh
buildscripts/ci/setup-macos.sh
```

It installs the build tools that are missing through Homebrew (cmake, ninja, lld, swig, and Lua with `lpeg` and `lfs`), and clones and bootstraps vcpkg into `vcpkg/`. Tools you already have are left as they are.

## Building

```sh
buildscripts/darwin-1.6.13/build-releaseonly.sh
```

The first build takes a while because vcpkg compiles the dependencies; later builds are quick. The result is `build-darwin-1.6.13-release/Hyperspace.1.6.13.amd64.dylib`.

| Script | Builds |
|---|---|
| `buildscripts/darwin-1.6.13/build-releaseonly.sh` | FTL 1.6.13, release |
| `buildscripts/darwin-1.6.13/build-debugonly.sh` | FTL 1.6.13, debug with tests |
| `buildscripts/darwin-1.6.12/build-releaseonly.sh` | FTL 1.6.12, release |
| `buildscripts/darwin-1.6.12/build-debugonly.sh` | FTL 1.6.12, debug with tests |
| `buildscripts/buildall-darwin.sh` | all of the above |
| `buildscripts/buildall-darwin-release-only.sh` | both releases |

Hyperspace for macOS is an x86_64 build, on Apple Silicon too.

## Windows and Linux builds

With [Docker Desktop](https://www.docker.com/products/docker-desktop/) running, a Mac can build the Windows and Linux versions too:

```sh
buildscripts/windows/build-releaseonly-from-docker.sh
buildscripts/linux-1.6.13/build-releaseonly-from-docker.sh
```

On Apple Silicon the Docker image runs under emulation, which is slower.
