#pragma once

#include "ZGameTime.h"

struct SAISharedEvent
{
	unsigned int m_start;
	unsigned int m_end;

	SAISharedEvent() = default;
	~SAISharedEvent() = default;
	float GetAge() const;
	float GetExpired() const;
	bool IsExpired() const;
	static bool IsCurrent(SAISharedEvent* pEvent);
	void SetStartTime(ZGameTime startTime);
	void SetEndTime(ZGameTime endTime);
	ZGameTime GetStartTime() const;
	ZGameTime GetEndTime() const;
	static unsigned int GameTimeToEventTime(ZGameTime gameTime);
	static ZGameTime EventTimeToGameTime(unsigned int eventTime);
};
