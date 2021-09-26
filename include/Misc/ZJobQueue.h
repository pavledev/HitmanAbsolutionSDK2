#pragma once

#include "NMP.h"

struct Job;

class ZJobQueue
{
public:
	unsigned short m_numJobs;
	unsigned short m_nextFreeByteIndex;
	NMP::Memory::Resource m_data;
	NMP::Memory::Format m_bufferFormat;

	ZJobQueue() = default;
	~ZJobQueue() = default;
	void Clear();
	unsigned short AddJob(const Job* pJob);
	Job* GetJob(unsigned short byteOffset);
	unsigned int GetNumJobs();
};
