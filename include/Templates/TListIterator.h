#pragma once

#include "TIterator.h"

template <class T>
class TListIterator : public TIterator<T>
{
public:
	TListIterator() = default;
	~TListIterator() = default;
};
