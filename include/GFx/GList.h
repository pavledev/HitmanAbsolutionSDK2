#pragma once

#include "GListNode.h"

template <class T>
class GList
{
public:
	GListNode<T> Root;

	GList() = default;
	~GList() = default;
};
