#pragma once

#include "ZBoundedEntity.h"
#include "ISoundListenerPositionReceiver.h"
#include "ESOUND_3DROLLOFF_TYPE.h"
#include "TSharedValue.h"
#include "ZCurve.h"
#include "SFMODRolloffCurve.h"
#include "ZSoundOcclusionProbe.h"
#include "ZSoundPlayableBase.h"

class ZSoundBlendContainerExternalParameters;

class ZSoundSpatialParameter : public ZBoundedEntity, public ISoundListenerPositionReceiver
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_fMinDistance;
	float m_fMaxDistance;
	ESOUND_3DROLLOFF_TYPE m_e3dRolloffType;
	float m_fInsideConeAngle;
	float m_fOutsideConeAngle;
	float m_fOutsideAttenuation;
	float m_fDopplerLevel;
	TSharedValue<ZCurve> m_RolloffCurve;
	float m_f3DWeight;
	SVector3 m_vRandomLocationInner;
	SVector3 m_vRandomLocationOuter;
	float m_fReverbLevelNear;
	float m_fReverbLevelFar;
	float m_fReverbRadius;
	bool m_bRaycastOcclusion;
	float m_fGeometryOcclusionFactor;
	bool m_bEnableFocusLowpass;
	float m_fOcclusionAttenuation;
	float m_fOcclusionMaxRadius;
	float m_fOcclusionMinRadius;
	float m_fOcclusionMaxDistOverride;
	float m_fOcclusionReverbAttenuation;
	float m_fOcclusionLowpassHigh;
	float m_fOcclusionLowpassLow;
	float m_fLowpassMaxDistance;
	float m_fLowpassMaxDistanceCutoff;
	float m_fLFEAttenuation;
	float4 m_vPos;
	float4 m_vPosRandomOffset;
	float4 m_vVelocity;
	float4 m_vOcclusionTargetPos;
	TSharedValue<SFMODRolloffCurve> m_aCustomRolloffCurve;
	unsigned int m_nMemOptimizedData;
	ZSoundOcclusionProbe m_OcclusionProbe;
	float m_fOcclusionSmoothingOverride;
	TEntityRef<ZSoundPlayableBase> m_parentEntity;
	TEntityRef<ZSoundBlendContainerExternalParameters> m_pBlendContainer;

	static SComponentMapEntry s_componentMap[0];

	~ZSoundSpatialParameter() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void CalculateBounds(float4& vMin, float4& vMax, const unsigned int nIncludeFlags, const unsigned int nExcludeFlags) override;

	void OnListenerPositionUpdated(const SMatrix& mListenerTransform) override;

	ZSoundSpatialParameter() = default;
	static void RegisterType();
	ZSoundSpatialParameter(ZComponentCreateInfo& info);
	void OnChannelPlay(ZSoundPlayerChannel* pChannel);
	void DisableOcclusion();
	void UpdateChannels(ZSoundPlayerChannel* pChannel);
	ESOUND_3DROLLOFF_TYPE GetRolloffType() const;
	void SetPosition(const float4& vNewPos, bool bUpdateVelocity);
	void GenerateRandomPosOffset();
	int GetNumOcclusionRaycasts();
	unsigned int CreateInitialFmodMode();
	float GetOcclusionAttenuation();
	float GetOcclusionLowpassCutoff();
	bool IsFocusLowpassEnabled();
	void On3DOcclusionChangedCallback(float*& fDirect, float*& fReverb);
	void OnSet3DWeight(float f3DWeight);
	void OnSetMinDistance(float fMinDistance);
	void OnFreezePosition();
	void OnRaycastOcclusionChanged();
	void OnHelperChanged();
	void OnSetEnableFocusLowpass(bool bEnable);
	void OnSetOcclusionLowpassHigh(float fValue);
	void OnSetOcclusionLowpassLow(float fValue);
	void On3DWeightChanged();
	void OnDopplerLevelChanged();
	void OnMinDistanceChanged();
	void OnMaxDistanceChanged();
	void OnRolloffCurveChanged();
	void On3DConeSettingsChanged();
	void OnRandomLocationChanged();
	void OnReverbLevelNearChanged();
	void OnReverbLevelFarChanged();
	void OnReverbRadiusChanged();
	void Update3DPosition(ZSoundPlayerChannel* pChannel);
	void UpdateReverbParameters(const float4& vListenerPosition, ZSoundPlayerChannel* pChannel);
	void UpdateLFEAttenuation(ZSoundPlayerChannel* pChannel);
	void OnLFEAttenuationChanged();
	TArrayIterator<ZSoundPlayerChannel*> ChannelsBegin();
	TArrayIterator<ZSoundPlayerChannel*> ChannelsEnd();
	bool ChannelsEmpty() const;
};
