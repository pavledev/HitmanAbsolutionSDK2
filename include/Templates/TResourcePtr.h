#pragma once

#include "ZResourcePtr.h"

template <class T>
class TResourcePtr : public ZResourcePtr
{
public:
	TResourcePtr() = default;
	~TResourcePtr() = default;
};
