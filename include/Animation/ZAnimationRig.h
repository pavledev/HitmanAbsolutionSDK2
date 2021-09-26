#pragma once

#include "ZAnimationBoneHierarchy.h"
#include "ZAnimationBonePose.h"
#include "TArray.h"
#include "TArrayRef.h"
#include "THashMap.h"

class ZString;
struct SBoneDefinition;
struct SMatrix43;
struct SQV;
template <class A, class B> class TDefaultHashMapPolicy;

class ZAnimationRig
{
public:
	ZAnimationBoneHierarchy m_boneHierarchy;
	ZAnimationBonePose m_bindPose;
	TArray<ZString> m_boneNames;
	TArray<int> m_aMeshIDtoGlobalID;
	unsigned short* m_pGlobalToMeshID;
	TArrayRef<unsigned short> m_aGlobalToMeshID;
	THashMap<int, int, TDefaultHashMapPolicy<int, int>> m_globalIDToMeshID;
	SMatrix43* m_pObjectSpaceToBindPoseSpace;
	TArrayRef<SMatrix43> m_aObjectSpaceToBindPoseSpace;
	SQV* m_pObjectSpaceToBindPoseSpaceSQV;
	TArrayRef<SQV> m_aObjectSpaceToBindPoseSpaceSQV;
	SQV* m_pBindPoseSpaceToObjectSpaceSQV;
	TArrayRef<SQV> m_aBindPoseSpaceToObjectSpaceSQV;
	bool m_bGlobalDirty;

	virtual ~ZAnimationRig() = default;

	ZAnimationRig() = default;
	void Init(const SBoneDefinition* pBoneDefinitions, const SQV* pBindPose, const SMatrix43* pObjectSpaceToBindPoseSpace, int nBoneCount);
	const ZAnimationBoneHierarchy& GetBoneHierarchy() const;
	const ZAnimationBonePose& GetBindPose() const;
	const TArray<ZString>& GetBoneNames() const;
	unsigned int GetBoneCount() const;
	const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& GetGlobalToMeshIDMap() const;
	const TArrayRef<unsigned short> GetGlobalToMeshIDArray() const;
	const TArray<int>& GetMeshToGlobalIDMap() const;
	const int GetRootBoneIndex() const;
	const TArrayRef<SMatrix43> GetObjectSpaceToBindPoseSpaceTransforms() const;
	const TArrayRef<SQV> GetObjectSpaceToBindPoseSpaceTransformsSQV() const;
	const TArrayRef<SQV> GetBindPoseSpaceToObjectSpaceTransformsSQV() const;
	void SetBoneNames(const SBoneDefinition* pBoneDefinitions, int nBoneCount);
	void MapMeshIDToGlobalID(const SBoneDefinition* pBoneDefinitions, int nBoneCount);
	void MapGlobalIDToMeshID(const SBoneDefinition* pBoneDefinitions, int nBoneCount);
	void ReparentTwistBones();
	void ResetTwisterBonesInBindPose();
	unsigned char GetBodyPartForBoneIndex(int nBoneIndex);
	void SetBodyParts(const SBoneDefinition* pBoneDefinitions, int nBoneCount);
	void AddDimensionToUpperArms(const SBoneDefinition* pBoneDefinitions, bool bRight);
	void AddDimensionToForeArms(const SBoneDefinition* pBoneDefinitions, bool bRight);
	void AddDimensionToTighs(const SBoneDefinition* pBoneDefinitions, bool bRight);
	void ResizeGlobalToMeshID(unsigned int size) const;
	void ResizeObjectSpaceToBindPoseSpace(unsigned int size) const;
};
