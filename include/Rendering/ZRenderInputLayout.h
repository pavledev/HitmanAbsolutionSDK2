#pragma once

#include "TRenderReferencedCountedImpl.h"
#include "SRenderInputElementDesc.h"
#include "TArray.h"
#include "d3d11.h"

class ZRenderDevice;
class RenderReferencedCountedBaseStub;

class ZRenderInputLayout : public TRenderReferencedCountedImpl<RenderReferencedCountedBaseStub, 0>
{
public:
	struct SBinding
	{
		ID3D11InputLayout* m_pInputLayout;
		unsigned char* m_pIAInputSignature;
		unsigned int m_nIAInputSignatureSize;
	};

	unsigned int m_nNumElements;
	SRenderInputElementDesc m_Elements[16];
	TArray<SBinding> m_aBindings;

	~ZRenderInputLayout() override = default;
	virtual unsigned int GetElements(SRenderInputElementDesc* pElements) const;

	ZRenderInputLayout() = default;
	ZRenderInputLayout(const SRenderInputElementDesc* pElements, unsigned int nNumElements, ZRenderDevice* pRenderDevice);
	void Create(ID3D11Device* pDevice, unsigned char* pIAInputSignature, unsigned int nIAInputSignatureSize);
	ID3D11InputLayout* GetInterface(unsigned char* pIAInputSignature, unsigned int nIAInputSignatureSize) const;
};
