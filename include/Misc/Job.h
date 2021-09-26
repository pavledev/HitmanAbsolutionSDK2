#pragma once

#include "EJobType.h"

struct Job
{
	unsigned short m_jobType : 3;
	unsigned short m_jobSize : 12;
	unsigned short m_bufferIndex;

	Job(EJobType jobType, unsigned short jobSize);
	Job() = default;
	~Job() = default;
};
