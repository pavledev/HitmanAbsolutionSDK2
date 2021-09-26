#pragma once

#include "SHashMapInfo.h"
#include "THashMapIterator.h"

template <class A, class B> class TPair;

template <class A, class B, class C>
class THashMap
{
public:
    unsigned int m_nSize;
    int m_iFree;
    SHashMapInfo<A const, B> m_info;

    THashMap() = default;
    ~THashMap() = default;

    THashMapIterator<A, B> Begin()
    {
        unsigned int buckets;
        SHashMapInfo<A const, B>* hashMapInfo;
        unsigned int bucket;
        int* i;
        THashMapIterator<A, B>* hashMapIterator;
        int index;
        TPair<A, B>* pair;

        buckets = this->m_info.m_nBuckets;
        hashMapInfo = &this->m_info;
        bucket = 0;

        if (!buckets)
        {
            hashMapIterator->m_info = hashMapInfo;
            hashMapIterator->m_pCurrent = 0;
            hashMapIterator->m_nBucket = bucket;
        }

        for (i = this->m_info.m_pBuckets; *i == -1; ++i)
        {
            if (++bucket >= buckets)
            {
                hashMapIterator->m_info = hashMapInfo;
                hashMapIterator->m_pCurrent = 0;
                hashMapIterator->m_nBucket = bucket;

                return hashMapIterator;
            }
        }

        index = this->m_info.m_pBuckets[bucket];

        if (index != -1)
        {
            pair = &this->m_info.m_pNodes[index].m_data;

            hashMapIterator->m_info = hashMapInfo;
            hashMapIterator->m_pCurrent = pair;
            hashMapIterator->m_nBucket = bucket;
        }
        else
        {
            hashMapIterator->m_info = hashMapInfo;
            hashMapIterator->m_pCurrent = 0;
            hashMapIterator->m_nBucket = bucket;
        }

        return hashMapIterator;
    }

    THashMapIterator<A, B> End()
    {
        THashMapIterator<A, B> hashMapIterator;

        hashMapIterator->m_pCurrent = 0;
        hashMapIterator->m_info = &this->m_info;
        hashMapIterator->m_nBucket = -1;

        return hashMapIterator;
    }

    unsigned int Size()
    {
        return this->m_nSize;
    }
};
