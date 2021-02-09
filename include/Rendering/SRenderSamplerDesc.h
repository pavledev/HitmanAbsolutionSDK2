#pragma once
#pragma warning(disable : 4005)

#include "SRenderConstDesc.h"
#include <D3D11.h>

class SRenderSamplerDesc: SRenderConstDesc
{
public:
    ID3D11SamplerState* pSamplerState;
};
