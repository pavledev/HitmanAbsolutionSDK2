#pragma once

#include "EAISharedEventType.h"
#include "ZSharedKnowledgeRef.h"
#include "ZGridNodeRef.h"
#include "float4.h"

struct STypeID;

class ZSituationOrder
{
public:
	enum EOrderClearStatus
	{
		COMPLETED = 0,
		ABANDONED = 1,
		FAILED = 2
	};

	int m_nRefCount;
	EAISharedEventType m_type;
	STypeID* m_classType;
	ZSharedKnowledgeRef m_target;
	bool m_bHasPosition;
	float4 m_vPosition;
	ZGridNodeRef m_rGridNode;

	virtual ~ZSituationOrder() = default;

	ZSituationOrder() = default;
	ZSituationOrder(EAISharedEventType type, STypeID* classType, const ZGridNodeRef& rGridNode, const ZSharedKnowledgeRef& target);
	ZSituationOrder(EAISharedEventType type, STypeID* classType, const float4& vPosition, const ZGridNodeRef& rGridNode, const ZSharedKnowledgeRef& target);
	ZSituationOrder(EAISharedEventType type, STypeID* classType, const ZSharedKnowledgeRef& target);
	ZSituationOrder(EAISharedEventType type, const float4& vPosition, const ZGridNodeRef& rGridNode, const ZSharedKnowledgeRef& target);
	void AddRef() const;
	void Release() const;
	EAISharedEventType GetType() const;
	STypeID* GetClassType() const;
	const ZSharedKnowledgeRef& GetTarget() const;
	bool HasPosition() const;
	float4 GetPosition() const;
	ZGridNodeRef GetGridNode() const;
};
