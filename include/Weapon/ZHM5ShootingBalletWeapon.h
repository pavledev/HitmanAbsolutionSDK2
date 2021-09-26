#pragma once

#include "ZHM5ProjectilePool.h"
#include "TEntityRef.h"

class ZHM5ShootingBalletWeapon
{
public:
	ZHM5ProjectilePool m_ProjectilePool;
	TEntityRef<IHM5ItemWeapon> m_rWeapon;

	ZHM5ShootingBalletWeapon() = default;
	void SetWeapon(const TEntityRef<IHM5ItemWeapon>& rWeapon);
	void Fire(const float4& vFrom, const float4& vAt, unsigned int iBulletId, const ZHM5SBTag& tag);
	~ZHM5ShootingBalletWeapon() = default;
};
