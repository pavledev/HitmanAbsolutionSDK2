#pragma once

struct SActorCounts
{
	int nAlerted;
	int nAlertedArmed;
	int nEngaged;
	int nInCombat;
	int nAlertableActorOnScreen;
	int nAlertableGuardOnScreen;

	SActorCounts() = default;
	~SActorCounts() = default;
};
