#pragma once

#include "TResourcePtr.h"
#include "TEntityRef.h"
#include "ERayDetailLevel.h"
#include "ZMutex.h"
#include "ZResourcePtr.h"
#include "ZString.h"

class IApplication;
class ICameraEntity;
class IEntityBlueprintFactory;
class IEntityFactory;
class IRenderDestination;
class IRenderDestinationEntity;
class ZCameraEntity;
class ZFreeCameraControlEntity;
class ZHeaderLibrary;
class ZLoadingTransitionHandler;
class ZRayQueryOutput;
class ZResourceLibrarySet;
struct SRenderDestinationDesc;
struct SSceneInitParameters;
struct float4;

class ZEngineAppCommon
{
public:
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
	unsigned long long m_nFrameCount;
	bool m_bProfileWholeApplication;
	bool m_bWindowActiveInStandalone;
	bool m_bResetKeyTables;
	bool m_bTerminate;
	ZLoadingTransitionHandler* m_pTransition;
	bool m_bSceneLoaded;
	int m_loadingScreenDelay;
	ZMutex m_InputDevicesMutex;

	ZEngineAppCommon() = default;
	ZEngineAppCommon(IApplication* pApplication, const ZString& sInstanceName);
	void ExecuteConsoleCmds();
	bool Initialize(const SRenderDestinationDesc& description);
	void Uninitialize();
	void OnLoadFailed();
	bool MainLoopSequence();
	void DefaultMainLoopSequence();
	void UpdateSceneTransition();
	void OnMainWindowActivatedInStandalone(bool bActive);
	void OnSceneReleased();
	void LoadGlobalResources();
	void ReleaseGlobalResources();
	IRenderDestination* GetRenderDestination();
	void RaiseTerminateFlag();
	static void InitModules();
	static ZString GetDefaultSettings();
	void UpdateInputDeviceManager();
	void HandleTransition();
	void HandleMarketingMode();
	void CreateRenderDestination(TEntityRef<ICameraEntity> pMainCamera);
	void CreateFreeCameraAndControl();
	void HandleFreeCamera();
	void ToggleFreeCamera();
	void HandleFreeCameraInputBinding();
	void CopyMainCameraSettingsToFreeCamera();
	void TeleportMainCharacter();
	void InstantlyKillNpc();
	bool ShootRayFromFreeCamera(float4& vRet);
	bool GetFreeCameraRayCastClosestHitQueryOutput(const ERayDetailLevel& eDetailLevel, ZRayQueryOutput* pRayQueryOutput);
	bool LoadScene(const SSceneInitParameters& parameters);
	void ResetSceneCallback();
	void PreloadFirstStreamingState();
	~ZEngineAppCommon() = default;
};
