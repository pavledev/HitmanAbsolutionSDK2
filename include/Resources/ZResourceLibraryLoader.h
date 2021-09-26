#pragma once

#include "ZResourcePending.h"
#include "ZMutex.h"
#include "TSharedPointer.h"
#include "ZRuntimeResourceID.h"

class ZBufferBlock;
struct SScratchMemory;
class IResourceInstaller;
class ZResourceDataBuffer;
class ZResourceLibraryInfo;
template <class A, int B> class TFixedArray;
template <class A, int B> class TMaxArray;

class ZResourceLibraryLoader
{
public:
	bool m_bFinished;
	bool m_bFailed;
	ZResourcePending m_LibraryResource;
	ZResourceLibraryInfo* m_pLibraryEntries;
	ZMutex m_BlocksMutex;
	unsigned int m_nMaxResourceSize;
	unsigned int m_nEntryBytesLeft;
	unsigned int m_nEntryIndex;
	TSharedPointer<ZResourceDataBuffer> m_pFixedBuffer;
	TSharedPointer<ZResourceDataBuffer> m_pCurrentData;
	unsigned int m_nReadPosition;
	unsigned int m_nParsePosition;
	unsigned int m_nLibraryFileSize;
	unsigned int m_nAllocationCount;

	static TFixedArray<ZBufferBlock, 2>* m_pBlocks;
	static TMaxArray<SScratchMemory, 4> m_aAvailableScratchBuffers;

	ZResourceLibraryLoader() = default;
	ZResourceLibraryLoader(const ZResourcePending& libraryResource, ZResourceLibraryInfo* pLib);
	~ZResourceLibraryLoader() = default;
	void StartLoading();
	void LoadNext(int nMaxBlocks);
	ZRuntimeResourceID GetLibraryID();
	bool IsFailed();
	bool IsFinished();
	static void InitializeBuffers();
	static void UninitializeBuffers();
	static bool RegisterScratchBuffer(void* pMemoryBlock, unsigned int nSize);
	static bool UnregisterScratchBuffer(void* pMemoryBlock);
	bool HasPendingBlockReads();
	void ReadNextBlock(ZBufferBlock* pDestinationBlock, unsigned int nReadSize);
	void OnBlockReadComplete(int handle, void* pBuffer, unsigned int nPosition, unsigned int nSize);
	ZBufferBlock* FindLoadedBlock(unsigned int nWithPosition);
	bool ProcessBlock(ZBufferBlock* pBlock);
	void AllocateEntry(IResourceInstaller* pInstaller, unsigned int nSize, ZRuntimeResourceID ridResource);
	void ReleaseCurrentEntry();
};
