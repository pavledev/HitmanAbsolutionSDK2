#pragma once

#include "SHashMapInfo.h"

template <class A, class B, class C>
class TMultiHashMap
{
public:
    unsigned int m_nSize;
    int m_iFree;
    SHashMapInfo<A const, B> m_info;

    TMultiHashMap() = default;
    ~TMultiHashMap() = default;
};
