#pragma once

template <class T> struct THashSetNode;

template <class T>
struct SHashSetInfo
{
    unsigned int m_nBuckets;
    int* m_pBuckets;
    THashSetNode<T>* m_pNodes;

    SHashSetInfo() = default;
    ~SHashSetInfo() = default;
};
