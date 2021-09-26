#pragma once

#include "TIterator.h"

template <class A, class B> class TPair;
template <class A, class B> struct SHashMapInfo;
template <class A, class B> struct THashMapNode;

template <class A, class B>
class THashMapIterator : public TIterator<TPair<A, B>>
{
public:
	SHashMapInfo<A, B>* m_info;
	unsigned int m_nBucket;

    THashMapIterator() = default;
    ~THashMapIterator() = default;

    THashMapNode<A, B>* Node()
    {
        return reinterpret_cast<THashMapNode<A, B>*>(this->m_pCurrent - 1);
    }
};
