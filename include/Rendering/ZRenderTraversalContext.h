#pragma once

#include "STraversalSortedIndex.h"
#include "float4.h"
#include "SMatrix.h"
#include "STraversalTaskInput.h"

class ZRenderTraversalContext
{
public:
	STraversalSortedIndex m_SortedIndices[32];
	float4 m_avClipPlanes[32];
	float4 m_vEyePoint;
	float4 m_vRoomPoint;
	SMatrix mViewToProjectionMatrix;
	SMatrix mWorldToView;
	unsigned long long m_nBookmark;
	STraversalTaskInput* m_pTaskInput;
	unsigned int m_nNumClipPlanes;
	float m_fProjectedAreaCullingFactor;
	unsigned int m_nMaxTraversalDepth;
	unsigned short m_nRoomID;
	unsigned short m_nOverrideStartRoomId;
	bool m_bMainCameraTraversal;
	bool m_bAsyncTraversalStarted;
	bool m_bUsePortalClipplanes;
	bool m_bSimpleTraversal;
	bool m_bTraversalStarted;
	TArray<ZRenderGraphNode*> m_visibleNodes;
	TArray<ZRenderGraphNode*> m_Nodes;
	TArray<unsigned short> m_VisibleGates;
	SOccluderPlaneStateSoA m_OccluderPlaneState;

	ZRenderTraversalContext() = default;
	~ZRenderTraversalContext() = default;
	float4 GetEyePoint();
	float4 GetRoomPoint();
	void SetEyePoint(const float4& f);
	void SetRoomPoint(const float4& f);
	void Clear();
	SMatrix GetWorldToViewMatrix();
	SMatrix GetViewToProjectionMatrix();
	static ZRenderTraversalContext* GetTraversalContext(const void* pOwner, unsigned int nIndex, bool bClear);
};
