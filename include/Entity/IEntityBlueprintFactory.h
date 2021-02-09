#pragma once

#include "IComponentInterface.h"
#include "ZEntityType.h"
#include "SEntityStats.h"

class IEntityBlueprintFactory : public IComponentInterface
{
public:
    virtual void GetMemoryRequirements(unsigned int*, unsigned int*, unsigned int*);
    virtual ZEntityType* GetFactoryEntityType();
    virtual ZEntityType** CreateEntity(unsigned __int8*, ZEntityType*);
    virtual void DestroyEntity(ZEntityType**);
    virtual void DisableReloadOfConstAfterStartResources(ZEntityType**);
    virtual bool AreAllResourcesReady(ZEntityType**);
    virtual void Start(ZEntityType**);
    virtual void CollectInternalEntities(ZEntityType**, TArray<ZEntityRef>*);
    virtual void CollectEntityStats(SEntityStats*);
    virtual void ClearAllEntityReferences(ZEntityType**);
    virtual void ClearAllEntityReferencesOnChildren(ZEntityType**);
    virtual void OnOrphanedResource();
};
