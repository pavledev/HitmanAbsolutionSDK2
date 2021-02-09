#pragma once

#include "SVector3.h"

struct SVector4
{
    union
    {
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };

        struct
        {
            SVector3 n;
            float d;
        };

        float v[4];
    };
};
