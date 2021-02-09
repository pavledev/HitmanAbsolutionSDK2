#pragma once

#include "ERenderFillMode.h"
#include "ERenderCullMode.h"

class SRenderRasterizerStateDesc
{
public:
    ERenderFillMode eFillMode;
    ERenderCullMode eCullMode;
    bool bFrontCounterClockWise;
    int nDepthBias;
    float fDepthBiasClamp;
    float fSlopeScaledDepthBias;
    bool bDepthClipEnable;
    bool bScissorEnable;
    bool bMultiSampleEnable;
    bool bAntialiasedLineEnable;
};
