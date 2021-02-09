#include "ZEntityManager.h"
#include "Function.h"

SComponentMapEntry* ZEntityManager::GetComponentInterfacesInternal()
{
	return Function::CallMethodAndReturn<SComponentMapEntry*, ZEntityManager*>(BaseAddresses::runtimeEntity + 0x11C2, this);
}

ZEntityType** ZEntityManager::AllocateEntity(ZString* sDebugName, IEntityFactory* pEntityFactory)
{
	return Function::CallMethodAndReturn<ZEntityType**, ZEntityManager*, ZString*, IEntityFactory*>(BaseAddresses::runtimeEntity + 0x146A, this, sDebugName, pEntityFactory);
}

void ZEntityManager::DeleteEntities(TArrayRef<ZEntityRef> aEntities)
{
	Function::CallMethod<ZEntityManager*, TArrayRef<ZEntityRef>>(BaseAddresses::runtimeEntity + 0x1776, this, aEntities);
}

void ZEntityManager::DestructEntity(IEntityBlueprintFactory* pBlueprint, ZEntityRef entityRef)
{
	Function::CallMethod<ZEntityManager*, IEntityBlueprintFactory*, ZEntityRef>(BaseAddresses::runtimeEntity + 0x19C9, this, pBlueprint, entityRef);
}

void ZEntityManager::FreeEntity(ZEntityType** pEntity)
{
	Function::CallMethod<ZEntityManager*, ZEntityType**>(BaseAddresses::runtimeEntity + 0x1AEB, this, pEntity);
}

ZEntityRef* ZEntityManager::ConstructEntity(ZEntityRef* result, ZString* sDebugName, ZResourcePtr* pEntityFactory, char* pMemBlock, ZEntityRef* transformParent)
{
	return Function::CallMethodAndReturn<ZEntityRef*, ZEntityManager*, ZEntityRef*, ZString*, ZResourcePtr*, char*, ZEntityRef*>(BaseAddresses::runtimeEntity + 0x212B, this, result, sDebugName, pEntityFactory, pMemBlock, transformParent);
}

ZEntityRef* ZEntityManager::NewUninitializedEntity(ZEntityRef* result, ZString* sDebugName, IEntityFactory* pEntityFactory)
{
	return Function::CallMethodAndReturn<ZEntityRef*, ZEntityManager*, ZEntityRef*, ZString*, IEntityFactory*>(BaseAddresses::runtimeEntity + 0x2658, this, result, sDebugName, pEntityFactory);
}

IEntitySceneContext* ZEntityManager::GetSceneContext()
{
	return Function::CallMethodAndReturn<IEntitySceneContext*, ZEntityManager*>(BaseAddresses::runtimeEntity + 0x28E2, this);
}

unsigned int ZEntityManager::GetAdditionalMemoryForCreatedEntity(IEntityBlueprintFactory* pBlueprint)
{
	return Function::CallMethodAndReturn<unsigned int, ZEntityManager*, IEntityBlueprintFactory*>(BaseAddresses::runtimeEntity + 0x2BF8, this, pBlueprint);
}

ZEntityRef* ZEntityManager::NewEntity(ZEntityRef* result, ZString* sDebugName, ZResourcePtr* pEntityFactory, ZEntityRef* transformParent)
{
	return Function::CallMethodAndReturn<ZEntityRef*, ZEntityManager*, ZEntityRef*, ZString*, ZResourcePtr*, ZEntityRef*>(BaseAddresses::runtimeEntity + 0x2CDE, this, result, sDebugName, pEntityFactory, transformParent);
}

ZEntityRef* ZEntityManager::ConstructEntity(ZEntityRef* result, ZString* sDebugName, IEntityFactory* pEntityFactory, char* pMemBlock, ZEntityRef* transformParent)
{
	return Function::CallMethodAndReturn<ZEntityRef*, ZEntityManager*, ZEntityRef*, ZString*, IEntityFactory*, char*, ZEntityRef*>(BaseAddresses::runtimeEntity + 0x3440, this, result, sDebugName, pEntityFactory, pMemBlock, transformParent);
}

void ZEntityManager::SetSceneContext(IEntitySceneContext* pContext)
{
	Function::CallMethod<ZEntityManager*, IEntitySceneContext*>(BaseAddresses::runtimeEntity + 0x3445, this, pContext);
}

ZEntityRef* ZEntityManager::NewEntity(ZEntityRef* result, ZString* sDebugName, IEntityFactory* pEntityFactory, ZEntityRef* transformParent)
{
	return Function::CallMethodAndReturn<ZEntityRef*, ZEntityManager*, ZEntityRef*, ZString*, IEntityFactory*, ZEntityRef*>(BaseAddresses::runtimeEntity + 0x3472, this, result, sDebugName, pEntityFactory, transformParent);
}

void ZEntityManager::DeleteEntity(ZEntityRef entityRef)
{
	Function::CallMethod<ZEntityManager*, ZEntityRef>(BaseAddresses::runtimeEntity + 0x3EAE, this, entityRef);
}

ZEntityType** ZEntityManager::ConstructUninitializedEntity(ZString* sDebugName, IEntityFactory* pEntityFactory, char* pMemBlock)
{
	return Function::CallMethodAndReturn<ZEntityType**, ZEntityManager*, ZString*, IEntityFactory*, char*>(BaseAddresses::runtimeEntity + 0x3F58, this, sDebugName, pEntityFactory, pMemBlock);
}

char* ZEntityManager::GetAllocationPointerFromCreatedEntity(ZEntityType** pEntity)
{
	return Function::CallMethodAndReturn<char*, ZEntityManager*, ZEntityType**>(BaseAddresses::runtimeEntity + 0x504C, this, pEntity);
}

IEntityBlueprintFactory* ZEntityManager::GetBlueprintFromCreatedEntity(ZEntityType** pEntity)
{
	return Function::CallMethodAndReturn<IEntityBlueprintFactory*, ZEntityManager*, ZEntityType**>(BaseAddresses::runtimeEntity + 0x52DB, this, pEntity);
}
