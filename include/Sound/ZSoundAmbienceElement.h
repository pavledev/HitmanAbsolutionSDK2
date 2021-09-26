#pragma once

#include "ZSoundAmbienceBase.h"
#include "SVector3.h"
#include "TEntityRef.h"
#include "ZSoundPlayableBase.h"
#include "ESoundAmbiencePlayState.h"

class ZSoundAmbienceElement : public ZSoundAmbienceBase
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bIsTempSpatial;
	bool m_bAmbienceActivated;
	bool m_bTriggerByAmbience;
	bool m_bUseTimer;
	float m_fMinTime;
	float m_fMaxTime;
	float m_fTimeMultiplier;
	float m_fProbability;
	int m_nMaxPlayCount;
	bool m_bUseAmbienceAttenuation;
	SVector3 m_vTempSpatialPos;
	float m_fTempSpatialWeight;
	TEntityRef<ZSoundPlayableBase> m_parentEntity;
	ESoundAmbiencePlayState m_eCurrPlayState;
	ESoundAmbiencePlayState m_eNextPlayState;
	ESoundAmbiencePlayState m_eSavedPlayState;
	float m_fMinTimeInterpolated;
	float m_fMaxTimeInterpolated;
	float m_fTimeMultiplierInterpolated;
	float m_fProbabilityInterpolated;
	float m_fLowpassCutoffInterpolated;
	float m_fRemaining;
	bool m_bTriggeredByPin;
	bool m_bPaused;
	bool m_bPlaying;
	bool m_bSingleSoundStarted;
	unsigned int m_nIncrementAddCount;
	int m_nCurrentPlayCount;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int m_snTimeOut;

	~ZSoundAmbienceElement() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	void SetTempSpatialPosition(const SVector3& pos, unsigned int nRecursionTag) override;
	void SetTempSpatialOcclusionAttenuation(float fOcclusionAttenuation, unsigned int nRecursionTag) override;
	void SetTempSpatialOcclusionLowpassCutoff(float fOcclusionLowpassCutoff, unsigned int nRecursionTag) override;
	void AmbienceTraverse(unsigned int nRecursionTag, ESoundAmbienceOperation eOperation, SSoundAmbienceDynamicParameters* pDynamicParameters) override;

	ZSoundAmbienceElement() = default;
	static void RegisterType();
	ZSoundAmbienceElement(ZComponentCreateInfo& info);
	void UpdateTempSpatialWeight();
	void UpdateTempSpatial();
	void ChangePlayState(bool bPlay);
	void ChangePauseState(bool bPause);
	void OnUseTimerChanged(const bool& oldValue);
	void OnMinTimeChanged();
	void OnMaxTimeChanged();
	void OnTimeMultiplierChanged();
	void OnProbabilityChanged();
	void OnMaxPlayCountChanged();
	void OnAmbienceActivatedChanged();
	void OnAmbienceStart();
	void OnAmbienceStop();
	void OnAmbienceRestart();
	void OnAmbienceActivate();
	void OnAmbienceDeactivate();
	void OnTimeMultiplier(float fTimeMultiplier);
	void GameUpdate(const SGameUpdateEvent& updateEvent);
	TArrayIterator<ZSoundPlayerChannel*> ChannelsBegin();
	TArrayIterator<ZSoundPlayerChannel*> ChannelsEnd();
};
