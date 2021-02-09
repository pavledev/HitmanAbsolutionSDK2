#pragma once

#include "ZHM5BaseGuide.h"
#include "ZTextListData.h"
#include "ZHM5GuideLedge.h"

class ZHM5GuideWindow : public ZHM5BaseGuide
{
public:
    ZResourcePtr m_pHelper;
    float m_fWidth;
    float m_fDepth;
    TEntityRef<ZSpatialEntity> m_WindowFrame;
    float m_fOffsetFromSide;
    bool m_bAccessibleFromRight;
    bool m_bAccessibleFromLeft;
    bool m_bClosed;
    bool m_bPushVictim;
    TResourcePtr<ZTextListData> m_pTextListResource;
    ZString m_sEnterTextID;
    ZString m_sCachedEnterString;
    bool m_bIgnoreTransformCallback;
    ZHM5GuideLedge* m_pConnectedWindows[2];
    float4 m_vClimbThrougPoints[2];
};
