#pragma once

class ZRefCount
{
public:
	long m_nCount;

	ZRefCount() = default;
	~ZRefCount() = default;
	int operator--();
	int operator++();
	operator int() const;
};
