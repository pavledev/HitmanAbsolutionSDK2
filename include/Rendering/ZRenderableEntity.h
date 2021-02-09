#pragma once

#include "ZBoundedEntity.h"
#include "ZRenderGraphNode.h"

class ZRenderableEntity : public ZBoundedEntity
{
public:
    unsigned __int8 m_nChangedFlag;
    __int8 m_bIgnoreRooms : 1;
    __int8 m_bPerformVisibilityTest : 1;
    __int8 m_bNotifyVisibleOnScreenChanged : 1;
    __int8 m_bDontDraw : 1;
    __int8 m_bActiveRenderGraphNode : 1;
    ZRenderGraphNode* m_pRenderGraphData;

    enum EChangeFlags : __int32
    {
        CHANGE_SPATIAL = 0x1,
        CHANGE_OTHER = 0x2,
        CHANGE_FULL = 0x3,
        CHANGE_USE_POST_REFLECT = 0x80,
    };

    virtual void OnVisibleOnScreenChanged(bool);
};
