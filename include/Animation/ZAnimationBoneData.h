#pragma once

#include "ZAnimationFacePoseCollection.h"
#include "ZAnimationRig.h"

class ZUnsafeResourceReader;
struct SBoneConstraintsHeader;
struct SBoneDefinition;

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

	virtual ~ZAnimationBoneData() = default;

	ZAnimationBoneData() = default;
	void ReadBoneData(ZUnsafeResourceReader& primReader);
	bool IsInitialized() const;
	const ZAnimationRig& GetRig() const;
	const ZAnimationFacePoseCollection& GetFacePoseCollection() const;
	unsigned int GetNumberOfAnimatedBones() const;
	unsigned int GetNumberOfDeformBones() const;
	const SBoneConstraintsHeader* GetBoneConstraintsHeader() const;
	unsigned int GetBoneConstraintsSizeBytes() const;
	const SBoneDefinition* GetBoneDefinitions() const;
	void InitRig(const ZUnsafeResourceReader& primReader);
	void InitFacePoses(const ZUnsafeResourceReader& primReader, unsigned int nPoseBoneHeaderOffset);
};
