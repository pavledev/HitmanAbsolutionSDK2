#pragma once

#include "TArray.h"
#include "TArrayRef.h"
#include "float4.h"

class ZAnimationBoneData;
class ZAnimationBonePose;
struct SMatrix43;
struct SMatrix;
struct SQV;
template <class A, class B, class C> class THashMap;
template <class A, class B> class TDefaultHashMapPolicy;

class ZMorphemePostProcessorInfo
{
public:
	float m_fDeltaTime;
	const SMatrix43& m_mvObjToWorld;
	const SMatrix* m_pCameraMatrix;
	ZAnimationBonePose* m_pPose;
	TArray<SQV> m_bindPose;
	const TArrayRef<int> m_hierarchy;
	const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& m_globalToMeshIDMap;
	float4 m_vGroundOffset;
	float4 m_vGroundPosition;
	const ZAnimationBoneData* m_pBoneData;

	ZMorphemePostProcessorInfo() = default;
	ZMorphemePostProcessorInfo(float fDeltaTime, const SMatrix43& mvObjToWorld, const SMatrix* pCameraMatrix, ZAnimationBonePose* pPose, TArrayRef<SQV const> bindPose, const TArrayRef<int> hierarchy, const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap, const ZAnimationBoneData* pBoneData);
	~ZMorphemePostProcessorInfo() = default;
};
