#pragma once

template <class T>
class TSListNode
{
public:
	TSListNode<T>* m_pNext;
	T m_data;

	TSListNode() = default;
	~TSListNode() = default;
};
