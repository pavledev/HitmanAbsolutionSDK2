#pragma once

#include "float4.h"

class alignas(16) SMatrix
{
public:
    float4 mat[4];
};
