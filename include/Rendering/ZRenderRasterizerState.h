#pragma once
#pragma warning(disable : 4005)

#include "SRenderRasterizerStateDesc.h"
#include <D3D11.h>

class ZRenderRasterizerState
{
public:
    SRenderRasterizerStateDesc m_Description;
    ID3D11RasterizerState* m_pRasterizerState;

    virtual ~ZRenderRasterizerState();
};
