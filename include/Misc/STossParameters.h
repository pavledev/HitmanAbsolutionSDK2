#pragma once

class alignas(4) STossParameters
{
public:
    float m_fTossTime;
    float m_fTossLength;
    float m_fVecticalVelocity;
    float m_fHorizontalVelocity;
    bool m_bIsValid;
};
