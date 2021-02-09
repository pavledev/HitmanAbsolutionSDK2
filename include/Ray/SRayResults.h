#pragma once

#include "SActionRayResult.h"

class alignas(8) SRayResults
{
public:
    SActionRayResult m_res[2];
    bool m_bRefreshed;
};
