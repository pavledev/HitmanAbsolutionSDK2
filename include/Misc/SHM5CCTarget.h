#pragma once

#include "TEntityRef.h"
#include "ZActor.h"
#include "ECCNodeType.h"
#include "ECCTargetPos.h"

class alignas(16) SHM5CCTarget
{
public:
    TEntityRef<ZActor> m_rActor;
    bool m_bAtPos;
    bool m_bValidPos;
    ECCNodeType m_eStartState;
    ECCTargetPos m_eTargetPos;
    float4 m_vPos;
    float4 m_vRunInPos;
    bool m_bSelected;
    bool m_bPassified;
    float m_fTimeToAttack;
    bool m_bDisabled;
    bool m_bMainTarget;
    bool m_bBeenMainTarget;
    float m_fDamageReceived;
    float m_fPendingDamage;
    float m_fTimeInQueue;
    unsigned int m_nNormalAttacksReceived;
    bool m_bFirstAttack;
};
