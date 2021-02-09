#pragma once

enum ENetworkState : __int32
{
    eNetworkState_Stand = 0x0,
    eNetworkState_ToStand = 0x1,
    eNetworkState_NormalMove = 0x2,
    eNetworkState_ToMove = 0x3,
    eNetworkState_TurnToMoveLeft45 = 0x4,
    eNetworkState_TurnToMoveRight45 = 0x5,
    eNetworkState_TurnToMoveLeft135 = 0x6,
    eNetworkState_TurnToMoveRight135 = 0x7,
    eNetworkState_Turn = 0x8,
    eNetworkState_Turn1 = 0x9,
    eNetworkState_IdleAnimation = 0xA,
    eNetworkState_StrafeStand = 0xB,
    eNetworkState_StrafeForward = 0xC,
    eNetworkState_StrafeBackward = 0xD,
    eNetworkState_LocomotionStandRoot = 0xE,
    eNetworkState_LocomotionMoveRoot = 0xF,
    eNetworkState_LocomotionRoot = 0x10,
    eNetworkState_StrafeRoot = 0x11,
    eNetworkState_Count = 0x12
};
