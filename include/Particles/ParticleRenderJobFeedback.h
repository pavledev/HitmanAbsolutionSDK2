#pragma once

#include "SVector3.h"
#include "SVector4.h"

struct ParticleRenderJobFeedback
{
    SVector3 m_vBBMin;
    unsigned int m_nNumParticles;
    SVector3 m_vBBMax;
    unsigned int m_nNumEmitterFeedbacks;
    SVector3 m_vPosScale;
    SVector3 m_vPosBias;
    SVector4 m_vDirScaleBias;
    SVector3 m_vVecScale;
    SVector3 m_vVecBias;
};
