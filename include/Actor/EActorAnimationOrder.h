#pragma once

enum EActorAnimationOrder : __int32
{
    AAO_None = 0x0,
    AAO_Stand = 0x1,
    AAO_Move = 0x2,
    AAO_React = 0x3,
    AAO_Act = 0x4,
    AAO_MoveToAct = 0x5,
    AAO_MoveToCover = 0x6,
    AAO_ShootFromCover = 0x7,
    AAO_PeekFromCover = 0x8,
    AAO_Death = 0x9,
    AAO_Impact = 0xA,
    AAO_Controlled = 0xB
};
