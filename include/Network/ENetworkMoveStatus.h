#pragma once

enum ENetworkMoveStatus
{
	eNetworkMoveStatus_Stand = 1,
	eNetworkMoveStatus_Walk = 2,
	eNetworkMoveStatus_FastWalk = 4,
	eNetworkMoveStatus_Run = 8,
	eNetworkMoveStatus_Sneak = 16,
	eNetworkMoveStatus_Strafe = 32,
	eNetworkMoveStatus_StandUp = 64,
	eNetworkMoveStatus_IdleAnims = 128
};
