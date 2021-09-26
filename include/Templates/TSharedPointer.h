#pragma once

template <class T>
class TSharedPointer
{
public:
	struct ZNull
	{
	};

	T* m_pObject;

	TSharedPointer() = default;
	~TSharedPointer() = default;
};
