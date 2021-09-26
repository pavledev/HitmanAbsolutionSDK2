#pragma once

#include "float4.h"
#include "ZRenderDevice.h"
#include "ZRenderContext.h"
#include "ZRenderTraversalContext.h"
#include "SClipPlanes4.h"
#include "SRenderGatherContext.h"
#include "SRenderPrimitiveEntry.h"
#include "TMaxArray.h"
#include "ETraversalMethod.h"

struct SRenderDrawContext;
struct SCrowdDrawData;
struct SScatterDrawInstanceSort;
struct SScatterDrawInstance;

class ZRenderGraphTraversal
{
public:
	enum
	{
		EMAX_CONCURRENT_TRAVERSALS = 32
	};

	unsigned int m_nNumClipPlanes;
	float4 m_avClipPlanes[32];
	ZRenderDevice* m_pRenderDevice;
	ZRenderContext* m_pRenderContext;
	ZRenderTraversalContext* m_pTraversalContext;
	TArray<ZRenderGraphNode*> m_VisibleNodes;
	TFixedArray<SClipPlanes4, 8> m_aClipPlanes4;
	unsigned int m_nNumClipPlanesSoA;
	SRenderGatherContext* m_pGatherContext;
	TArray<SRenderPrimitiveEntry> m_TempPrimitiveEntries;
	TArray<ZRenderGraphNode*> m_TempRGNPtrArray;
	TMaxArray<STraversalTaskInput*, 32> m_TraversalTaskInput;
	IJobChain* m_JobChain;
	IJob* m_pCollectOpaqueJobs[4];

	static const unsigned int C_MAX_COLLECTOPAQUE_JOBS;

