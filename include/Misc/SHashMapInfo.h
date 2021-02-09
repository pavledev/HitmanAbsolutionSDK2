#pragma once

#include "THashMapNode.h"

template<class A, class B>
struct SHashMapInfo
{
    unsigned int m_nBuckets;
    int* m_pBuckets;
    THashMapNode<A, B>* m_pNodes;
};
