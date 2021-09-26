#pragma once

class SActorHSState
{
public:
    enum EHSEnterAnimation
    {
        eHSEnterAnimation_GrabShield = 0,
        eHSEnterAnimation_DisarmRifle = 1,
        eHSEnterAnimation_DisarmGun = 2
    };

    enum eActorHSState
    {
        eEnter = 0,
        eStandIdle = 1,
        eMove = 2,
        eKillHS = 3,
        eExitHS = 4,
        eUnknown = 5
    };
};
