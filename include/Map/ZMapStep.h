#pragma once

#include "ZMap.h"

class ZMapStep : public ZMap
{
public:
    bool m_bStartStateHigh;
    unsigned int m_nNumTransitions;
};
