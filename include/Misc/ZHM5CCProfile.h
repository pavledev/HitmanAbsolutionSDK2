#pragma once

#include "ZEntityImpl.h"
#include "EActorCCPreset.h"

class ZHM5CCProfile : public ZEntityImpl
{
public:
    int m_nAttacksForTakeDown;
    float m_fTakeDownWindow;
    float m_fTakeDownWindowIncFraction;
    float m_fHitmanDamage;
    bool m_bAllowAttackingHitman;
    float m_fDecayTime;
    int m_nKillMashNum;
    int m_nNumChainsToKill;
    EActorCCPreset m_eActorCCPreset;
};
