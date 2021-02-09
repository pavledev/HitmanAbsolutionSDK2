#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZCameraBlendNodeInterface.h"
#include "SVector3.h"

class alignas(4) ZMainCameraBlendNodeEntity : public ZEntityImpl
{
public:
    TEntityRef<ZCameraBlendNodeInterface> m_source;
    float m_fBlend;
    float m_userInputWeight;
    SVector3 m_lookToDirection;
    float m_fBlendPosition;
    float m_fBlendOrientation;
    bool m_bUseSeparateBlendFactors;
};
