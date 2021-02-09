#pragma once

#include "ZGridNodeRef.h"

class INodeRatingDebug
{
public:
    virtual ~INodeRatingDebug();
    virtual float GetNodeDebugRating(const ZGridNodeRef*);
    virtual float GetNodeDebugTextRatingScale();
};
