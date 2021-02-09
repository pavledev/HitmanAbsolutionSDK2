#pragma once

struct alignas(4) SRenderPostfilterStarDefinition
{
    unsigned int nNumStarLines;
    unsigned int nPasses;
    float fSampleLength;
    float fAttenuation;
    float fInclination;
    bool bRotation;
};
