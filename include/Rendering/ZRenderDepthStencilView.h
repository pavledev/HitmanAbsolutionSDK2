#pragma once

#include "SRenderDepthStencilViewDesc.h"
#include "ZRenderTexture2D.h"

class ZRenderDepthStencilView
{
public:
    SRenderDepthStencilViewDesc m_Description;
    ZRenderTexture2D* m_pTexture;
    ID3D11DepthStencilView* m_pDSV;

    virtual ~ZRenderDepthStencilView();
};
