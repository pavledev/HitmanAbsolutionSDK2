#pragma once

template <class T>
class TComponentSharedPtr
{
public:
	struct ZNull
	{
	};

    T* m_pComponent;

	TComponentSharedPtr() = default;
	~TComponentSharedPtr() = default;
};
