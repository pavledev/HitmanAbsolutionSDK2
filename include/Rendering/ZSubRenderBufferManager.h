#pragma once

#include "TArray.h"
#include "RangeAllocator.h"

class ZRenderDevice;
class ZRenderBuffer;
struct SRenderBufferDescription;

class ZSubRenderBufferManager
{
public:
	struct Block
	{
		ZRenderBuffer* pBuffer;
		unsigned int nOffset;
		unsigned int nBindFlags;
		RangeAllocator::Block* pBlock;
	};

	struct Bin
	{
		unsigned int nBindFlags;
		ZRenderBuffer* pBuffer;
		RangeAllocator* pAllocator;

		Bin(unsigned int bufferSize);
		~Bin() = default;
	};

	ZRenderDevice* m_pRenderDevice;
	TArray<Bin*> m_bins;

	ZSubRenderBufferManager() = default;
	ZSubRenderBufferManager(ZRenderDevice* pRenderDevice);
	~ZSubRenderBufferManager() = default;
	Block* Alloc(const SRenderBufferDescription* pDescription);
	void Free(Block* pBlock);
};
