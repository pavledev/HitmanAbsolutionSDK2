#pragma once

enum ENetworkEvent
{
	eNetworkEvent_FootStepRight = 100,
	eNetworkEvent_FootStepLeft = 200,
	eNetworkEvent_ExitRight = 101,
	eNetworkEvent_ExitLeft = 201,
	eNetworkEvent_ExitTurn = 900,
	eNetworkEvent_ExitSmallStep = 1200,
	eNetworkEvent_RotationComplete = 1201,
	eNetworkEvent_ExitMoveToStand = 1202
};
