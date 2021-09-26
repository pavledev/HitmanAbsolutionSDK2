#pragma once

template <class A, int B>
struct ZFixedArrayData
{
    A m_pStart[B];

	A* GetEnd();
	const A* GetEnd() const;
	ZFixedArrayData() = default;
	~ZFixedArrayData() = default;
	ZFixedArrayData& operator=(const ZFixedArrayData&__that);
};
