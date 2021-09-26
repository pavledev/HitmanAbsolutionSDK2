#pragma once

#include "IComponentInterface.h"
#include "ZEntityRef.h"
#include "ZResourcePtr.h"
#include "ZVariantRef.h"

class IEntityBlueprintFactory;
class IEntityFactory;
class IEntitySceneContext;
class ZEntityType;
class ZString;
struct SComponentMapEntry;
struct STypeID;
template <class T> class TArrayRef;

class ZEntityManager : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	IEntitySceneContext* m_pSceneContext;
	unsigned int m_nTransformParentPropertyID;
	unsigned int m_nObjectToParentID;

	~ZEntityManager() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZEntityManager() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	ZEntityRef NewEntity(const ZString& sDebugName, IEntityFactory* pEntityFactory, const ZEntityRef& transformParent);
	ZEntityRef NewEntity(const ZString& sDebugName, const ZResourcePtr& pEntityFactory, const ZEntityRef& transformParent);
	ZEntityRef NewUninitializedEntity(const ZString& sDebugName, IEntityFactory* pEntityFactory);
	void DeleteEntity(const ZEntityRef entityRef);
	void DeleteEntities(const TArrayRef<ZEntityRef> aEntities);
	const IEntityBlueprintFactory* GetBlueprintFromCreatedEntity(ZEntityType** pEntity) const;
	ZEntityRef ConstructEntity(const ZString& sDebugName, IEntityFactory* pEntityFactory, unsigned char* pMemBlock, const ZEntityRef& transformParent);
	ZEntityRef ConstructEntity(const ZString& sDebugName, const ZResourcePtr& pEntityFactory, unsigned char* pMemBlock, const ZEntityRef& transformParent);
	ZEntityType** ConstructUninitializedEntity(const ZString& sDebugName, IEntityFactory* pEntityFactory, unsigned char* pMemBlock);
	void DestructEntity(IEntityBlueprintFactory* pBlueprint, ZEntityRef entityRef);
	void SetSceneContext(IEntitySceneContext* pContext);
	IEntitySceneContext* GetSceneContext();
	ZEntityType** AllocateEntity(const ZString& sDebugName, IEntityFactory* pEntityFactory);
	void FreeEntity(ZEntityType** pEntity);
	unsigned int GetAdditionalMemoryForCreatedEntity(const IEntityBlueprintFactory* pBlueprint) const;
	unsigned char* GetAllocationPointerFromCreatedEntity(ZEntityType** pEntity) const;
};
