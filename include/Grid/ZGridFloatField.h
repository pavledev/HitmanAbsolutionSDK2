#pragma once

#include "TArray.h"

class ZGridFloatField
{
public:
    int m_nRefCount;
    float m_fInitialValue;
    TArray<float> m_field;
};
