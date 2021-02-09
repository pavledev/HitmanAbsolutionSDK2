#pragma once

#include "ZSplineKnot.h"

enum EType : __int32
{
    TypeLinear = 0x0,
    TypeHermite = 0x1,
    TypeBezier = 0x2,
    TypeManual = 0x3
};

class alignas(4) ZSpline
{
public:
    EType m_eType;
    unsigned int m_iNumberOfKnots;
    ZSplineKnot* m_pKnots;
    bool m_bLooping;

    virtual ~ZSpline();
};
