#pragma once

enum EDefaultCollidableLayer : __int32
{
    DCL_STATIC = 0x0,
    DCL_KINEMATIC = 0x1,
    DCL_KINEMATIC_TRANSPARENT = 0x2,
    DCL_DYNAMIC = 0x3,
    DCL_DYNAMIC_TRANSPARENT = 0x4,
    DCL_AUXILIARY = 0x5,
    DCL_UNUSED_LAST = 0x6
};
