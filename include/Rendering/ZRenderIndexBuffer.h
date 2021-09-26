#pragma once

#include "ZRenderBuffer.h"

class ZRenderDevice;
struct SRenderBufferDescription;

class ZRenderIndexBuffer : public ZRenderBuffer
{
public:
	~ZRenderIndexBuffer() override = default;

	ZRenderIndexBuffer() = default;
	ZRenderIndexBuffer(const SRenderBufferDescription* pDescription, const void* pData, ZRenderDevice* pRenderDevice);
};
