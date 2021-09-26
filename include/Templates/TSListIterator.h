#pragma once

#include "TIterator.h"
#include "Function.h"

template <class T>
class TSListIterator : public TIterator<T>
{
public:
    TSListIterator() = default;
    ~TSListIterator() = default;

	unsigned int IncrementOperatorOffset();
	unsigned int AssignmentOperatorOffset();

	TSListIterator& operator++()
	{
		return Function::CallMethodAndReturn<TSListIterator&, TSListIterator*>(IncrementOperatorOffset(), this);
	}

	TSListIterator& operator=(const TSListIterator& __that)
	{
		return Function::CallMethodAndReturn<TSListIterator&, TSListIterator*, const TSListIterator&>(AssignmentOperatorOffset(), this, __that);
	}
};
