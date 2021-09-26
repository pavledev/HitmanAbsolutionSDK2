#pragma once

#include "EActorType.h"
#include "ECombatDialogType.h"
#include "ESpeechPriority.h"
#include "SActorSoundDefs.h"
#include "TEntityRef.h"
#include "ZGameTime.h"

class ZActor;
struct SDialogDescData;

struct SDialogInstanceData
{
	SDialogDescData* m_pData;
	TEntityRef<ZActor> m_pLastSpeaker;
	ZGameTime m_cooldownTime;
	ZGameTime m_spokenEndTime;
	unsigned char m_secPriority;
	bool m_bPreventLastSpeaker;
	bool m_bSharedCooldownGroup;
	bool m_bResponseGroup;
	bool m_bPlaying;

	void Init(unsigned char nIndex);
	void Reset();
	float GetCooldownPlayed();
	float GetCooldownAttempt();
	float GetChance();
	ESpeechPriority GetPriority();
	SActorSoundDefs::EDefinition GetDialog();
	ECombatDialogType GetDialogType();
	bool GetFirstTimeGuaranteed();
	bool GetAllowHolding();
	float GetWeightRandom();
	float GetWeightInSightMin();
	float GetWeightInSightMax();
	float GetWeightProximity();
	float GetMaxDist();
	EActorType GetActorType();
	SDialogInstanceData(const SDialogInstanceData& __that);
	SDialogInstanceData() = default;
	~SDialogInstanceData() = default;
};
