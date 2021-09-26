#pragma once

#include "TMaxArray.h"
#include "EGameTension.h"
#include "TArrayEnumerator.h"
#include "ZGameTime.h"
#include "float4.h"
#include "ZEntityRef.h"

class ZAttentionHUD
{
public:
	enum
	{
		MAX_ATTENTION_PEAKS = 6
	};

	struct SAttentionHudDataElement
	{
		float fAngle;
		float fAttention;
		float fAlpha;
		unsigned int nColor;
	};

	struct SAttentionMeterInfo
	{
		enum EAttentionMeterState
		{
			AMS_SHOWING = 0,
			AMS_FADEOUT = 1,
			AMS_DEPLETED = 2
		};

		enum EThreatType
		{
			ETT_Guard = 0,
			ETT_Civilian = 1,
			ETT_Special = 2
		};

		ZEntityRef m_rThreat;
		float m_fAttention;
		EGameTension m_eGameTension;
		EThreatType m_eThreatType;
		bool m_bInSight;
		bool m_bShowAttention;
		float4 m_vPosition;
		float m_fAlpha;
		float m_fOldAttention;
		EGameTension m_eOldGameTension;
		EAttentionMeterState m_eState;
		bool m_bResetted;
		ZGameTime m_timeOfTouch;

		SAttentionMeterInfo(const SAttentionMeterInfo& __that);
		SAttentionMeterInfo(const ZEntityRef& rThreat);
		~SAttentionMeterInfo() = default;
		SAttentionMeterInfo& operator=(const SAttentionMeterInfo& __that);
	};

	bool m_bBlinkState;
	float m_fBlinkDuration;
	bool m_bPrevAttentionOn;
	bool m_bEnabled;
	TMaxArray<SAttentionMeterInfo, 100> m_attentionMeterInfos;
	TMaxArray<SAttentionHudDataElement, 6> m_aAttentionHUDScaleformData;

	ZAttentionHUD() = default;
	void RegisterThreat(const ZEntityRef& rThreat);
	void UnregisterThreat(const ZEntityRef& rThreat);
	void EnableAttention();
	void DisableAttention();
	void Update();
	TArrayEnumerator<SAttentionHudDataElement const> GetAttentionPeakEnumerator() const;
	bool UpdateAttentionHUD();
	void AddAttentionHUDPeak(float fAngle, float fAttention, float fAlpha, unsigned int nColor);
	~ZAttentionHUD() = default;
};
