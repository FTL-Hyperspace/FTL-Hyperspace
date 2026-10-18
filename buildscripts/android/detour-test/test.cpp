// Unit test for Arm64Detour: functions whose first instruction is each PC-relative kind.
#include "Arm64Detour.h"
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>

extern "C" {
long f_plain(long);      // add x0, x0, #1 first
long f_adrp(long);       // adrp first
long f_adr(long);        // adr first
long f_b(long);          // b first (thunk)
long f_bl(long);         // bl first
long f_cbz(long);        // cbz first
long f_tbnz(long);       // tbnz first
long f_bcond(long);      // b.eq first
long f_ldrlit(long);     // ldr x literal first
long f_ldrw(long);       // ldr w literal first
double f_ldrd(double);   // ldr d literal first
long helper(long x) { return x * 10; }
long data_word = 4242;
}
asm(R"(
.text
.p2align 4
.globl f_plain
f_plain: add x0, x0, #1
 ret
.p2align 4
.globl f_adrp
f_adrp: adrp x1, data_word
 add x1, x1, :lo12:data_word
 ldr x1, [x1]
 add x0, x0, x1
 ret
.p2align 4
.globl f_adr
f_adr: adr x1, 1f
 ldr x1, [x1]
 add x0, x0, x1
 ret
1: .quad 7
.p2align 4
.globl f_b
f_b: b helper
.p2align 4
.globl f_bl
f_bl: bl helper2
 add x0, x0, #3
 ret
helper2: add x0, x0, #100
 ret
.p2align 4
.globl f_cbz
f_cbz: cbz x0, 1f
 mov x0, #11
 ret
1: mov x0, #22
 ret
.p2align 4
.globl f_tbnz
f_tbnz: tbnz x0, #0, 1f
 mov x0, #33
 ret
1: mov x0, #44
 ret
.p2align 4
.globl f_bcond
f_bcond: cmp x0, #5
 b.eq 1f
 mov x0, #55
 ret
1: mov x0, #66
 ret
)");
asm(R"(
.text
.p2align 4
.globl f_ldrlit
f_ldrlit: ldr x1, 1f
 add x0, x0, x1
 ret
1: .quad 1000
.p2align 4
.globl f_ldrw
f_ldrw: ldr w1, 1f
 add x0, x0, x1
 ret
1: .word 77
.p2align 4
.globl f_ldrd
f_ldrd: ldr d1, 1f
 fadd d0, d0, d1
 ret
1: .double 0.5
)");

// A constructor in Apple's arm64 ABI returns `this`, and its caller may keep using x0.
// f_ctor stores 5 at this[0] and returns this; f_ctor_caller calls it, then stores 9 at
// x0[1] without saving `this` itself, the way the game's derived constructors do.
asm(R"(
.text
.p2align 4
.globl f_ctor
f_ctor: mov x1, #5
 str x1, [x0]
 ret
.p2align 4
.globl f_ctor_caller
f_ctor_caller: stp x29, x30, [sp, #-16]!
 mov x29, sp
 bl f_ctor
 mov x1, #9
 str x1, [x0, #8]
 ldp x29, x30, [sp], #16
 ret
)");
extern "C" void *f_ctor(long *self);
extern "C" void f_ctor_caller(long *self);
static void (*orig_ctor)(long *);
static long g_ctorSeen;

// Hyperspace's hooks on constructors return void and leave x0 to chance
__attribute__((noinline)) static void h_ctor(long *self)
{
    orig_ctor(self);
    g_ctorSeen = self[0];
    asm volatile("mov x0, #0" ::: "x0");
}

typedef long (*lf)(long);
static lf orig[16];
#define HOOK(N, I) static long h_##N(long x) { return orig[I](x) + 1000000; }
HOOK(plain, 0)
HOOK(adrp, 1)
HOOK(adr, 2)
HOOK(b, 3)
HOOK(bl, 4)
HOOK(cbz, 5)
HOOK(tbnz, 6)
HOOK(bcond, 7)
HOOK(ldrlit, 8)
HOOK(ldrw, 9)
static double (*orig_d)(double);
static double h_ldrd(double x) { return orig_d(x) * 2; }
static long h_plain2(long x) { return orig[10](x) + 5; }  // a second hook on f_plain, chained

static int fails;

static void check(const char *what, long got, long want)
{
    printf("%-22s got %ld want %ld %s\n", what, got, want, got == want ? "ok" : "FAIL");
    if (got != want)
        fails++;
}

static void *hook(const char *what, void *function, void *hook, int flags)
{
    char err[256];
    printf("hooking %s\n", what);
    void *original = Arm64Detour::Hook(function, hook, flags, err, sizeof err);
    if (!original)
    {
        printf("hooking %s failed: %s\n", what, err);
        exit(1);
    }
    return original;
}

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    struct { const char *name; void *function, *hook; } hooks[] = {
        {"plain", (void *)f_plain, (void *)h_plain},
        {"adrp", (void *)f_adrp, (void *)h_adrp},
        {"adr", (void *)f_adr, (void *)h_adr},
        {"b", (void *)f_b, (void *)h_b},
        // A function that starts with BL can't return (its LR is gone), so f_bl is only
        // hooked, to relocate a BL, and never called
        {"bl", (void *)f_bl, (void *)h_bl},
        {"cbz", (void *)f_cbz, (void *)h_cbz},
        {"tbnz", (void *)f_tbnz, (void *)h_tbnz},
        {"bcond", (void *)f_bcond, (void *)h_bcond},
        {"ldrlit", (void *)f_ldrlit, (void *)h_ldrlit},
        {"ldrw", (void *)f_ldrw, (void *)h_ldrw},
    };
    for (int i = 0; i < 10; i++)
        orig[i] = (lf)hook(hooks[i].name, hooks[i].function, hooks[i].hook, 0);
    orig_d = (double (*)(double))hook("ldrd", (void *)f_ldrd, (void *)h_ldrd, 0);
    orig[10] = (lf)hook("plain again", (void *)f_plain, (void *)h_plain2, 0);
    orig_ctor = (void (*)(long *))hook("ctor", (void *)f_ctor, (void *)h_ctor, Arm64Detour::KeepThis);

    long obj[2] = {0, 0};
    f_ctor_caller(obj);
    check("keep this: hook ran", g_ctorSeen, 5);
    check("keep this: caller's x0", obj[1], 9);
    check("plain (chained)", f_plain(1), 2 + 1000000 + 5);
    check("adrp", f_adrp(1), 4243 + 1000000);
    check("adr", f_adr(1), 8 + 1000000);
    check("b", f_b(2), 20 + 1000000);
    check("cbz taken", f_cbz(0), 22 + 1000000);
    check("cbz not taken", f_cbz(1), 11 + 1000000);
    check("tbnz taken", f_tbnz(1), 44 + 1000000);
    check("tbnz not taken", f_tbnz(2), 33 + 1000000);
    check("b.eq taken", f_bcond(5), 66 + 1000000);
    check("b.eq not taken", f_bcond(4), 55 + 1000000);
    check("ldr x literal", f_ldrlit(1), 1001 + 1000000);
    check("ldr w literal", f_ldrw(1), 78 + 1000000);
    check("ldr d literal", (long)(f_ldrd(1.0) * 10), 30);
    printf(fails ? "FAILED %d\n" : "all passed\n", fails);
    return fails != 0;
}
