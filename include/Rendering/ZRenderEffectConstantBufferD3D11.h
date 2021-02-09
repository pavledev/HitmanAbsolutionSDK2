#pragma once

#include "ZString.h"
#include "ZRenderEffect.h"
#include "ERenderResourceMapType.h"

class ZRenderEffectConstantBufferD3D11
{
public:
    ZString m_sName;
    ZRenderEffect* m_pEffect;
    ID3DX11EffectConstantBuffer* m_pConstantBuffer;
    ID3D11Buffer* m_pBuffer;
    ID3D11DeviceContext* m_pDeviceContext;
    unsigned int m_nBackBufferSize;
    char* m_pBackBuffer;

    virtual ~ZRenderEffectConstantBufferD3D11();
    virtual void Map(ERenderResourceMapType, void**);
    virtual void Unmap();
};
