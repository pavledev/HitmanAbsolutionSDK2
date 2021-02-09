#pragma once

#include "TArray.h"

class ZGridByteField
{
public:
    int m_nRefCount;
    char m_nInitialValue;
    TArray<signed char> m_field;
};
