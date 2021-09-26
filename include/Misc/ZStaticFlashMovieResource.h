#pragma once

#include "ZFlashMovieResource.h"

class GFxMovieDef;

class ZStaticFlashMovieResource : public ZFlashMovieResource
{
public:
	GFxMovieDef* m_pMovieDef;

	ZStaticFlashMovieResource() = default;
	ZStaticFlashMovieResource(GFxMovieDef* pMovieDef);
	~ZStaticFlashMovieResource() = default;
	void ReleaseMovie();
};
