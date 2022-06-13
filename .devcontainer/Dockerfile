# 1st image: Build mingw-w64 for Windows with modified configurations
FROM ubuntu:focal

ENV DEBIAN_FRONTEND=noninteractive
COPY mingw.patch /mingw-build/

# Fetch build tools and deps
RUN sed -Ei 's/^# deb-src /deb-src /' /etc/apt/sources.list \
    && apt update \
    && apt install -y --no-install-recommends build-essential dpkg-dev devscripts locales \
    && ln -s /usr/bin/autoconf /usr/bin/autoconf2.69 \
    && ln -s /usr/bin/autom4te /usr/bin/autom4te2.69 \
    && (LC_ALL=en_US.UTF-8 LANGUAGE=en_US.UTF-8 locale-gen en_US.UTF-8) \
    && apt build-dep -y g++-mingw-w64-i686

# Fetch source
RUN mkdir -p /mingw-build/mingw-dwarf2-build \
    && cd /mingw-build/mingw-dwarf2-build \
    && apt source g++-mingw-w64-i686

# Patch .deb buildscripts and build
RUN cd /mingw-build/mingw-dwarf2-build \
    && patch -p1 -s < /mingw-build/mingw.patch \
    && cd gcc-mingw-w64-22~exp1ubuntu4 \
    && debuild -b -uc -us

# 2nd image: devcontainer
FROM ubuntu:focal

ENV DEBIAN_FRONTEND=noninteractive

RUN echo deb http://dk.archive.ubuntu.com/ubuntu/ xenial main >> /etc/apt/sources.list \
    && echo deb http://dk.archive.ubuntu.com/ubuntu/ xenial universe >> /etc/apt/sources.list \
    && dpkg --add-architecture i386 \
    && apt update

# Install common build tools
RUN apt install -y --no-install-recommends ca-certificates curl zip unzip tar git ninja-build clang-10 pkg-config

# Setup CMake
RUN cd /usr/local \
    && (curl -sL https://github.com/Kitware/CMake/releases/download/v3.23.2/cmake-3.23.2-linux-x86_64.sh) \
    > /tmp/cmakeinstall.sh \
    && bash /tmp/cmakeinstall.sh --skip-license

# Setup Linux toolchain
# (See https://github.com/FTL-Hyperspace/FTL-Hyperspace/blob/master/BUILDING.LINUX.md#compiling-requires-llvm-clang)
RUN apt install -y --no-install-recommends g++-4.8-multilib \
    && mkdir -p /usr/gcc-4.8-clang-toolchain/lib/gcc/x86_64-linux-gnu \
    && cd /usr/gcc-4.8-clang-toolchain \
    && ln -s /usr/include include \
    && ln -s /usr/bin bin \
    && cd lib/gcc/x86_64-linux-gnu \
    && ln -s /usr/lib/gcc/x86_64-linux-gnu/4.8 4.8

# Setup Windows toolchain (Powershell is required for Windows build when vcpkg is involved)
COPY --from=0 /mingw-build/mingw-dwarf2-build/*.deb /mingw-build/mingw-dwarf2-build/
RUN (curl -sL \
    https://github.com/PowerShell/PowerShell/releases/download/v7.2.4/powershell-lts_7.2.4-1.deb_amd64.deb) \
    > /tmp/pwsh.deb \
    && apt install -y --no-install-recommends /mingw-build/mingw-dwarf2-build/*.deb /tmp/pwsh.deb \
    && pwsh -Command "Write-Output 'Powershell installed successfully.'"

# TODO: vcpkg-fy
# RUN apt install -y --no-install-recommends lua5.3 luarocks liblua5.3-dev

# Setup vcpkg
RUN cd / \
    && git clone https://github.com/microsoft/vcpkg \
    && cd /vcpkg \
    && ./bootstrap-vcpkg.sh \
    && ln -s /vcpkg/vcpkg /usr/bin/vcpkg
COPY triplets/* /vcpkg/triplets/
COPY toolchains/* /vcpkg/scripts/toolchains/

# Workarounds for boost
RUN ln -s /usr/bin/clang-10 /usr/bin/clang && ln -s /usr/bin/clang++-10 /usr/bin/clang++

# Workarounds for SDL2
RUN ln -s /usr/gcc-4.8-clang-toolchain/include/asm-generic /usr/gcc-4.8-clang-toolchain/include/asm

# TODO: Add
# RUN rm -rf /var/lib/apt/lists/*

ENV DEBIAN_FRONTEND=
