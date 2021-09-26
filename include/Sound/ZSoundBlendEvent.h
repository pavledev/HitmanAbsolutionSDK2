#pragma once

#include "ZSoundGroupTarget.h"
#include "TMap.h"
#include "ESustainPointState.h"
#include "ZSoundBlendContainerBase.h"
#include <fmod.hpp>
#include "ESoundCollisionType.h"

class ZSoundBlendTrackInstance;

class ZSoundBlendEvent : public ZSoundGroupTarget
{
public:
	TMap<int, ESustainPointState> m_SustainPointStates;
	bool m_bTimerRunning;
	ZSoundBlendContainerBase* m_pContainerOwner;
	TArray<ZSoundBlendTrackInstance*> m_pBlendTrackInstances;
	unsigned long m_nUniqueID;
	ESoundCollisionType m_eCollisionSupport;
	float4 m_vPosition;
	TArray<float> m_fSourceParameters;
	int m_nNumTrackInstances;
	int m_nRegisterIndex;
	int m_nPriority;
	bool m_bAllowChannelCreation;
	bool m_bDisposable;
	bool m_bSourceParametersDirty;
	bool m_bAutoDestruct;
	bool m_bMemorizeAutoDestruct;
	bool m_bIs3D;
	bool m_bSustainPointReleasedPrematurely;
	bool m_bIsLoudPhysicsEvent;
	ZGameTime m_timestamp;
	float m_fBaseAttenuation;
	FMOD::ChannelGroup* m_pMasterEffectsGroup;
	ZSoundBlendEvent* m_pPrev;
	ZSoundBlendEvent* m_pNext;

	~ZSoundBlendEvent() override = default;
	int GetPriority() override;
	float GetAudibility(bool bIncludeSoundGroupFadeLevel) override;
	float GetSquaredDistanceToListener(const float4& vListenerPos) override;
	ZGameTime GetTimestamp() override;
	void StopTarget() override;
	ZString GetSoundGroupTargetName() const override;
	bool UpdateSoundGroupFade(bool bMuted, float fFadeTime, float fDeltaTime) override;
	virtual void AttachEffectInstance(FMOD::DSP* pEffect, void* pOwner);
	virtual bool IsSilent() const;

	ZSoundBlendEvent() = default;
	ZSoundBlendEvent(ZSoundBlendContainerBase* pOwner, unsigned long nUniqueID, bool bAutoDestruct, int nPriority);
	void SetParameter(int nIndex, float fParameter);
	float GetParameter(int nIndex);
	void UpdateParameters();
	void Play(ESoundCollisionType eCollisionSupport, const float4& vPosition, bool bIs3D, bool bStartedFromGUI);
	void Stop(bool bForceStop);
	void StopAutomatedParameters();
	void SetPosition(const float4& vPosition);
	void Update(float fDeltaTime);
	void UpdateAutomatedParameters(float fDeltaTime);
	bool HasTrackInstances() const;
	void ReleaseSustainPoint(unsigned int nSustainSourceIndex);
	void SetTrackMuteState(int nTrackIndex, bool bIsMuted);
	void SetBaseAttenuation(float fAttenuation);
	float GetBaseAttenuation() const;
	const unsigned int GetUniqueID() const;
	void SetCollisionSupport(ESoundCollisionType eCollisionSupport);
	ESoundCollisionType GetCollisionSupport();
	void SetRegisterIndex(const int nIndex);
	const int GetRegisterIndex() const;
	void SetIsLoudPhysicsEvent(bool bIsLoudPhysicsEvent);
	bool IsLoudPhysicsEvent() const;
	void DetachTrackInstance(ZSoundBlendTrackInstance* pInstance, int nTrackIndex);
	void CreateGroupAndEffects(ZSoundBlendTrackInstance* pCurrTrackInstance, bool bIsMasterEffectsGroup, TEntityRef<ZSoundBlendTrack> pTrack);
	ZSoundBlendContainerExternalParameters* GetContainerExternalParameters() const;
	SItemPair FindIntersectingItems(TEntityRef<ZSoundBlendItemSubtrack> pItemSubTrack, unsigned int nPrimarySourceIndex, float fPrimarySource);
};
