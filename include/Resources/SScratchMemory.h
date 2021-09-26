#pragma once

struct SScratchMemory
{
	bool m_bInUse;
	void* m_pMemory;
	unsigned int m_nSize;
	void* m_pAlignedMemory;
	unsigned int m_nAlignedMemorySize;

	SScratchMemory(void* pMemory, unsigned int nSize);
	SScratchMemory() = default;
	~SScratchMemory() = default;
};
