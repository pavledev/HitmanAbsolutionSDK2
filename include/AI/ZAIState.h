#pragma once

#include "IComponentInterface.h"
#include "ZKnownEntityContainer.h"
#include "SComponentMapEntry.h"
#include "TRefCountPtrArg.h"

class ZAIState : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZKnownEntityContainer m_knownEntityContainer;

	~ZAIState() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZAIState() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	SKnownEntity* AllocateKnownEntity();
	void FreeKnownEntity(SKnownEntity* pEntity);
	unsigned int GetNumAllocatedKnownEntities();
	bool CanAllocateKnownEntity();
	void DumpAllocatedSharedEntities();
	void DumpAllocatedKnownEntities();
	TRefCountPtrArg<SKnownEntity> GetKnownEntity(unsigned int actorId, unsigned int entityId);
	ZKnownEntityContainer::ZActorKnownEntitiesEnumerator GetKnownEntities(unsigned int actorIndex);
	void RemoveAllKnownEntities(unsigned int actorId);
	bool RemoveKnownEntity(unsigned int actorId, unsigned int entityId);
	void AddKnownEntity(unsigned int actorId, unsigned int entityId, SKnownEntity* pKnownEntity);
};
