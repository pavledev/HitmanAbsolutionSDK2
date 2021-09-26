#pragma once

template <class T>
class GAtomicValueBase
{
public:
	volatile T Value;

	GAtomicValueBase() = default;
	~GAtomicValueBase() = default;
};
