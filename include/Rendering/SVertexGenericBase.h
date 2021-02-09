#pragma once

#include "SVector3.h"
#include "SVector2.h"

struct SVertexGenericBase
{
    SVector3 p;
    unsigned int n;
    unsigned int T;
    unsigned int B;
    SVector2 t;
    unsigned int c;
};
