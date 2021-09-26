#pragma once

#include "ZString.h"

struct SExposedEntityData
{
	ZString m_sExposedEntityName;
	int m_nEntityOffset;

	SExposedEntityData(const SExposedEntityData& __that);
	SExposedEntityData() = default;
	~SExposedEntityData() = default;
};
