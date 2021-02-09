#pragma once

#include "SMatrix43.h"
#include "SMatrix.h"
#include "ZAnimationBonePose.h"
#include "TArray.h"
#include "SQV.h"
#include "TArrayRef.h"
#include "THashMap.h"
#include "TDefaultHashMapPolicy.h"
#include "ZAnimationBoneData.h"

class alignas(16) ZMorphemePostProcessorInfo
{
public:
    float m_fDeltaTime;
    const SMatrix43* m_mvObjToWorld;
    const SMatrix* m_pCameraMatrix;
    ZAnimationBonePose* m_pPose;
    TArray<SQV> m_bindPose;
    const TArrayRef<int> m_hierarchy;
    const THashMap<int, int, TDefaultHashMapPolicy<int, int> >* m_globalToMeshIDMap;
    float4 m_vGroundOffset;
    float4 m_vGroundPosition;
    const ZAnimationBoneData* m_pBoneData;
};
