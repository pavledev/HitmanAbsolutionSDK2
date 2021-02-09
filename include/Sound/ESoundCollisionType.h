#pragma once

enum ESoundCollisionType : __int32
{
    ESCT_IMPACT = 0x0,
    ESCT_ROLLING = 0x1,
    ESCT_SLIDING = 0x2,
    ESCT_ENDED = 0x3,
    ESCT_SHATTER = 0x4,
    ESCT_NUMCOLLISIONTYPES = 0x5
};
