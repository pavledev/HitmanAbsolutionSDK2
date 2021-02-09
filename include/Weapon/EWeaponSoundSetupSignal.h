#pragma once

enum EWeaponSoundSetupSignal : __int32
{
    eWSSS_OwnedByNPC = 0x0,
    eWSSS_EmptyShot = 0x1,
    eWSSS_EndFire = 0x2,
    eWSSS_HM_EndFire = 0x3,
    eWSSS_HM_WeaponEquipped = 0x4,
    eWSSS_HM_WeaponUnequipped = 0x5,
    eWSSS_HM_WeaponSwapped = 0x6,
    eWSSS_TriggerRelease = 0x7,
    eWSSS_Hitman_AllShots = 0x8,
    eWSSS_NPC_AllShots = 0x9
};
