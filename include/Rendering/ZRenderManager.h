#pragma once

#include "IComponentInterface.h"
#include "ZEvent.h"
#include "ZMutex.h"
#include "ZThreadEvent.h"
#include "TMap.h"
#include "ZThread.h"
#include "SMatrix.h"
#include "TArray.h"
#include "TEntityRef.h"
#include "ZDelegate.h"
#include "ZGameTime.h"
#include "ZString.h"
#include "ZVariantRef.h"

struct SRenderPrimitiveMeshData;
struct SGameUpdateEvent;
class ICameraEntity;
class IListenerRegistrar;
class IPostRenderHook;
class IRenderDebugRender;
class IRenderDestination;
class IRenderDestinationEntity;
class IRenderPrimitiveMesh;
class IRenderResourceAsyncUpdate;
class ZEventNull;
class ZRender2DRenderTarget;
class ZRenderContext;
class ZRenderDebugRenderBuffer;
class ZRenderDestination;
class ZRenderDevice;
class ZRenderGraphNode;
class ZRenderGraphNodeCamera;
class ZRenderGraphNodeDestination;
class ZRenderGraphNodeRenderer;
class ZRenderGraphTraversal;
class ZRenderPrimitiveConstructor;
class ZRenderResourceAsyncUpdateIndexBuffer;
class ZRenderResourceAsyncUpdateVertexBuffer;
class ZRenderSharedResources;
class ZRenderTexture2D;
class ZRenderTraversalContext;
class ZRenderUtilities;
class ZRuntimeDecalManager;
struct BinkDrawData;
struct SComponentMapEntry;
struct SRenderDestinationDesc;
struct SRenderPrimitiveMeshDesc;
struct SRenderPrimitiveMeshInit;
struct SRenderSharedStates;
struct STypeID;
struct float4;

