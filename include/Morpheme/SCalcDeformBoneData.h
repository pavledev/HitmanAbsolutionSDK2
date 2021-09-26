#pragma once

#include "BoneIdSystem.h"

struct SBoneConstraintsHeader;
struct SBoneDefinition;
struct SQV;
struct float4;

struct SCalcDeformBoneData
{
	SQV* m_pBoneCache;
	unsigned int m_nBoneCacheSize;
	float4* m_pMinBound;
	float4* m_pMaxBound;
	const unsigned short* m_pGlobalToMeshId;
	unsigned int m_nGlobalToMeshIdSize;
	const SQV* m_pBindPose;
	unsigned int m_nBindPoseSize;
	const int* m_pHierarchy;
	const SBoneDefinition* m_pBoneDefinition;
	const SBoneConstraintsHeader* m_pBoneConstraintsHeader;
	unsigned int m_nBoneConstraintsBytes;
	bool m_bCalcTwistBones : 1;
	bool m_bCalcConstraintBones : 1;
	BoneIdSystem m_BoneIdData;

	SCalcDeformBoneData() = default;
	~SCalcDeformBoneData() = default;
};
