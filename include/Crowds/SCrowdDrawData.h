#pragma once

#include "ZRenderShaderResourceView.h"
#include "float4.h"
#include "SMatrix.h"
#include "ZRenderConstBufferRef.h"

struct SCrowdDrawData
{
	unsigned char nIsGlowPass;
	SMatrix mWorldMatrix;
	float4 vPositionScale;
	float4 vPositionBias;
	float4 vTexScaleBias;
	float4 vCurGlowColor;
	ZRenderShaderResourceView* pDiffuseOverride;
	ZRenderConstBufferRef cb;

	SCrowdDrawData() = default;
	~SCrowdDrawData() = default;
};
