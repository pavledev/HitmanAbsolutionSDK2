#pragma once

#include "SMatrix.h"

class SThrowAnimInfo
{
public:
    unsigned int m_nAnimID;
    unsigned int m_nAnimStateID;
    unsigned int m_nParentStateID;
    float m_fStartAlignFraction;
    float m_fEndAlignFraction;
    float m_fReleaseFraction;
    float m_fColiCheckFraction;
    float m_fDuration;
    SMatrix m_mLockFootReleaseMatPos;
    SMatrix m_mRightHandReleaseMatPos;
    SMatrix m_mRightAttacherReleaseMatPos;
    SMatrix m_mRightAttacherColiCheckMatPos;
    SMatrix m_mReleaseGroundDelta;
};
