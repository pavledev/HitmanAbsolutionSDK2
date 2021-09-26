#pragma once

#include "ECombatDialogType.h"
#include "SActorSoundDefs.h"
#include "TArray.h"
#include "TMaxArray.h"
#include "SDialogPendingData.h"
#include "SDialogSlotData.h"

class ZActor;
class ZCombatSituationMember;
class ZHM5BaseCharacter;
class ZProtoCombatSituation;
class ZSituationMember;
struct SDialogEvalParams;
struct SDialogInstanceData;
template <class T> class TEntityRef;
template <class T> class TRefCountPtr;
template <class T> class TRefCountPtrArg;

class ZCombatDialogManager
{
public:
	enum EDialogGroupType
	{
		EDGT_SharedCooldown = 0,
		EDGT_Response = 1
	};

	struct SDialogGroup
	{
		TArray<SDialogInstanceData*> m_pDialogs;
		EDialogGroupType m_eType;
		float m_fCooldown;

		bool IsType(EDialogGroupType eType);
		void SetCooldown(float fCooldown);
		float GetCooldown();
		SDialogGroup(const SDialogGroup& __that);
		SDialogGroup() = default;
		~SDialogGroup() = default;
	};

	class ZCombatDialogManagerInternal
	{
	public:
		TArray<SDialogInstanceData> m_aDialogs;
		TArray<SDialogGroup> m_aDialogGroups;
		TMaxArray<SDialogPendingData, 1> m_aDialogsPending;
		TMaxArray<SDialogSlotData, 1> m_aDialogSlots;
		ZProtoCombatSituation* m_pCombatSituation;

		ZCombatDialogManagerInternal() = default;
		~ZCombatDialogManagerInternal() = default;
	};

	ZCombatDialogManagerInternal* m_pInternal;

	ZCombatDialogManager() = default;
	~ZCombatDialogManager() = default;
	void SetCombatSituation(ZProtoCombatSituation* pCombatSituation);
	void Update();
	void Reset();
	bool Play(SActorSoundDefs::EDefinition eSoundDef, TEntityRef<ZActor> pActor, TRefCountPtr<ZCombatSituationMember> pMember, ECombatDialogType eDialogType, SActorSoundDefs::EDefinition eResponseTo);
	SDialogInstanceData* LookupInstanceData(SActorSoundDefs::EDefinition eDialog);
	void OnActorLeave(TRefCountPtrArg<ZSituationMember> pMember);
	SDialogGroup* DialogGroup_Create(EDialogGroupType eType, SActorSoundDefs::EDefinition eDialog, SActorSoundDefs::EDefinition eOtherDialog);
	void DialogGroup_Append(SDialogGroup* pDialogGroup, SActorSoundDefs::EDefinition eDialog);
	bool UpdateSlots();
	void UpdateSituationBanter();
	void UpdateActorBanter();
	void UpdateSpeakerSelection();
	bool CanPlay(SDialogEvalParams& evalParams, int eDialogType);
	SDialogPendingData* TryAddPending(SDialogInstanceData* pDialogData, TEntityRef<ZActor> pActor, TEntityRef<ZHM5BaseCharacter> pTarget, bool bForceSpeaker);
	bool PlayPending(SDialogPendingData* pPending);
	bool CalculateActorWeighting(SDialogEvalParams& evalParams);
	void ApplySharedCoolDown(SDialogInstanceData* pDialog);
	bool AddResponse(SDialogInstanceData* pDialog, SDialogInstanceData* pResponseDialog, TEntityRef<ZActor> pResponseSpeaker, bool& bResponseQueued, bool& bAddPendingResponse);
	bool TryPlayResponse(SDialogInstanceData* pDialog, TEntityRef<ZActor> pResponseSpeaker, bool& bResponseQueued, bool& bAddPendingResponse);
};
