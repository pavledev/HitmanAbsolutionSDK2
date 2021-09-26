#pragma once

#include "GNewOverrideBase.h"

class GFxEvent : public GNewOverrideBase<2>
{
public:
	enum EventType
	{
		None = 0,
		MouseMove = 1,
		MouseDown = 2,
		MouseUp = 3,
		MouseWheel = 4,
		KeyDown = 5,
		KeyUp = 6,
		SceneResize = 7,
		SetFocus = 8,
		KillFocus = 9,
		DoShowMouse = 10,
		DoHideMouse = 11,
		DoSetMouseCursor = 12,
		CharEvent = 13,
		IMEEvent = 14
	};

	EventType Type;

	GFxEvent() = default;
	GFxEvent(EventType eventType);
	~GFxEvent() = default;
};
