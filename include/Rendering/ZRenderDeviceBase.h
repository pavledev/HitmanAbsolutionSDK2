#pragma once

#include "TBag.h"
#include "TArray.h"
#include "ZMutex.h"
#include "ETempBufferAllocLockMode.h"
#include "ZString.h"

struct SRenderRecordRingBuffer;
struct SRenderRecordedDrawCmdBuffer;
class ZRenderTexture2D;
struct SRenderTexture2DDesc;
class ZRenderBlendState;
class ZRenderDepthStencilState;
class ZRenderRasterizerState;
class ZRenderTexture3D;
struct SRenderBlendStateDesc;
struct SRenderDepthStencilStateDesc;
struct SRenderRasterizerStateDesc;
struct SRenderSubResourceData;
struct SRenderTexture3DDesc;

class __declspec(novtable) ZRenderDeviceBase
{
public:
	enum EThreadOwnership
	{
		THREAD_OWNER_RENDERDEVICE = 1,
		THREAD_OWNER_RENDERGRAPH = 2,
		THREAD_OWNER_FULL = 3
	};

	enum
	{
		MAX_NUM_SIMULTANEOUS_RENDER_TARGETS = 8
	};

	struct SRenderDeviceStats
	{
		unsigned int m_nNumDIPs;
		unsigned int m_nNumTriangles;
		unsigned int m_nNumClears;
	};

	struct STempBufferEntry
	{
		unsigned int nKey;
		ZRenderTexture2D* pTexture;
		bool bFree;
		bool bLocked;
	};

	struct StatesBundle
	{
		ZRenderBlendState* m_pBlendState;
		float m_fBlendFactor;
		ZRenderRasterizerState* m_pRasterizerState;
		unsigned int m_nStencilRef;
		ZRenderDepthStencilState* m_pDepthStencilState;
	};

	ZRenderBlendState* m_pBlendState;
	float m_fBlendFactor;
	ZRenderRasterizerState* m_pRasterizerState;
	unsigned int m_nStencilRef;
	ZRenderDepthStencilState* m_pDepthStencilState;
	TBag<STempBufferEntry, TArray<STempBufferEntry>> m_TempBuffers;
	unsigned int m_nPushedStateBundlesCnt;
	StatesBundle m_PushedStates[3];
	ZMutex m_DeviceMutex;
	ZMutex m_GraphMutex;
	unsigned int m_nPresentCount;

	static ZRenderTexture2D* m_pTexture_OutOfMemory;
	static const unsigned int MaxStateBundles;
	static unsigned int m_nReflectFrameCounter;
	static unsigned int m_nRenderFrameCounter;
	static unsigned int m_nRenderDeviceResetCounter;
	static SRenderRecordRingBuffer* m_pCurrentRecordRingBuffer;
	static SRenderRecordRingBuffer m_MainRecordRingBuffer;
	static SRenderRecordedDrawCmdBuffer m_RecordedDrawCmdBuffer;
	static unsigned int m_nInfoFrameCounter;

	virtual ~ZRenderDeviceBase() = default;
	virtual ZRenderTexture2D* CreateTexture2D(const SRenderTexture2DDesc* renderTexture2DDesc, const SRenderSubResourceData* renderSubResourceData) = 0;
	virtual ZRenderTexture3D* CreateTexture3D(const SRenderTexture3DDesc* renderTexture3DDesc, const SRenderSubResourceData* renderSubResourceData) = 0;
	virtual void SetGamma(float param1) = 0;
	virtual void Trim();
	virtual void PlayCommandBufferWait();

	ZRenderDeviceBase() = default;
	void Invalidate();
	ZRenderBlendState* CreateBlendStateBase(const SRenderBlendStateDesc* pDescription);
	ZRenderRasterizerState* CreateRasterizerStateBase(const SRenderRasterizerStateDesc* pDescription);
	ZRenderDepthStencilState* CreateDepthStencilStateBase(const SRenderDepthStencilStateDesc* pDescription);
	void PushStates(bool bZeroStates);
	void PopStates();
	void AcquireThreadOwnership(EThreadOwnership Ownership);
	void ReleaseThreadOwnership(EThreadOwnership Ownership);
	void PlayRecordedDrawCommandBufferBase(SRenderRecordedDrawCmdBuffer* DrawCmds);
	static unsigned int GetReflectFrameCounter();
	static void SetReflectFrameCounter(unsigned int nFrameCounter);
	static unsigned int GetRenderFrameCounter();
	static void SetRenderFrameCounter(unsigned int nFrameCounter);
	static unsigned int GetRenderDeviceResetCounter();
	static void SetRenderDeviceResetCounter(unsigned int nFrameCounter);
	static unsigned int GetInfoFrameCounter();
	static void SetInfoFrameCounter(unsigned int nFrameCounter);
	void AllocateTempBuffer(ZRenderTexture2D* pRenderResource, unsigned int nLocation, ETempBufferAllocLockMode LockMode);
	void FreeTempBuffer(ZRenderTexture2D* pRenderResource, ETempBufferAllocLockMode LockMode);
	void LockTempBuffer(ZRenderTexture2D* pRenderResource);
	void UnlockTempBuffers();
	const unsigned int GetTempBufferChecksum(const ZRenderTexture2D* pRenderResource);
	ZRenderBlendState* GetCurrentBlendState();
	ZRenderRasterizerState* GetCurrentRasterizerState();
	ZRenderDepthStencilState* GetCurrentDepthStencilState();
	unsigned int GetPresentCount();
	SRenderRecordedDrawCmdBuffer* AllocRecordedDrawCmdBuffer();
	void CreateOutOfMemoryTexture();
	void DeleteOutOfMemoryTexture();
	static void DumpScreenShotCallback(ZString pzCmd, const unsigned int argc, const char** argv, void* pUserData);
	void FreeRecordedDrawCmdBuffer(SRenderRecordedDrawCmdBuffer* pBuffer);
	void InvalidateStates();
	void SetBlendStateInternal(ZRenderBlendState* pBlendState, float fBlendFactor);
	void SetRasterizerStateInternal(ZRenderRasterizerState* pRasterizerState);
	void SetDepthStencilStateInternal(ZRenderDepthStencilState* pDepthStencilState, unsigned int nStencilRef);
	ZString GenerateNextScreenshotFilePath(const ZString& sFilePathFormat);
	int FindAvailableScreenShotIndex(int nStartAtIndex, const ZString& sFilePathFormat);
	ZString GenerateScreenShotFilePath(int index, const ZString& sFilePathFormat);
	static void SetRecordRingBuffer(SRenderRecordRingBuffer* pRingBuffer);
};
