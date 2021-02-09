#pragma once

#include "IComponentInterface.h"
#include "ZEntityRef.h"
#include "IEntityFactory.h"
#include "TArrayRef.h"

class IEntitySceneContext : public IComponentInterface
{
public:
    virtual void AddEntity(const ZEntityRef*, IEntityFactory*);
    virtual void RemoveEntity(const ZEntityRef*);
    virtual void ClearScene(bool);
    virtual void PrepareNewScene();
    virtual void CreateScene();
    virtual void CreateScene(const ZString*);
    virtual void ResetScene(const ZString*);
    virtual void SetSceneResources(TResourcePtr<IEntityFactory>, TResourcePtr<IEntityBlueprintFactory>, ZResourcePtr);
    virtual void DropSceneFactory();
    virtual bool IsRestartingThroughEngine();
    virtual ZEvent<ZEntityRef const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull>* GetEntityAddedEvent();
    virtual ZEvent<ZEntityRef const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull>* GetEntityRemovedEvent();
    virtual ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>* GetRequestSceneResetEvent();
    virtual ZResourcePtr* GetSceneHeaderLibrary(ZResourcePtr* result);
    virtual bool IsClearingGraph();
    virtual void RegisterForResetSceneEvent(const ZDelegate<void __cdecl(void)>*);
    virtual void UnregisterForResetSceneEvent(const ZDelegate<void __cdecl(void)>*);
    virtual ZEntityRef* GetScene(ZEntityRef* result);
    virtual void StartEntities();
    virtual ZEntityRef* CreateUninitializedEntityWithFactory(ZEntityRef* result, const ZString*, IEntityFactory*);
    virtual void DeleteEntities(const TArrayRef<ZEntityRef>);
};
