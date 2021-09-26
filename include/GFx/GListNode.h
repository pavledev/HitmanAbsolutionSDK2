#pragma once

template <class T>
struct GListNode
{
	T* pPrev;
	T* pNext;

	GListNode() = default;
	~GListNode() = default;
};
