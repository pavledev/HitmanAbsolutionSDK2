#pragma once

enum ELogState
{
	LS_None = 0,
	LS_MoveToStand = 1,
	LS_StandToMove = 2,
	LS_StandToMoveToStand = 3,
	LS_Move = 4,
	LS_Reposition = 5,
	LS_React = 6,
	LS_Act = 7,
	LS_Death = 8,
	LS_Impact = 9
};
