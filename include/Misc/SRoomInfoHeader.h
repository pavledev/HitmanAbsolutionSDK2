#pragma once

#include "SVector3.h"
#include "SRoomInfoEntry.h"
#include "SMatrix43.h"

class ZRenderGraphNode;
template <class T> class TArray;

struct SRoomInfoHeader
{
	enum
	{
		RF_ACTIVE = 1,
		RF_OUTSIDE = 2,
		RF_CSMROOM = 4,
		RF_CROWDROOM = 8,
		RF_OVERRIDE_GLOBAL_AMBIENT = 16,
		RF_OVERRIDE_GLOBAL_LIT_FACTOR = 32,
		RF_OVERRIDE_GLOBAL_ILLUMINATION = 64,
		RF_OMNIPRESENT = 128,
		RF_TRAVERSE_MASK = 129
	};

	SVector3 vOBBCenter;
	SRoomInfoEntry Gates;
	SVector3 vOBBHalfSize;
	SMatrix43 mOBBTransform;
	SRoomInfoEntry Excludes;
	SRoomInfoEntry Includes;
	SRoomInfoEntry Occluders;
	TArray<ZRenderGraphNode*>* DynamicNodes;
	SRoomInfoEntry Nodes;
	unsigned int nNumClients;
	TArray<ZRenderGraphNode*>* Lights;
	unsigned short nFlags;
	unsigned short nGateSet;

	SRoomInfoHeader(const SRoomInfoHeader& copy);
	SRoomInfoHeader() = default;
	~SRoomInfoHeader() = default;
	void AddDynamicNode(ZRenderGraphNode* pNode);
	bool RemoveDynamicNode(ZRenderGraphNode* pNode);
	void AddLight(ZRenderGraphNode* pLight);
	unsigned int IsOutside() const;
	unsigned int IsCSMRoom() const;
	unsigned int IsCrowdRoom() const;
};
