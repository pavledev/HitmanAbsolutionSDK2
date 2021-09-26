#pragma once

#include "ERenderPostfilterStarType.h"

struct SRenderPostfilterStarDefinition;
struct SRenderPostfilterStarLineDefinition;

class ZRenderPostfilterStarDefinition
{
public:
	SRenderPostfilterStarDefinition* m_pStarDefinition;
	SRenderPostfilterStarLineDefinition* m_pStarLineDefinitions;
	ERenderPostfilterStarType m_eStarType;

	ZRenderPostfilterStarDefinition() = default;
	~ZRenderPostfilterStarDefinition() = default;
	float GetInclination() const;
	unsigned int GetNumStarLines() const;
	SRenderPostfilterStarLineDefinition& GetStarLineDefinition(unsigned int nIndex) const;
	void SetStarType(ERenderPostfilterStarType eStarType);
	void GenerateStarLineDefinition();
	void SetParameters(unsigned int nNumStarLines, unsigned int nPasses, float fSampleLength, float fAttenuation, float fInclination, bool bRotation);
};
