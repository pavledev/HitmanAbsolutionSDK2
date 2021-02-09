#pragma once

enum ECollisionSupport : __int32
{
    ECS_VOID = 0x0,
    ECS_IMPACT = 0x1,
    ECS_ROLLING = 0x2,
    ECS_SLIDING = 0x3,
    ECS_RESTING = 0x4,
    ECS_SUPPORTED = 0x5,
    ECS_ENDED = 0x6
};
