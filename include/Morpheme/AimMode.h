#pragma once

struct AimMode
{
    enum eAimMode : __int32
    {
        eNormalAim = 0x0,
        eDualAim = 0x1,
        ePistolAim = 0x2,
        ePistolAimHumanShield = 0x3,
        ePistolAimLeftHandOnly = 0x4
    };
};