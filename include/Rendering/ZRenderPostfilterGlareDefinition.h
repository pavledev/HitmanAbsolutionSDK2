#pragma once

#include "float4.h"
#include "ERenderPostfilterGlareType.h"

class ZRenderPostfilterStarDefinition;
struct SRenderPostfilterGlareDefinition;

class ZRenderPostfilterGlareDefinition
{
public:
	ZRenderPostfilterStarDefinition* m_pStarDefinition;
	SRenderPostfilterGlareDefinition* m_pGlareDefinition;
	float4* m_pChromaticAberrationColor;
	ERenderPostfilterGlareType m_eGlareType;

	ZRenderPostfilterGlareDefinition() = default;
	~ZRenderPostfilterGlareDefinition() = default;
	float GetBloomLuminance() const;
	float GetChromaticAberration() const;
	float4 GetChromaticAberrationColor(unsigned int nIndex) const;
	float GetGlareLuminance() const;
	ZRenderPostfilterStarDefinition* GetStarDefinition() const;
	float GetStarInclination() const;
	float GetStarLuminance() const;
	void SetGlareType(ERenderPostfilterGlareType eGlareType);
	void SetParameters(float fGlareLuminance, float fBloomLuminance, float fGhostLuminance, float fGhostDistortion, float fStarLuminance, float fStarInclination, float fChromaticAberration);
};
