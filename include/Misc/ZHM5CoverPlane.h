#pragma once

#include "ZBoundedEntity.h"
#include "IHM5CoverPlane.h"
#include "SVector2.h"
#include "eCoverSize.h"
#include "eExtraPlaneProperty.h"
#include "sNeighbourInfo.h"

class ZHM5CoverPlane : public ZBoundedEntity, public IHM5CoverPlane
{
public:
    sNeighbourInfo m_Neighbours[2];
    SVector3 m_vCoverPos;
    SVector3 m_vCoverSideDir;
    SVector2 m_vCoverDir;
    float m_fCornerT;
    unsigned __int8 m_nCornerFlags;
    unsigned int m_nAIReservingActorIdentifier;
    unsigned __int8 m_nAIFlags;
    bool m_bDisableNPC;
    bool m_bDisablePush;
    bool m_bShootOverDisabled;
    bool m_bDisableCornerRight;
    bool m_bDisableCornerLeft;
    bool m_bGiveFocusOnDumpBody;
    bool m_bDumpedBodyHidden;
    bool m_bIgnoreCoverSpeedRestriction;
    float m_fCoverLength;
    float m_fCoverDepth;
    eCoverSize m_CoverSize;
    eExtraPlaneProperty m_ExtraPlaneProperty;
    bool m_bForceCoverSpot;
    bool m_bWindowCover;
    bool m_bIgnoreCornerAngle;
    __int8 m_bActivated : 1;
    __int8 m_bEnabled : 1;
    __int8 m_bPlaneValidForColiWorld : 1;
    __int8 m_bInEditMode : 1;
    __int8 m_bStreamedIn : 1;
    __int8 m_bAddedStateReadyEvent : 1;

    enum ESide : __int32
    {
        RIGHT = 0x0,
        LEFT = 0x1
    };

    enum eEdgePointIndex : __int32
    {
        EDGE00 = 0x0,
        EDGE01 = 0x1,
        EDGE10 = 0x2,
        EDGE11 = 0x3
    };
};
