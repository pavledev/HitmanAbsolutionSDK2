#pragma once

#include "ZBoundedEntity.h"
#include "ISoundListenerPositionReceiver.h"
#include "ISoundUpdateListener.h"
#include "ESoundGlobalReverb.h"
#include "ZResourcePtr.h"
#include "ZSoundPlayableBase.h"
#include "ZSoundChannelGroup.h"
#include "ISoundVolumetricGeom.h"
#include "SSoundVolumetricOcclusionData.h"
#include "ZSoundBlendContainerExternalParameters.h"

class ZSoundVolumetricAspect : public ZBoundedEntity, public ISoundListenerPositionReceiver, public ISoundUpdateListener
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_fDistanceAttenuation;
	float m_fDirectionalAttenuation;
	float m_fDirectionalAttenuationCurve;
	float m_f3DWeight;
	float m_fReverbLevelNear;
	float m_fReverbLevelFar;
	float m_fReverbRadius;
	float m_fOcclusionAttenuation;
	float m_fDopplerLevel;
	float m_fOcclusionLowpassHigh;
	float m_fOcclusionLowpassLow;
	bool m_bAlignListener;
	bool m_bUseAllInputChannels;
	ESoundGlobalReverb m_eSoundGlobalReverbChannelGroup;
	float m_fGlobalReverb1AttenuationChannelGroup;
	ZResourcePtr m_pHelper;
	TArray<ZEntityRef> m_pVolumetricGeometry;
	TEntityRef<ZSoundPlayableBase> m_parentSoundEntity;
	TEntityRef<ZSoundChannelGroup> m_parentSoundChannelGroup;
	TEntityRef<ZSoundBlendContainerExternalParameters> m_pBlendContainer;
	TArray<FMOD::Channel*> m_TempFrameUpdateChannels;
	int m_nNumSpeakers;
	float m_fOcclusionLowpassFrequency;
	float m_fDopplerShiftFilter1;
	float m_fDopplerShiftFilter2;
	float m_fDopplerShiftFilter3;
	float m_fDopplerVelocity;
	float m_fInsideness;
	float m_fSpeakerLevelsTarget[8];
	float m_fSpeakerLevelsSmooth[64];
	float4 m_vListenerPosition;
	float4 m_vObjectPosition;
	bool m_bDrawDebugRays;
	bool m_bHasUnoccludedPath;
	SMatrix m_mListenerMatrix;
	float4 m_vOcclusionPosition;
	float4 m_vAverageCenter;
	int m_nMaxRayCastResults;
	int m_nNextMaxRayCastResults;
	int m_asyncRaycastHandleCleanupHelper;
	TArray<ISoundVolumetricGeom*> m_pGeoms;
	SSoundVolumetricOcclusionData* m_pOcclusionData;

	static SComponentMapEntry s_componentMap[0];
	static const unsigned int MAX_SPEAKERS;
	static float4 s_vSpeakerPosition[8];
	static float4 s_vSpeakerDirection[8];
	static float s_fIsLFE[8];

	~ZSoundVolumetricAspect() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void CalculateBounds(float4& vMin, float4& vMax, const unsigned int nIncludeFlags, const unsigned int nExcludeFlags) override;

	void OnListenerPositionUpdated(const SMatrix& mTransform) override;

	void OnSoundUpdate() override;

	ZSoundVolumetricAspect() = default;
	static void RegisterType();
	ZSoundVolumetricAspect(ZComponentCreateInfo& info);
	void CalculateDopplerPoint();
	float4 GetAverageCenter();
	void OnGeometryChanged();
	void Update(float fDeltaTime);
	void OnHelperChanged();
	void CancelPendingRayHandles();
	void CheckAndReleaseRaycastHandles();
	void SetSpeakerLevels(const int nNumInputChannels, TArray<FMOD::Channel*>& aChannels);
	void OnTransformChanged(const ZEntityRef& entity, const SMatrix43& mNewValue);
	void OnSet3DWeight(float f3DWeight);
	int GetChannels(TArray<FMOD::Channel*>& aChannels);
	int GetChannelsRecursively(FMOD::ChannelGroup* pChannelGroup, TArray<FMOD::Channel*>& aChannels);
};
