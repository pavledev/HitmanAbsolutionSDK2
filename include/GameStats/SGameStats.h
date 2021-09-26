#pragma once

#include "TArray.h"

struct SGameStats
{
	TArray<int> m_aKillsByBodyPart;
	TArray<int> m_aKillsByWeapon;
	TArray<int> m_aKillsBySituation;
	TArray<int> m_aKillsByVictim;
	TArray<int> m_aActorDamageByBodyPart;
	TArray<int> m_aActorDamageByWeapon;
	TArray<int> m_aStealthSituations;
	TArray<int> m_aExplodingProps;

	SGameStats(const SGameStats& __that);
	SGameStats() = default;
	~SGameStats() = default;
	SGameStats& operator=(const SGameStats& __that);
};
