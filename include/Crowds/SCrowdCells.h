#pragma once

#include "TFixedArray.h"

struct SCrowdCells
{
	TFixedArray<unsigned char, 128> m_cells;

	SCrowdCells(const SCrowdCells& __that);
	SCrowdCells() = default;
	~SCrowdCells() = default;
};
