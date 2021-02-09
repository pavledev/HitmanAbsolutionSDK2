#pragma once

#include "EAISharedEventType.h"
#include "STypeID.h"
#include "ZSharedKnowledgeRef.h"
#include "ZGridNodeRef.h"

class ZSituationOrder
{
public:
    alignas(16) int m_nRefCount;
    EAISharedEventType m_type;
    STypeID* m_classType;
    ZSharedKnowledgeRef m_target;
    bool m_bHasPosition;
    float4 m_vPosition;
    ZGridNodeRef m_rGridNode;

    virtual ~ZSituationOrder();
};
