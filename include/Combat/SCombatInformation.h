#pragma once

#include "EActorGroup.h"

class SCombatInformation
{
public:
    int m_nActiveFighting;
    int m_nActorsInHoldGuard;
    int m_nHumanShieldGroups;
    int m_nCheckLastPositionGroups;
    int m_nDeaths;
    int m_nGuardsShooting;
    int m_nPotentialCLPActorCount;
    bool m_bNoStanddown;
    EActorGroup m_actorGroupForCLP;
};
