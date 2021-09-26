#pragma once

#include "ZPinFunctor.h"

struct SPinInfo
{
	ZPinFunctor m_functor;
	unsigned int m_nExtraData;

	SPinInfo() = default;
	~SPinInfo() = default;
};
