#pragma once

#include "ZSpatialEntity.h"
#include "IParticleEmitterEntity.h"
#include "ZResourcePtr.h"
#include "SParticleBlockHeader.h"
#include "ZParticleControllerEntity.h"
#include "TSharedPointer.h"
#include "ZEntitySingleton.h"

class ZParticleEmitterBaseEntity : public ZSpatialEntity, public IParticleEmitterEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_fSpeedMin;
	float m_fSpeedMax;
	float m_fInnerConeAngle;
	float m_fOuterConeAngle;
	ZResourcePtr m_pParticleControllerResource;
	ZEntityRef m_ParticleController;
	bool m_bEnabled;
	bool m_bEmitterSpaceParticles;
	bool m_bActivated : 1;
	bool m_bPositionPrevIsFoobar : 1;
	bool m_bHasVelocityConstants : 1;
	bool m_bEnabledRT : 1;
	bool m_bHasBeenEnabledRT : 1;
	bool m_bLulling : 1;
	bool m_bUsingControllerEntityRef : 1;
	bool m_bControllerResourceIsBad : 1;
	bool m_bIsStreamedIn : 1;
	float m_fEmissionTimeSeconds;
	float m_fParticlesPerSecond;
	float m_fParticlesPerSecondMax;
	float m_fFixedEmissionCount;
	float m_fVelocityContributionFactor;
	ZEntityRef m_TriggerBox;
	float m_fEmissionCameraProximity;
	SParticleBlockHeader* m_pBlockList;
	SVector3 m_vPositionPrev;
	unsigned int m_nShaderMask;
	float m_fEmissionTimeLeft;
	float m_fEmissionTimeFraction;
	float m_fEmissionCntLeft;
	int m_nESEntry;
	ZParticleControllerEntity* m_pParticleController;
	TSharedPointer<ZEntitySingleton> m_ParticleControllerSingletonPtr;

	static SComponentMapEntry s_componentMap[0];

	~ZParticleEmitterBaseEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void StreamIn() override;
	void StreamOut() override;
	bool IsStreamedIn() override;
	void Init() override;
	void OnSpatialChange() override;

	unsigned int GetEmissionCount(float fDeltaTime, const float4& vCameraPosition, float4* avCameraCullPlanes) override;
	bool UseEmitterSpaceParticles() const override;
	int GetEmitterSpaceEntry() const override;
	void SetEmitterSpaceEntry(int nEmitterSpaceEntry) override;
	void ActivateEmitter() override;
	void DeactivateEmitter() override;
	void ParticleControlerDeleted(const ZParticleControllerEntity* pDeletedController) override;

	ZParticleEmitterBaseEntity() = default;
	static void RegisterType();
	ZParticleEmitterBaseEntity(const ZParticleEmitterBaseEntity& __that);
	ZParticleEmitterBaseEntity(ZComponentCreateInfo& Info, unsigned int nShaderId);
	unsigned int ShaderMask();
	bool IsEnabled() const;
	SParticleBlockHeader* GetBlockListPtr() const;
	void SetBlockListPtr(SParticleBlockHeader* ptr);
	ZParticleControllerEntity* GetParticleController(bool bPreventEnable, bool bNoCreate);
	void SetDirty();
	void SetSizeDirty();
	void OnActivate();
	void OnDeactivate();
	void OnSetSpeedMin(float newVal);
	void OnSetSpeedMax(float newVal);
	void OnSetInnerConeAngle(float newVal);
	void OnSetOuterConeAngle(float newVal);
	void OnSetMinParticlesPerSecond(float newVal);
	void OnSetMaxParticlesPerSecond(float newVal);
	void OnParticleControllerResourceChanged();
	void OnEnabledChanged(const bool& bOldEnabled);
	void OnEnabledRTChanged(const bool& bOldEnabledRT);
	void OnVelocityContributionChanged(const float& fOldVelocityContribution);
	bool HasVelocityConstants() const;
	ZParticleEmitterBaseEntity& operator=(const ZParticleEmitterBaseEntity& __that);
};
