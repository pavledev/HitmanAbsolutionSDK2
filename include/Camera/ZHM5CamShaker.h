#pragma once

#include "SVector4.h"

struct float4;

class ZHM5CamShaker
{
public:
	struct SWigglerParams
	{
		float m_fWigglerPct;
		float m_fWigglerTimeLeft;
		float m_fWigglerRelease;
		float m_fWigglerFrequency;
		SVector4 m_vWigglerRange;
		float m_fWigglerDelay;
		bool m_bLoop;
		void* m_pWigglerId;
		float m_fMinFov;
		float m_fMaxFov;

		SWigglerParams() = default;
	};

	SVector4 m_vWigglerPrevPos;
	SVector4 m_vWigglerNextPos;
	float m_fWigglerPct;
	float m_fWigglerTimeLeft;
	float m_fWigglerRelease;
	float m_fWigglerFrequency;
	SVector4 m_vWigglerRange;
	float m_fWigglerDelay;
	bool m_bWigglerPostfilter;
	bool m_bActive;
	SVector4 m_vFocalOffset;
	float m_fRollOffset;
	float m_fFovOffset;
	float m_fMinFov;
	float m_fMaxFov;
	bool m_bLoop;
	SWigglerParams m_sOverridenWiggler;
	bool m_bEnabled;
	void* m_pWigglerId;

	ZHM5CamShaker() = default;
	~ZHM5CamShaker() = default;
	void SetActive(bool bValue);
	void Reset();
	bool IsActive() const;
	void Enable(bool bEnable);
	bool IsEnabled() const;
	void Update();
	void StartWiggler(float fDelay, float fSustain, float fRelease, float fFrequency, float fRangeH, float fRangeV, float fRangeRoll, float fMinFov, float fMaxFov, bool bLoop, void* pWigglerId);
	void StopWiggler(void* pWigglerId);
	float4 GetFocalOffset() const;
	float GetRollOffset() const;
	void Deactivate(void* pWigglerId);
	void UpdateWiggler();
};
