#pragma once

enum ERenderPostfilterGlareType
{
	GLARE_TYPE_CAMERA = 0,
	GLARE_TYPE_NATURAL = 1,
	GLARE_TYPE_CHEAP_LENS = 2,
	GLARE_TYPE_FILTER_CROSS_SCREEN = 3,
	GLARE_TYPE_FILTER_CROSS_SCREEN_SPECTRAL = 4,
	GLARE_TYPE_FILTER_SNOW_CROSS = 5,
	GLARE_TYPE_FILTER_SNOW_CROSS_SPECTRAL = 6,
	GLARE_TYPE_FILTER_SUNNY_CROSS = 7,
	GLARE_TYPE_FILTER_SUNNY_CROSS_SPECTRAL = 8,
	GLARE_TYPE_CINECAM_VERTICAL_SLITS = 9,
	GLARE_TYPE_CINECAM_HORIZONTAL_SLITS = 10,
	GLARE_TYPE_USER_DEFINED = 11
};
