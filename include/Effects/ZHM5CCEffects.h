#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZRuntimeResourceID.h"
#include "ECCEmitterEffect.h"
#include "SMatrix.h"
#include "ECCDecalEffect.h"
#include "SComponentMapEntry.h"
#include "TResourcePtr.h"
#include "ZEntityRef.h"
#include "ZVariantRef.h"

struct SCloseCombatEffect;
class ZHitman5;
class ZHM5BaseCharacter;
class ZCrowdActor;
class ZRayQueryInput;
class ZRayQueryOutput;
class ZAnimationBoneData;
class ZAnimationBonePose;
class IEntityBlueprintFactory;
class ZComponentCreateInfo;
class ZHM5MaterialDescriptorEntity;
struct STypeID;
struct SVector3;
struct float4;

class ZHM5CCEffects : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	struct SCCEffect
	{
		float m_fEffectTime;
		int m_nBoneGlobalID;
		SMatrix m_mEmitterLocal;
		ZEntityRef m_rEffect;
		ECCEmitterEffect m_eEffect;
		TEntityRef<ZHM5BaseCharacter> m_rBaseChar;
		TEntityRef<ZCrowdActor> m_pCrowdActor;
		bool m_bActive;
		TResourcePtr<IEntityBlueprintFactory> m_pBlueprintResource;

		SCCEffect() = default;
		void Init(const TEntityRef<ZHM5BaseCharacter>& rBaseChar, const TEntityRef<ZHitman5>& pHitman, const SMatrix& mEffect);
		void Update(float fDeltaTime);
		bool GetGlobalBoneMatrix(SMatrix* pBone, SVector3* pBoneSize);
		bool GetAnimationPose(const ZAnimationBoneData** pBoneData, const ZAnimationBonePose** pBonePose);
		SMatrix GetTargetWorldMatrix();
		SMatrix GetEmitterMatrix(const float4& vNormal, const float4& vPos, const SMatrix& mBoneGlobal);
		void CastRayAgainstTarget(const ZRayQueryInput& sRayInput, ZRayQueryOutput* pOutput);
		void SetupLocalBone(const ZRayQueryOutput& RayOutput);
		~SCCEffect() = default;
	};

	TEntityRef<ZHitman5> m_pHitman;
	ZRuntimeResourceID m_SlitThroatEmitter;
	ZRuntimeResourceID m_StabEmitter;
	ZRuntimeResourceID m_Blunt1HEmitter;
	ZRuntimeResourceID m_Blunt2HEmitter;
	ZRuntimeResourceID m_Slash1HEmitter;
	ZRuntimeResourceID m_ShatterEmitter;
	ZRuntimeResourceID m_AxeCleaveEmitter;
	ZRuntimeResourceID m_AxePullEmitter;
	ZRuntimeResourceID m_AxePullSlitThroatEmitter;
	ZRuntimeResourceID m_FacePunchEmitter;
	ZRuntimeResourceID m_BloodEmitter;
	TEntityRef<ZHM5MaterialDescriptorEntity> m_rSlitThroatDecal;
	TEntityRef<ZHM5MaterialDescriptorEntity> m_rStabDecal;
	TEntityRef<ZHM5MaterialDescriptorEntity> m_rBlunt1HDecal;
	TEntityRef<ZHM5MaterialDescriptorEntity> m_rBlunt2HDecal;
	TEntityRef<ZHM5MaterialDescriptorEntity> m_rSlash1HDecal;
	TEntityRef<ZHM5MaterialDescriptorEntity> m_rShatterDecal;
	TEntityRef<ZHM5MaterialDescriptorEntity> m_rAxeCleaveDecal;
	TEntityRef<ZHM5MaterialDescriptorEntity> m_rAxePullsDecal;
	TEntityRef<ZHM5MaterialDescriptorEntity> m_rAxePullsSlitThroat;
	TEntityRef<ZHM5MaterialDescriptorEntity> m_rFacePunchEmitterDecal;
	TEntityRef<ZHM5MaterialDescriptorEntity> m_rBruise;
	int m_NumSlitThroatEmitters;
	int m_NumStabEmitters;
	int m_NumBlunt1HEmitters;
	int m_NumBlunt2HEmitters;
	int m_NumSlash1HEmitters;
	int m_NumShatter1HEmitters;
	int m_NumAxeCleaveEmitters;
	int m_NumAxePullEmitters;
	int m_NumAxeSlitThroatEmitters;
	int m_NumFacePunchEmitters;
	int m_NumBloodEmitters;
	SCCEffect* m_pEmitters;
	int m_nNumEmitters;
	bool m_bEnabled;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5CCEffects() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZHM5CCEffects() = default;
	static void RegisterType();
	ZHM5CCEffects(ZComponentCreateInfo& info);
	void Update();
	void StartEffect(const TEntityRef<ZHM5BaseCharacter>& rBaseChar, const SCloseCombatEffect& sEffect, const SMatrix& mEffect);
	void SetHitman(const TEntityRef<ZHitman5>& pHitman);
	void Reset();
	void SetEnabled(bool bEnabled);
	SCCEffect* GetEmitterEffect(ECCEmitterEffect eEffect);
	void SetDecal(const TEntityRef<ZHM5BaseCharacter>& rBaseChar, const SMatrix& mDecal, ECCDecalEffect eEffect);
};
