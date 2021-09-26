#pragma once

#include "TIterator.h"

template <class T>
class TArrayIterator : public TIterator<T>
{
public:
	TArrayIterator() = default;
	~TArrayIterator() = default;
};
