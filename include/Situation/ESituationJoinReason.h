#pragma once

enum ESituationJoinReason
{
	AISJR_Default = 0,
	AISJR_HeardSound = 1,
	AISJR_HitmanStrange = 2,
	AISJR_HitmanIllegal = 3,
	AISJR_Assist = 4,
	AISJR_Propagate = 5,
	AISJR_Spawned = 6,
	AISJR_HelpCivilian = 7,
	AISJR_Escalating = 8,
	AISJR_DeadBody = 9,
	AISJR_Bloodpool = 10,
	AISJR_StandDown = 11,
	AISJR_ForcedToHold = 12
};
