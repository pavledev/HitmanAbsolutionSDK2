#pragma once

class ZBitAlloc
{
public:
	unsigned long long* m_pChunks;
	unsigned int m_nUsed;
	unsigned int m_nSlots;
	unsigned int m_nChunks;

	ZBitAlloc() = default;
	~ZBitAlloc() = default;
	void Init(unsigned int nSlots);
	bool Alloc(unsigned int nSize, unsigned int* pnSlot, unsigned int nDirection);
	bool AllocTop(unsigned int nSize, unsigned int* pnSlot);
	bool AllocBottom(unsigned int nSize, unsigned int* pnSlot);
	void Free(unsigned int nSlot, unsigned int nSize);
	unsigned int GetUsed();
	static unsigned long long CheckFit(unsigned long long x, unsigned int nSlots);
	static unsigned int CountTrailingZeros(unsigned long long x);
	static unsigned int CalcMaxConsBits(unsigned long long x);
	static unsigned int FoldBits(unsigned int x);
	static unsigned int PrevPow2(unsigned int n);
	void SetBits(unsigned int nSlot, unsigned int nSize);
	void FlipBits(unsigned int nStart, unsigned int nSize);
};
