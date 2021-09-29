#pragma once

#include "ZEntityImpl.h"
#include "IHM5Projectile.h"
#include "ZRayQueryInput.h"

class IAsyncRayHandle;
struct SGameUpdateEvent;
struct SHitInfo;

class ZHM5Projectile : public ZEntityImpl, public IHM5Projectile
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bActive;
	ZEntityRef m_pWeaponOwner;
	ZHM5ProjectileDamageProperties m_Damage;
	IAsyncRayHandle* m_pRayCastHandle;
	unsigned int m_nColiFilter;
	unsigned int m_nProjectileId;
	float m_fBulletEnergy;
	float m_fTraveledDistance;
	SMatrix43 m_mvStartMatPos;
	SVector3 m_vCurrentPos;
	SVector3 m_vTrajectoryDir;
	float m_fImpactForce;
	float m_fRagdollImpactForce;
	float m_fRagdollImpactUpKick;
	ZRayQueryInput m_coliin;
	unsigned int m_nBodyPartRecastFilter;
	bool m_bCastRay;
	bool m_bSynchronous;
	float4 m_vTracerStartPos;
	ZEntityRef m_pLastBlockingSpatialEntity;
	TEntityRef<ZCrowdActor> m_pLastBlockingCrowdActor;
	float m_fBulletSpeedMultiplier;
	const ZHM5SBTag* m_pSBTag;
	bool m_bAllowAIEvents;
	bool m_bHMPreciseShot;
	bool m_bHMBlindShot;
	bool m_bHadHit;
	bool m_bHMSnipershot;
	bool m_bHasCountedShot;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5Projectile() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	float CalcDamageByProjectile(const float4& vHitPos) override;
	const ZEntityRef GetProjectileOwner() override;
	SMatrix GetProjectileStartMatPos() override;
	float4 GetTrajectoryDir() const override;
	unsigned int GetProjectileId() const override;
	float GetImpactForce() const override;
	void SetImpactForce(float fForce) override;
	float GetRagdollImpactForce() const override;
	void SetRagdollImpactForce(float fForce) override;
	float GetRagdollImpactUpKick() const override;
	void SetRagdollImpactUpKick(float fForce) override;
	bool IsNPCProjectile() const override;

	bool IsActive() override;
	void Activate(const ZHM5ProjectileDamageProperties& Properties, const SMatrix43& mStartMatPos, const float4& vTrajectory, bool bSynchronous, unsigned int nProjectileId, bool bAllowActorHitActor, bool bAllowAIEvents) override;
	eWeaponType GetWeaponType() const override;
	void SetSBTag(const ZHM5SBTag* pSBTag) override;
	eItemType GetItemType() const override;
	const STokenID& GetItemTypeToken() const override;
	eAmmoType GetAmmoType() const override;
	bool IsSBProjectile() const override;
	const ZHM5SBTag* GetSBTag() const override;

	ZHM5Projectile() = default;
	static void RegisterType();
	ZHM5Projectile(ZComponentCreateInfo& pInfo);
	void SpawnBulletTracer(const ZRayQueryOutput& ColiOut) const;
	void SubmitNewBulletRay(ZRayQueryInput& RayInput, float nTimePassed);
	void SubmitNewBulletRay(float nTimePassed);
	void FrameUpdate(const SGameUpdateEvent& updateEvent);
	void DoImpactEffects(const bool bHitACharacter, const SHitInfo& HitInfo, ZRayQueryOutput& coliout);
	void ActivateFrameUpdate();
	void DeactivateFrameUpdate();
	void SynchronousRaycast();
	void HandleRayCollision(float fDeltaFrameTime, ZRayQueryOutput& coliout, TEntityRef<ZCrowdActor> pHitCrowdActor);
	void InitHitInfoStructure(SHitInfo& HitInfo, const ZRayQueryOutput& ColiOut) const;
	TEntityRef<ZCrowdActor> CheckBulletAgainstCrowds(ZRayQueryOutput* pOutput);
	void NotifyCrowdsAboutShotFromPos();
	void NotifyCrowdsAboutShotHitPos(const SVector3& vShotWorldPos);
	void BulletStopped();
	void BodyPartRecast(ZRayQueryOutput& coliout);
};
