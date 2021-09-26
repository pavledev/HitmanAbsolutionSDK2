#pragma once

#include "ZVTablePaddingRemover.h"
#include "SVector3.h"
#include "ZString.h"
#include "float4.h"

class ZRenderableEntity;
class ZRenderGraphTraversal;
class ZRenderTraversalContext;
class ZRenderContext;
class IJobChain;
struct SVector4;
struct SRoomInfoHeader;
struct SGateInfoHeader;
struct SMatrix;
template <class T> class TArray;

class ZRenderGraphNode : public ZVTablePaddingRemover
{
public:
	enum TYPE
	{
		GEOM = 0,
		LINKED = 1,
		PARTICLES = 2,
		SPATIAL = 3,
		LIGHT = 4,
		CAMERA = 5,
		MATERIAL = 6,
		VISIBILITY_PROXY = 7,
		POSTFILTER = 8,
		RAIN = 9,
		RAINMODIFIER = 10,
		COMPOSITOR = 11,
		DESTINATION = 12,
		VIDEO_PLAYER = 13,
		VOLUMELIGHT = 14,
		FOGBOX = 15,
		CROWDENTITY = 16,
		GLOBALLIGHT = 17,
		SCATTER = 18,
		MIRROR = 19,
		CUBEMAPPROBE = 20,
		TYPE_SIZE = 21,
		RENDERABLE_TYPE_MASK = 7,
		RENDERABLE_TYPE_FIRST = 0,
		RENDERABLE_TYPE_LAST = 2
	};

	enum FLAGS
	{
		PERFORM_VISIBILITY_TEST = 2048,
		IS_RENDERABLE = 4096,
		CAST_SHADOWS = 16384,
		HAS_TRANSPARENCY = 32768,
		HAS_PLANAR_REFLECTION = 65536,
		HAS_REFRACTION = 131072,
		HAS_DECALS = 262144,
		HAS_USES_DISCARD = 524288,
		HAS_USES_LM_SKIN = 1048576,
		IS_DYNAMIC = 2097152,
		HAS_TRANS_LIT = 4194304,
		IS_PLAYER = 8388608,
		DONT_DRAW = 16777216,
		ROOM_MANAGER_IN_CLIENT = 33554432,
		IS_GHOST = 67108864,
		TEST_MIRROR = 134217728,
		HAS_PACKED_OVERLAPING_ROOMS = 268435456,
		IS_GLOWING_BACKGROUND = 536870912,
		IS_GLOWING_BACKGROUND_UNMASKED = 1073741824,
		DEBUG_ROOM_TRACK = 2147483648
	};

	enum LIGHT_SHADOW_PRIORITY_FLAGS
	{
		LSP_IS_INSIDE = 1,
		LSP_WANTS_SHADOW = 2,
		LSP_MAX_FLAG = 32768
	};

	enum
	{
		NUM_OVERLAP_ROOMS = 2
	};

	unsigned int m_nFlags;
	unsigned int m_dummy;
	ZRenderableEntity* m_pRenderableEntity;
	float4 m_mObjectToWorld_[3];
	SVector3 m_vCenter_;
	SVector3 m_vHalfSize_;
	ZString m_sDebugName;
	unsigned short m_nRoomID;
	unsigned short m_nRoomIDOverlap[2];
	unsigned char m_nType;

	~ZRenderGraphNode() override = default;
	virtual void Traverse(ZRenderGraphNode* pParent, ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderTraversalContext* pParentTraversalContext, ZRenderContext* pRenderContext);
	virtual void Reflect(ZRenderableEntity* pRenderableEntity, IJobChain* pJobChain);
	virtual void ReflectPost();
	virtual void CleanUp();
	virtual void PostVisibleChangedEvent(ZRenderableEntity* pRenderableEntity, bool bVisible);
	virtual void OnRoomInit();
	virtual void OnRoomClear();

	ZRenderGraphNode() = default;
	ZRenderGraphNode(const ZRenderGraphNode& __that);
	ZRenderGraphNode(TYPE eType);
	void ReflectBase(ZRenderableEntity* pEntity);
	const SMatrix GetObjectToWorldTransform() const;
	const float4 GetObjectToWorldTrans() const;
	void SetObjectToWorldTransform(const SVector4* pInputMatrix3x4);
	float4 GetLocalHalfSize() const;
	float4 GetLocalCenter() const;
	void SetLocalHalfSize(const SVector3& vHalfSize);
	void SetLocalCenter(const SVector3& vCenter);
	void SetLocal(const float4& vHalfSize, const float4& vCenter);
	void GetTotalExtents(float4& vMin, float4& vMax, const SMatrix* pmTransform);
	void SetPerformVisibilityTest(bool bPerformVisibilityTest);
	void SetCastShadows(bool bCastShadows);
	TYPE GetType() const;
	void SetEntity(ZRenderableEntity* pRenderableEntity);
	ZRenderableEntity* GetEntity();
	static void FindNodes(TArray<ZRenderGraphNode*>& result, TArray<ZRenderGraphNode*>& visibleNodes, TYPE eType);
	static void FindNodesWithFlags(TArray<ZRenderGraphNode*>& result, TArray<ZRenderGraphNode*>& visibleNodes, unsigned int nFlags);
	void SetRoomID(unsigned short nRoomID);
	unsigned short GetRoomID() const;
	unsigned short FindEnclosingRoom();
	void SetTestMirror();
	void SetType(TYPE eType);
	unsigned int ClearOverlappingRooms(unsigned short* pRoomsCleared, unsigned int nMaxRooms, const unsigned int nStartID, TArray<SRoomInfoHeader>& Rooms, const TArray<SGateInfoHeader>& Gates);
	unsigned int FindOverlappingRoomsGate(unsigned short* pRoomsAdded, unsigned int nMaxRooms, const unsigned short nStartID, TArray<SRoomInfoHeader>& Rooms, const TArray<SGateInfoHeader>& Gates);
	unsigned int FindOverlappingRooms(unsigned short* pRoomsOverlapping, unsigned int nMaxRooms, const unsigned short nStartID, TArray<SRoomInfoHeader>& Rooms, const TArray<SGateInfoHeader>& Gates);
	bool UpdateDynamicRoomID(unsigned short& nOldRoomID, unsigned short& nNewRoomID);
	void UpdateDynamicOverlap(unsigned short nOldRoomID, unsigned short nNewRoomID);
	void RemoveFromDynamicLists();
	ZRenderGraphNode& operator=(const ZRenderGraphNode& __that);
};
