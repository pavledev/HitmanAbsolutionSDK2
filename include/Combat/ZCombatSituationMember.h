#pragma once

#include "ZSituationMember.h"

class alignas(8) ZCombatSituationMember : public ZSituationMember
{
public:
    float m_fDistanceToTarget;
    float m_fDistanceFieldValue;
    bool m_bIsPreferredToFire;
    bool m_bIsReinforcing;
    bool m_bCanRequestCoverFire;
    bool m_bDialogPreventShooting;
    bool m_bCanFlee;
    bool m_bCantFleeNoPath;
};
