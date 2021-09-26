#pragma once

class ZCyclicBuffer
{
public:
	char* m_pBuffer;
	int m_iBufferSize;
	int m_iFirst;
	int m_iCount;
	int m_iStart;
	int m_iEnd;

	virtual ~ZCyclicBuffer() = default;

	ZCyclicBuffer() = default;
	ZCyclicBuffer(int iBufferSize);
	void* Alloc(int iSize);
	void* Get(int iNr);
	int Last();
	int First();
	int Count();
	void FreeSpace();
	int SpaceFree();
};
