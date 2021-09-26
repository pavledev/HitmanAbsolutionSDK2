#pragma once

enum eHitmanPermissionReason
{
	eHPReason_MovementContext = 1,
	eHPReason_ItemHandlingInProcess = 2,
	eHPReason_SniperMode = 4,
	eHPReason_CrippleBox = 8,
	eHPReason_LevelDesign = 16,
	eHPReason_PlayerInput = 32,
	eHPReason_InstinctBlendIn = 64,
	eHPReason_NUM = 6,
	eHPReason_ALLReasons = -1
};
