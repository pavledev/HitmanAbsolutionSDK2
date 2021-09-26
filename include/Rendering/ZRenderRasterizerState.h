#pragma once
#pragma warning(disable : 4005)

#include "SRenderRasterizerStateDesc.h"
#include "d3d11.h"

class ZRenderDevice;

class ZRenderRasterizerState
{
public:
	SRenderRasterizerStateDesc m_Description;
	ID3D11RasterizerState* m_pRasterizerState;

	virtual ~ZRenderRasterizerState() = default;

	ZRenderRasterizerState() = default;
	ZRenderRasterizerState(const SRenderRasterizerStateDesc* pDescription, ZRenderDevice* pRenderDevice);
	ID3D11RasterizerState* GetRasterizerState() const;
};
