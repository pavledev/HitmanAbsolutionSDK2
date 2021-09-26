#pragma once

struct SRenderPostfilterStarDefinition
{
	unsigned int nNumStarLines;
	unsigned int nPasses;
	float fSampleLength;
	float fAttenuation;
	float fInclination;
	bool bRotation;

	SRenderPostfilterStarDefinition() = default;
	~SRenderPostfilterStarDefinition() = default;
};
