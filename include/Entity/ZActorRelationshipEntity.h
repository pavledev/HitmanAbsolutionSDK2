#pragma once

#include "ZEntityImpl.h"
#include "EAIActorRelationshipType.h"
#include "TEntityRef.h"
#include "ZEntityRef.h"

class ZActor;
class ZComponentCreateInfo;
class ZString;

class ZActorRelationshipEntity : public ZEntityImpl
{
public:
	bool m_bAutoSetOnActivate;
	EAIActorRelationshipType m_eType;
	TEntityRef<ZActor> m_rActorA;
	TEntityRef<ZActor> m_rActorB;
	ZEntityRef m_rRelationshipData;

	~ZActorRelationshipEntity() override = default;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;

	ZActorRelationshipEntity() = default;
	ZActorRelationshipEntity(ZComponentCreateInfo& info);
	void OnSet();
	void OnRemove();
};
