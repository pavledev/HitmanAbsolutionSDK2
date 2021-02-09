#pragma once

#include "TIterator.h"

template<class T>
class TBinaryTreeIterator : public TIterator<T>
{
public:
    TBinaryTreeNode<T>* Node()
    {
        T* val = this->m_pCurrent - 1;

        return reinterpret_cast<TBinaryTreeNode<T>*>(val);
    }
};
