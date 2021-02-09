#pragma once

#include "ZSpatialEntity.h"
#include "EGameTension.h"
#include "ZHM5Outfit.h"
#include "ZActor.h"
#include "ZGameTime.h"

class alignas(8) ZSocialActor : public ZSpatialEntity
{
public:
    bool m_bEnabled;
    bool m_bDisguiseGreetingsEnabled;
    EGameTension m_eRequiredActorTension;
    float m_fCooldown;
    float m_fGreetingChance;
    float m_fResponseChance;
    float m_fHitmanGreetingChance;
    float m_fRadius;
    float m_fMinInSightTime;
    bool m_bTestActors;
    bool m_bTestHitman;
    TArray<TEntityRef<ZHM5Outfit> > m_aOutfits;
    TEntityRef<ZActor> m_pActorToControl;
    ZGameTime m_fCooldownTimer;
    bool m_bActivated;
    bool m_bRegistered;
};
