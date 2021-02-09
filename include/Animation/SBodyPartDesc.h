#pragma once

#include "SMatrix43.h"
#include "EShapeType.h"

class SBodyPartDesc
{
public:
    unsigned int m_nID;
    SMatrix43 m_tTransform;
    EShapeType m_Type;
    float m_fRadius;
    SVector3 m_vExtents;
    SVector3 m_vOffset;
    float m_fFriction;
    float m_fMassPercentage;
};
