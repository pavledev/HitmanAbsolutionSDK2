#pragma once

enum eOnLedgeMoveType : __int32
{
    eMoveOnLedge = 0x0,
    eMoveJumpToRightNeighbour = 0x1,
    eMoveJumpToLeftNeighbour = 0x2,
    eMoveJumpToUpwardNeighbour = 0x3,
    eMoveJumpToDownwardNeighbour = 0x4,
    eMoveDismount = 0x5,
    eMoveMount = 0x6,
    eMoveDismountMount = 0x7,
    eMoveClimbWindowLeft = 0x8,
    eMoveClimbWindowRight = 0x9,
    eMoveSneakPastWindowToRight = 0xA,
    eMoveSneakPastWindowToLeft = 0xB,
    eMovePullVictimFromLedge = 0xC,
    eMoveUnknown = 0xD
};
