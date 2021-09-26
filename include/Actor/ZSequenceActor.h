#pragma once

#include "ZEntityImpl.h"
#include "IMorphemeCutSequenceAnimatable.h"
#include "ISoundPlayable.h"
#include "EActorPerceptionSensitivity.h"
#include "EActorEmotionState.h"
#include "EGameTension.h"
#include "ZActorsSequence.h"
#include "ZWaypointEntity.h"

class ZActor;

class ZSequenceActor : public ZEntityImpl, public IMorphemeCutSequenceAnimatable, public ISoundPlayable
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TEntityRef<ZActor> m_pActor;
	float m_fDistanceThreshold;
	bool m_bIsMandatoryActor;
	bool m_bShouldHaveReachedWaypoint;
	bool m_bEnableAmbientLookAt;
	EActorPerceptionSensitivity m_ePerceptionSensitivity;
	float m_fUpperBodyOnly;
	EActorEmotionState m_eRequiredEmotionState;
	EGameTension m_eMaximumGameTension;
	bool m_bStopActsAtFullBody;
	bool m_bStayAtWaypointTillSequenceEnds;
	bool m_bWaitForSequenceEvenIfDoneWithAct;
	bool m_bProjectToGround;
	bool m_bWithinDistance : 1;
	bool m_bHasReachedWayPoint : 1;
	bool m_bIsPlayingSequence : 1;
	bool m_bHasPlayedSequence : 1;
	bool m_bHasLeftSequence : 1;
	bool m_bHasCompletedLeadIn : 1;
	bool m_bHasStartedLeadOut : 1;
	bool m_bHasLeadinLeadout : 1;
	bool m_bIsPreviewing : 1;
	bool m_bIsRunningWaypointBehavior : 1;
	bool m_bExternallyBinded : 1;
	bool m_bShouldntStopAct : 1;
	ZActorsSequence* m_pActorsSequence;
	ZWaypointEntity* m_pWaypoint;
	SMatrix m_mTransformAtFullBody;
	SMatrix m_mTransformAtSequenceStart;

	static SComponentMapEntry s_componentMap[0];

	~ZSequenceActor() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	void CutSequenceStarted(ISequenceEntity* pSequence, const ZString& sSlotName, float fBodyPartSelector) override;
	void CutSequenceUpdate(ISequenceEntity* pSequence, ZString sSlotName, float fWeight) override;
	SMatrix43 CutSequenceGetWorldTransform() override;
	void CutSequenceSetWorldTransform(const SMatrix43& mNewWorldTransform) override;
	SMatrix43 CutSequenceGetParentTransform() override;
	void CutSequenceSetParentTransform(const SMatrix43& mNewParentTransform) override;
	void CutSequenceEnded(ISequenceEntity* pSequence, ZString sSlotName) override;
	ZEvent0& GetAnimatableChangedEvent() override;
	void AbortCutSequence() override;
	bool SetCutSequenceData(ISequenceEntity* pSequence, const SCutSequenceData& cutSequenceData, const ZString& sSlotName, float fBodyPartSelector) override;

	void Activate() override;
	void Deactivate() override;
	ISoundPlayerChannel* Play(TResourcePtr<ZWaveBankData> pWavebank, int nChannel, bool bPaused, unsigned int nChannelFlags, bool bForceSubsound, float4* vInitialPosition, void* pCallbackUserData, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> FailedCallback, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)> StartedCallback, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> StoppedCallback, void* pSeqCallbackUserData, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> SeqFailedCallback, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)> SeqStartedCallback, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> SeqStoppedCallback) override;
	ISoundPlayerChannel* PlayChannelAtPoint(SSoundTriggerPoint channelAndPoint) override;
	void SetPausedState(bool bPaused) override;
	void Stop(bool bIgnoreFade) override;
	bool IsPlaying() const override;
	bool IsPlayOnGameStart() const override;
	bool IsPaused() const override;
	float GetDuration() const override;
	void SetPlayPosition(float fNewPosition) override;
	float GetPlayPosition() override;
	void SetGamePaused(bool bPaused) override;
	bool IsGamePaused() const override;
	ZEntityRef GetEntityRef() const override;
	void SetDefaultPlayFailedCallback(const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>& failedCallback) override;
	void SetDefaultPlayStartedCallback(const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)>& startedCallback) override;
	void SetDefaultPlayStoppedCallback(const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>& stoppedCallback) override;
	const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>& GetDefaultPlayFailedCallback() override;
	const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)>& GetDefaultPlayStartedCallback() override;
	const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>& GetDefaultPlayStoppedCallback() override;
	void RemoveFailedCallback(const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>& failedCallback) override;
	void RemoveStartedCallback(const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)>& startedCallback) override;
	void RemoveStoppedCallback(const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>& stoppedCallback) override;
	ISoundGroup* GetSoundGroup() override;

	ZSequenceActor() = default;
	static void RegisterType();
	ZSequenceActor(ZComponentCreateInfo& info);
	void OnUpperBodyOnlySet(const float& fOldBlend);
	bool OnActorTargetingWaypoint(TEntityRef<ZActor> pActor, TEntityRef<ZWaypointEntity> pWaypoint);
	void OnActorWalkingToWaypoint(float distance);
	void OnActorHasReachedWaypoint();
	bool CanActorLeaveWaypoint() const;
	void OnActorLeavingWaypoint() const;
	void OnActorWaitingAtWaypoint();
	void OnActorTargetingAnotherWaypoint();
	void OnActorChangingBehavior();
	void SetWaypoint(ZWaypointEntity* pWaypoint);
	EActorEmotionState GetRequiredEmotionState() const;
	bool IsPlayingSequence() const;
	bool CanPlaySequence() const;
	bool CanStartSequence() const;
	void StartSequencePlayback();
	void StopSequencePlayback(ZActorsSequence::StopReason::Enum stopReason);
	bool HasLeftSequence() const;
	void LeaveSequence();
	bool IsRunningWaypointBehavior() const;
	void Reset();
	void SetActorsSequence(ZActorsSequence* sequence);
	ZString WhyCantStart() const;
	ZString WhyCantPlay() const;
	void AlignWaypointIfNeeded();
	bool ReadSequenceStartingPosition(SMatrix& mWorldTransform) const;
	bool ShouldTeleportToSequenceStartingPosition() const;
	bool HasUpperBodyDrivenFromSequence() const;
	bool SequenceHasOrigin() const;
	bool IsDrivenBySequenceRelativeTrack() const;
	bool Bind(TEntityRef<ZActor> pActor);
	void Unbind();
	bool IsBinded() const;
	bool IsSetupWiredCorrectly() const;
	const ZString GetActorsSequenceDebugName() const;
	const ZString GetActorDebugName() const;
};
