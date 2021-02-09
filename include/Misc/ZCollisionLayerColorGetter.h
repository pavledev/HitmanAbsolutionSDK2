#pragma once

#include "ICollisionManager.h"

class alignas(4) ZCollisionLayerColorGetter
{
public:
    ICollisionManager* m_pColMan;
    unsigned int m_nColorOverride;
    __int8 m_bIsInWorld : 1;
    __int8 m_bIsSleeping : 1;
    __int8 m_bIsStatic : 1;
    __int8 m_bStopMode : 1;
};
