#pragma once

#include "ZHM5CoverPlane.h"
#include "ZGameTime.h"

class alignas(8) SCoverTimestamp
{
public:
    ZHM5CoverPlane* pPlane;
    ZGameTime tLastUpdate;
    bool bHasLOF;
};
