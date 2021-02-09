#pragma once

enum EDragBodyState : __int32
{
    eStandIdleToDragIdle_State = 0x0,
    eDragBodyMain_State = 0x1,
    eDragIdle_State = 0x2,
    eDragIdleToStandIdle_State = 0x3,
    eDragMove_State = 0x4,
    eNumDragStates = 0x5
};
