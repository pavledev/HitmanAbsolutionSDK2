#pragma once

enum ESocialActorState : __int32
{
    SAS_Candidate = 0x0,
    SAS_InteractHitman = 0x1,
    SAS_ConsiderActor = 0x2,
    SAS_InteractActor = 0x3,
    SAS_Cooldown = 0x4,
    SAS_Purge = 0x5
};
