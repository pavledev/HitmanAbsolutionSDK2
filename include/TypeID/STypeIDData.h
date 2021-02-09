#pragma once

#include "STypeID.h"

struct STypeIDData
{
    STypeID id;
    const char* (__cdecl* pFunc)(STypeID*);
};
