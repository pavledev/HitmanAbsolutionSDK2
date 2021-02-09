#pragma once

#include "TArray.h"
#include "SRenderConstDesc.h"
#include "SRenderSamplerDesc.h"

class SRenderConstBufferDesc
{
public:
    unsigned int nGuid;
    unsigned int nConstSize;
    unsigned int nSamplerSize;
    unsigned int nNumConstants;
    unsigned int nNumSamplers;
    unsigned int nWaste;
    TArray<SRenderConstDesc> Constants;
    TArray<SRenderSamplerDesc> Samplers;
};
