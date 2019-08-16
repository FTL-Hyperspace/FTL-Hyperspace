
#define ASM_HOOK __declspec(naked) void

void JMP(BYTE *pAddress, DWORD dwJumpTo, DWORD dwLen);
void NOP(DWORD instruction, DWORD dwLen);
void WriteByte(void *pAddress, BYTE val);



class ASMHook
{
public:
    ASMHook(BYTE* offset, int bytes, ASM_HOOK(*funcTo)(), BYTE* pathOffset = 0);
    BYTE* _address;
    BYTE* _address2;
    int _size;

private:
    BYTE* _offset;
    ASM_HOOK(*_funcTo)();
};







#define HOOK_ASM_0(_name, _offset, _bytes, _type, _pathOffset) \
namespace Hook_##_name { \
    static ASM_HOOK hook(); \
    static auto toCall _type; \
    static ASMHook hookObj = ASMHook((BYTE*)_offset, _bytes, &hook, (BYTE*)_pathOffset); \
    static void* func = (void*)&toCall; \
} \
auto Hook_##_name::toCall _type

#define HOOK_ASM_PATH(_name, _offset, _bytes, _type, _pathOffset) \
    HOOK_ASM_0(_name, _offset, _bytes, _type, _pathOffset)

#define HOOK_ASM(_name, _offset, _bytes, _type) \
    HOOK_ASM_0(_name, _offset, _bytes, _type, 0)

#define STRINGIFY2(X) #X
#define STRINGIFY(X) STRINGIFY2(X)
#define A 2
#define DEFINE_ASM(_name) \
ASM_HOOK Hook_##_name::hook()

#define HOOK_TO func
#define JMP_TO hookObj._address
#define JMP_TO2 hookObj._address2


