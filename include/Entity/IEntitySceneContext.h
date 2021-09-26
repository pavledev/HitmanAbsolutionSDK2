#pragma once

#include "IComponentInterface.h"
#include "ZEntityRef.h"
#include "ZResourcePtr.h"

class IEntityBlueprintFactory;
class IEntityFactory;
class ZEventNull;
class ZString;
template <class A, class B, class C, class D, class E> class ZEvent;
template <class T> class TArrayRef;
template <class T> class TResourcePtr;
template <class T> class alignas(8) ZDelegate;

class __declspec(novtable) IEntitySceneContext : public IComponentInterface
{
public:
	~IEntitySceneContext() override = default;
	virtual void AddEntity(const ZEntityRef& entityRef, IEntityFactory* entityFactory) = 0;
	virtual void RemoveEntity(const ZEntityRef& entityRef) = 0;
	virtual void ClearScene(bool param1) = 0;
	virtual void PrepareNewScene() = 0;
	virtual void CreateScene() = 0;
	virtual void CreateScene(const ZString& string) = 0;
	virtual void ResetScene(const ZString& string) = 0;
	virtual void SetSceneResources(TResourcePtr<IEntityFactory> resourcePtr, TResourcePtr<IEntityBlueprintFactory> resourcePtr2, ZResourcePtr resourcePtr3) = 0;
	virtual void DropSceneFactory() = 0;
	virtual bool IsRestartingThroughEngine() const = 0;
	virtual ZEvent<ZEntityRef const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetEntityAddedEvent() = 0;
	virtual ZEvent<ZEntityRef const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetEntityRemovedEvent() = 0;
	virtual ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetRequestSceneResetEvent() = 0;
	virtual ZResourcePtr GetSceneHeaderLibrary() const = 0;
	virtual bool IsClearingGraph() const = 0;
	virtual void RegisterForResetSceneEvent(const ZDelegate<void __cdecl(void)>& delegate) = 0;
	virtual void UnregisterForResetSceneEvent(const ZDelegate<void __cdecl(void)>& delegate) = 0;
	virtual ZEntityRef GetScene() = 0;
	virtual void StartEntities() = 0;
	virtual ZEntityRef CreateUninitializedEntityWithFactory(const ZString& string, IEntityFactory* entityFactory) = 0;
	virtual void DeleteEntities(const TArrayRef<ZEntityRef> arrayRef) = 0;

	IEntitySceneContext() = default;
};
