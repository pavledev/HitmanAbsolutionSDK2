#pragma once

enum ECharacterCollidableLayer : __int32
{
    CCL_DYNAMIC = 0x0,
    CCL_DYNAMIC_TRANSPARENT = 0x1,
    CCL_DYNAMIC_NO_COLLISION = 0x2,
    CCL_DYNAMIC_NO_COLLISION_TRANSPARENT = 0x3,
    CCL_UNUSED_LAST = 0x4
};
