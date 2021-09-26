#pragma once

#include "SMatrix.h"

struct sPelvisOffsetElement
{
	SMatrix m_mvOffset;
	void* m_pClassPtr;

	sPelvisOffsetElement() = default;
	~sPelvisOffsetElement() = default;
	bool operator==(const sPelvisOffsetElement& other);
};
