#pragma once

#include "float4.h"

struct SSoundPhysicsEventParameters
{
	float m_aActualParams[10];
	float4 m_vPosition;
	float4 m_vContactNormal;
	unsigned int m_nID;
	unsigned int m_nReferencePoint;

	SSoundPhysicsEventParameters() = default;
	~SSoundPhysicsEventParameters() = default;
};
