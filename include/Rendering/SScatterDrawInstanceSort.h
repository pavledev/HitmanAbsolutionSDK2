#pragma once

struct SScatterDrawInstanceSort
{
	unsigned int nIdx;
	float m_fDistance;

	SScatterDrawInstanceSort() = default;
	~SScatterDrawInstanceSort() = default;
	bool operator<(const SScatterDrawInstanceSort& other);
};
