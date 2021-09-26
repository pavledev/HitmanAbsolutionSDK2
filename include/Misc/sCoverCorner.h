#pragma once

#include "float4.h"
#include "eCornerSide.h"

struct sCoverCorner
{
	float4 m_vCornerPoint;
	eCornerSide m_eSide;
	bool m_bValid : 1;
	bool m_bHighCoverCorner : 1;
	bool m_bWindowCorner : 1;
	bool m_bDisabled : 1;

	sCoverCorner() = default;
	~sCoverCorner() = default;
	void Reset();
};
