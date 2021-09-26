#pragma once

#include "SConstBufferImpl.h"
#include "ZRenderShader.h"

class ZRenderConstBufferRef;

struct ZRenderConstBuffer
{
	SConstBufferImpl* m_pImpl;

	static const ZRenderConstBufferRef Null();
	ZRenderConstBuffer() = default;
	~ZRenderConstBuffer() = default;
	char* Map(ZRenderShader* pShader);
	void Unmap();
	void* GetLastBuffer() const;
	unsigned int GetLastBufferSize() const;
};
