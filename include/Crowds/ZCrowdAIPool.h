#pragma once

#include "TArray.h"

class IEntityFactory;
class ZAnimationBoneData;
class ZAnimationBonePose;
class ZCrowdAIActor;
class ZLinkedEntity;
template <class T> class TEntityRef;
template <class T> class TResourcePtr;

class ZCrowdAIPool
{
public:
	TArray<ZCrowdAIActor> m_aAIPool;

	ZCrowdAIPool(const ZCrowdAIPool& __that);
	ZCrowdAIPool() = default;
	~ZCrowdAIPool() = default;
	void InitializePool(const TResourcePtr<IEntityFactory>& m_pFactory, unsigned int nPoolSize);
	void DestroyPool();
	unsigned int GetAIActorPoolSize() const;
	void UpdatePossessedAnimations(float fDeltaTime);
	int GetNumFreeAIActors();
	ZCrowdAIActor* GetFreeCrowdAIActor(const ZAnimationBoneData* pBoneData);
	ZCrowdAIActor* GetCurrentCrowdAIActor(TEntityRef<ZLinkedEntity> pActor);
	void ReleaseAIActor(TEntityRef<ZLinkedEntity> pActor);
	unsigned int GetAIActorSlotIndex(TEntityRef<ZLinkedEntity> pActor);
	ZAnimationBonePose* GetAIActorAnimPoseByIndex(unsigned int nSlot);
	ZCrowdAIPool& operator=(const ZCrowdAIPool& __that);
};
