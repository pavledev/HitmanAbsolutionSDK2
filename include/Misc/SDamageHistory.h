#pragma once

#include "ZGameTime.h"

struct SDamageHistory
{
	float m_fDamage;
	ZGameTime m_tTime;

	SDamageHistory() = default;
	~SDamageHistory() = default;
};
