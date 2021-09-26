#pragma once
#pragma warning(disable : 4005)

#include "SRenderBlendStateDesc.h"
#include "d3d11.h"

class ZRenderDevice;

class ZRenderBlendState
{
public:
	SRenderBlendStateDesc m_Description;
	ID3D11BlendState* m_pBlendState;

	virtual ~ZRenderBlendState() = default;

	ZRenderBlendState() = default;
	ZRenderBlendState(const SRenderBlendStateDesc* pDescription, ZRenderDevice* pRenderDevice);
	ID3D11BlendState* GetBlendState() const;
};
