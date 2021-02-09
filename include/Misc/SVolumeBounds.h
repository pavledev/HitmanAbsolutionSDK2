#pragma once

#include "SQV.h"
#include "SVector3.h"

class alignas(16) SVolumeBounds
{
public:
    SQV mTransform;
    SVector3 vCenter;
    SVector3 vHalfSize;
};
