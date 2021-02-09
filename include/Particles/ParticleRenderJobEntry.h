#pragma once

#include "SVector3.h"
#include "SVector4.h"

struct ParticleRenderJobEntry
{
    unsigned int m_nConstEa;
    unsigned int m_nConstSize;
    unsigned int m_nSpriteBufferEa;
    unsigned int m_nEmitterFeedbacksEa;
    unsigned int m_nFlags;
    unsigned int m_nNumControllers;
    unsigned int m_nTilesX;
    unsigned int m_nTilesY;
    float m_fAspect;
    float m_fScaleRange;
    float m_fScaleFactor;
    float m_fAOBending;
    unsigned int m_nShaderMask;
    unsigned int m_nIADataSize;
    unsigned int m_nIADataEa;
    unsigned int m_nNumCollisionParticles;
    SVector3 m_vPosScalePrev;
    SVector3 m_vPosBiasPrev;
    SVector4 m_vDirScaleBiasPrev;
    SVector3 m_vVecScalePrev;
    SVector3 m_vVecBiasPrev;
};
