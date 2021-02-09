#pragma once

#include "ERenderFormat.h"
#include "ERenderResourceMipInterpolation.h"

class SRenderShaderResourceViewDesc
{
public:
    ERenderFormat eFormat;

    enum EViewDimension : __int32
    {
        VIEW_DIMENSION_TEXTURE2D = 0x1,
        VIEW_DIMENSION_TEXTURE2DMS = 0x2,
        VIEW_DIMENSION_TEXTURE2DARRAY = 0x3,
        VIEW_DIMENSION_TEXTURE3D = 0x4,
        VIEW_DIMENSION_TEXTURECUBE = 0x5,
    } eViewDimension;

    ERenderResourceMipInterpolation eMipInterpolation;
    
    union
    {
        struct SViewTexture2D
        {
            unsigned int nMostDetailedMip;
            unsigned int nMipLevels;
        } viewTexture2D;

        struct SViewTexture2DArray
        {
            unsigned int nMostDetailedMip;
            unsigned int nMipLevels;
            unsigned int nFirstArraySlice;
            unsigned int nArraySize;
        } viewTexture2DArray;

        struct SViewTexture3D
        {
            unsigned int nMostDetailedMip;
            unsigned int nMipLevels;
        } viewTexture3D;

        struct SViewTextureCube
        {
            unsigned int nMostDetailedMip;
            unsigned int nMipLevels;
        } viewTextureCube;
    };
};
