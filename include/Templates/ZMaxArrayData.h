#pragma once

#include "TAlignedType.h"

template <class A, int B>
class ZMaxArrayData
{
public:
	union
	{
		unsigned __int8 m_data[B * sizeof(A)];
		TAlignedType<alignof(A)> alignDummy;
	};
};