#pragma once

#include "ZEntityImpl.h"
#include "EAIActorRelationshipType.h"
#include "TEntityRef.h"
#include "ZActor.h"

class ZActorRelationshipEntity : public ZEntityImpl
{
public:
    bool m_bAutoSetOnActivate;
    EAIActorRelationshipType m_eType;
    TEntityRef<ZActor> m_rActorA;
    TEntityRef<ZActor> m_rActorB;
    ZEntityRef m_rRelationshipData;
};
