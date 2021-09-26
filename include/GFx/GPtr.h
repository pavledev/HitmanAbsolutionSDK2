#pragma once

template <class T>
class GPtr
{
public:
	T* pObject;

	GPtr() = default;
	~GPtr() = default;
};
