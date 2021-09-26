#pragma once

#include "TArray.h"
#include "TEntityRef.h"
#include "IHM5Projectile.h"

class ZHM5ProjectilePool
{
public:
	TArray<TEntityRef<IHM5Projectile>> m_nProjectiles;

	static int m_snProjectileId;

	ZHM5ProjectilePool() = default;
	~ZHM5ProjectilePool() = default;
	bool CreatePool(unsigned int nNumInstances);
	void DestroyPool();
	int GetProjectiles(IHM5Projectile** pProjectiles, int nReqNum);
};
