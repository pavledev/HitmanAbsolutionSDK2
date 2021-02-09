#pragma once

#include "ZFlashMovieResource.h"
#include "GFxMovieDef.h"

class ZStaticFlashMovieResource : public ZFlashMovieResource
{
public:
    GFxMovieDef* m_pMovieDef;
};
