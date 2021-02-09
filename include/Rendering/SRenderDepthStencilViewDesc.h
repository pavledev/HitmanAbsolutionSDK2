#pragma once

#include "ERenderFormat.h"

struct SRenderDepthStencilViewDesc
{
    ERenderFormat eFormat;
    SRenderShaderResourceViewDesc::EViewDimension eViewDimension;

    struct SViewTexture2D
    {
        unsigned int nMipSlice;
    } viewTexture2D;
};
