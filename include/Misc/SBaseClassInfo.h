#pragma once

#include "STypeID.h"

struct SBaseClassInfo
{
	STypeID* m_Type;
	int m_nOffset;

	SBaseClassInfo() = default;
	~SBaseClassInfo() = default;
};
