#pragma once

#include "TEntityRef.h"
#include "IHM5ItemWeapon.h"
#include "ZLinkedEntity.h"
#include "ESlowDownState.h"
#include "ZHitman5.h"
#include "ZMapPoly.h"

class alignas(8) ZHM5SniperController
{
public:
    TEntityRef<IHM5ItemWeapon> m_rSniper;
    TEntityRef<ZLinkedEntity> m_pReplica;
    int m_nCurScopeZoomIndex;
    float m_fBobingAngleX;
    float m_fBobingAngleY;
    bool m_bModelSwitched;
    SVector2 m_vDrag;
    float4 m_vSniperShootDir;
    bool m_bUpdateCamera;
    bool m_bResetCameraCollision;
    bool m_bActive;
    bool m_bEnableSlowdown;
    float m_fSlowDownTime;
    float m_fPrecisionAimTimer;
    ESlowDownState m_eSlowDownState;
    TEntityRef<ZHitman5> m_pHitman;
    float m_fMainCamFPSFovBefore;
    SHM5ScopeParameters m_ScopeParameters;
    float m_fRecoilTime;
    ZMapPoly m_MapPoly;
    float m_fZoomInTime;
    float m_fPrecisionAim;
    ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_OnHairtriggerStart;
    ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_OnHairtriggerStop;
};
