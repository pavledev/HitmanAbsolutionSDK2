#pragma once

enum eOnLedgeMoveType
{
	eMoveOnLedge = 0,
	eMoveJumpToRightNeighbour = 1,
	eMoveJumpToLeftNeighbour = 2,
	eMoveJumpToUpwardNeighbour = 3,
	eMoveJumpToDownwardNeighbour = 4,
	eMoveDismount = 5,
	eMoveMount = 6,
	eMoveDismountMount = 7,
	eMoveClimbWindowLeft = 8,
	eMoveClimbWindowRight = 9,
	eMoveSneakPastWindowToRight = 10,
	eMoveSneakPastWindowToLeft = 11,
	eMovePullVictimFromLedge = 12,
	eMoveUnknown = 13
};
