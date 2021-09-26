#pragma once

#include "float4.h"
#include "ZEntityRef.h"

struct SSphereSweepOutput
{
	float4 m_vSweepEndPosition;
	float4 m_vContactPosition;
	float4 m_vNormal;
	ZEntityRef m_BlockingEntity;
	float m_fSweepDistancePrct;
	bool m_bHasHit;

	SSphereSweepOutput() = default;
	~SSphereSweepOutput() = default;
};
