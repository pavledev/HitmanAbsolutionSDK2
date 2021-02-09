#pragma once
#pragma warning(disable : 4005)

#include "TRenderResourceImpl.h"
#include "IRenderResource.h"
#include "SRenderTexture2DDesc.h"
#include <D3D11.h>
#include "ZRenderShaderResourceView.h"

class ZRenderTexture2D : public TRenderResourceImpl<IRenderResource, 1>
{
public:
    SRenderTexture2DDesc m_Description;
    ID3D11Texture2D* m_pTexture2D;
    const ZRenderTexture2D* m_pParent;
    const unsigned __int8* m_pIAData;
    unsigned int m_nIADataSize;
    ID3D11DeviceContext* m_pDeviceContext;
    ZRenderShaderResourceView* m_pSRV;

    virtual void Allocate(unsigned int);
    virtual void Free();
};
