#pragma once

#include "GNewOverrideBase.h"

class GFxEvent : public GNewOverrideBase<2>
{
public:
    enum EventType : __int32
    {
        None = 0x0,
        MouseMove = 0x1,
        MouseDown = 0x2,
        MouseUp = 0x3,
        MouseWheel = 0x4,
        KeyDown = 0x5,
        KeyUp = 0x6,
        SceneResize = 0x7,
        SetFocus = 0x8,
        KillFocus = 0x9,
        DoShowMouse = 0xA,
        DoHideMouse = 0xB,
        DoSetMouseCursor = 0xC,
        CharEvent = 0xD,
        IMEEvent = 0xE
    } Type;
};
