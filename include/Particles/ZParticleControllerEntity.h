#pragma once

#include "ZEntityImpl.h"
#include "EParticleSpritePivotLocation.h"
#include "SColorRGB.h"
#include "ZParticleRenderEntityBase.h"
#include "ParticleControllerJobFeedback.h"
#include "TFixedArray.h"
#include "SCollidingParticle.h"
#include "TBlockArray.h"
#include "SParticleEmitterEntry.h"
#include "TBag.h"

class ZParticleControllerEntity : public ZEntityImpl, public IParticleControllerEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EControllerDirtyFlagShifts
	{
		EMITTER_CONST_SIZE_DIRTY_SHIFT = 0,
		MODIFIER_CONST_SIZE_DIRTY_SHIFT = 1,
		PROPERTIES_DIRTY_SHIFT = 2,
		NUM_DEAD_NEEDED_DIRTY_SHIFT = 3,
		MODIFIERS_DIRTY_SHIFT = 4,
		EMITTERS_DIRTY_SHIFT = 5,
		JUST_DIRTY_SHIFT = 6,
		EMITTER_SHADER_MASK_DIRTY_SHIFT = 7,
		MODIFIER_SHADER_MASK_DIRTY_SHIFT = 8
	};

	enum EControllerDirtyFlags
	{
		EMITTER_CONST_SIZE_DIRTY = 1,
		MODIFIER_CONST_SIZE_DIRTY = 2,
		PROPERTIES_DIRTY = 4,
		NUM_DEAD_NEEDED_DIRTY = 8,
		MODIFIERS_DIRTY = 16,
		EMITTERS_DIRTY = 32,
		JUST_DIRTY = 64,
		EMITTER_SHADER_MASK_DIRTY = 128,
		MODIFIER_SHADER_MASK_DIRTY = 256,
		ALL_DIRTY = 511
	};

	ZResourcePtr m_pParticleRenderResource;
	ZEntityRef m_ParticleRender;
	unsigned int m_nMaxNumParticles;
	float m_fParticleCollisionSizeFactor;
	float m_fMotionStretchFactor;
	EParticleSpritePivotLocation m_ePivotLocation;
	float m_fWindMultiplier;
	float m_fCameraFadeNearDistance;
	float m_fCameraFadeFarDistance;
	float m_fCameraFadeSizeFactor;
	float m_fTimeToLiveSecondsMin;
	float m_fTimeToLiveSecondsMax;
	float m_fRotationSpeedMin;
	float m_fRotationSpeedMax;
	float m_fInitialRotation;
	float m_fInitialRotationDeviation;
	SVector3 m_vUpVectorRangeStart;
	SVector3 m_vUpVectorRangeEnd;
	SColorRGB m_ParticleColorRangeStart;
	SColorRGB m_ParticleColorRangeEnd;
	float m_fParticleSizeMin;
	float m_fParticleSizeMax;
	float m_fArrayIndexMin;
	float m_fArrayIndexMax;
	bool m_bGlobalAttractorsEnabled;
	bool m_bSizeDependantFadeDistances;
	bool m_bRandomRotation;
	bool m_bEmitterSpaceInitialUpVector;
	bool m_bEmitFrozen;
	bool m_bRandomFlipU;
	bool m_bRandomFlipV;
	bool m_bSomeEmittersWereDisabled : 1;
	bool m_bUsingRenderEntityRef : 1;
	bool m_bRenderResourceIsBad : 1;
	bool m_bIsStreamedIn : 1;
	ZParticleRenderEntityBase* m_pParticleRender;
	TSharedPointer<ZEntitySingleton> m_ParticleRenderSingletonPtr;
	ParticleControllerJobFeedback* m_pFeedback;
	TFixedArray<SCollidingParticle, 8> m_CollisionsFeedback;
	TBlockArray<SParticleEmitterEntry> m_ParticleEmitters;
	TArray<ZParticleEmitterBaseEntity*> m_ParticleEmittersDisabled;
	TArray<SParticleBlockHeader*> m_RemovedParticleEmittersThisFrame;
	TBag<TEntityRef<IParticleModifierEntity>, TArray<TEntityRef<IParticleModifierEntity>>> m_ParticleModifiers;
	unsigned int m_nNumModifiers;
	TBag<TEntityRef<IParticleHeirEntity>, TArray<TEntityRef<IParticleHeirEntity>>> m_ParticleHeirs;
	TEntityRef<IParticleColliderEntity> m_ParticleCollider;
	int m_nDirty;
	unsigned int m_nConstSizeEmitterCnt;
	unsigned int m_nLastConstSize;
	unsigned int m_nLastModifierConstSize;
	unsigned int m_nLastEmitterConstSize;
	unsigned int m_nEmitterShaderMask;
	unsigned int m_nModifierShaderMask;
	void* m_pPreviousSimulationMemBuffer;
	unsigned int m_nNumDeadParticlesNeeded;

	static SComponentMapEntry s_componentMap[0];

	~ZParticleControllerEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void StreamIn() override;
	void StreamOut() override;
	bool IsStreamedIn() override;
	void Init() override;

	void RegisterEmitter(ZParticleEmitterBaseEntity* pParticleEmitter, bool bEmitterSpaceParticles) override;
	void UnregisterEmitter(ZParticleEmitterBaseEntity* pParticleEmitter, bool bEmitterSpaceParticles) override;
	void EnableEmitter(ZParticleEmitterBaseEntity* pParticleEmitter, bool bEmitterSpaceParticles) override;
	bool DisableEmitter(ZParticleEmitterBaseEntity* pParticleEmitter, bool bEmitterSpaceParticles) override;
	void RegisterModifier(const TEntityRef<IParticleModifierEntity>& pParticleModifier) override;
	void UnregisterModifier(const TEntityRef<IParticleModifierEntity>& pParticleModifier) override;
	void RegisterHeir(const TEntityRef<IParticleHeirEntity>& pParticleHeir) override;
	void UnregisterHeir(const TEntityRef<IParticleHeirEntity>& pParticleHeir) override;
	void HeirChanged() override;
	void RegisterCollider(const TEntityRef<IParticleColliderEntity>& pParticleCollider) override;
	void UnregisterCollider(const TEntityRef<IParticleColliderEntity>& pParticleCollider) override;

	ZParticleControllerEntity() = default;
	static void RegisterType();
	ZParticleControllerEntity(ZComponentCreateInfo& Info);
	const TBag<TEntityRef<IParticleModifierEntity>, TArray<TEntityRef<IParticleModifierEntity>>>& GetParticleModifiers() const;
	unsigned int BeginUpdate(void* pBuffer, float fDeltaTime, const float4& vCameraPosition, float4* avCameraCullPlanes, bool bRepack);
	void EndUpdate();
	unsigned int ConstSize();
	unsigned int ShaderMask();
	void SetDirtyFlag(EControllerDirtyFlags flag);
	void OnPropertyChanged();
	void OnSetParticleCollisionSizeFactor(float newVal);
	void OnSetMotionStretchFactor(float newVal);
	void OnSetRandomRotation(bool newVal);
	void OnMaxNumParticlesChanged();
	void OnParticleRenderResourceChanged();
	ZParticleRenderEntityBase* GetParticleRender(bool bNoCreate);
	void UpdateNumDeadParticlesNeeded();
	void HandleDeadParticles();
	void HandleCollidingParticles();
	void ConstPackProperties(ParticleControllerJobEntry* pControllerJobEntry);
	float GetInitialRotation() const;
	SParticleBlockHeader* InitBlockPtr();
	void TrulyDisableEmitters();
};
