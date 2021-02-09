#pragma once

#include "ZContentKitEntity.h"
#include "ZHM5WeaponBasicConfigEntity.h"

class alignas(4) ZFireArmKitEntity : public ZContentKitEntity
{
public:
    TEntityRef<ZHM5WeaponBasicConfigEntity> m_BasicConfig;
    ZRuntimeResourceID m_sHiResNotebookImage;
    bool m_bIsNewPickup;

    virtual bool PickedUp(int, int);
    virtual bool WasPickedUp(int, int);
    virtual bool IsNewPickUp(int, int);
};
