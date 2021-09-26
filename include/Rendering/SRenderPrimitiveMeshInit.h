#pragma once

#include "float4.h"
#include "ZRenderMaterialInstance.h"
#include "TResourcePtr.h"

struct SRenderPrimitiveMeshInit
{
	float4 vPositionScale;
	float4 vPositionBias;
	float4 vTextureScaleBias;
	float4 vBoundsMin;
	float4 vBoundsMax;
	TResourcePtr<ZRenderMaterialInstance> pMaterial;
	unsigned int nWireColor;
	unsigned int nNumIndicesToDraw;
	unsigned char nLODMask;
	unsigned char nZBias;
	unsigned char nZOffset;
	unsigned char nAxisLockedMask : 3;

	SRenderPrimitiveMeshInit() = default;
	~SRenderPrimitiveMeshInit() = default;
};
