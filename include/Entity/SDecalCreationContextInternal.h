#pragma once

#include "SDecalCreationContext.h"
#include "SMatrix.h"
#include "float4.h"

struct SDecalCreationContextInternal : SDecalCreationContext
{
	SMatrix m_mDecalToWorld;
	SMatrix m_mObjectToSpatial;
	SMatrix m_mProjection;
	float4 m_vAxisX;
	float4 m_vAxisY;
	float4 m_vSize;
	float m_fOffsetZ;
	float m_fAngle;

	SDecalCreationContextInternal() = default;
	SDecalCreationContextInternal(SDecalCreationContext Context);
	~SDecalCreationContextInternal() = default;
};
