#pragma once

template <class T>
struct ZMaxArrayRefData
{
	T* m_data;
	unsigned int m_nCapacity;

	ZMaxArrayRefData() = default;
	~ZMaxArrayRefData() = default;
};
