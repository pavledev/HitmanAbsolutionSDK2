#pragma once

#include "TArray.h"

struct SRenderConstDesc;
struct SRenderSamplerDesc;

struct SRenderConstBufferDesc
{
	unsigned int nGuid;
	unsigned int nConstSize;
	unsigned int nSamplerSize;
	unsigned int nNumConstants;
	unsigned int nNumSamplers;
	unsigned int nWaste;
	TArray<SRenderConstDesc> Constants;
	TArray<SRenderSamplerDesc> Samplers;

	SRenderConstBufferDesc() = default;
	const SRenderConstDesc* GetConstantDesc() const;
	const SRenderSamplerDesc* GetTextureDesc() const;
	~SRenderConstBufferDesc() = default;
};
