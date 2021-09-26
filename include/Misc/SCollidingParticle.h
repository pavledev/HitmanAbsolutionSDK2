#pragma once

#include "float4.h"

struct SCollidingParticle
{
	float4 m_vPosition;
	float4 m_vVelocity;
	unsigned int m_nColor;
	float m_fSize;

	SCollidingParticle() = default;
	~SCollidingParticle() = default;
};
