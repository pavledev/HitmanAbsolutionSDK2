#pragma once

#include "SMatrix.h"

struct sQueuedReset
{
	bool m_bResetQueued;
	SMatrix m_mvResetPoint;

	sQueuedReset() = default;
	~sQueuedReset() = default;
};
