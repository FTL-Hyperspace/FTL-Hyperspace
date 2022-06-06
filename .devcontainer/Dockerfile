FROM ubuntu:latest

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
RUN apt install -y --no-install-recommends g++-4.8-multilib \
    && mkdir -p /usr/gcc-4.8-clang-toolchain/lib/gcc/x86_64-linux-gnu \
    && cd /usr/gcc-4.8-clang-toolchain \
    && ln -s /usr/include include \
    && ln -s /usr/bin bin \
    && cd lib/gcc/x86_64-linux-gnu \
    && ln -s /usr/lib/gcc/x86_64-linux-gnu/4.8 4.8

# Setup Windows toolchain
RUN apt install -y --no-install-recommends g++-mingw-w64-i686-win32

# TODO: vcpkg-fy
# RUN apt install -y --no-install-recommends libboost-all-dev lua5.3 luarocks liblua5.3-dev libsdl2-dev:i386 libsdl2-dev

# Setup vcpkg
RUN cd / \
    && git clone https://github.com/microsoft/vcpkg \
    && cd /vcpkg \
    && ./bootstrap-vcpkg.sh \
    && ln -s /vcpkg/vcpkg /usr/bin/vcpkg
COPY triplets/* /vcpkg/triplets/
COPY toolchains/* /vcpkg/scripts/toolchains/

# Workaround for boost
RUN ln -s /usr/bin/clang-10 /usr/bin/clang && ln -s /usr/bin/clang++-10 /usr/bin/clang++

# Workaround for SDL2
RUN ln -s /usr/gcc-4.8-clang-toolchain/include/asm-generic /usr/gcc-4.8-clang-toolchain/include/asm

# TODO: Add
# RUN rm -rf /var/lib/apt/lists/*

ENV DEBIAN_FRONTEND=
