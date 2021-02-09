#pragma once

enum EHMAttentionType : __int32
{
    eHMA_UNKNOWN = 0x0,
    eHMA_TRESSPASSING = 0x1,
    eHMA_ILLEGALACTION = 0x2,
    eHMA_FORCEDILLEGAL = 0x3,
    eHMA_COMBAT = 0x4,
    eHMA_HUNTING = 0x5,
    eHMA_DISGUISE = 0x6,
    eHMA_DEADBODY = 0x7,
    eHMA_FORCEDFULL = 0x8,
    eHMA_MAX = 0x9
};
