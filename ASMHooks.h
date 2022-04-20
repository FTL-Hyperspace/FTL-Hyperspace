
#ifdef _WIN32
#define ASM_HOOK __declspec(naked) void
#elif defined(__linux__)
#define ASM_HOOK void
#endif

void JMP(uint8_t *pAddress, uint32_t dwJumpTo, uint32_t dwLen);
void NOP(uint32_t instruction, uint32_t dwLen);
void WriteByte(void *pAddress, uint8_t val);



class ASMHook
{
public:
    ASMHook(uint8_t* offset, int bytes, ASM_HOOK(*funcTo)(), uint8_t* pathOffset = 0);
    uint8_t* _address;
    uint8_t* _address2;
    int _size;

private:
    uint8_t* _offset;
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

#define DEFINE_ASM(_name) \
ASM_HOOK Hook_##_name::hook()

#define HOOK_TO func
#define JMP_TO hookObj._address
#define JMP_TO2 hookObj._address2


