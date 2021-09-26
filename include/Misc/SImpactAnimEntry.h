#pragma once

struct SImpactAnimEntry
{
	unsigned int m_nAnimNodeID;
	unsigned int m_nAnimNodeID2;
	float m_fNodeBlendWeight;
	bool m_bKeepHandsRelative;
	float m_fAnimDuration;
	float m_fAnimTime;
	float m_fWeight;

	SImpactAnimEntry() = default;
	~SImpactAnimEntry() = default;
	void Reset();
};
