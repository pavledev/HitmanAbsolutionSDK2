#pragma once

#include "TSListIterator.h"
#include "Function.h"

template <class T> class TSListNode;

template <class T>
class TSList
{
public:
    struct SFakeNode
    {
        TSListNode<T>* m_pFirst;
    };

    unsigned int m_nSize;
    SFakeNode m_list;

    TSList() = default;
    ~TSList() = default;

	unsigned int BeginOffset();
	unsigned int EndOffset();

	TSListIterator<T> Begin()
	{
		return Function::CallRVOMethodAndReturn<TSListIterator<T>, TSList*>(BeginOffset(), this);
	}

	TSListIterator<T> End()
	{
		return Function::CallRVOMethodAndReturn<TSListIterator<T>, TSList*>(EndOffset(), this);
	}
};
