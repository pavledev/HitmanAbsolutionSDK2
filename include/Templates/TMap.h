#pragma once

#include "TRedBlackTree.h"
#include "TPair.h"
#include "TMapKeyEnumerator.h"
#include "TBinaryTreeIterator.h"
#include "Function.h"
#include "BaseAddresses.h"

template<class A, class B>
class TMap
{
public:
    TRedBlackTree<TPair<A const, B>> m_container;

    TBinaryTreeIterator<TPair<A const, B>> Begin()
    {
        TPair<A const, B>* pair;
        TBinaryTreeIterator<TPair<A const, B>> binaryTreeIterator;

        if (this->m_container.m_tree.m_pLeftRoot)
        {
            pair = &TBinaryTreeNode<TPair<A const, B>>::GetNextNode((TBinaryTreeNode<TPair<A const, B>>*)this)->m_data;
            binaryTreeIterator.m_pCurrent = pair;
        }
        else
        {
            binaryTreeIterator.m_pCurrent = (TPair<A const, B>*) & this->m_container.m_nSize;
        }

        return binaryTreeIterator;
    }

    TBinaryTreeIterator<TPair<A const, B>> End()
    {
        TBinaryTreeIterator<TPair<A const, B>> binaryTreeIterator;
        binaryTreeIterator.m_pCurrent = (TPair<A const, B>*) & this->m_container.m_nSize;

        return binaryTreeIterator;
    }
};