	ZRenderGraphTraversal() = default;
	ZRenderGraphTraversal(const ZRenderGraphTraversal& __that);
	ZRenderGraphTraversal(ZRenderContext* pRenderContext, ZRenderDevice* pRenderDevice);
	~ZRenderGraphTraversal() = default;
	void BeginTraverseGates(ZRenderTraversalContext* pTraversalContext, bool bTraverseParticles, float fGateClipDistanceScale, float fCSMProjectedAreaCullingFactor, float4* pCSMData, bool bShadow, bool bDirectional);
	void EndTraverseGates(ZRenderTraversalContext* pTraversalContext);
	void TraverseSimple(ZRenderTraversalContext* pTraversalContext);
	void Traverse(ZRenderTraversalContext* pTraversalContext, ETraversalMethod eTraversalMethod, float fGateClipDistanceScale);
	void FindNodesInsideFrustum(ZRenderGraphNode** pInputNodes, unsigned int nNumInputNodes, TArray<ZRenderGraphNode*>& output, const unsigned int nNumClipPlanes, float4* pClipPlanes, const float4& vEyePosWS, float fProjectedAreaThreshold);
	void FindNodesInsideFrustum(ZRenderGraphNode** pInputNodes, unsigned int nNumInputNodes, TArray<ZRenderGraphNode*>& output, const unsigned int nNumClipPlanes, float4* pClipPlanes);
	void NotifyRenderGraphManagerVisible(TArray<ZRenderGraphNode*>& visibleNodes);
	void GatherNodes(TArray<ZRenderGraphNode*>& InputNodes, SRenderGatherContext* pGatherContext, unsigned int nStartIndex, unsigned int nEndIndex) const;
	void GatherGlowNodes(SRenderGatherContext* pGatherContext, float4* pClipPlanes, unsigned int nNumClipPlanes, const SMatrix& mWorldToView_, bool bShowGlow, bool bShowHints) const;
	void BuildRenderPrimitiveEntries(ZRenderGraphNode** pInputNodes, unsigned int nNumNodes, TArray<SRenderPrimitiveEntry>& Entries, unsigned int nTransparencyMask, unsigned int nExclusionMask, ERenderLayer eRenderLayer, const SMatrix& mWorldToView, unsigned int nLODOffset);
	void FilterAndConstructRenderPrimitiveEntries(SRenderDrawFilterEntry* pInputEntries, unsigned int nNumEntries, TArray<SRenderPrimitiveEntry>& OutputEntries, unsigned int nTransparencyMask, unsigned int nExclusionMask, ERenderLayer eRenderLayer);
	void InitDrawContext(SRenderDrawContext& DrawContext, ZRenderContext* pRenderContext, bool bSetBlendState, bool bSetRasterizerState, ERenderLayer eRenderLayer);
	void RecordDrawCommandBuffer(SRenderPrimitiveEntry* pEntries, unsigned int nNumEntries, SRenderRecordedDrawCmdBuffer* pDrawCommands, ZRenderTraversalContext* pTraversalContext, ERenderLayer eRenderLayer, bool bTransparentPass, bool bEmissiveAdditive, bool bUseBlendFactor, ERenderLayer eShadeAsRenderLayer);
	void RecordCrowdDrawCommandBuffer(SRenderPrimitiveEntry* pEntries, unsigned int nNumEntries, SRenderRecordedDrawCmdBuffer* pDrawCommands, ZRenderTraversalContext* pTraversalContext, ERenderLayer eRenderLayer, SCrowdDrawData* pCrowdDrawData, bool bEmissiveAdditive);
	void RecordScatterDrawCommandBuffer(SRenderPrimitiveEntry* pEntries, unsigned int nNumEntries, SRenderRecordedDrawCmdBuffer* pDrawCommands, ZRenderTraversalContext* pTraversalContext, ERenderLayer eRenderLayer, const SScatterDrawInstanceSort* pSortInfo, const SScatterDrawInstance* pScatterInstanceData, const unsigned int nScatterInstances, bool bTransparentPass);
	void SortRenderObjectInstances(TArray<SRenderPrimitiveEntry>& Entries);
	void SortRenderObjectInstancesBackToFront(TArray<SRenderPrimitiveEntry>& Entries);
	void SortRenderObjectInstancesZBias(TArray<SRenderPrimitiveEntry>& Entries);
	SRenderGatherContext* GetGatherContext();
	TArray<SRenderPrimitiveEntry>& GetTempPrimitiveEntryArray();
	TArray<ZRenderGraphNode*>& GetTempRGNPtrArray();
	void RecordDrawArray(SRenderRecordedDrawCmdBuffer* DrawCmds, unsigned int nNumEntries, SRenderPrimitiveEntry* pEntries, ZRenderShader* pShader, ZRenderConstBufferRef* aConstBuffers, ZRenderShader** pVertexShaders);
	void RecordDrawArray(SRenderRecordedDrawCmdBuffer* DrawCmds, unsigned int nNumEntries, SRenderPrimitiveEntry* pEntries, ZRenderShader* pShader, ZRenderConstBufferRef ConstBuffer, ZRenderShader** pVertexShaders);
	void InitDrawCommandBuffer(SRenderRecordedDrawCmdBuffer* pDrawCommands, ZRenderTraversalContext* pTraversalContext, ERenderLayer eRenderLayer);
	void ProcessRenderPrimInstance(SRenderGatherContext* pGatherContext, ZRenderPrimitiveInstance* pPrimInstance, ZRenderGraphNode* pRenderGraphNode, bool bMatches0, bool bMatches1, unsigned int nLODMask0, unsigned int nLODMask1, unsigned char nLODFade0, unsigned char nLODFade1, unsigned int nSimpleIndex, unsigned int nSimpleMask0, bool bIsMirror) const;
	void InitTraversal(ZRenderTraversalContext* pTraversalContext);
	void SetClipPlanes(const unsigned int nNumClipPlanes, float4* pClipPlanes);
	void ConvertClipPlanesToSOA();
	bool IsInsideFrustum(ZRenderGraphNode* pNode) const;
	unsigned long long KickJob(STraversalTaskInput* pTaskInput);
	void WaitForJob(STraversalTaskInput* pTaskInput, unsigned long long nBookmark);
	STraversalTaskInput* AllocTaskInput();
	void ReleaseTaskInput(STraversalTaskInput* pTaskInput);
	STraversalTaskInput* LazyAllocTaskInput();
	void LazyReleaseTaskInput(STraversalTaskInput* pInput);
	ZRenderGraphTraversal& operator=(const ZRenderGraphTraversal& __that);
};
