#pragma once

#include "IEntitySceneContext.h"
#include "SSceneInitParameters.h"
#include "TEntityRef.h"
#include "TArray.h"
#include "TResourcePtr.h"
#include "ZEntityRef.h"
#include "ZEvent.h"
#include "ZResourcePtr.h"
#include "ZRuntimeResourceID.h"
#include "ZVariantRef.h"

struct SComponentMapEntry;
class IEntityBlueprintFactory;
class IEntityFactory;
class ISceneEntity;
class ZEventNull;
class ZString;
struct STypeID;
template <class T> class TArrayRef;
template <class T> class alignas(8) ZDelegate;

class ZEntitySceneContext : public IEntitySceneContext
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZRuntimeResourceID m_ridSceneFactory;
	TResourcePtr<IEntityFactory> m_sceneFactoryResource;
	TResourcePtr<IEntityBlueprintFactory> m_sceneBlueprintResource;
	unsigned char* m_pSceneMemoryBlock;
	unsigned int m_nSceneMemoryBlockSize;
	ZResourcePtr m_pSceneHeaderLibraryResource;
	ZEntityRef m_pLoadedScene;
	bool m_bRestartingThroughEngine;
	ZEvent<ZEntityRef const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_OnEntityAddedEvent;
	ZEvent<ZEntityRef const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_OnEntityRemovedEvent;
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_RequestSceneResetEvent;
	SSceneInitParameters m_SceneInitParameters;
	bool m_bIsClearingGraph;
	TEntityRef<ISceneEntity> m_pScene;
	TArray<ZEntityRef> m_EntitiesOwnedByTheScene;
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_ResetSceneEvent;

	~ZEntitySceneContext() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void AddEntity(const ZEntityRef& entity, IEntityFactory* pFactory) override;
	void RemoveEntity(const ZEntityRef& entity) override;
	void ClearScene(bool bFullyUnloadScene) override;
	void PrepareNewScene() override;
	void CreateScene() override;
	void CreateScene(const ZString& sStreamingState) override;
	void ResetScene(const ZString& sStreamingState) override;
	void SetSceneResources(TResourcePtr<IEntityFactory> pSceneFactoryResource, TResourcePtr<IEntityBlueprintFactory> pSceneBlueprintResource, ZResourcePtr pSceneHeaderLibraryResource) override;
	void DropSceneFactory() override;
	bool IsRestartingThroughEngine() const override;
	ZEvent<ZEntityRef const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetEntityAddedEvent() override;
	ZEvent<ZEntityRef const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetEntityRemovedEvent() override;
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetRequestSceneResetEvent() override;
	ZResourcePtr GetSceneHeaderLibrary() const override;
	bool IsClearingGraph() const override;
	void RegisterForResetSceneEvent(const ZDelegate<void __cdecl(void)>& fpCallback) override;
	void UnregisterForResetSceneEvent(const ZDelegate<void __cdecl(void)>& fpCallback) override;
	ZEntityRef GetScene() override;
	void StartEntities() override;
	ZEntityRef CreateUninitializedEntityWithFactory(const ZString& sDebugName, IEntityFactory* pEntityFactory) override;
	void DeleteEntities(const TArrayRef<ZEntityRef> aEntities) override;
	virtual void ResetSceneResources();
	virtual void SetSceneInitParameters(const SSceneInitParameters& params);
	virtual bool IsLoaded();

	ZEntitySceneContext() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	const SSceneInitParameters& GetSceneInitParameters() const;
	bool IsRegisteredForResetSceneEvent(const ZDelegate<void __cdecl(void)>& fpCallback) const;
	void DeleteAllEntities();
	void DeleteEntity(const ZEntityRef entity);
	void Start();
	bool AreAllResourcesReady() const;
	void DisableReloadOfConstAfterStartResources() const;
};
