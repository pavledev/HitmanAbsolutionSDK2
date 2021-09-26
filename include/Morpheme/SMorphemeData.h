#pragma once

#include "BoneIdSystem.h"
#include "TArrayRef.h"

class ZAnimationBoneData;
class ZMorphemeNetworkInstance;
struct SBoneConstraintsHeader;
struct SBoneDefinition;
struct SCutSequenceData;
struct SQV;
struct ZChildNetworkEntry;
template <class A, class B> class TMap;
template <class T> class TArray;

struct __declspec(novtable) SMorphemeData
{
	ZAnimationBoneData* m_pBoneData;
	TArray<int>* m_pMeshIDToRigID;
	TMap<unsigned int, ZChildNetworkEntry>* m_pChildNetworks;
	ZMorphemeNetworkInstance* m_pParentNetwork;
	unsigned short* m_pGlobalToMeshId;
	unsigned int m_nGlobalToMeshIdSize;
	const SBoneConstraintsHeader* m_pBoneConstraintsHeader;
	unsigned int m_nBoneConstraintsBytes;
	BoneIdSystem m_BoneIdData;

	virtual ~SMorphemeData() = default;
	virtual const SCutSequenceData* GetCutSequenceData(const char* param1) const = 0;
	virtual unsigned int GetNumberOfDeformBones() const = 0;
	virtual const TArrayRef<SQV> GetMeshBindPose() const = 0;
	virtual int* GetMeshIDToRigIDMap() const = 0;
	virtual int* GetMeshHierarchy() const = 0;
	virtual const SBoneDefinition* GetBoneDefinitions() const = 0;

	SMorphemeData() = default;
};
