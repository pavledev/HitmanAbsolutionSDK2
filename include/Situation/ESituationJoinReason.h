#pragma once

enum ESituationJoinReason : __int32
{
    AISJR_Default = 0x0,
    AISJR_HeardSound = 0x1,
    AISJR_HitmanStrange = 0x2,
    AISJR_HitmanIllegal = 0x3,
    AISJR_Assist = 0x4,
    AISJR_Propagate = 0x5,
    AISJR_Spawned = 0x6,
    AISJR_HelpCivilian = 0x7,
    AISJR_Escalating = 0x8,
    AISJR_DeadBody = 0x9,
    AISJR_Bloodpool = 0xA,
    AISJR_StandDown = 0xB,
    AISJR_ForcedToHold = 0xC
};
