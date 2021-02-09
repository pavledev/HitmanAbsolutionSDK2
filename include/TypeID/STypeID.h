#pragma once

#include "IType.h"

struct STypeID
{
    unsigned __int16 flags;
    unsigned __int16 typeNum;
    IType* pTypeInfo;
    STypeID* pSourceType;
};
