#pragma once

struct SRenderPostfilterStarLineDefinition
{
	unsigned int nPasses;
	float fSampleLength;
	float fAttenuation;
	float fInclination;

	SRenderPostfilterStarLineDefinition() = default;
	~SRenderPostfilterStarLineDefinition() = default;
};
