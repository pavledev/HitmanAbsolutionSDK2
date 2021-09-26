#pragma once

#include "Function.h"
#include "TBinaryTreeIterator.h"

template <class T> class TBinaryTreeNode;

template <class T>
class TBinaryTree
{
public:
    struct SFakeTreeNode
    {
        int m_reserved1;
        TBinaryTreeNode<T>* m_pNULL;
        TBinaryTreeNode<T>* m_pRightRoot;
        TBinaryTreeNode<T>* m_pLeftRoot;

        SFakeTreeNode() = default;
    };

    SFakeTreeNode m_tree;
    int m_nSize;

    TBinaryTree() = default;
    ~TBinaryTree() = default;

	unsigned int BeginOffset();
	unsigned int EndOffset();

    TBinaryTreeIterator<T> Begin()
    {
        return Function::CallRVOMethodAndReturn<TBinaryTreeIterator<T>, TBinaryTree*>(BeginOffset(), this);
    }

    TBinaryTreeIterator<T> End()
    {
        return Function::CallRVOMethodAndReturn<TBinaryTreeIterator<T>, TBinaryTree*>(EndOffset(), this);
    }
};
