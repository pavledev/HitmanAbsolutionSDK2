#pragma once
#pragma warning(disable : 4005)

#include "SRenderTargetViewDesc.h"
#include "ZRenderTexture3D.h"
#include <D3D11.h>

class ZRenderTargetView3D
{
public:
    SRenderTargetViewDesc m_Description;
    ZRenderTexture3D* m_pTexture;
    ID3D11RenderTargetView* m_pRTV;

    virtual ~ZRenderTargetView3D();
};
