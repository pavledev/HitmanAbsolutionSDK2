#pragma once

#include "GListNode.h"
#include "GList.h"
#include "GLock.h"

class __declspec(novtable) GMemoryHeap : public GListNode<GMemoryHeap>
{
public:
	enum MemReportType
	{
		MemReportBrief = 0,
		MemReportSummary = 1,
		MemReportMedium = 2,
		MemReportFull = 3,
		MemReportSimple = 4,
		MemReportSimpleBrief = 5,
		MemReportFileSummary = 6,
		MemReportHeapsOnly = 7,
		MemReportHeapDetailed = 8
	};

	enum HeapFlags
	{
		Heap_ThreadUnsafe = 1,
		Heap_FastTinyBlocks = 2,
		Heap_FixedGranularity = 4,
		Heap_Root = 8,
		Heap_NoDebugInfo = 16,
		Heap_UserDebug = 4096
	};

	enum RootHeapParameters
	{
		RootHeap_MinAlign = 16,
		RootHeap_Granularity = 16384,
		RootHeap_Reserve = 16384,
		RootHeap_Threshold = 262144,
		RootHeap_Limit = 0
	};

	struct HeapDesc
	{
		unsigned int Flags;
		unsigned int MinAlign;
		unsigned int Granularity;
		unsigned int Reserve;
		unsigned int Threshold;
		unsigned int Limit;
		unsigned int HeapId;
		unsigned int Arena;

		HeapDesc(unsigned int flags, unsigned int minAlign, unsigned int granularity, unsigned int reserve, unsigned int threshold, unsigned int limit, unsigned int heapId, unsigned int arena);
	};

	struct RootHeapDesc : HeapDesc
	{
		RootHeapDesc() = default;
	};

	struct HeapInfo
	{
		HeapDesc Desc;
		GMemoryHeap* pParent;
		char* pName;

		HeapInfo() = default;
	};

	struct __declspec(novtable) HeapVisitor
	{
		virtual ~HeapVisitor() = default;
		virtual void Visit(GMemoryHeap* memoryHeap, GMemoryHeap* memoryHeap2) = 0;

		HeapVisitor() = default;
	};

	struct __declspec(novtable) LimitHandler
	{
		virtual ~LimitHandler() = default;
		virtual bool OnExceedLimit(GMemoryHeap* memoryHeap, unsigned int param2) = 0;
		virtual void OnFreeSegment(GMemoryHeap* memoryHeap, unsigned int param2) = 0;

		LimitHandler() = default;
	};

	struct __declspec(novtable) HeapTracer
	{
		virtual ~HeapTracer() = default;
		virtual void OnCreateHeap(const GMemoryHeap* memoryHeap) = 0;
		virtual void OnDestroyHeap(const GMemoryHeap* memoryHeap) = 0;
		virtual void OnAlloc(const GMemoryHeap* memoryHeap, unsigned int param2, unsigned int param3, unsigned int param4, const void* param5) = 0;
		virtual void OnRealloc(const GMemoryHeap* memoryHeap, const void* param2, unsigned int param3, const void* param4) = 0;
		virtual void OnFree(const GMemoryHeap* memoryHeap, const void* param2) = 0;

		HeapTracer() = default;
	};

	struct RootStats
	{
		unsigned int SysMemFootprint;
		unsigned int SysMemUsedSpace;
		unsigned int PageMapFootprint;
		unsigned int PageMapUsedSpace;
		unsigned int BookkeepingFootprint;
		unsigned int BookkeepingUsedSpace;
		unsigned int DebugInfoFootprint;
		unsigned int DebugInfoUsedSpace;
		unsigned int UserDebugFootprint;
		unsigned int UserDebugUsedSpace;
	};

	unsigned int SelfSize;
	volatile unsigned int RefCount;
	unsigned int OwnerThreadId;
	void* pAutoRelease;
	HeapInfo Info;
	GList<GMemoryHeap> ChildHeaps;
	GLock HeapLock;
	bool UseLocks;
	bool TrackDebugInfo;

	GMemoryHeap() = default;
};
