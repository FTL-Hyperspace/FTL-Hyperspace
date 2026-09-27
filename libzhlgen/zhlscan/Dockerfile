# Build environment for the offline ZHL signature scanners.

FROM ubuntu:24.04

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        clang lld llvm cmake ninja-build git curl zip unzip tar pkg-config \
        python3 ca-certificates \
    && rm -rf /var/lib/apt/lists/*

ENV CC=clang CXX=clang++ VCPKG_FORCE_SYSTEM_BINARIES=1

RUN git clone --depth 1 https://github.com/microsoft/vcpkg /vcpkg \
    && /vcpkg/bootstrap-vcpkg.sh -disableMetrics

# Pre-build the scanner's dependencies (LIEF) into the image so that builds
# from a fresh checkout only compile the scanner itself.
COPY vcpkg.json /tmp/zhlscan/vcpkg.json
RUN cd /tmp/zhlscan && /vcpkg/vcpkg install --triplet x64-linux && rm -rf /tmp/zhlscan

WORKDIR /workspaces/FTL-Hyperspace
