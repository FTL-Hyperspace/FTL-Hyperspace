#pragma once

#include "Global.h"
#include "hash-library/sha3.h"

#ifdef DEBUG
void PrintHashes();
#endif // DEBUG

#ifndef DEBUG
void CheckHashes();
#endif // DEBUG
