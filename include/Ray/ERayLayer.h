#pragma once

enum ERayLayer
{
	eRayLayer_COLLIDE_WITH_ALL = 0,
	eRayLayer_CAMERA_COLI = 1,
	eRayLayer_CAMERA_COLI_CAMERA_OBSTACE_ONLY = 2,
	eRayLayer_HERO_FIRE = 3,
	eRayLayer_ACTOR_FIRE = 4,
	eRayLayer_ACTOR_LINE_OF_FIRE = 5,
	eRayLayer_AIM_COLI = 6,
	eRayLayer_FOOTSTEPS_COLI = 7,
	eRayLayer_BLOODSPLATDECAL_COLI = 8,
	eRayLayer_COLLIDE_WITH_STATIC = 9,
	eRayLayer_COLLIDE_WITH_STATIC_EXCL_TRANSPARENT = 10,
	eRayLayer_PARTICLES = 11,
	eRayLayer_COVERSEARCH = 12,
	eRayLayer_ACTOR_VISIBILITY = 13,
	eRayLayer_MARK_ACTOR = 14,
	eRayLayer_PICKUP = 15,
	eRayLayer_HERO_PROXY = 16,
	eRayLayer_ACTIONS_FARFEEDBACK = 17,
	eRayLayer_COLLIDE_WITH_STATIC_AND_SLOPE = 18,
	eRayLayer_UNUSED_LAST = 19
};
