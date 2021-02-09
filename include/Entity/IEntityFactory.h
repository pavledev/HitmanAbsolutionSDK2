#pragma once

#include "IComponentInterface.h"
#include "ZEntityType.h"
#include "IEntityBlueprintFactory.h"
#include "TResourcePtr.h"

class IEntityFactory : public IComponentInterface
{
public:
    virtual void GetMemoryRequirements(unsigned int*, unsigned int*, unsigned int*);
    virtual ZEntityType* GetFactoryEntityType();
    virtual ZEntityType** CreateEntity(unsigned __int8*, ZEntityType*);
    virtual void ConfigureEntity(ZEntityType**);
    virtual void InitializeEntity(ZEntityType**);
    virtual void DestroyEntity(ZEntityType**);
    virtual void DisableReloadOfConstAfterStartResources(ZEntityType**);
    virtual bool AreAllResourcesReady(ZEntityType**);
    virtual void Start(ZEntityType**);
    virtual void CollectInternalEntities(ZEntityType**, TArray<ZEntityRef>*);
    virtual IEntityBlueprintFactory* GetBlueprint();
    virtual TResourcePtr<IEntityBlueprintFactory>* GetBlueprintResource(TResourcePtr<IEntityBlueprintFactory>* result);
};
