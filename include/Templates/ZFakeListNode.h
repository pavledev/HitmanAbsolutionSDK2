#pragma once

#include "TListNode.h"

template<class T>
struct ZFakeListNode
{
    TListNode<T>* m_pFirst;
    TListNode<T>* m_pLast;
};
