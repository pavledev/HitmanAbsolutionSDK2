#pragma once

#include "TArray.h"

class SGameStats
{
public:
    TArray<int> m_aKillsByBodyPart;
    TArray<int> m_aKillsByWeapon;
    TArray<int> m_aKillsBySituation;
    TArray<int> m_aKillsByVictim;
    TArray<int> m_aActorDamageByBodyPart;
    TArray<int> m_aActorDamageByWeapon;
    TArray<int> m_aStealthSituations;
    TArray<int> m_aExplodingProps;
};
