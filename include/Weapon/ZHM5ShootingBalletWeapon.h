#pragma once

#include "ZHM5ProjectilePool.h"
#include "TEntityRef.h"

class ZHM5ShootingBalletWeapon
{
public:
    ZHM5ProjectilePool m_ProjectilePool;
    TEntityRef<IHM5ItemWeapon> m_rWeapon;
};
