#pragma once

#include "ERenderFormat.h"

class SRenderTargetViewDesc
{
public:
    ERenderFormat eFormat;

    enum EViewDimension
    {
        VIEW_DIMENSION_TEXTURE2D = 0x1,
        VIEW_DIMENSION_TEXTURE2DMS = 0x2,
        VIEW_DIMENSION_TEXTURE2DARRAY = 0x3,
        VIEW_DIMENSION_TEXTURE3D = 0x4,
    } eViewDimension;

    union
    {
        struct SViewTexture2D
        {
            unsigned int nMipSlice;
        } viewTexture2D;

        struct SViewTexture2DArray
        {
            unsigned int nMipSlice;
            unsigned int nFirstArraySlice;
            unsigned int nArraySize;
        } viewTexture2DArray;

        struct SViewTexture3D
        {
            unsigned int nMipSlice;
            unsigned int nFirstWSlice;
            unsigned int nWSize;
        } viewTexture3D;
    };
};
