#pragma once

#include "ZSpatialEntity.h"
#include "ZResourcePtr.h"
#include "SActorSoundDefs.h"
#include "IChildNetworkEntity.h"

class alignas(4) ZCombatActEntity : public ZSpatialEntity
{
public:
    ZResourcePtr m_pGizmo;
    SActorSoundDefs::EDefinition m_eDialog;
    bool m_bEnableOnStart;
    bool m_bAlignActor;
    bool m_bEnableDefault;
    bool m_bEnableReverse;
    float m_fTriggerRadius;
    float m_fDefaultRadius;
    float m_fDefaultAlignAngle;
    float m_fDefaultActivationAngle;
    float m_fDefaultActivationArc;
    SVector3 m_vDefaultAlignOffset;
    float m_fReverseRadius;
    float m_fReverseAlignAngle;
    float m_fReverseActivationAngle;
    float m_fReverseActivationArc;
    SVector3 m_vReverseAlignOffset;
    TEntityRef<IChildNetworkEntity> m_pDefaultAct;
    TEntityRef<IChildNetworkEntity> m_pReverseAct;
    bool m_bIsActive;
    bool m_bIsLocked;
    bool m_bActivated;
};
