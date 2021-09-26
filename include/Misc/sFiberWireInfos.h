#pragma once

#include "SMatrix.h"

struct sFiberWireInfos
{
	SMatrix m_mvAttacherTarget[2];
	SMatrix m_mvVictimNeck;
	bool m_bValid;

	sFiberWireInfos() = default;
	~sFiberWireInfos() = default;
	void Reset();
};
