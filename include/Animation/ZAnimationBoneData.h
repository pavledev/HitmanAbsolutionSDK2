#pragma once

#include "SBoneConstraintsHeader.h"
#include "SBoneDefinition.h"
#include "ZAnimationFacePoseCollection.h"
#include "ZAnimationRig.h"

class ZAnimationBoneData
{
public:
    bool m_bIsInitialized;
    int m_nNumberOfDeformBones;
    int m_nNumberOfAnimatedBones;
    unsigned int m_nBoneConstraintsSize;
    SBoneConstraintsHeader* m_pBoneConstraintsHeader;
    SBoneDefinition* m_pBoneDefinitions;
    ZAnimationFacePoseCollection m_facePoseCollection;
    ZAnimationRig m_rig;

    virtual ~ZAnimationBoneData();
};
