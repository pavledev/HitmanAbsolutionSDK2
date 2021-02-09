#pragma once

#include "float4.h"
#include "ZHM5GuideWindow.h"

class alignas(16) SWindowZone
{
public:
    float4 mvFrom;
    float4 mvTo;
    ZHM5GuideWindow* m_pWindow;
};
