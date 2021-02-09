#pragma once

enum ESurrenderState : __int32
{
    eStateRaiseArms = 0x0,
    eStateTurnToActor = 0x1,
    eStateIdleWaitingForActor = 0x2,
    eStateIdleNormal = 0x3
};
