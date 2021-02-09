#pragma once

#include "IComponentInterface.h"
#include "IEntitySceneContext.h"
#include "SComponentMapEntry.h"

class ZEntityManager : public IComponentInterface
{
public:
    IEntitySceneContext* m_pSceneContext;
    unsigned int m_nTransformParentPropertyID;
    unsigned int m_nObjectToParentID;

    virtual ~ZEntityManager();
    virtual ZVariantRef* GetVariantRef(ZVariantRef* result);
    virtual int AddRef();
    virtual int Release();
    virtual void* QueryInterface(STypeID* iid);

    SComponentMapEntry* GetComponentInterfacesInternal();
    ZEntityType** AllocateEntity(ZString* sDebugName, IEntityFactory* pEntityFactory);
    void DeleteEntities(TArrayRef<ZEntityRef> aEntities);
    void DestructEntity(IEntityBlueprintFactory* pBlueprint, ZEntityRef entityRef);
    void FreeEntity(ZEntityType** pEntity);
    ZEntityRef* ConstructEntity(ZEntityRef* result, ZString* sDebugName, ZResourcePtr* pEntityFactory, char* pMemBlock, ZEntityRef* transformParent);
    ZEntityRef* NewUninitializedEntity(ZEntityRef* result, ZString* sDebugName, IEntityFactory* pEntityFactory);
    IEntitySceneContext* GetSceneContext();
    unsigned int GetAdditionalMemoryForCreatedEntity(IEntityBlueprintFactory* pBlueprint);
    ZEntityRef* NewEntity(ZEntityRef* result, ZString* sDebugName, ZResourcePtr* pEntityFactory, ZEntityRef* transformParent);
    ZEntityRef* ConstructEntity(ZEntityRef* result, ZString* sDebugName, IEntityFactory* pEntityFactory, char* pMemBlock, ZEntityRef* transformParent);
    void SetSceneContext(IEntitySceneContext* pContext);
    ZEntityRef* NewEntity(ZEntityRef* result, ZString* sDebugName, IEntityFactory* pEntityFactory, ZEntityRef* transformParent);
    ZEntityManager();
    void DeleteEntity(ZEntityRef entityRef);
    ZEntityType** ConstructUninitializedEntity(ZString* sDebugName, IEntityFactory* pEntityFactory, char* pMemBlock);
    char* GetAllocationPointerFromCreatedEntity(ZEntityType** pEntity);
    IEntityBlueprintFactory* GetBlueprintFromCreatedEntity(ZEntityType** pEntity);
};
