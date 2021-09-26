#pragma once

class ZRenderIndexBuffer;

class ZRenderResourceAsyncUpdateIndexBuffer
{
public:
	ZRenderIndexBuffer* m_pIndexBuffer;
	unsigned long long m_nBookmark;
	unsigned int m_nOffset;
	unsigned int m_nSize;
	char* m_pData;

	virtual ~ZRenderResourceAsyncUpdateIndexBuffer() = default;

	ZRenderResourceAsyncUpdateIndexBuffer() = default;
	ZRenderResourceAsyncUpdateIndexBuffer(ZRenderIndexBuffer* pIndexBuffer);
	void Apply();
	void Map(unsigned int nOffset, unsigned int nSize, void** ppData);
	void Unmap(unsigned long long bookmark);
	unsigned int GetOffset() const;
	unsigned int GetSize() const;
	const char* GetData() const;
};
