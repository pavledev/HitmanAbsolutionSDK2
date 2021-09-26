#pragma once

#include "SMatrix.h"

struct sMuzzleInfo
{
	SMatrix m_mvMuzzleMatPos;
	bool m_bValid;

	sMuzzleInfo() = default;
	~sMuzzleInfo() = default;
	void Reset();
};
