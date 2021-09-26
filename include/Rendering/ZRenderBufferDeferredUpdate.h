#pragma once

class ZRenderBuffer;

class ZRenderBufferDeferredUpdate
{
public:
	unsigned int m_nOffset;
	unsigned int m_nSize;
	ZRenderBuffer* m_pBuffer;

	ZRenderBufferDeferredUpdate() = default;
	ZRenderBufferDeferredUpdate(ZRenderBuffer* pBuffer, unsigned int nOffset, unsigned int nSize);
	~ZRenderBufferDeferredUpdate() = default;
	void Update();
};
