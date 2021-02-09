#pragma once
#pragma warning(disable : 4005)

#include "SRenderBlendStateDesc.h"
#include <D3D11.h>

class ZRenderBlendState
{
public:
    SRenderBlendStateDesc m_Description;
    ID3D11BlendState* m_pBlendState;

    virtual ~ZRenderBlendState();
};
