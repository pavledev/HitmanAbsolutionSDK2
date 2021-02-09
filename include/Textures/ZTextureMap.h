#pragma once

class ZTextureMap
{
public:
    const unsigned __int8* m_pData;

    enum EInterpretAs : __int32
    {
        INTERPRET_AS_COLOR = 0x0,
        INTERPRET_AS_NORMAL = 0x1,
        INTERPRET_AS_HEIGHT = 0x2,
    };

    enum EDimensions : __int32
    {
        DIMENSIONS_2D = 0x0,
        DIMENSIONS_CUBE = 0x1,
        DIMENSIONS_VOLUME = 0x2,
    };

    enum ETextureFlags : __int32
    {
        TEXF_SWIZZLED = 0x1,
        TEXF_DEFERRED = 0x2,
        TEXF_MEMORY_READY_XBOX360 = 0x4,
        TEXF_GAMMA = 0x8,
        TEXF_EMISSIVE = 0x10,
        TEXF_DDSC_ENCODED = 0x20,
    };

    struct SMipLevel
    {
        unsigned int nWidth;
        unsigned int nHeight;
        unsigned int nSizeInBytes;
        const unsigned __int8* pData;
    };

    struct STextureMapHeader
    {
        unsigned int nTotalSize;
        unsigned int nFlags;
        unsigned __int16 nWidth;
        unsigned __int16 nHeight;
        unsigned __int16 nFormat;
        unsigned __int8 nNumMipLevels;
        unsigned __int8 nDefaultMipLevel;
        unsigned __int8 nInterpretAs;
        unsigned __int8 nDimensions;
        unsigned __int8 nMipInterpolation;
        unsigned int nIADataSize;
        unsigned int nIADataOffset;
    };
};
