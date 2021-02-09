#pragma once
#pragma warning(disable : 4005)

#include "TRenderReferencedCountedImpl.h"
#include "RenderReferencedCountedBaseStub.h"
#include "SRenderShaderResourceViewDesc.h"
#include "IRenderResource.h"
#include "D3D11.h"

class ZRenderShaderResourceView : public TRenderReferencedCountedImpl<RenderReferencedCountedBaseStub, 0>
{
public:
    SRenderShaderResourceViewDesc m_Description;
    IRenderResource* m_pResource;
    ID3D11ShaderResourceView* m_pSRV;
};
