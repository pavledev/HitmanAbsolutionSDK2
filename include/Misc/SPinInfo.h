#pragma once

#include "ZPinFunctor.h"

struct alignas(8) SPinInfo
{
    ZPinFunctor m_functor;
    unsigned int m_nExtraData;
};
