#pragma once

#include "SHashSetInfo.h"

template <class A, class B>
class THashSet
{
public:
    bool m_bFixed;
    unsigned int m_nSize;
    int m_iFree;
    SHashSetInfo<A const> m_info;

    THashSet() = default;
    ~THashSet() = default;
};
