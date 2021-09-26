#pragma once

class IAllocator;

class RangeAllocator
{
public:
	class Block
	{
	public:
		unsigned int m_start;

		union 
		{
			unsigned int m_padding;
			Block* m_nextFree;
		};

		Block* m_prev;
		Block* m_next;
		Block* m_prevFree;

		Block() = default;
	};

	unsigned int m_start;
	unsigned int m_size;
	unsigned int m_capacity;
	unsigned int m_pageSize;
	unsigned int m_firstPage;
	unsigned int m_minBlockSize;
	Block* m_first;
	Block* m_last;
	Block* m_firstFree;
	Block* m_pageBounds;
	IAllocator* m_pBlockAllocator;

	RangeAllocator() = default;
	RangeAllocator(unsigned int start, unsigned int size, unsigned int capacity, unsigned int pageSize, unsigned int minBlockSize, IAllocator* pBlockAllocator);
	~RangeAllocator() = default;
	void Reinit(unsigned int start, unsigned int size, unsigned int pageSize);
	Block* Alloc(unsigned int size, unsigned int alignment);
	Block* Alloc(unsigned int size);
	void Free(Block* b);
	void FreeAll();
	void SetCapacity(unsigned int capacity);
	unsigned int GetBlockStart(const Block* b) const;
	void SetMinBlockSize(unsigned int minBlockSize);
	void IncreaseSize(unsigned int size);
	unsigned int GetFreeMemory() const;
	unsigned int CheckConsistency() const;
	void IterateFreeBlocks() const;
	Block* AllocBlock();
	void FreeBlock(Block* b);
	Block* InsertBefore(Block* b, unsigned int start);
	Block* InsertAfter(Block* b, unsigned int start);
	void AddFree(Block* b);
	void RemoveFree(Block* b);
	void SplitIntoPages(Block* b);
	Block* AllocExtra(unsigned int size, unsigned int alignment);
};
