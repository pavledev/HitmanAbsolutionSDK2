#pragma once

struct SVector2
{
    union
    {
        struct
        {
            float x;
            float y;
        };

        float v[2];
    };
};
