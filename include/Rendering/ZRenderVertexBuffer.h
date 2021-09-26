#pragma once

#include "ZRenderBuffer.h"

class ZRenderDevice;
struct SRenderBufferDescription;

class ZRenderVertexBuffer : public ZRenderBuffer
{
public:
	~ZRenderVertexBuffer() override = default;

	ZRenderVertexBuffer() = default;
	ZRenderVertexBuffer(const SRenderBufferDescription* pDescription, const void* pData, ZRenderDevice* pRenderDevice);
};
