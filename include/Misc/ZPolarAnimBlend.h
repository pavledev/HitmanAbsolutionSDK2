#pragma once

class ZPolarAnimBlend
{
public:
	struct SActiveAnims
	{
		unsigned int m_anAnimId[2];
		float m_afAnimFractions[2];
		float m_fBlendFraction;
	};

	struct SAnimEntry
	{
		unsigned int m_nAnimId;
		float m_fYawAngle;
		float m_fMinPitch;
		float m_fMaxPitch;
		float m_fAnimFraction;
		float m_fBlendFraction;
	};

	unsigned int m_nNumAnimations;
	float m_fEdgeAngleThreshold;
	SAnimEntry m_AnimEntries[4];

	static const unsigned int NUM_ANIMATION_ENTRIES;

	ZPolarAnimBlend() = default;
	ZPolarAnimBlend(float fEdgeAngleThreshold);
	~ZPolarAnimBlend() = default;
	void AddAnimation(unsigned int nAnimId, float fYawAngle, float fMinPitch, float fMaxPitch);
	void CalcultateBlends(float fYawAngle, float fPitchAngle);
	float GetAnimBlendFraction(unsigned int nIndex) const;
	float GetAnimFraction(unsigned int nIndex) const;
	unsigned int GetAnimId(unsigned int nIndex) const;
	unsigned int GetNumAnimEntries() const;
	void Reset();
	SActiveAnims GetActiveAnims();
};
