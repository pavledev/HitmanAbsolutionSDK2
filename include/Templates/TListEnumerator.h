#pragma once

#include "TEnumeratorBase.h"

template <class T>
class TListEnumerator : public TEnumeratorBase<T>
{
public:
	class ZEnumeratorImpl
	{
	};

	TListEnumerator() = default;
	~TListEnumerator() = default;
};
