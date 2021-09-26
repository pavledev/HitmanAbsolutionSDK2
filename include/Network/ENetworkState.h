#pragma once

enum ENetworkState
{
	eNetworkState_Stand = 0,
	eNetworkState_ToStand = 1,
	eNetworkState_NormalMove = 2,
	eNetworkState_ToMove = 3,
	eNetworkState_TurnToMoveLeft45 = 4,
	eNetworkState_TurnToMoveRight45 = 5,
	eNetworkState_TurnToMoveLeft135 = 6,
	eNetworkState_TurnToMoveRight135 = 7,
	eNetworkState_Turn = 8,
	eNetworkState_Turn1 = 9,
	eNetworkState_IdleAnimation = 10,
	eNetworkState_StrafeStand = 11,
	eNetworkState_StrafeForward = 12,
	eNetworkState_StrafeBackward = 13,
	eNetworkState_LocomotionStandRoot = 14,
	eNetworkState_LocomotionMoveRoot = 15,
	eNetworkState_LocomotionRoot = 16,
	eNetworkState_StrafeRoot = 17,
	eNetworkState_Count = 18
};
