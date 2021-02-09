#pragma once

#include "ZEntityImpl.h"
#include "IDecalControllerEntity.h"

class alignas(4) ZDecalControllerEntity : ZEntityImpl, IDecalControllerEntity
{
    unsigned __int16* m_pDecalTrivialAccept;
    unsigned int m_nNumDecalTrivialAccept;

    struct SBaryCentricVertex
    {
        unsigned int nTriangleIndex;
        float4 vBaryCentricCoord;
    }* m_pDecalClippedTriangleVBNew;

    unsigned int m_nNumClippedTriangleVtx;

    enum ERotationType : __int32
    {
        eRotationDisable = 0x0,
        eRotationAlignRay = 0x1,
        eRotationRandom = 0x2
    } m_eRotationType;

    enum EScaleType : __int32
    {
        eScaleDisable = 0x0,
        eScaleUniform = 0x1,
        eScaleY = 0x2
    } m_eScaleType;

    float m_fScaleTarget;
    float m_fScaleTime;
    float m_fScaleStartSlope;
    float m_fScaleEndSlope;
    float m_fExpirationFadeTime;
    unsigned int m_nLastLOD;
    unsigned __int8 m_nDecalBuffer;

    enum EClipInclusionMode
    {
        CLIP_MODE_CLIP = 0x0,
        CLIP_MODE_PARTIALLY_INSIDE = 0x1
    };

    struct SSlot
    {
        char aSlot[16];
    };

    struct SBucketInfo
    {
        unsigned __int16 nHead;
        
        union
        {
            unsigned __int16 nCur;
            unsigned __int16 nStart;
        };
    };

    struct SRemapInfo
    {
        unsigned __int16 aBucketCounts[256];
        SBucketInfo aBucketInfo[256];
        unsigned __int16* pNext;
        SSlot* pSlots;
    };
};
