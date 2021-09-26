#pragma once
#pragma warning(disable : 4005)

#include "SRenderConstDesc.h"
#include "d3d11.h"

struct SRenderSamplerDesc : SRenderConstDesc
{
	ID3D11SamplerState* pSamplerState;

	SRenderSamplerDesc(const SRenderSamplerDesc& __that);
	SRenderSamplerDesc() = default;
	~SRenderSamplerDesc() = default;
};
