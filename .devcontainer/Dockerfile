FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive

RUN echo deb http://dk.archive.ubuntu.com/ubuntu/ xenial main >> /etc/apt/sources.list \
    && echo deb http://dk.archive.ubuntu.com/ubuntu/ xenial universe >> /etc/apt/sources.list \
    && dpkg --add-architecture i386 \
    && apt update \
    && apt install -y --no-install-recommends git cmake ninja-build g++-4.8-multilib clang-10 libboost-all-dev \
        lua5.3 luarocks liblua5.3-dev libsdl2-dev:i386 libsdl2-dev \
    && rm -rf /var/lib/apt/lists/*

# Setup Linux toolchain
RUN mkdir -p /usr/gcc-4.8-clang-toolchain/lib/gcc/x86_64-linux-gnu \
    && cd /usr/gcc-4.8-clang-toolchain \
    && ln -s /usr/include include \
    && ln -s /usr/bin bin \
    && cd lib/gcc/x86_64-linux-gnu \
    && ln -s /usr/lib/gcc/x86_64-linux-gnu/4.8 4.8

ENV DEBIAN_FRONTEND=
