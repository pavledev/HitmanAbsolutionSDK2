#pragma once

#include "EAIEventType.h"
#include "ZGameTime.h"

struct SAIEvent
{
	unsigned int m_type : 31;
	unsigned int m_bHandled : 1;
	unsigned int m_start;
	unsigned int m_end;

	SAIEvent() = default;
	~SAIEvent() = default;
	EAIEventType GetType() const;
	void SetType(EAIEventType type);
	void SetHandled(bool bHandled);
	bool GetHandled() const;
	float GetAge() const;
	float GetDuration() const;
	float GetExpired() const;
	bool IsExpired() const;
	bool IsCurrent() const;
	static unsigned int IsBooleanEventType(const EAIEventType type);
	void SetStartTime(ZGameTime startTime);
	void SetEndTime(ZGameTime endTime);
	ZGameTime GetStartTime() const;
	ZGameTime GetEndTime() const;
	static unsigned int GameTimeToEventTime(ZGameTime gameTime);
	static ZGameTime EventTimeToGameTime(unsigned int eventTime);
};
