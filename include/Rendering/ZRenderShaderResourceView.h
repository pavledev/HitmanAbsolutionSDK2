#pragma once
#pragma warning(disable : 4005)

#include "TRenderReferencedCountedImpl.h"
#include "SRenderShaderResourceViewDesc.h"
#include "d3d11.h"

class ZRenderDevice;
class IRenderResource;
class RenderReferencedCountedBaseStub;

class ZRenderShaderResourceView : public TRenderReferencedCountedImpl<RenderReferencedCountedBaseStub, 0>
{
public:
	SRenderShaderResourceViewDesc m_Description;
	IRenderResource* m_pResource;
	ID3D11ShaderResourceView* m_pSRV;

	~ZRenderShaderResourceView() override = default;

	ZRenderShaderResourceView() = default;
	ZRenderShaderResourceView(const SRenderShaderResourceViewDesc* pDescription, IRenderResource* pResource, ZRenderDevice* pRenderDevice);
	const SRenderShaderResourceViewDesc& GetDesc() const;
	ID3D11ShaderResourceView* GetShaderResourceView() const;
};
