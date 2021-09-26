#pragma once

#include "ZGameTime.h"
#include "TEntityRef.h"
#include "ZSituationOrder.h"
#include "ZSituationGroup.h"

class ZSituationBase;
struct SKnownEntity;

class ZSituationMember
{
public:
	int m_nRefCount;
	ZGameTime m_tJoinedTime;
	TEntityRef<ZSituationBase> m_rSituation;
	ZSituationGroup* m_pActiveGroup;
	TRefCountPtr<ZSituationOrder> m_pCurrentOrder;
	bool m_bCurrentOrderValid;
	ZGameTime m_tCurrentOrderStart;
	float m_fCurrentOrderForceTime;
	TRefCountPtr<ZSituationOrder> m_pPendingOrder;
	float m_fPendingOrderForceTime;
	TEntityRef<ZActor> m_pActor;
	TRefCountPtr<SKnownEntity> m_rKnownTarget;

	virtual ~ZSituationMember() = default;
	virtual void OnOrderAssigned();

	ZSituationMember() = default;
	ZSituationMember(const TEntityRef<ZSituationBase>& rSituation, const TEntityRef<ZActor>& rActor);
	void AddRef() const;
	void Release() const;
	TEntityRef<ZActor>& GetActor();
	ZGameTime GetJoinedTime() const;
	bool IsActiveInGroup() const;
	TRefCountPtrArg<ZSituationGroup> GetActiveGroup() const;
	bool IsBusy() const;
	bool HasOrder() const;
	bool HasAssignedOrder(EAISharedEventType eOrder) const;
	bool IsOrderValid() const;
	bool IsOrderForced() const;
	float GetOrderDuration() const;
	bool HasPendingOrder() const;
	bool IsPendingOrderForced() const;
	TRefCountPtrArg<ZSituationOrder> GetOrder() const;
	TRefCountPtrArg<ZSituationOrder> GetPendingOrder() const;
	TEntityRef<ZSituationBase> GetSituation() const;
	void SetActiveGroup(ZSituationGroup* pGroup);
	void AssignOrder(TRefCountPtrArg<ZSituationOrder> pOrder, float fForceTime);
	void AssignPendingOrder(TRefCountPtrArg<ZSituationOrder> pOrder, float fForceTime);
	void InvalidateOrder();
	void ClearOrder();
	void ClearPendingOrder();
	void ClearAllOrders();
	void ExpireForcedOrder();
	void OnLeaveSituation();
};
