#pragma once
#pragma warning(disable : 4005)

#include "TRenderResourceImpl.h"
#include "IRenderResource.h"
#include "SRenderTexture3DDesc.h"
#include <D3D11.h>

class ZRenderTexture3D : TRenderResourceImpl<IRenderResource, 2>
{
public:
    SRenderTexture3DDesc m_Description;
    ID3D11Texture3D* m_pTexture3D;
    ID3D11DeviceContext* m_pDeviceContext;
};
