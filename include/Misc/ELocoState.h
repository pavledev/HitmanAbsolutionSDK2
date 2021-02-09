#pragma once

enum ELocoState : __int32
{
    eLocoState_InActive = 0x0,
    eLocoState_TransitInPreCheck = 0x1,
    eLocoState_TransitIn = 0x2,
    eLocoState_Active = 0x3
};
