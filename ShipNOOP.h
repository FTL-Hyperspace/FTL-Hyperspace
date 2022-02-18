#ifndef SHIPNOOP_H_INCLUDED
#define SHIPNOOP_H_INCLUDED

#include "InstructionEnum.h"
#include "PALMemoryProtection.h"

static void doNOOP(uintptr_t ptrToCode, const unsigned int noopingLength);

static void doNOOP(uintptr_t ptrToCode, const unsigned int noopingLength)
{
    const unsigned int noopingSkip = 4;
    //printf("POINTER LOCATION: %08x\n", ptrToCode);
    ptrToCode += noopingSkip;
    //printf("POINTER LOCATION AFTER SKIP: %08x\n", ptrToCode);
    const size_t noopingSize = sizeof(uintptr_t) * noopingLength;
    MEMPROT_SAVE_PROT(dwOldProtect);
    MEMPROT_PAGESIZE();
    MEMPROT_UNPROTECT(ptrToCode, noopingSize, dwOldProtect);
    for(unsigned int i = 0; i < noopingLength; i++)
    {
        *(uint8_t*)(ptrToCode++) = ProcessorInstruction::NOP;
    }
    MEMPROT_REPROTECT(ptrToCode, noopingSize, dwOldProtect);
}

static void Ship__SetupNOOP()
{
    // OnInit NOOP blocks
#if defined(__linux__) && defined(__i386__)
    doNOOP(Global__NOP__Ship_OnInit_0, 8);
    doNOOP(Global__NOP__Ship_OnInit_1, 3);
    doNOOP(Global__NOP__Ship_OnInit_2, 3);
    doNOOP(Global__NOP__Ship_OnInit_3, 8);
    doNOOP(Global__NOP__Ship_OnInit_4, 3);
    doNOOP(Global__NOP__Ship_OnInit_5, 3);
#elif defined(_WIN32) && defined(__i386__)
    doNOOP(Global__NOP__Ship_OnInit_0, 8);
    doNOOP(Global__NOP__Ship_OnInit_1, 8);
    doNOOP(Global__NOP__Ship_OnInit_2, 8);
    doNOOP(Global__NOP__Ship_OnInit_3, 8);
#else
#endif // architecture diffs
}

#endif // SHIPNOOP_H_INCLUDED
