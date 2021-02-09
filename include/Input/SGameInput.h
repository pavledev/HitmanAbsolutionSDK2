#pragma once

class alignas(4) SGameInput
{
public:
    float m_AnalogGameInput[8];
    bool m_iGameInputFlags[67];
    bool m_iPreviousGameInputFlags[67];
    bool m_iGameInputUpdatingFlags[67];
    bool m_iGameInputActivatingFlags[67];
    bool m_iConsumedGameInputFlags[67];
};
