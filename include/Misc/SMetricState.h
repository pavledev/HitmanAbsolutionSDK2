#pragma once

#include "float4.h"
#include "float1.h"
#include "ZString.h"

class alignas(16) SMetricState
{
public:
    float4 pos;
    float1 camangle;
    float1 angle;
    float hp;
    ZString outfit;
    ZString aistate;
    bool instinct;
    bool cover;
    bool running;
    bool scalecover;
};
