#pragma once

template <class T>
class GPoint
{
public:
	enum BoundsType
	{
		Min = 0,
		Max = 1
	};

	T x;
	T y;

	GPoint() = default;
	~GPoint() = default;
};
