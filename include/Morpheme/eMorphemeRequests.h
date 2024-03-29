#pragma once

enum eMorphemeRequests
{
	eStart = 0,
	eStop = 1,
	eRunStop = 2,
	eForceStop = 3,
	eForward = 4,
	eLeft = 5,
	eRight = 6,
	eBackward = 7,
	eForceStopStrafe = 8,
	eEnterHumanShield = 9,
	eEnterHumanShieldIdle = 10,
	eKnockOutHumanShieldVictim = 11,
	eKillHumanShieldVictim = 12,
	eEnterCarryCivilian = 13,
	eEnterCarryCivilianIdle = 14,
	eEnterCloseCombat = 15,
	eEnterFakeCloseCombat = 16,
	eChangeClothes = 17,
	eDismountGuide = 18,
	eMountGuide = 19,
	eJumpLedgeLeft = 20,
	eJumpLedgeRight = 21,
	eEnterShootingBallet = 22,
	eEnterLocomotion = 23,
	eUp = 24,
	eDown = 25,
	eCoverMove = 26,
	eCoverStop = 27,
	eEnterExitCover = 28,
	eEnterExitCorner = 29,
	eEnterExitShoot = 30,
	eEnterExitLadder = 31,
	eStartStopSlide = 32,
	eSpecialKill = 33,
	eClimbWindow = 34,
	eEnterCoverAim = 35,
	eExitCoverAim = 36,
	eExitCoverAimTransit = 37,
	eDie = 38,
	eEnterCloset = 39,
	eExitCloset = 40,
	eCoverToCover = 41,
	eDisableFuseBox = 42,
	eEnterExitVentilatorShaft = 43,
	eExitForwardHigh = 44,
	eExitForwardLow = 45,
	eExitBackwardsHigh = 46,
	eExitBackwardsLow = 47,
	ePickLock = 48,
	eLookVentGrillDown = 49,
	eLookVentGrillLeft = 50,
	eLookVentGrillRight = 51,
	eLookVentGrillForward = 52,
	eUseKeyCardReader = 53,
	eStartDragBody = 54,
	eExitDragBody = 55,
	eEnterLocoMotion = 56,
	eScaleCoverRight = 57,
	eScaleCoverLeft = 58,
	eSwitchCoverFacing = 59,
	eExitSwitchCoverFacing = 60,
	eEnterSafeZone = 61,
	eToss = 62,
	eStartContextAction = 63,
	eStartInteractiveCutsequence = 64,
	eSurrender = 65,
	eSurrenderIdle = 66,
	eTurnToActor = 67,
	eEnterAlign = 68,
	ePickupItem = 69,
	eUseHealthStation = 70,
	eLedgeStop = 71,
	eLedgeMove = 72,
	eUpperBodyReload = 73,
	eUpperBodyEquip = 74,
	eLastReq = 75
};
