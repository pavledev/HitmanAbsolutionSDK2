#pragma once

#include "TIterator.h"
#include "Function.h"

template <class T> class TBinaryTreeNode;

template <class T>
class TBinaryTreeIterator : public TIterator<T>
{
public:
    TBinaryTreeIterator() = default;
    ~TBinaryTreeIterator() = default;

    unsigned int NodeOffset();
    unsigned int IncrementOperatorOffset();

    TBinaryTreeNode<T>& Node()
    {
        return Function::CallMethodAndReturn<TBinaryTreeNode<T>&, TBinaryTreeIterator*>(NodeOffset(), this);
    }

    TBinaryTreeIterator& operator++()
    {
        return Function::CallMethodAndReturn<TBinaryTreeIterator&, TBinaryTreeIterator*>(IncrementOperatorOffset(), this);
    }
};
