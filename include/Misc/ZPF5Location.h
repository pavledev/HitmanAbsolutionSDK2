#pragma once

#include "SVector3.h"

class alignas(16) ZPF5Location
{
public:
    SVector3 m_vPos;
    int m_iComponent;

    ZPF5Location();
};
