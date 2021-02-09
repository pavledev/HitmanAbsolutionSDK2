#pragma once

enum ESituationType : __int32
{
    AIST_Any = 0x0,
    AIST_Ambient = 0x1,
    AIST_Fusebox = 0x2,
    AIST_InvestigateStanding = 0x3,
    AIST_InvestigateCurious = 0x4,
    AIST_HandleDisguise = 0x5,
    AIST_HandleTrespassing = 0x6,
    AIST_DeadBody = 0x7,
    AIST_Agitated = 0x8,
    AIST_InvestigateCautious = 0x9,
    AIST_StandOff = 0xA,
    AIST_AvoidExplosion = 0xB,
    AIST_ProtoCombat = 0xC,
    AIST_CloseCombat = 0xD
};
