#pragma once

#include <D3DX11.h>
#include "IAmdDxExtInterface.h"

class __declspec(novtable) IAmdDxExtQuadBufferStereo : public IAmdDxExtInterface
{
public:
	~IAmdDxExtQuadBufferStereo() override = default;
	virtual HRESULT EnableQuadBufferStereo(int param1) = 0;
	virtual HRESULT GetDisplayModeList(DXGI_FORMAT dxgiFormat, unsigned int param2, unsigned int* param3, DXGI_MODE_DESC* dxgiModeDesc) = 0;
	virtual unsigned int GetLineOffset(IDXGISwapChain* swapChain) = 0;

	IAmdDxExtQuadBufferStereo() = default;
};
