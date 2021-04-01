#pragma once
#include "FTLGame.h"

struct Store_Extend
{
    Store *orig;


    ~Store_Extend()
    {

    }
};

Store_Extend* Get_Store_Extend(Store* c);

#define STORE_EX Get_Store_Extend
