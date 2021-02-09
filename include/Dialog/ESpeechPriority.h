#pragma once

enum ESpeechPriority : __int32
{
    SP_AMBIENT = 0x0,
    SP_ALERTED = 0x1,
    SP_PAIN = 0x2,
    SP_ALERTED_IMPORTANT = 0x3,
    SP_COMBAT = 0x4,
    SP_COMBAT_IMPORTANT = 0x5,
    SP_DEATH = 0x6,
    SP_MAX = 0x7,
    SP_COUNT__ = 0x8
};
