#pragma once

#include "ZFakeListNode.h"

template<class T>
class TList
{
public:
    unsigned int m_nSize;
    ZFakeListNode<T> m_list;

    unsigned int Size()
    {
        return this->m_nSize;
    }
};
