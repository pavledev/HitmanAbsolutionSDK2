#pragma once

enum EMetaContent : __int32
{
    Meta_Nothing = 0x0,
    Meta_ContractsModeAccess = 0x1,
    Meta_SniperChallengeUnlockAccess = 0x2,
    Meta_UnlockAllCheckpoints = 0x3,
    Meta_UnlockAllWeapons = 0x4,
    Meta_UnlockAllDisguises = 0x5,
    Meta_UnlockSpecific = 0x6
};
