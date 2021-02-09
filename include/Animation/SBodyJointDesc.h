#pragma once

#include "SVector3.h"
#include "EJointType.h"
#include "EMotionType.h"
#include "SVector2.h"

class SBodyJointDesc
{
    EJointType m_Type;
    unsigned int m_nParentPartID;
    unsigned int m_nChildPartID;
    SVector3 m_vAnchor;
    SVector3 m_vAxis;
    SVector3 m_vNormal;
    SVector3 m_vSwing;
    EMotionType m_eTwistMotion;
    SVector2 m_vTwistLimits;
    EMotionType m_eSwing1Motion;
    EMotionType m_eSwing2Motion;
    float m_fSwingLimit1;
    float m_fSwingLimit2;
    float m_fSpringForce;
    bool m_bNewFrames;
    SVector3 m_vParentAnchor;
    SVector3 m_vParentAxis;
    SVector3 m_vParentNormal;
    SVector3 m_vChildAnchor;
    SVector3 m_vChildAxis;
    SVector3 m_vChildNormal;
};
