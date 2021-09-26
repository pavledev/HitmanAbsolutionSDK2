#pragma once

#include "TBlockArrayInfo.h"

template <class T>
class TBlockArray
{
public:
    TBlockArrayInfo<T> m_info;

    TBlockArray() = default;
    ~TBlockArray() = default;
};
