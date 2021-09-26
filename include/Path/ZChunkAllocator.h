#pragma once

class ZChunkAllocator
{
public:
	unsigned short m_nMaxCount;
	unsigned short m_nChunkSizeInElements;
	unsigned short m_nRemaining;
	unsigned short m_nMinRemaining;
	unsigned short m_nFirstFree;
	unsigned short* m_pMemory;

	ZChunkAllocator() = default;
	~ZChunkAllocator() = default;
	unsigned int GetRemainingChunkCount();
	int GetIndex(const void* pData) const;
	void Init(unsigned int nChunkCount, unsigned int nChunkByteSize);
	void* Allocate();
	void Free(void* pFree);
};
