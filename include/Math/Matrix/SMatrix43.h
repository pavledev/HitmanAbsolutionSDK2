#pragma once

#include "SVector3.h"
#include "SMatrix33.h"

struct SMatrix43
{
    union
    {
        struct
        {
            SVector3 XAxis;
            SVector3 YAxis;
            SVector3 ZAxis;
            SVector3 Trans;
        };

        struct
        {
            SMatrix33 Rot;
            float m41;
            float m42;
            float m43;
        };

        struct
        {
            float m11;
            float m12;
            float m13;
            float m21;
            float m22;
            float m23;
            float m31;
            float m32;
            float m33;
        };

        float v[12];
        SVector3 r[4];
    };
};
