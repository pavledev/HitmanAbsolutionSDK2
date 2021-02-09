#pragma once

#include "ZDynamicResourceLibrary.h"
#include "TEntityRef.h"
#include "IHM5Outfit.h"

class alignas(4) SLoadingOutfit
{
public:
    ZDynamicResourceLibrary* m_pOutfitLibrary;
    TEntityRef<IHM5Outfit> m_Outfit;
    __int8 m_bPlaceClothBundle : 1;
    __int8 m_bForce : 1;
    __int8 m_bEquipWhenReady : 1;
};
