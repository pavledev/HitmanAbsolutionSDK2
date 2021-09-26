#pragma once

struct SRenderShadowMapInfo
{
	enum EShadowFadeTypes
	{
		SFT_FADE_NONE = 0,
		SFT_FADE_IN = 1,
		SFT_FADE_OUT = 2
	};

	float m_fFadeStartTime;
	float m_fShadowFadeIntensity;
	unsigned int m_nFadeMode;
	unsigned int m_nLastFrameUsed;
	void* m_pOwner;

	SRenderShadowMapInfo() = default;
	~SRenderShadowMapInfo() = default;
};
