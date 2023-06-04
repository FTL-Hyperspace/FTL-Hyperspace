/**
 * Mologie Detours
 * Copyright (c) 2011 Oliver Kuckertz <oliver.kuckertz@mologie.de>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @file	hde.h
 *
 * @brief	Includes the 32 or 64 bit version of HDE
 */

#ifndef INCLUDED_LIB_MOLOGIE_DETOURS_HDE_H
#define INCLUDED_LIB_MOLOGIE_DETOURS_HDE_H

#if (defined(_M_IX86) || defined(___i386__) || defined(__i386) || defined(__X86__) || defined(_X86_) || defined(__I86__))
#  define MOLOGIE_DETOURS_HDE_32
#  define T_HDE hde32s
#  define HDE_DISASM hde32_disasm
#  include "hde32/include/hde32.h"
#elif (defined(_M_X64) || defined(__x86_64__) || defined(__amd64__)) // TODO: Add more predefined macros for more compilers
#  define MOLOGIE_DETOURS_HDE_64
#  define T_HDE hde64s
#  define HDE_DISASM hde64_disasm
#  include "hde64/include/hde64.h"
#else
#  error Mologie Detours: Unknown architecture
#endif

#endif // !INCLUDED_LIB_MOLOGIE_DETOURS_HDE_H
