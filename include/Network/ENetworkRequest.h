#pragma once

enum ENetworkRequest
{
	eNetworkRequest_Move = 0,
	eNetworkRequest_TurnToMove = 1,
	eNetworkRequest_Stop = 2,
	eNetworkRequest_Turn = 3,
	eNetworkRequest_ExitTurn = 4,
	eNetworkRequest_ExitLeft = 5,
	eNetworkRequest_ExitRight = 6,
	eNetworkRequest_eEnterStrafe = 7,
	eNetworkRequest_eExitStrafe = 8,
	eNetworkRequest_StrafeForward = 9,
	eNetworkRequest_StrafeBackward = 10,
	eNetworkRequest_StrafeRight = 11,
	eNetworkRequest_StrafeLeft = 12,
	eNetworkRequest_StrafeForwardMatchFeet = 13,
	eNetworkRequest_StrafeBackwardMatchFeet = 14,
	eNetworkRequest_PlayIdleAnimation = 15,
	eNetworkRequest_StopIdleAnimation = 16,
	eNetworkRequest_ExitToMove = 17,
	eNetworkRequest_Count = 18
};
