#pragma once
#pragma warning(disable : 4005)

#include "SRenderTargetViewDesc.h"
#include "ZRenderTexture2D.h"
#include <D3D11.h>

class ZRenderTargetView
{
public:
    SRenderTargetViewDesc m_Description;
    ZRenderTexture2D* m_pTexture;
    ID3D11RenderTargetView* m_pRTV;

    virtual ~ZRenderTargetView();
};
