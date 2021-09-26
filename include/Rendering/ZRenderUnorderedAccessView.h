#pragma once

#include "TRenderReferencedCountedImpl.h"
#include "SRenderUnorderedAccessViewDesc.h"
#include "d3d11.h"

class ZRenderDevice;
class IRenderResource;
class RenderReferencedCountedBaseStub;

class ZRenderUnorderedAccessView : public TRenderReferencedCountedImpl<RenderReferencedCountedBaseStub, 0>
{
public:
	SRenderUnorderedAccessViewDesc m_Description;
	IRenderResource* m_pResource;
	ID3D11UnorderedAccessView* m_pUAV;

	~ZRenderUnorderedAccessView() override = default;

	ZRenderUnorderedAccessView() = default;
	ZRenderUnorderedAccessView(const SRenderUnorderedAccessViewDesc* pDescription, IRenderResource* pResource, ZRenderDevice* pRenderDevice);
	ID3D11UnorderedAccessView* GetUnorderedAccessView() const;
};
