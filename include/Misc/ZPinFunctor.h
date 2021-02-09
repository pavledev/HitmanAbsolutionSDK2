#pragma once

#include "ZVariantRef.h"

struct ZPinFunctor
{
    void* pfInvoke;
    void* func;

    //void(__cdecl* pfInvoke)(void(__thiscall*)(void), void*, ZVariantRef*, unsigned int);
    //void(__thiscall* func)();

    //void(__cdecl* pfInvoke)(void(__thiscall*)(ZGenericMemberFunctionTarget* this), ZGenericMemberFunctionTarget*, ZVariantRef*, unsigned int);
    //void(__thiscall* func)(ZGenericMemberFunctionTarget* this);
};
