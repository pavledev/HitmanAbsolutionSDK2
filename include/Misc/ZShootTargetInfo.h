#pragma once

#include "TMaxArray.h"
#include "SShootTargetEntry.h"
#include "ZGridNodeRef.h"

class alignas(16) ZShootTargetInfo
{
public:
    TMaxArray<SShootTargetEntry, 32> m_ShootTargetInfo;
    unsigned int m_LastUpdateEntryIndex;
    ZGridNodeRef m_alternativeShootTargetNode;
    float m_fAlternativeShootTargetDistanceToTarget;
};
