#pragma once

#include "float4.h"
#include "ZEntityRef.h"
#include "TEntityRef.h"
#include "TResourcePtr.h"

class ZActor;
class ZRayQueryOutput;
class ZSpatialEntity;
class ZRenderMaterialInstance;
class ZCrowdActor;

class ZHM5SBTag
{
public:
	struct SRayInfo
	{
		float4 m_vFromLocal;
		float4 m_vToLocal;
		float4 m_vPosition;
		float4 m_vNormal;
		float4 m_vDecalPosition;
		float4 m_vDecalNormal;
		ZEntityRef m_rBlockingEntity;
		TEntityRef<ZSpatialEntity> m_rBlockingSpatialEntity;
		TResourcePtr<ZRenderMaterialInstance> m_pBlockingMaterial;

		SRayInfo(const SRayInfo& __that);
		SRayInfo() = default;
		~SRayInfo() = default;
		SRayInfo& operator=(const SRayInfo& __that);
	};

	float4 m_vShotPos;
	unsigned int m_nTargetBone;
	float m_fTagTimeFraction;
	float m_fTime;
	float m_fDamageDealt;
	ZEntityRef m_rEntity;
	TEntityRef<ZCrowdActor> m_pCrowdActor;
	bool m_bKillingShot : 1;
	bool m_bKillConfirmed : 1;
	bool m_bShot : 1;
	bool m_bActorTag : 1;
	bool m_bDead : 1;
	bool m_bExplodingProp : 1;
	bool m_bActorUntaggable : 1;
	bool m_bHasHitThroughChainReaction : 1;
	bool m_bShowTag : 1;
	float m_fLocalBoneHeight;
	SRayInfo m_rayInfo;

	ZHM5SBTag(const ZHM5SBTag& __that);
	ZHM5SBTag() = default;
	float4 GetShotPos(float fScale) const;
	bool IsActorTag() const;
	bool IsCrowdTag() const;
	bool IsExplodingPropTag() const;
	bool IsKillingShot() const;
	bool IsDead() const;
	const ZEntityRef& GetTaggedEntity() const;
	void UpdateTime(float dt);
	bool operator==(const TEntityRef<ZActor>& rhs) const;
	ZHM5SBTag& operator=(const ZHM5SBTag& rhs);
	void GetRayQueryOutput(ZRayQueryOutput& RayQueryOutput) const;
	~ZHM5SBTag() = default;
};
