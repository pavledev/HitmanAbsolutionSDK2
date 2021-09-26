#pragma once

#include "TSharedPointer.h"

class ISharedPointerTarget;

class ZThreadEvent
{
public:
	TSharedPointer<ISharedPointerTarget> m_pImpl;

	ZThreadEvent() = default;
	void WaitEvent();
	static void SignalEvent(ZThreadEvent& event);
	void SignalEvent();
	static bool WaitForSingleEvent(ZThreadEvent& event, int nTimeOutMSecs);
	~ZThreadEvent() = default;
};
