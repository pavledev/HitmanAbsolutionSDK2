#pragma once

#include "SMatrix.h"

class alignas(16) SCameraState
{
public:
    SMatrix transform;
    float fov;

    //SCameraState();
};
