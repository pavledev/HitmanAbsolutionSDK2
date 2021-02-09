#pragma once

enum ENetworkMoveStatus : __int32
{
    eNetworkMoveStatus_Stand = 0x1,
    eNetworkMoveStatus_Walk = 0x2,
    eNetworkMoveStatus_FastWalk = 0x4,
    eNetworkMoveStatus_Run = 0x8,
    eNetworkMoveStatus_Sneak = 0x10,
    eNetworkMoveStatus_Strafe = 0x20,
    eNetworkMoveStatus_StandUp = 0x40,
    eNetworkMoveStatus_IdleAnims = 0x80
};
