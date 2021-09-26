#pragma once

#include "TFixedArrayBase.h"
#include "ZArrayRefData.h"

template <class T>
class TArrayRef : public TFixedArrayBase<T, ZArrayRefData<T>>
{
public:
	TArrayRef() = default;
	~TArrayRef() = default;
};
