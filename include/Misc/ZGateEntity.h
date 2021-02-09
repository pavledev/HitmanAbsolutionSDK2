#pragma once

#include "ZBoundedEntity.h"
#include "IGateEntity.h"
#include "ZPresenceState.h"
#include "ZResourcePtr.h"

class alignas(4) ZGateEntity : public ZBoundedEntity, public IGateEntity, public ZPresenceState
{
public:
    bool m_bIsOpen;
    bool m_bSound;
    bool m_bVisibility;
    bool m_bPerception;
    bool m_bReasoning;
    SColorRGB m_ClosedColor;
    SVector3 m_vPortalSize;
    ZEntityRef m_RoomLeft;
    bool m_bFlipLeftNormal;
    ZEntityRef m_RoomRight;
    float m_fClipDistance;
    TArray<ZEntityRef> m_Clients;
    ZResourcePtr m_pHelper;
    SVector3 m_vConnectorOffset;
    __int8 m_bActive : 1;

    virtual void SetOpen(bool);
};
