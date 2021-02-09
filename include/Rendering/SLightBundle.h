#pragma once

#include "TArray.h"
#include "ZRenderGraphNode.h"
#include "ZRenderGraphNodeLight.h"

class alignas(4) SLightBundle
{
public:
    TArray<ZRenderGraphNode*> nodes;
    ZRenderGraphNodeLight* pLight;
    unsigned int nInsideFlag;
    float m_fPriority;
    float m_fOcclusionPriority;
    unsigned int m_nPixelsTouched;
    unsigned int lights[1];
    unsigned int m_nKey;
    __int8 bUseStencil : 1;
    bool bCastShadows;
    char nLightType;
};
