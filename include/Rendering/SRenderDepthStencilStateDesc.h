#pragma once

#include "ERenderCompareFunc.h"
#include "ERenderStencilOp.h"

class SRenderDepthStencilStateDesc
{
public:
    bool bDepthEnable;

    enum EDepthWriteMask : __int32
    {
        DEPTH_WRITE_MASK_NONE = 0x1,
        DEPTH_WRITE_MASK_ALL = 0x2,
    } eDepthWriteMask;

    ERenderCompareFunc eDepthFunc;
    bool bStencilEnable;
    unsigned __int8 nStencilReadMask;
    unsigned __int8 nStencilWriteMask;

    /*struct SStencilOpDesc
    {
        ERenderStencilOp eStencilFailOp;
        ERenderStencilOp eStencilDepthFailOp;
        ERenderStencilOp eStencilPassOp;
        ERenderCompareFunc eStencilFunc;
    } frontFace;

    struct SStencilOpDesc
    {
        ERenderStencilOp eStencilFailOp;
        ERenderStencilOp eStencilDepthFailOp;
        ERenderStencilOp eStencilPassOp;
        ERenderCompareFunc eStencilFunc;
    } backFace;*/

    struct SStencilOpDesc
    {
        ERenderStencilOp eStencilFailOp;
        ERenderStencilOp eStencilDepthFailOp;
        ERenderStencilOp eStencilPassOp;
        ERenderCompareFunc eStencilFunc;
    } frontFace, backFace;
};
