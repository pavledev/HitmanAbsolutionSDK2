#pragma once

#include "IComponentInterface.h"
#include "TResourcePtr.h"

class IEntityBlueprintFactory;
class ZEntityRef;
class ZEntityType;
template <class T> class TArray;

class __declspec(novtable) IEntityFactory : public IComponentInterface
{
public:
	~IEntityFactory() override = default;
	virtual void GetMemoryRequirements(unsigned int* param1, unsigned int* param2, unsigned int* param3) const = 0;
	virtual ZEntityType* GetFactoryEntityType() const = 0;
	virtual ZEntityType** CreateEntity(unsigned char* param1, ZEntityType* entityType) = 0;
	virtual void ConfigureEntity(ZEntityType** entityType) = 0;
	virtual void InitializeEntity(ZEntityType** entityType) = 0;
	virtual void DestroyEntity(ZEntityType** entityType) const = 0;
	virtual void DisableReloadOfConstAfterStartResources(ZEntityType** entityType) const = 0;
	virtual bool AreAllResourcesReady(ZEntityType** entityType) const = 0;
	virtual void Start(ZEntityType** entityType) const = 0;
	virtual void CollectInternalEntities(ZEntityType** entityType, TArray<ZEntityRef>& array) const = 0;
	virtual IEntityBlueprintFactory* GetBlueprint() const = 0;
	virtual TResourcePtr<IEntityBlueprintFactory> GetBlueprintResource() const = 0;

	IEntityFactory() = default;
};