class ZRenderManager : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum ERenderCommand
	{
		RENDER_COMMAND_EXPORT_CUBEMAPS = 0
	};

	struct STraversalContextAlloc
	{
		const void* pOwner;
		unsigned int nIndex;
		ZRenderTraversalContext* pContext;
	};

	bool m_bExlusiveFullScreenResult;
	int m_nSkipFlip;
	int m_nSequenceRunning;
	bool m_bSequenceRunningCurr;
	bool m_bSequenceRunningPrev;
	unsigned int m_nGameFrameCount;
	bool m_bGammaEnabled;
	float m_fGamma;
	bool m_bGammaChanged : 1;
	IListenerRegistrar* m_pListenerRegistrar;
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_SyncWindowEvent;
	ZMutex m_SyncWindowEventLock;
	ZDelegate<void __cdecl(ZRenderContext*)> m_onDisplayscaleformCallback;
	ZDelegate<void __cdecl(void)> m_displayScaleformLoadingScreenCallback;
	ZDelegate<void __cdecl(void)> m_ScaleformUpdateCallback;
	ZDelegate<void __cdecl(void)> m_HUDUpdateCallback;
	ZThreadEvent m_ScaleformEvent;
	bool m_bScaleformKicked;
	ZDelegate<bool __cdecl(void)> m_LoadingScreenVideoCallback;
	ZDelegate<void __cdecl(void)> m_LoadingScreenVideoCleanUpCallback;
	ZRenderDevice* m_pRenderDevice;
	ZRenderSharedResources* m_pRenderSharedResources;
	ZRenderGraphNodeRenderer* m_pRenderGraphNodeRenderer;
	ZRenderUtilities* m_pRenderUtilities;
	SRenderSharedStates* m_pRenderSharedStates;
	ZRenderDebugRenderBuffer* m_pRenderDebugRenderBuffer;
	ZRenderDebugRenderBuffer* m_pRenderDebugRenderBufferFullScreen;
	ZRenderDebugRenderBuffer* m_pRenderDebugRenderBufferInfoFrame;
	IRenderDebugRender* m_pRenderDebugRender;
	ZMutex m_RenderDestinationLock;
	TMap<ZString, ZRenderDestination*> m_RenderDestinations;
	ZThreadEvent m_RenderStartEvent;
	ZThreadEvent m_RenderUpdateEvent;
	ZThreadEvent m_RenderEndEvent;
	ZGameTime m_GameTime;
	ZGameTime m_RealTime;
	ZGameTime m_GameTimeDelta;
	ZGameTime m_RealTimeDelta;
	bool m_bRenderSeparateThread;
	bool m_bNotWaitingRenderToBeDone;
	bool m_bTerminate;
	bool m_bDeviceLost;
	ZThread m_RenderThread;
	long m_RenderThreadCommand;
	long long m_tFrameTimeLast;
	unsigned int m_nFrameCount;
	unsigned int m_nTrisCount;
	float m_fFramesPerSecond;
	float m_fTrisPerSecond;
	ZMutex m_AsyncUpdateMutex;
	TArray<IRenderResourceAsyncUpdate*> m_ResourceAsyncUpdateMainThread;
	TArray<ZRenderResourceAsyncUpdateVertexBuffer*> m_ResourceAsyncUpdateVertexBufferMainThread;
	TArray<ZRenderResourceAsyncUpdateIndexBuffer*> m_ResourceAsyncUpdateIndexBufferMainThread;
	TArray<IRenderResourceAsyncUpdate*> m_ResourceAsyncUpdateRenderThread;
	TArray<ZRenderResourceAsyncUpdateVertexBuffer*> m_ResourceAsyncUpdateVertexBufferRenderThread;
	TArray<ZRenderResourceAsyncUpdateIndexBuffer*> m_ResourceAsyncUpdateIndexBufferRenderThread;
	ZRuntimeDecalManager* m_pDecalManager;
	ZRenderContext* m_pRenderContext;
	ZRenderGraphTraversal* m_pRenderGraphTraversal;
	IPostRenderHook* m_pPostHook;
	ZEvent<ZRenderContext*, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_EndRenderHandlers;
	ZRenderGraphNode* m_pDestinationOverride;
	ZRenderPrimitiveConstructor* m_pPrimitiveConstructor;
	TArray<STraversalContextAlloc> m_TraversalContextList;
	const SRenderDestinationDesc* m_pSwapChainCreateDesc;
	ZThreadEvent m_CreateSwapChainThreadEvent;
	const SRenderDestinationDesc* m_pResetRenderDeviceDesc;
	ZString m_ExportCubemapPath;
	bool m_bExportCubemapsPending;
	bool m_bExportCubemaps;
	bool m_bLoadingScreenFocusLoss;
	ZRender2DRenderTarget* m_pTempBuffer;
	ZRenderTexture2D* m_pTempBuffer2;
	float4* m_pTempBuffer3;
	unsigned int* m_pTempBuffer4;
	unsigned int* m_pTempBufferSSAO;
	ZRenderTexture2D* m_pTempBufferDepth;
	ZRenderTexture2D* m_pTempBufferOcclusion;
	bool m_bLetterboxFadeIn;
	float m_fLetterboxFadeTime;
	float m_fLetterboxAlpha;
	bool m_bFadeFadeIn;
	float m_fFadeFadeTime;
	float m_fFadeAlpha;
	int m_nOldMirrorQualitySetting;
	bool m_bLoadingScreenEnabled;
	bool m_bLoadingScreenEnabledPrev;

	~ZRenderManager() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	virtual void RenderVideo(BinkDrawData* pDrawData, unsigned int nLeft, unsigned int nTop, unsigned int nWidth, unsigned int nHeight);
	virtual void SetLoadingScreenVideoCallback(ZDelegate<bool __cdecl(void)> callback);
	virtual void SetLoadingScreenVideoCleanUpCallback(ZDelegate<void __cdecl(void)> callback);
	virtual void SetLoadingScreenActive(bool bActive);
	virtual bool IsLoadingScreenActive();

	ZRenderManager() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void StartRenderThread();
	void StopRenderThread();
	void KickRenderThread(unsigned int nMask);
	void ExecuteScaleformCallback();
	void Activate();
	void Deactivate();
	void Trim();
	IRenderDestination* CreateRenderDestinationScreen(const SRenderDestinationDesc& renderDestinationScreenDesc);
	IRenderDestination* CreateRenderDestination(const SRenderDestinationDesc& description);
	IRenderDestination* GetRenderDestination(const ZString& sName) const;
	SMatrix GetViewportTransform(int nX, int nY, int nWidth, int nHeight) const;
	void WaitRenderDone();
	void WaitGPUFence();
	void BeginUpdate();
	void EndUpdate();
	void MainThreadWaitForScaleform();
	IRenderPrimitiveMesh* CreateDynamicMeshPrimitive(const SRenderPrimitiveMeshDesc* pDesc, const SRenderPrimitiveMeshInit* pInit, const SRenderPrimitiveMeshData* pData);
	void RegisterPostRenderHook(IPostRenderHook* pPostRenderHook);
	void UnregisterPostRenderHook();
	void GetInternalParameters(void** parameter1, void** parameter2);
	void RegisterForSyncWindowEvent(const ZDelegate<void __cdecl(void)>& fpCallback);
	void UnregisterForSyncWindowEvent(const ZDelegate<void __cdecl(void)>& fpCallback);
	void SetListenerRegistrar(IListenerRegistrar* pListenerRegistrar);
	IListenerRegistrar* GetListenerRegistrar() const;
	void SetDestinationOverride(ZRenderGraphNode* pDestination);
	void RegisterEndRenderHandler(const ZDelegate<void __cdecl(ZRenderContext*)>& handler);
	void UnregisterEndRenderHandler(const ZDelegate<void __cdecl(ZRenderContext*)>& handler);
	void AddRenderDestination(const ZString& sName, ZRenderDestination* pRenderDestination);
	void RemoveRenderDestination(const ZString& sName, ZRenderDestination* pRenderDestination);
	void AddResourceAsyncUpdate(IRenderResourceAsyncUpdate* pAsyncUpdate);
	void AddResourceAsyncUpdateVertexBuffer(ZRenderResourceAsyncUpdateVertexBuffer* pAsyncUpdate);
	void AddResourceAsyncUpdateIndexBuffer(ZRenderResourceAsyncUpdateIndexBuffer* pAsyncUpdate);
	void MoveResourceAsyncUpdates();
	void ExecuteResourceAsyncUpdates();
	TEntityRef<IRenderDestinationEntity> GetGameRenderDestinationEntity();
	TEntityRef<IRenderDestinationEntity> GetActiveRenderDestinationEntity() const;
	TEntityRef<ICameraEntity> GetMainCamera(TEntityRef<IRenderDestinationEntity> pRenderDestination) const;
	bool GetMainCameraPosWS(float4& vCameraPositionWS) const;
	bool GetMainCameraPosAndLookAtDirectionWS(float4& vCameraPositionWS, float4& vLookAtDirectionWS) const;
	ZRenderDevice* GetRenderDevice() const;
	ZRenderSharedResources* GetRenderSharedResources() const;
	ZRenderGraphNodeRenderer* GetRenderGraphNodeRenderer() const;
	ZRenderUtilities* GetRenderUtilities() const;
	IRenderDebugRender* GetRenderDebugRender() const;
	ZRenderPrimitiveConstructor* GetPrimitiveConstructor() const;
	ZGameTime GetGameTime();
	ZGameTime GetRealTime();
	ZGameTime GetGameTimeDelta();
	ZGameTime GetRealTimeDelta();
	ZRenderDebugRenderBuffer* GetGlobalDebugRenderBuffer();
	ZRuntimeDecalManager* GetDecalManager();
	ZRenderTraversalContext* GetTraversalContext(const void* pOwner, unsigned int nIndex, bool bClear);
	void TraversalContextReset();
	void TraversalContextFree();
	void SequenceStarted();
	void SequenceStopped();
	void SetOnDisplayScaleformCallback(ZDelegate<void __cdecl(ZRenderContext*)> callback);
	ZDelegate<void __cdecl(ZRenderContext*)> GetOnDisplayScaleformCallback();
	void SetScaleformLoadingScreenCallback(ZDelegate<void __cdecl(void)> callback);
	void SetScaleformUpdateCallback(ZDelegate<void __cdecl(void)> callback);
	void SetHUDUpdateCallback(ZDelegate<void __cdecl(void)> callback);
	void SetGamma(float fGamma);
	static void SetGammaCallback(ZString pzCmd, const unsigned int argc, const char** argv, void* pUserData);
	bool GetGammaEnabled() const;
	void ForceGammaUpdate();
	bool IsDebugChannelEnabled(unsigned int debugChannel);
	unsigned int GetPresentCount();
	void OnCameraCut();
	bool InCameraCut();
	void StartLetterbox(float fFadeTime);
	void StopLetterbox(float fFadeTime);
	float GetLetterboxAlpha();
	void StartFade(float fFadeTime);
	void StopFade(float fFadeTime);
	float GetFadeAlpha();
	bool IsFading() const;
	void ResetRenderDevice(const SRenderDestinationDesc* pDescription);
	bool InSequence();
	void Allocate();
	void Free();
	bool RenderLoadingScreen();
	void TraverseMirrors(ZRenderGraphNodeCamera* pCamera, ZRenderTraversalContext* pActiveTraversalContext);
	void UpdateLetterbox();
	void UpdateFade();
	unsigned int RenderThread(void* pData);
	void DebugFrameUpdate(const SGameUpdateEvent& event);
	void RenderDebug(bool bScreenFound, ZRenderGraphNodeDestination* pFoundRenderDestination, bool bScreenDestIsInvalid);
	void CreateSwapChainRenderThread();
	void CreateSwapChainMainThread(const SRenderDestinationDesc* pRenderDestinationScreenDesc);
};
