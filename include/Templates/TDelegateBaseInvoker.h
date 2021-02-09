#pragma once

#include "ZVariant.h"
#include "TArrayRef.h"
#include "ZVariantRef.h"

template<class T>
struct TDelegateBaseInvoker
{
    unsigned int argCount;
    ZVariant* (__cdecl* pfInvoke)(ZVariant* result, void*, const TArrayRef<ZVariantRef>*);
    STypeID* retType;
    STypeID* a0Type;
};
