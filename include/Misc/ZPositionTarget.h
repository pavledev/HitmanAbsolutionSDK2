#pragma once

#include "SVector3.h"
#include "TRefCountPtr.h"
#include "SKnownEntity.h"

class ZPositionTarget
{
public:
    SVector3 wsTargetPosition;
    TRefCountPtr<SKnownEntity> rTargetEntity;
};
