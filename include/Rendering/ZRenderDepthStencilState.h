#pragma once
#pragma warning(disable : 4005)

#include "SRenderDepthStencilStateDesc.h"
#include "D3D11.h"

class ZRenderDepthStencilState
{
public:
    SRenderDepthStencilStateDesc m_Description;
    ID3D11DepthStencilState* m_pDepthStencilState;

    virtual ~ZRenderDepthStencilState();
};
