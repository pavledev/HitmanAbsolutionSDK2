#pragma once

#include "ZLinkedEntity.h"
#include "TEntityRef.h"
#include "TMultiMap.h"

class alignas(4) ZLinkedProxyEntity : public ZLinkedEntity
{
public:
    TEntityRef<ZLinkedEntity> m_Target;
    TArray<TRefCountPtr<IRenderPrimitive>> m_OwnPrimitives;
    unsigned int m_nOwnPrimitiveChangeCounter;
    TMultiMap<unsigned int, ZSpatialEntity*> m_OwnBoneAttachments;
    bool m_bOwnBoneAttachmentsCollected;
};
