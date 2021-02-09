#pragma once

#include "ZEntityImpl.h"
#include "IHM5ActionEntityListener.h"
#include "ZHM5Outfit.h"

class alignas(4) ZHM5DisguiseSafeZoneEntity : public ZEntityImpl, public IHM5ActionEntityListener
{
public:
    TEntityRef<IChildNetworkEntity> m_pSafeZoneNetwork;
    TEntityRef<ZHM5Action> m_pAction;
    TArray<TEntityRef<ZHM5Outfit> > m_OutfitList;
    TEntityRef<ZSpatialEntity> m_pSafeZoneOrigin;
    TEntityRef<IEventConsumerCollection> m_pEventConsumerCollection;
    bool m_bHideItems;
    bool m_bHideHitman;
    bool m_bEnabled;
    bool m_bAlignYawAngle;
    float m_fYawAngle;
    bool m_bAlignPitchAngle;
    float m_fPitchAngle;
    bool m_bSafeZoneInUse;
};
