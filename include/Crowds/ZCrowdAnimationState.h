#pragma once

#include "ZCrowdEntity.h"
#include "SCrowdAnimData.h"
#include "ZMeshRig.h"

class ZCrowdAnimationState
{
public:
	struct SCrowdAnimData
	{
		unsigned int m_nSource;
		unsigned int m_nIndex;
		unsigned char m_nLODFlags;
		SMatrix m_mMatrix;

		SCrowdAnimData() = default;
	};

	ZCrowdEntity* m_pCrowd;
	bool m_bInitialized;
	unsigned int m_nMaxNumVisibleCharacters;
	unsigned int m_nRagdollPoolSize;
	unsigned int m_nMaxBoneCacheSize;
	TArray<unsigned char> m_aRagdollIndices;
	TArray<unsigned short> m_aPossessedAnimIndices;
	unsigned int m_nNumTotalRagdollBones;
	unsigned int m_nNumTotalPossessedBones;
	TArray<ZAnimationLibrary*> m_aAnimationLibraries;
	TArray<TPair<unsigned int, unsigned int>> m_aAnimationLibBufferLocation;
	TArray<SQV*> m_apRenderPoses;
	TArray<SCrowdAnimData> m_aCrowdAnimData;
	TArray<ZAnimationBoneData const*> m_aBoneData;
	TArray<int> m_aAnimLibIndex;
	TArray<ZMeshRig> m_aMeshRigs;
	TArray<ZAnimationBonePose*> m_aTemporaryBonePose;
	unsigned int m_nRagdollStorageBegin;
	unsigned int m_nPossessedAnimStorageBegin;
	TArray<SQV> m_aRenderPosesStorage;
	TArray<SQV> m_aUnitBones;

	static const unsigned int INVALID_ANIM_STATE;
	static const unsigned int MAX_NUM_BONES;

	ZCrowdAnimationState() = default;
	ZCrowdAnimationState(ZCrowdEntity* pCrowd);
	~ZCrowdAnimationState() = default;
	void Allocate(unsigned int nNumCrowdActors, unsigned int nNumTemplates, unsigned int nMaxVisibleChars, unsigned int nRagdollPoolSize);
	void Initialize(const TArray<TEntityRef<ZCrowdActorEntity>>& pTemplates);
	void Clear();
	void PreIntegration();
	void PostIntegration();
	void AddActor(unsigned short nActorIndex, TEntityRef<ZCrowdActor> pActor, ZCrowdRagdollManager* pRagdollManager);
	void EndAddingActors(const TArray<TEntityRef<ZCrowdActorEntity>>& aActorTemplates, ZCrowdRagdollManager* pRagdollManager);
	unsigned int GetMaxBoneCacheSize() const;
	const SMatrix& GetActorWorldMatrix(const unsigned int i) const;
	unsigned char GetActorLOD(unsigned short nActorIndex) const;
	bool GetActorCulled(unsigned short nActorIndex) const;
	const ZAnimationBoneData* GetBoneData(unsigned int nTemplateIndex) const;
	const ZAnimationBonePose* GetBonePose(unsigned short nActorIndex, unsigned int nTemplateIndex) const;
	void GetRenderPose(unsigned short nActorIndex, const SQV** ppPose, unsigned int* pNumBones) const;
	void AddActorStopMode(unsigned short nActorIndex, TEntityRef<ZCrowdActor> pActor);
};
