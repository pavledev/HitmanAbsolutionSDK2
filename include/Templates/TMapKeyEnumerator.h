#pragma once

#include "TEnumeratorBase.h"

template<class A, class B>
class TMapKeyEnumerator : public TEnumeratorBase<A const>
{
public:
	class ZEnumeratorImpl
	{
	};

	TMapKeyEnumerator() = default;
	~TMapKeyEnumerator() = default;
};
