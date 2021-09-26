#pragma once

#include "ECameraPOI.h"

struct SCameraPOI
{
	bool m_bAllowInterrupt;
	float m_fTimeOnPOI;
	float m_fBlendInTime;
	ECameraPOI m_ePOIType;

	SCameraPOI() = default;
	~SCameraPOI() = default;
};
