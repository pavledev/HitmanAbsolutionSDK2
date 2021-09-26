#pragma once

#include "SPropertyInfo.h"

struct SNamedPropertyInfo
{
	unsigned int m_nPropertyID;
	SPropertyInfo m_propertyInfo;

	SNamedPropertyInfo() = default;
	~SNamedPropertyInfo() = default;
};
