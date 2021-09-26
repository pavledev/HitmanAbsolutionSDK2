#pragma once

#include "TRefCountPtrArg.h"

template <class T>
class TRefCountPtr : public TRefCountPtrArg<T>
{
public:
	TRefCountPtr() = default;
	~TRefCountPtr() = default;
};
