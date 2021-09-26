#pragma once

template <class T>
class GRect
{
public:
	enum BoundsType
	{
		Min = 0,
		Max = 1
	};

	T Left;
	T Top;
	T Right;
	T Bottom;

	~GRect() = default;
	GRect() = default;
};
