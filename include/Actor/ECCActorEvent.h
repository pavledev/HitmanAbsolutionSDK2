#pragma once

enum ECCActorEvent : __int32
{
    eCCActorEvent_NeckSnap = 0x0,
    eCCActorEvent_StrangleStart = 0x1,
    eCCActorEvent_StrangleEnd = 0x2,
    eCCActorEvent_PropAttack = 0x3,
    eCCActorEvent_Impact = 0x4,
    eCCActorEvent_ImpactFinal = 0x5,
    eCCActorEvent_FiberwireKill = 0x6,
    eCCActorEvent_FiberwireInit = 0x7,
    eCCActorEvent_ExecutePistol = 0x8,
    eCCActorEvent_StrangleMoveInit = 0x9,
    eCCActorEvent_AttackChainCivilian = 0xA,
    eCCActorEvent_PropAttackInit = 0xB,
    eCCActorEvent_HumanShieldGrab = 0xC,
    eCCActorEvent_HumanShieldKill = 0xD,
    eCCActorEvent_Grab = 0xE,
    eCCActorEvent_Fall = 0xF,
    eCCActorEvent_ImpactHitman = 0x10
};
