#pragma once

#include "ZSituationBase.h"
#include "ECombatState.h"
#include "ZCombatSituationMember.h"
#include "EFleeRuleState.h"
#include "ZHandleVentGroup.h"
#include "ZHandleClosetGroup.h"
#include "ZCheckLastPositionGroup.h"
#include "ZHumanShieldGroup.h"
#include "SCombatHazardZone.h"
#include "ZGuardPointGroup.h"
#include "EHumanShieldCombatState.h"
#include "SCombatInformation.h"
#include "SDialogInformation.h"
#include "ZCombatTacticalHelper.h"
#include "SFindBestTacticalPositionOutput.h"

class alignas(16) ZProtoCombatSituation : public ZSituationBase
{
public:
    ECombatState m_combatState;
    TRefCountPtr<ZGridFloatField> m_dangerField;
    ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_dangerFieldRequest;
    TRefCountPtr<ZGridFloatField> m_fleeToGuardField;
    ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_fleeToGuardFieldRequest;
    TRefCountPtr<ZCombatSituationMember> m_pFleeCandidate;
    ZGridJobRequest<ZGridNodeRef> m_fleeNodeRequest;
    unsigned int m_nFleeIndex;
    EFleeRuleState m_eFleeRuleState;
    ZGameTime m_tNextFleeCandiate;
    TMaxArray<TEntityRef<ZActor>, 8> m_aHelpfulGuards;
    TRefCountPtr<ZHandleVentGroup> m_handleVentGroup;
    TRefCountPtr<ZHandleClosetGroup> m_handleClosetGroup;
    TRefCountPtr<ZCheckLastPositionGroup> m_checkLastPositionGroup;
    TRefCountPtr<ZHumanShieldGroup> m_humanShieldGroup;
    TMaxArray<SCombatHazardZone, 128> m_CombatHazardZones;
    THashMap<unsigned int, TRefCountPtr<ZGuardPointGroup>, TDefaultHashMapPolicy<unsigned int, TRefCountPtr<ZGuardPointGroup>>> m_guardPointToGroup;
    TMaxArray<TRefCountPtr<SKnownEntity>, 8> m_aExplosiveEntities;
    ZGameTime m_lastLOSTime;
    ZGameTime m_tTargetLostTime;
    ZGameTime m_tCombatStartTime;
    bool m_bCLPAttentionResetDone;
    float m_fCLPTargetOutOfSightTime;
    int m_nCLPCount;
    ZGridNodeRef m_rLastKnownTargetNode;
    ZHM5CoverPlane* m_pThreatCover;
    float4 m_vLastLOSPosition;
    bool m_bTargetLost;
    bool m_bSearchCompleted;
    bool m_bHandleClosetCompleted;
    ZGameTime m_tLastHandleClosetTime;
    bool m_bHandleVentCompleted;
    ZGameTime m_tLastHandleVentTime;
    ZGameTime m_tLastTacticalOrderIssued;
    ZGameTime m_tLastGuardShooting;
    EHumanShieldCombatState m_humanShieldState;
    bool m_bTargetKnownInCloset;
    bool m_bTargetKnownInVent;
    float m_fAggressionLevel;
    ZGameTime m_tLastWeaponFiredHandleTime;
    SCombatInformation m_combatInfo;
    SDialogInformation m_dialogInfo;
    TRefCountPtr<ZActorDialog> m_pSpottedDialog;
    ZCombatTacticalHelper m_TacticalInfo;
    unsigned int m_nUpdateTacticalInfoIndex;
    TRefCountPtr<ZCombatSituationMember> m_pMemberBeingUpdated;
    ZGridJobRequest<SFindBestTacticalPositionOutput> m_tacticalPositionRequest;
    ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_occupancyFieldRequest;
};
