#pragma once

#include "SFakeNode.h"

template<class T>
class TSList
{
public:
    unsigned int m_nSize;
    SFakeNode<T> m_list;
};
