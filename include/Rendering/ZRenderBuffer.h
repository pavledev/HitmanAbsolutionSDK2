#pragma once
#pragma warning(disable : 4005)

#include "TRenderReferencedCountedImpl.h"
#include "SRenderBufferDescription.h"
#include "ZSubRenderBufferManager.h"
#include "ERenderResourceMapType.h"
#include "d3d11.h"

class ZRenderDevice;
class RenderReferencedCountedBaseStub;

class ZRenderBuffer : public TRenderReferencedCountedImpl<RenderReferencedCountedBaseStub, 0>
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

	~ZRenderBuffer() override = default;

	ZRenderBuffer() = default;
	ZRenderBuffer(const SRenderBufferDescription* pDescription, const void* pData, ZRenderDevice* pRenderDevice);
	void Map(ERenderResourceMapType eMapType, void** ppData);
	void Unmap();
	void ScheduleUpdate(unsigned int nOffset, unsigned int nSize, const char* pData);
	void UpdateSubresource(unsigned int nOffset, unsigned int nSize);
	ID3D11Buffer* GetBuffer() const;
	unsigned int GetOffset();
};
