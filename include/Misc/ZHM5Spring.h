#pragma once

class ZHM5Spring
{
public:
    float m_fStiffness;
    float m_fUpdatedPos;
    float m_fMaxDiff;
    bool m_bActive;
    bool m_bPullStiffnessFromZero;
    float m_fCurStiffness;
    float m_fDelta;
    float m_fPullTime;
};
