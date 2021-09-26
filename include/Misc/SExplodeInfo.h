#pragma once

#include "SVector3.h"

struct SExplodeInfo
{
	float m_fPushOrigin;
	float m_fPushBorder;
	unsigned int m_nPushSharpness;
	float m_fRotateMultiplier;
	float m_fLiftBias;
	float m_fLiftMultiplier;
	unsigned int m_nLiftSharpness;
	SVector3 m_vRadius;

	SExplodeInfo() = default;
	~SExplodeInfo() = default;
};
