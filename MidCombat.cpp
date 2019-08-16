#include "Global.h"
#include "ASMHooks.h"
#include "rapidxml.hpp"

/*
HOOK_ASM(ProcessShipEventMidCombat, 0x001BFED4, 0x8, (rapidxml::xml_node<char>* node) -> void)
{
    //printf("%s\n", node->name());
}

DEFINE_ASM(ProcessShipEventMidCombat)
{
    __asm__(

            "push eax;"
            "push ebx;"
            "push ecx;"
            "push edx;"
            "push esi;"
            "call %0;"
            "pop esi;"
            "pop edx;"
            "pop ecx;"
            "pop ebx;"
            "pop eax;"

            "mov DWORD PTR [esp+8], 1;"

            "jmp %1" :: "m"(HOOK_TO), "m"(JMP_TO)

            );
}


HOOK_METHOD(EventsParser, ProcessEvent, (rapidxml::xml_node<char>* node, std::string& event, EventTemplate& eventref) -> void**)
{
    auto ret = super(node, event, unk);
    printf()
    return ret;
}
*/
