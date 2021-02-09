#pragma once

enum eCoverMoveType : __int32
{
    eMoveCoverDefault = 0x0,
    eMoveSwitchCoverFacing = 0x1,
    eMoveShootFromCover = 0x2,
    eMoveEnterToShootPos = 0x3,
    eMoveExitFromShootPos = 0x4,
    eMoveEnterCover = 0x5,
    eMoveExitCover = 0x6,
    eMoveBlindFire = 0x7,
    eMoveExitBlindFire = 0x8,
    eMoveEnterCoverForced = 0x9,
    eMoveEnterCoverNoTrans = 0xA,
    eMoveCoverToCover = 0xB,
    eMoveExitCoverScale = 0xC
};
