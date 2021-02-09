#pragma once
#pragma warning(disable : 4005)

#include "TRenderReferencedCountedImpl.h"
#include "RenderReferencedCountedBaseStub.h"
#include "SRenderBufferDescription.h"
#include <D3D11.h>

class ZRenderDevice;

class alignas(4) ZRenderBuffer : TRenderReferencedCountedImpl<RenderReferencedCountedBaseStub, 0>
{
public:
    SRenderBufferDescription m_Description;
    ID3D11Buffer* m_pBuffer;
    ZRenderDevice* m_pRenderDevice;
    ID3D11DeviceContext* m_pDeviceContext;
    unsigned int m_nOffset;
    ZSubRenderBufferManager::Block* m_pPoolBlock;
    char* m_pCPUBuffer;
    bool m_bCPUBufferMapped;
};
