#pragma once

struct CrowdUtil
{
    enum ECrowdActorMood : __int32
    {
        CM_AMBIENT = 0x0,
        CM_ALERTED = 0x1,
        CM_SCARED = 0x2,
        CM_PANICED = 0x3,
        CM_DEAD = 0x4,
        CM_DISABLED = 0x5,
        NUM_ACTOR_MOOD_TYPES = 0x6
    };

    enum ECrowdFacing : __int32
    {
        FRONT = 0x0,
        BACK = 0x1
    };

    enum ECrowdDirection : __int32
    {
        NORTH = 0x0,
        EAST = 0x1,
        SOUTH = 0x2,
        WEST = 0x3
    };
};
