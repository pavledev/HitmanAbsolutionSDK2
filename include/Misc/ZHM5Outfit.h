#pragma once

#include "ZEntityImpl.h"
#include "IHM5Outfit.h"
#include "TEntityRef.h"
#include "ZTokenIDEntity.h"
#include "TResourcePtr.h"

class ZHM5Outfit : public ZEntityImpl, public IHM5Outfit
{
public:
    int m_iZoneMask;
    bool m_bZoneDefault;
    bool m_bZoneA;
    bool m_bZoneB;
    bool m_bZoneC;
    bool m_bZoneD;
    bool m_bZoneE;
    bool m_bZoneF;
    bool m_bZoneG;
    bool m_bZoneH;
    TArray<TEntityRef<ZTokenIDEntity>> m_aOutfitTokens;
    TResourcePtr<ZEntityRef> m_ContentKitEntity;
};
