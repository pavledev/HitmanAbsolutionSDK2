#pragma once

#include "THashSetNode.h"

template<class T>
struct SHashSetInfo
{
    unsigned int m_nBuckets;
    int* m_pBuckets;
    THashSetNode<T>* m_pNodes;
};
