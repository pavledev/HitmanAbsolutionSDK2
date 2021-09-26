#pragma once

#include "ESpeechPriority.h"
#include "SActorSoundDefs.h"
#include "ECombatDialogType.h"
#include "EActorType.h"

struct SDialogEvalParams;

struct SDialogDescData
{
	float m_fCooldownPlayed;
	float m_fCooldownAttempt;
	float m_fChance;
	ESpeechPriority m_ePriority;
	SActorSoundDefs::EDefinition m_eDialog;
	ECombatDialogType m_eDialogType;
	bool m_bFirstTimeGuaranteed;
	bool m_bAllowHolding;
	bool (*pEvalFunctor)(SDialogEvalParams& dialogEvalParams);
	float m_fWeightRandom;
	float m_fWeightInSightMin;
	float m_fWeightInSightMax;
	float m_fWeightProximity;
	float m_fMaxDist;
	EActorType m_eActorType;

	SDialogDescData() = default;
	~SDialogDescData() = default;
};
