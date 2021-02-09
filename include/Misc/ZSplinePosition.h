#pragma once

#include "ZSpline.h"
#include "ZParametricCurve.h"

class ZSplinePosition
{
public:
    float m_fT;
    float m_fDone;
    float m_fLength;
    int m_iCurveIdx;
    const ZSpline* m_pSpline;
    ZParametricCurve m_Curve;
};
