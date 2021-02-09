#pragma once

#include "IEntitySceneContext.h"
#include "SSceneInitParameters.h"
#include "TEntityRef.h"
#include "ISceneEntity.h"

class ZEntitySceneContext : public IEntitySceneContext
{
public:
    ZRuntimeResourceID m_ridSceneFactory;
    TResourcePtr<IEntityFactory> m_sceneFactoryResource;
    TResourcePtr<IEntityBlueprintFactory> m_sceneBlueprintResource;
    unsigned __int8* m_pSceneMemoryBlock;
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

    virtual void ResetSceneResources();
    virtual void SetSceneInitParameters(const SSceneInitParameters*);
    virtual bool IsLoaded();
};
