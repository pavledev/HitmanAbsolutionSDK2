#pragma once

#include "TEnumeratorBase.h"

template <class T>
class TArrayEnumerator : public TEnumeratorBase<T>
{
public:
	class ZEnumeratorImpl
	{
	};

	TArrayEnumerator() = default;
	~TArrayEnumerator() = default;
};
