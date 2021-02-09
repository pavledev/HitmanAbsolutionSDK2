#pragma once

#include "TArray.h"
#include "TEntityRef.h"
#include "IHM5Projectile.h"

class ZHM5ProjectilePool
{
public:
    TArray<TEntityRef<IHM5Projectile>> m_nProjectiles;
};
