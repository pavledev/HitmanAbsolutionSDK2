#pragma once

#include "TIterator.h"
#include "TPair.h"
#include "SHashMapInfo.h"

template<class A, class B>
class THashMapIterator : public TIterator<TPair<A, B>>
{
public:
	SHashMapInfo<A, B>* m_info;
	unsigned int m_nBucket;

    THashMapNode<A, B>* Node()
    {
        return reinterpret_cast<THashMapNode<A, B>*>(this->m_pCurrent - 1);
    }
};
