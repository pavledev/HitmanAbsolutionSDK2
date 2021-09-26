#pragma once

struct CrowdUtil
{
	enum ECrowdActorMood
	{
		CM_AMBIENT = 0,
		CM_ALERTED = 1,
		CM_SCARED = 2,
		CM_PANICED = 3,
		CM_DEAD = 4,
		CM_DISABLED = 5,
		NUM_ACTOR_MOOD_TYPES = 6
	};

	enum ECrowdFacing
	{
		FRONT = 0,
		BACK = 1
	};

	enum ECrowdSide
	{
		LEFT = 0,
		RIGHT = 1
	};

	enum EDefaultStateTypes
	{
		STATE_IDLE = 0,
		STATE_WALK = 1,
		STATE_PENDINGWALK = 2,
		STATE_DEAD = 3,
		STATE_SCARED = 4,
		STATE_PENDINGSCARED = 5,
		STATE_POSSESSED = 6,
		STATE_ALERT = 7,
		STATE_PRONE = 8,
		NUM_DEFAULT_STATES = 9
	};

	enum ECrowdDirection
	{
		NORTH = 0,
		EAST = 1,
		SOUTH = 2,
		WEST = 3
	};
};
