#pragma once

struct SVector3
{
    union
    {
        struct
        {
            float x;
            float y;
            float z;
        };

        float v[3];
    };
};
