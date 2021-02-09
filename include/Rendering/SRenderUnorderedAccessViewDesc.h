#pragma once

#include "ERenderFormat.h"

enum EViewDimension : __int32
{
    UAV_DIMENSION_BUFFER = 0x1,
    UAV_DIMENSION_TEXTURE1D = 0x2,
    UAV_DIMENSION_TEXTURE1DARRAY = 0x3,
    UAV_DIMENSION_TEXTURE2D = 0x4,
    UAV_DIMENSION_TEXTURE2DARRAY = 0x5,
    UAV_DIMENSION_TEXTURE3D = 0x8,
};

class SRenderUnorderedAccessViewDesc
{
public:
    ERenderFormat eFormat;
    EViewDimension eViewDimension;

    union
    {
        struct SUAVBuffer
        {
            unsigned int nFirstElement;
            unsigned int nNumElements;
            unsigned int nFlags;
        } UAVBuffer;

        struct SUAVTexture
        {
            unsigned int nMipSlice;
        } UAVTexture;

        struct SUAVTextureArray
        {
            unsigned int nMipSlice;
            unsigned int nFirstArraySlice;
            unsigned int nArraySize;
        } UAVTextureArray;

        struct SUAVTexture3D
        {
            unsigned int nMostDetailedMip;
            unsigned int nMipLevels;
        } UAVTexture3D;
    };
};
