#pragma once

#include "EDialogEvalType.h"
#include "TEntityRef.h"
#include "TRefCountPtr.h"

struct SDialogInstanceData;
class ZActor;
class ZHM5BaseCharacter;
class ZCombatSituationMember;

struct SDialogEvalParams
{
	SDialogInstanceData* m_pDialogData;
	TEntityRef<ZActor> m_pCandidate;
	TEntityRef<ZHM5BaseCharacter> m_pTarget;
	TRefCountPtr<ZCombatSituationMember> m_pMember;
	float m_fWeighting;
	EDialogEvalType m_eType;

	SDialogEvalParams(SDialogInstanceData* pDialogData, TEntityRef<ZActor> pCandidate, TEntityRef<ZHM5BaseCharacter> pTarget, TRefCountPtr<ZCombatSituationMember> pMember, float fWeighting, EDialogEvalType eType);
	SDialogEvalParams() = default;
	~SDialogEvalParams() = default;
};
