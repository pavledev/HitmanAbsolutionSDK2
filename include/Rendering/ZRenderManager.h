#pragma once

#include "IComponentInterface.h"
#include "IListenerRegistrar.h"
#include "ZEvent.h"
#include "ZEventNull.h"
#include "ZMutex.h"
#include "ZRenderContext.h"
#include "ZThreadEvent.h"
#include "IRenderDebugRender.h"
#include "TMap.h"
#include "ZRenderDestination.h"
#include "ZThread.h"
#include "ZRenderGraphNodeRenderer.h"
#include "ZRenderUtilities.h"
#include "SRenderSharedStates.h"
#include "ZRenderDebugRenderBuffer.h"
#include "IRenderResourceAsyncUpdate.h"
#include "ZRenderResourceAsyncUpdateVertexBuffer.h"
#include "ZRenderResourceAsyncUpdateIndexBuffer.h"
#include "ZRuntimeDecalManager.h"
#include "ZRenderGraphTraversal.h"
#include "IPostRenderHook.h"
#include "ZRenderPrimitiveConstructor.h"
#include "STraversalContextAlloc.h"
#include "ZRender2DRenderTarget.h"
#include "BinkDrawData.h"

class ZRenderManager : public IComponentInterface
{
public:
    bool m_bExlusiveFullScreenResult;
    int m_nSkipFlip;
    int m_nSequenceRunning;
    bool m_bSequenceRunningCurr;
    bool m_bSequenceRunningPrev;
    unsigned int m_nGameFrameCount;
    bool m_bGammaEnabled;
    float m_fGamma;
    __int8 m_bGammaChanged : 1;
    IListenerRegistrar* m_pListenerRegistrar;
    ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_SyncWindowEvent;
    ZMutex m_SyncWindowEventLock;
    alignas(8) ZDelegate<void __cdecl(ZRenderContext*)> m_onDisplayscaleformCallback;
    alignas(8) ZDelegate<void __cdecl(void)> m_displayScaleformLoadingScreenCallback;
    alignas(8) ZDelegate<void __cdecl(void)> m_ScaleformUpdateCallback;
    alignas(8) ZDelegate<void __cdecl(void)> m_HUDUpdateCallback;
    alignas(8) ZThreadEvent m_ScaleformEvent;
    bool m_bScaleformKicked;
    ZDelegate<bool __cdecl(void)> m_LoadingScreenVideoCallback;
    alignas(8) ZDelegate<void __cdecl(void)> m_LoadingScreenVideoCleanUpCallback;
    alignas(8) ZRenderDevice* m_pRenderDevice;
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
    alignas(8) ZThread m_RenderThread;
    int m_RenderThreadCommand;
    __int64 m_tFrameTimeLast;
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

    virtual void RenderVideo(BinkDrawData*, unsigned int, unsigned int, unsigned int, unsigned int);
    virtual void SetLoadingScreenVideoCallback(ZDelegate<bool __cdecl(void)>);
    virtual void SetLoadingScreenVideoCleanUpCallback(ZDelegate<void __cdecl(void)>);
    virtual void SetLoadingScreenActive(bool);
    virtual bool IsLoadingScreenActive();
};
