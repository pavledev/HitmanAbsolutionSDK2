#pragma once

#include "eMorphemeRequests.h"
#include "TEntityRef.h"

class ZHitman5;
class IMorphemeEntity;
class ZMorphemeNetworkInstance;
class ZMovementAnimNode;
class ZString;

class ZMovementAnimTransition
{
public:
	unsigned int m_iAnimParentNode;
	ZMovementAnimNode* m_pAnimDestinationNode;
	eMorphemeRequests m_iMorphemeRequest;
	TEntityRef<ZHitman5> m_pHitman;

	ZMovementAnimTransition(const TEntityRef<ZHitman5>& pHitman, eMorphemeRequests iRequest);
	ZMovementAnimTransition(const TEntityRef<ZHitman5>& pHitman, ZMovementAnimNode* pDestination, eMorphemeRequests iRequest);
	ZMovementAnimTransition(const TEntityRef<ZHitman5>& pHitman, ZMovementAnimNode* pParent, ZMovementAnimNode* pDestination, eMorphemeRequests iRequest);
	ZMovementAnimTransition(const TEntityRef<ZHitman5>& pHitman, ZMorphemeNetworkInstance* pMorphemeNetwork, ZString szParentName, ZMovementAnimNode* pDestination, eMorphemeRequests iRequest);
	ZMovementAnimTransition(const TEntityRef<ZHitman5>& pHitman, IMorphemeEntity* pMorphemeEntity, ZString szParentName, ZMovementAnimNode* pDestination, eMorphemeRequests iRequest);
	ZMovementAnimTransition(const TEntityRef<ZHitman5>& pHitman, unsigned int iParent, ZMovementAnimNode* pDestination, eMorphemeRequests iRequest);
	ZMovementAnimTransition(const TEntityRef<ZHitman5>& pHitman);
	ZMovementAnimTransition() = default;
	void Init(eMorphemeRequests iRequest);
	void Init(ZMovementAnimNode* pDestination, eMorphemeRequests iRequest);
	void Init(ZMovementAnimNode* pParent, ZMovementAnimNode* pDestination, eMorphemeRequests iRequest);
	void Init(IMorphemeEntity* pMorphemeEntity, ZString szParentName, ZMovementAnimNode* pDestination, eMorphemeRequests iRequest);
	void Init(ZMorphemeNetworkInstance* pMorphemeNetwork, ZString szParentName, ZMovementAnimNode* pDestination, eMorphemeRequests iRequest);
	void Init(unsigned int iParent, ZMovementAnimNode* pDestination, eMorphemeRequests iRequest);
	bool IsActive() const;
	bool IsTransitionComplete() const;
	bool StartTransition();
	bool ForceTransitionEnd();
	void SetHitman(const TEntityRef<ZHitman5>& pHitman);
	TEntityRef<ZHitman5> Hitman() const;
	~ZMovementAnimTransition() = default;
};
