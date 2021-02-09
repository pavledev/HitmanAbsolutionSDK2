#pragma once

#include "TBlockArrayInfo.h"
#include "ZResourcePending.h"

template<class T>
class TBlockArray
{
public:
    TBlockArrayInfo<ZResourcePending> m_info;
};
