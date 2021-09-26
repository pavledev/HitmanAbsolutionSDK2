#pragma once

struct ZRenderConstBuffer;
class ZRenderShader;
struct SConstBufferImpl;

struct ZRenderConstBufferRef
{
	SConstBufferImpl* m_pImpl;

	ZRenderConstBufferRef(const ZRenderConstBuffer& cb);
	ZRenderConstBufferRef() = default;
	~ZRenderConstBufferRef() = default;
	ZRenderConstBufferRef& operator=(const ZRenderConstBufferRef& o);
	void Clear();
	char* MapTemp(ZRenderShader* pShader);
	char* MapTemp(unsigned int nSize, unsigned int nWaste);
	char* MapTempPatch(ZRenderConstBufferRef cb);
	void Unmap();
	void* GetLastBuffer() const;
	unsigned int GetLastBufferSize() const;
	void DumpHex() const;
	void DumpFloats() const;
};
