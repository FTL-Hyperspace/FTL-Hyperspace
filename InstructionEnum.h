#ifndef INSTRUCTIONENUM_H_INCLUDED
#define INSTRUCTIONENUM_H_INCLUDED

#if defined(__i386__)
enum ProcessorInstruction : uint8_t {
    NOP = 0x90
};
#elif defined(__amd64__)
enum ProcessorInstruction : uint8_t {
    NOP = 0x90
};
#else
    #error "Unsupported architecture"
#endif // CPU Architecture

#endif // INSTRUCTIONENUM_H_INCLUDED
