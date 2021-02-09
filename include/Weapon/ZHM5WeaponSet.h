#pragma once

#include "TEntityRef.h"
#include "IHM5Item.h"

class alignas(4) ZHM5WeaponSet
{
public:
    TEntityRef<IHM5Item> m_rItems[2];
    
    union
    {
        unsigned __int8 m_unionInt;
        
        struct
        {
            __int8 m_bCanDualWield : 1;
            __int8 m_bDualWieldMode : 1;
        };
    };
};
