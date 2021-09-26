#pragma once

#include "ZGameTime.h"

struct SGameUpdateEvent
{
	ZGameTime m_GameTimeDelta;
	ZGameTime m_GameTimeCurrent;
	ZGameTime m_GameTimePrevious;
	ZGameTime m_RealTimeDelta;
	ZGameTime m_RealTimeCurrent;
	ZGameTime m_RealTimePrevious;
	float m_fGameTimeMultiplier;

	SGameUpdateEvent(const SGameUpdateEvent& __that);
	SGameUpdateEvent() = default;
	~SGameUpdateEvent() = default;
	SGameUpdateEvent& operator=(const SGameUpdateEvent& __that);
};
