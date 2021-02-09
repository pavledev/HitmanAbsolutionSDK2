#pragma once

#include <xmmintrin.h>

class float1;

struct alignas(16) float4
{
    __m128 m;

    float* operator[](int nSubscript);
    float1* Length3(float1 * result);
    float1* X(float1 * result);
    float1* Y(float1 * result);
    float1* Z(float1 * result);
    float1* W(float1 * result);
    float1* Dot2(float1 * result, float4 * v);
    float1* LengthSq2(float1 * result);
    float1* Length2(float1 * result);
    float1* LengthSq3(float1 * result);
    float4* Cross(float4 * result, float4 * v);
    float1* Dot3(float1 * result, float4 * v);
    float4* Normalize3Checked(float4 * result);
    static float4* Zero(float4 * result);
    float& z();
    const float* xConst(); //original name is x
    const float* yConst(); //original name is y
    float& x();
    float& y();
    const float* zConst(); //original name is z
    float4* Normalize3(float4 * result);
    float4* SetX(float4 * result, float1 * s);
    float4* SetY(float4 * result, float1 * s);
    float4* Normalize2(float4 * result);
    static float4* UnitZ(float4 * result);
    float4* SetZ(float4 * result, float1 * s);
    float& w();
    const float* wConst(); //original name is w

    float4 operator+(float4 f);
    float4 operator-(float4 f);
};
