#pragma once

#include "ZHM5BaseGuide.h"
#include "eJumpType.h"
#include "EForceDismountBehavior.h"
#include "EForceDropDownDirection.h"
#include "SSafeZone.h"

class alignas(16) ZHM5GuideJump : public ZHM5BaseGuide
{
public:
    IPhysicsObject* m_pAnchor;
    SMatrix m_mvAnchorMatPos;
    float4 m_vAnchorHalfSize;
    bool m_bKickNPCIsAccident;
    bool m_bBodyDumpEnabled;
    bool m_bDumpedBodyHidden;
    bool m_bHangable;
    bool m_bHangAutoDismount;
    SVector2 m_vSize;
    TEntityRef<ZHM5GuideJump> m_LandingZone;
    eJumpType m_JumpType;
    EForceDismountBehavior m_eForceGettingUpBehavior;
    EForceDismountBehavior m_eForceDropDownBehavior;
    EForceDropDownDirection m_eForceDropDownDirection;
    bool m_bDisableAnchor;
    bool m_bAllowDropDown;
    bool m_bMountableFromBottom;
    SVector3 m_vPlaneNormal;
    SVector3 m_vCenterToEdgeDir;
    float m_fPullIn;
    ZHM5BaseGuide* m_pLeftSideConnectedGuide;
    ZHM5BaseGuide* m_pRightSideConnectedGuide;
    TArray<SSafeZone> m_SafeZones;

    virtual float4* CalcGetLineEdgeIntersection(float4* result, const float4*, const float4*, bool, float);
    virtual void OnSizeChanged();
    virtual void OnLandingZoneChanged();
    virtual void OnDisableAnchorChanged();
};
