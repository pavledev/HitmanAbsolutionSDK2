#pragma once

#include "ZEntityRef.h"
#include "ZPhysicsObjectRef.h"
#include "IProjectile.h"
#include "float4.h"
#include "SExplodeInfo.h"

struct SHitInfo
{
	ZEntityRef m_HitEntity;
	ZPhysicsObjectRef m_pHitBody;
	unsigned int m_nHitBoneIndex;
	IProjectile* m_pProjectile;
	float4 m_vHitPos;
	float4 m_vHitNormal;
	SExplodeInfo m_Explosion;
	unsigned int m_nActorDeathType;
	bool m_bHitmanPreciseAim : 1;
	bool m_bHitmanBlindShot : 1;
	bool m_bHitmanSnipershot : 1;
	IProjectile* m_pChainReactionProjectile;

	SHitInfo(const SHitInfo& __that);
	SHitInfo() = default;
	float GetBaseDamage() const;
	float GetExplosionDamage() const;
	bool IsExplosion() const;
	bool IsProjectile() const;
	float GetTrajectoryLength() const;
	~SHitInfo() = default;
	SHitInfo& operator=(const SHitInfo& __that);
};
