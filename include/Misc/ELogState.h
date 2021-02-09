#pragma once

enum ELogState : __int32
{
    LS_None = 0x0,
    LS_MoveToStand = 0x1,
    LS_StandToMove = 0x2,
    LS_StandToMoveToStand = 0x3,
    LS_Move = 0x4,
    LS_Reposition = 0x5,
    LS_React = 0x6,
    LS_Act = 0x7,
    LS_Death = 0x8,
    LS_Impact = 0x9
};
