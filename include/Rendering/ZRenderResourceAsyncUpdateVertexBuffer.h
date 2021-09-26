#pragma once

class ZRenderVertexBuffer;

class ZRenderResourceAsyncUpdateVertexBuffer
{
public:
	ZRenderVertexBuffer* m_pVertexBuffer;
	unsigned long long m_nBookmark;
	unsigned int m_nOffset;
	unsigned int m_nSize;
	char* m_pData;

	virtual ~ZRenderResourceAsyncUpdateVertexBuffer() = default;

	ZRenderResourceAsyncUpdateVertexBuffer() = default;
	ZRenderResourceAsyncUpdateVertexBuffer(ZRenderVertexBuffer* pVertexBuffer);
	void Apply();
	void Map(unsigned int nOffset, unsigned int nSize, void** ppData);
	void Unmap(unsigned long long bookmark);
	unsigned int GetOffset() const;
	unsigned int GetSize() const;
	const char* GetData() const;
};
