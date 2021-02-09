#pragma once

#include "ZHM5GuideJump.h"
#include "ZTextListData.h"

class SWindowZone;

class alignas(16) ZHM5GuideLedge : public ZHM5GuideJump
{
public:
    bool m_bMountableFromTop;
    bool m_bWalkable;
    bool m_bMountDismountLeft;
    bool m_bMountDismountRight;
    TResourcePtr<ZTextListData> m_pTextListResource;
    ZString m_sEnterTextID;
    ZString m_sCachedEnterString;
    SMatrix33 m_mLeftMDMArea;
    SMatrix33 m_mRightMDMArea;
    SVector3 m_vLeftMDMArea;
    SVector3 m_vRightMDMArea;
    TArray<SWindowZone> m_WindowZones;

    virtual void OnWalkableChanged();
    virtual void OnMountDismountLeftChanged();
    virtual void OnMountDismountRightChanged();
    virtual void OnMountableFromTopChanged();
};
