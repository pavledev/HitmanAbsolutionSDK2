#pragma once

#include "GAtomicValueBase.h"

template <class T>
class GAtomicInt : public GAtomicValueBase<T>
{
public:
	GAtomicInt() = default;
	~GAtomicInt() = default;
	T ExchangeAdd_Acquire(T val);
};
