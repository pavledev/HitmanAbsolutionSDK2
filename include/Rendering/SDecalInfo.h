#pragma once

#include "ZRenderPrimitiveMeshDecal.h"
#include "ZRenderPrimitiveInstance.h"

class IRenderPrimitiveMesh;
class ZDecalControllerEntity;
class ZRenderGraphNodePrimitiveContainer;

struct SDecalInfo
{
	unsigned int nIdxSize;
	unsigned short nInstallSlot;
	unsigned int nVtxAllocOffset;
	unsigned int nVtxAllocSize;
	unsigned int nIdxOffset;
	unsigned int nVtxOffset;
	unsigned short nNumIdx;
	unsigned short nNext;
	unsigned short nPrev;
	unsigned short nNodeNext;
	unsigned short nNodePrev;
	ZRenderGraphNodePrimitiveContainer* pRGN;
	IRenderPrimitiveMesh* pAttachedTo;
	ZDecalControllerEntity* pDecalController;
	ZRenderPrimitiveInstance RenderPrimitiveInstance;
	ZRenderPrimitiveMeshDecal DecalMesh;
	float fFadeTimeLeft;
	float fCurScaleTime;
	unsigned int nColor;
	unsigned char nList : 1;
	bool bFading : 1;
	bool bStale : 1;
	bool bActive : 1;

	SDecalInfo() = default;
	~SDecalInfo() = default;
};
