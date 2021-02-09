#pragma once

#include "THashMap.h"
#include "ZAnimationFacePose.h"
#include "TDefaultHashMapPolicy.h"
#include "SRawFacePoseCollection.h"

class ZAnimationFacePoseCollection
{
public:
    THashMap<unsigned int, ZAnimationFacePose, TDefaultHashMapPolicy<unsigned int, ZAnimationFacePose>> m_facePoses;
    SRawFacePoseCollection* m_pRawFacePoseCollection;
};
