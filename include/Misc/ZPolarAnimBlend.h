#pragma once

#include "SAnimEntry.h"

class ZPolarAnimBlend
{
public:
    unsigned int m_nNumAnimations;
    float m_fEdgeAngleThreshold;
    SAnimEntry m_AnimEntries[4];

    struct SActiveAnims
    {
        unsigned int m_anAnimId[2];
        float m_afAnimFractions[2];
        float m_fBlendFraction;
    };
};
