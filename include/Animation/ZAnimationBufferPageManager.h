#pragma once

#include "TArray.h"
#include "NMP.h"

class ZAnimationBufferPageManager
{
public:
	struct SAnimBufferPage
	{
		NMP::Memory::Resource m_bufferResource;
		unsigned int m_numBuffersUsed;

		SAnimBufferPage(const unsigned int numBuffers, const NMP::Memory::Format bufferFormat, const unsigned int transformCount);
		SAnimBufferPage(const SAnimBufferPage& rhs);
		SAnimBufferPage() = default;
		~SAnimBufferPage() = default;
	};

	unsigned int m_pageByteSize;
	unsigned int m_numBuffersPerPage;
	unsigned int m_memoryPerPage;
	unsigned short m_nextFreeIndex;
	TArray<NMP::DataBuffer*> m_poseBuffers;
	NMP::Memory::Format m_bufferFormat;
	unsigned int m_transformCount;
	TArray<SAnimBufferPage> m_pages;

	ZAnimationBufferPageManager(const unsigned int pageByteSize, const unsigned int transformCount);
	ZAnimationBufferPageManager() = default;
	void Init(const unsigned int pageByteSize, const unsigned int transformCount);
	unsigned short GetNextFreeBufferIndex();
	NMP::DataBuffer* GetBufferFromIndex(const unsigned short index);
	void Clear();
	void Trim();
	void AllocateNewPage();
	~ZAnimationBufferPageManager() = default;
};
