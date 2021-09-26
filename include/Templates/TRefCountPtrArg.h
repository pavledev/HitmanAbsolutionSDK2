#pragma once

template <class T>
class TRefCountPtrArg
{
public:
	class ZNull
	{
	};

	T* m_pObject;

	TRefCountPtrArg() = default;
	~TRefCountPtrArg() = default;
};
