#pragma once

enum ESBCinematicState : __int32
{
    eSBCinematicState_None = 0x0,
    eSBCinematicState_Animation = 0x1,
    eSBCinematicState_Shot = 0x2,
    eSBCinematicState_Zoom = 0x3,
    eSBCinematicState_BulletImpact = 0x4,
    eSBCinematicState_BulletImpactPre = 0x5,
    eSBCinematicState_HitmanView = 0x6
};
