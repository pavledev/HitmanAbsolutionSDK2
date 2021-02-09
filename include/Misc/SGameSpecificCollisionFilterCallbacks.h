#pragma once

#include "ZFilterGroupMask.h"
#include "ZString.h"

class SGameSpecificCollisionFilterCallbacks
{
public:
    bool(__cdecl* m_fpGetRayLayerFilterGroupMask)(const unsigned int, ZFilterGroupMask*);
    bool(__cdecl* m_fpIsCollisionLayerOpaque)(const unsigned __int16);
    ZString* (__cdecl* m_fpGetLevelAndCheckpointName)(ZString* result);
};
