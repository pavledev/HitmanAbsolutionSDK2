#pragma once

#include "ERenderBlendMode.h"
#include "ERenderBlendOp.h"

class SRenderBlendStateDesc
{
public:
    bool bAlphaToCoverageEnable;
    bool bBlendEnable[8];
    ERenderBlendMode eSrcBlend;
    ERenderBlendMode eDestBlend;
    ERenderBlendOp eBlendOp;
    ERenderBlendMode eSrcBlendAlpha;
    ERenderBlendMode eDestBlendAlpha;
    ERenderBlendOp eBlendOpAlpha;
    unsigned __int8 nRenderTargetWriteMask[8];
};
