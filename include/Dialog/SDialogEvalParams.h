#pragma once

#include "EDialogEvalType.h"

class SDialogInstanceData;

class SDialogEvalParams
{
public:
    SDialogInstanceData* m_pDialogData;
    TEntityRef<ZActor> m_pCandidate;
    TEntityRef<ZHM5BaseCharacter> m_pTarget;
    TRefCountPtr<ZCombatSituationMember> m_pMember;
    float m_fWeighting;
    EDialogEvalType m_eType;
};
