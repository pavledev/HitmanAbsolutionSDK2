#pragma once

#include "TBinaryTreeNode.h"

template<class T>
class SFakeTreeNode
{
public:
    int m_reserved1;
    TBinaryTreeNode<T>* m_pNULL;
    TBinaryTreeNode<T>* m_pRightRoot;
    TBinaryTreeNode<T>* m_pLeftRoot;
};
