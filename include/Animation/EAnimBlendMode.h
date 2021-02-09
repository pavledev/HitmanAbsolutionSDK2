#pragma once

enum EAnimBlendMode : __int32
{
    EAnimBlendMode_InterpAttInterpPos = 0x0,
    EAnimBlendMode_InterpAttAddPos = 0x1,
    EAnimBlendMode_AddAttLeavePos = 0x2,
    EAnimBlendMode_AddAttAddPos = 0x3,
    EAnimBlendMode_Max = 0x4
};
