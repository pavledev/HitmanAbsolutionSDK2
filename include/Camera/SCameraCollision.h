#pragma once

#include "float4.h"
#include "IEntity.h"

struct alignas(16) SCameraCollision
{
    float4 lp;
    float4 ln;
    float4 cp;
    float t;
    IEntity* pEntity;
    float fLength;
    bool bColi;
};
