#pragma once

enum ESoundBlendLoopMode : __int32
{
    ESBLM_ONESHOT = 0x0,
    ESBLM_LOOP_IMMEDIATESTOP = 0x1,
    ESBLM_LOOP_FINISHLOOP = 0x2,
    ESBLM_RETRIGGER = 0x3
};
