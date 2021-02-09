#pragma once

class SActorHSState
{
public:
    enum EHSEnterAnimation : __int32
    {
        eHSEnterAnimation_GrabShield = 0x0,
        eHSEnterAnimation_DisarmRifle = 0x1,
        eHSEnterAnimation_DisarmGun = 0x2
    };

    enum eActorHSState : __int32
    {
        eEnter = 0x0,
        eStandIdle = 0x1,
        eMove = 0x2,
        eKillHS = 0x3,
        eExitHS = 0x4,
        eUnknown = 0x5
    };
};
