#pragma once

#include "ZEntityImpl.h"
#include "TResourcePtr.h"
#include "ZDynamicFlashMovieResource.h"

class ZScaleformResourceEntity : public ZEntityImpl
{
public:
    TResourcePtr<ZDynamicFlashMovieResource> m_pFlashMovieResource;
};
