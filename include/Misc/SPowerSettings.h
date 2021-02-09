#pragma once

struct SPowerSettings
{
    float m_fUpperBodyPositionSpringK;
    float m_fUpperBodyPositionDamping;
    float m_fUpperBodyOrientationSpringK;
    float m_fUpperBodyOrientationDamping;
    float m_fUpperBodyTwistOrientationSpringK;
    float m_fUpperBodyTwistOrientationDamping;
    float m_fLowerBodyPositionSpringK;
    float m_fLowerBodyPositionDamping;
    float m_fLowerBodyOrientationSpringK;
    float m_fLowerBodyOrientationDamping;
    float m_fPelvisFeetSpringK;
    float m_fPelvisFeetDamping;
};
