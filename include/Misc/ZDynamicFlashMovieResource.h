#pragma once

#include "ZStaticFlashMovieResource.h"

class GFxMovieDef;

class ZDynamicFlashMovieResource : public ZStaticFlashMovieResource
{
public:
	ZDynamicFlashMovieResource() = default;
	ZDynamicFlashMovieResource(GFxMovieDef* pMovieDef);
	~ZDynamicFlashMovieResource() = default;
};
