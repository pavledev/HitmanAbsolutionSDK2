#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZSpatialEntity.h"
#include "ZSoundMultiLayerControl.h"
#include "ZSoundOcclusionProbe.h"

class ZSoundMultiLayerMixer : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TEntityRef<ZSpatialEntity> m_pSpatialEntity;
	float m_fMinDistance;
	float m_fMaxDistance;
	float m_fSpatialAttenuation;
	float m_fSpatialFalloffAttenuation;
	float m_fDirectionalAttenuation;
	float m_fAttenuationL;
	float m_fAttenuationR;
	float m_fAttenuationC;
	float m_fAttenuationLFE;
	float m_fAttenuationBackL;
	float m_fAttenuationBackR;
	float m_fAttenuationSideL;
	float m_fAttenuationSideR;
	bool m_bRaycastOcclusion;
	float m_fOcclusionAttenuation;
	float m_fOcclusionMaxRadius;
	float m_fOcclusionMinRadius;
	float m_fOcclusionMaxDistOverride;
	float m_fOcclusionSmoothingOverride;
	TEntityRef<ZSoundMultiLayerControl> m_pControlEntity;
	TEntityRef<ZSpatialEntity> m_pSpatialAspect;
	float4 m_vPosition;
	float m_fSpeakerLevels[8];
	float m_fBaseVolume[8];
	float m_fSpatialBaseVolume;
	float m_fSpatialFalloffVolume;
	float m_fDirectionalVolume;
	float m_fOcclusionVolume;
	ZSoundOcclusionProbe m_OcclusionProbe;
	float4 m_vOcclusionTargetPos;
	unsigned long long m_nFrameUpdateTag;

	static SComponentMapEntry s_componentMap[0];

	~ZSoundMultiLayerMixer() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZSoundMultiLayerMixer() = default;
	static void RegisterType();
	ZSoundMultiLayerMixer(ZComponentCreateInfo& info);
	void Update();
	void OnSetPosition(const SVector3& vPos);
	void OnSetSpatialAttenuation(float fValue);
	void OnSetSpatialFalloffAttenuation(float fValue);
	void OnSetDirectionalAttenuation(float fValue);
	void OnSetOcclusionAttenuation(float fValue);
	void OnSpatialAttenuationChanged();
	void OnSpatialFalloffAttenuationChanged();
	void OnDirectionalAttenuationChanged();
	void OnMinDistanceChanged();
	void OnMaxDistanceChanged();
	void OnAttenuationLChanged();
	void OnAttenuationRChanged();
	void OnAttenuationCChanged();
	void OnAttenuationLFEChanged();
	void OnAttenuationBackLChanged();
	void OnAttenuationBackRChanged();
	void OnAttenuationSideLChanged();
	void OnAttenuationSideRChanged();
	void OnRaycastOcclusionChanged();
	void OnOcclusionAttenuationChanged();
	void OnOcclusionMaxRadiusChanged();
	void OnOcclusionMinRadiusChanged();
	void OnOcclusionMaxDistOverrideChanged();
	void OnOcclusionSmoothingOverrideChanged();
	TEntityRef<ZSpatialEntity> GetSpatialEntity() const;
};
