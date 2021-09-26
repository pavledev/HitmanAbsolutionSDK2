#pragma once

#include "IAsyncRayHandle.h"

class ZSoundOcclusionProbe
{
public:
	IAsyncRayHandle* m_pRayQueryHandle;
	float m_fOcclusionFactor;
	float m_fOcclusionFactorSmooth;
	float m_fOcclusionRadiusAdaptive;
	bool m_bIsActive;
	int m_asyncRaycastHandleCleanupHelper;

	static int s_nNumSoundOcclusionProbes;
	static int s_nNumActiveSoundOcclusionProbes;
	static int s_nMaxSoundOcclusionProbes;
	static int s_nMaxActiveSoundOcclusionProbes;

	ZSoundOcclusionProbe() = default;
	~ZSoundOcclusionProbe() = default;
	bool IsOcclusionActive() const;
	float GetOcclusionFactorSmooth() const;
	void SetOcclusionActive(bool bActive);
	void Run(const float4& vListenerPosition, const float4& vPos, float fDistance, float fOcclusionMinRadius, float fOcclusionMaxRadius, bool bUseDistanceFading, float fMaxDistOverride, float fSmoothingTimeOverride, float4* vTargetPoint);
	void CheckAndReleaseRaycastHandles();
	void AddRaycastHandle(ZRayQueryInput& pInput);
	void ReleaseRaycastHandle();
};
