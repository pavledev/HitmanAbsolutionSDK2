#pragma once

#include "ZGameTime.h"
#include "TArray.h"
#include "ZString.h"
#include "ESOUND_MAXAUDIBLEBEHAVIOR.h"
#include "float4.h"
#include "ZSoundGroupTarget.h"

class ZSoundGroupInternal
{
public:
	struct SSoundGroupTargetSortData
	{
		float m_aValue[3];
		ZSoundGroupTarget* m_pTarget;

		bool operator<(const SSoundGroupTargetSortData& r);
	};

	int m_nRefCount;
	ZGameTime m_lastTriggerTime;
	int m_nMaxAudible;
	int m_nVoiceHeadroom;
	float m_fMinTriggerInterval;
	float m_fFadeTime;
	ESOUND_MAXAUDIBLEBEHAVIOR m_eMaxAudibleBehavior;
	TArray<ZSoundGroupTarget*> m_aSoundGroupTargets;
	ZString m_sGroupName;

	ZSoundGroupInternal() = default;
	ZSoundGroupInternal(const ZString& sName);
	~ZSoundGroupInternal() = default;
	void AddRef();
	bool Release();
	void AddSoundGroupTarget(ZSoundGroupTarget* pTarget);
	void RemoveSoundGroupTarget(ZSoundGroupTarget* pTarget);
	bool AcceptsNewTarget(int nTargetPriority, const float4& vTargetPos);
	void SetMaxAudible(int nMaxAudible);
	void SetVoiceHeadroom(int nVoiceHeadroom);
	void SetMaxAudibleBehavior(ESOUND_MAXAUDIBLEBEHAVIOR eMaxAudibleBehavior);
	void SetMinTriggerInterval(float fMinTriggerInterval);
	void SetFadeTime(float fFadeTime);
	void Reset();
	void FrameUpdate(float fDeltaTime);
	int GetMaxAudible() const;
	int GetVoiceHeadroom() const;
	int GetMaxCapacity() const;
	int GetKillThreshold() const;
	SSoundGroupTargetSortData* GetSortedData();
	void KillExcessiveTargets(int nKillThreshold, SSoundGroupTargetSortData* pSortedData);
};
