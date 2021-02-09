#pragma once

#include "IApplication.h"
#include "TResourcePtr.h"
#include "IEntityFactory.h"
#include "IEntityBlueprintFactory.h"
#include "ZHeaderLibrary.h"
#include "ZResourceLibrarySet.h"
#include "IRenderDestination.h"
#include "TEntityRef.h"
#include "ZFreeCameraControlEntity.h"
#include "ZLoadingTransitionHandler.h"

class alignas(8) ZEngineAppCommon
{
    int m_SceneSwitchFrames;
    IApplication* m_pApplication;
    TResourcePtr<IEntityFactory> m_sceneFactoryResource;
    TResourcePtr<IEntityBlueprintFactory> m_sceneBlueprintResource;
    TResourcePtr<ZHeaderLibrary> m_sceneHeaderLibrary;
    TResourcePtr<ZHeaderLibrary> m_pGlobalHeaderLibrary;
    ZResourceLibrarySet* m_pGlobalLibraries;
    ZResourcePtr m_pGlobalIndex;
    IRenderDestination* m_pRenderDestination;
    TEntityRef<IRenderDestinationEntity> m_pCreatedRenderDestination;
    TEntityRef<ZFreeCameraControlEntity> m_pFreeCameraControl;
    TEntityRef<ZCameraEntity> m_pFreeCamera;
    TEntityRef<ZCameraEntity> m_pMainCamera;
    bool m_bIsGameInputActive;
    unsigned __int64 m_nFrameCount;
    bool m_bProfileWholeApplication;
    bool m_bWindowActiveInStandalone;
    bool m_bResetKeyTables;
    bool m_bTerminate;
    ZLoadingTransitionHandler* m_pTransition;
    bool m_bSceneLoaded;
    int m_loadingScreenDelay;
    ZMutex m_InputDevicesMutex;
};
