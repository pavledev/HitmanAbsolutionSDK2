#pragma once

#include "TPair.h"

template<class A, class B>
class THashMapNode
{
public:
    int m_iNext;
    TPair<A, B> m_data;
};
