#pragma once

#include "TPair.h"

template <class A, class B>
struct THashMapNode
{
	int m_iNext;
	TPair<A, B> m_data;

	THashMapNode() = default;
	~THashMapNode() = default;
};
