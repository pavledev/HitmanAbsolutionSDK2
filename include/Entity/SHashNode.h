#pragma once

#include "SLink.h"

struct SHashNode
{
    union
    {
        unsigned __int16 actorId;
        unsigned __int16 nextFreeHashNode;
    };

    unsigned __int16 entityId;
    unsigned __int16 padding;
    unsigned __int16 knownEntityId;
    SLink sameHash;
    SLink sameActor;
};
