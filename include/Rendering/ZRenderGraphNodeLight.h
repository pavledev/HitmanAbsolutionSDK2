#pragma once

#include "ZRenderGraphNode.h"
#include "SMatrix.h"
#include "float4.h"
#include "TArray.h"
#include "SVector3.h"
#include "SVector4.h"
#include "SVector2.h"
#include "ZRuntimeResourceID.h"
#include "TResourcePtr.h"
#include "ILightEntity.h"

struct SLightBundle;
class IJobChain;
class ZRenderContext;
class ZRenderGraphTraversal;
class ZRenderShaderResourceView;
class ZRenderTextureResource;
class ZRenderableEntity;
struct SGateInfoHeader;
struct SLightMinMaxGrid;
struct SRoomInfoHeader;

class ZRenderGraphNodeLight : public ZRenderGraphNode
{
public:
	enum ELightType
	{
		LIGHT_TYPE_DIRECTIONAL = 0,
		LIGHT_TYPE_DIRECTIONALCSM = 1,
		LIGHT_TYPE_ENVIRONMENT = 2,
		LIGHT_TYPE_OMNI = 3,
		LIGHT_TYPE_OMNI2D = 4,
		LIGHT_TYPE_SPOT = 5,
		LIGHT_TYPE_CAPSULE = 6,
		MAX_NUM_LIGHT_TYPES = 7
	};

	enum ELightDescMasks
	{
		LIGHT_DESC_TYPE_MASK = 31,
		LIGHT_DESC_ROOM_FLOW_MASK = 224,
		LIGHT_DESC_ROOM_FLOW_OFFSET = 5,
		LIGHT_DESC_SQUARE_SPOT = 256,
		LIGHT_DESC_SIMPLE_LIGHT = 512,
		LIGHT_DESC_USES_PROJECTOR = 1024,
		LIGHT_DESC_CASTS_SHADOWS = 2048,
		LIGHT_DESC_CASTS_OMNI_SHADOWS = 4096,
		LIGHT_DESC_CASTS_CSM_SHADOWS = 8192,
		LIGHT_DESC_DIR_BOX_ALIGN = 16384,
		LIGHT_DESC_IS_SUN = 32768,
		LIGHT_DESC_LIGHT_FADE_ENABLED = 65536,
		LIGHT_DESC_LIGHT_SIMPLIFICATION_ENABLED = 131072,
		LIGHT_DESC_SHADOW_IN_RANGE = 262144,
		LIGHT_DESC_DARKLIGHT = 524288,
		LIGHT_DESC_FORCE_FS_QUAD = 16777216
	};

	enum
	{
		ERGN_FLAG_ROOM_ARRAY_ALLOCATED = 32768
	};

	SMatrix m_mShadowProjection;
	float4 m_vDiffuseColor;
	float4 m_vNearFarAttenuation;
	float4 m_vProjectorMapTilingAndOffset;
	float4 m_vProjectionBoxHalfSize;
	TArray<ZRenderGraphNode*> m_VisibilityProxyNodes;
	TArray<ZRenderGraphNode*> m_AntiProxyNodes;
	unsigned int m_nLightDescMask;
	float m_fLightFadeIntentity;
	float m_fLightSimplificationFactor;
	float m_fMaxRange;
	float m_fMinAngle;
	float m_fMaxAngle;
	SVector3 m_vBoxHalfSize;
	SVector3 m_vBoxFadeNeg;
	SVector3 m_vBoxFadePos;
	SVector4 m_vCSMCascadeSplits;
	SVector3 m_vCSMSplitFades;
	SVector3 m_vDirectionalRotation;
	SVector2 m_vProjectorMapUVVelocity;
	float m_fAspectXByY;
	float m_fShadowFadeDistance;
	float m_fRcpShadowFadeLength;
	float m_fLightBleedingReduction;
	float m_fLightFadeDistance;
	float m_fRcpLightFadeLength;
	float m_fLightSimplificationDistance;
	float m_fRcpLightSimplificationLength;
	float m_fCapsuleHalfHeight;
	float m_fProjectedAreaCullingFactor;
	ZRuntimeResourceID m_idProjectorMap;
	TResourcePtr<ZRenderTextureResource> m_pProjectorMap;
	ZRenderShaderResourceView* m_pProjectorMapSRV;
	SLightMinMaxGrid* m_pMinMaxGrid;
	unsigned short m_nLightIndex;
	short m_nProjectorMapIndex;
	short m_nPriorityQueryIndex;
	unsigned char m_nShadowMapIndex;
	bool m_bEnableGI;
	float m_fGIIntensity;

	struct
	{
		union 
		{
			struct
			{
				unsigned short nFlag;
				unsigned short Rooms[3];
			} Static;

			struct
			{
				unsigned short nFlag;
				unsigned short AllocatedSize;
				unsigned short* AllocatedRoomPtr;
			} Dynamic;
		};
	} m_DynamicRooms;

	~ZRenderGraphNodeLight() override = default;
	void Reflect(ZRenderableEntity* pRenderableEntity, IJobChain* pJobChain) override;
	void ReflectPost() override;
	void OnRoomInit() override;
	void OnRoomClear() override;

	ZRenderGraphNodeLight() = default;
	ZRenderGraphNodeLight(ZRenderGraphNode::TYPE eType);
	void TraverseLight(ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderGraphNode** pTransLitNodes, unsigned int nNumTransLitNodes, ZRenderContext* pRenderContext, SLightBundle& lightBundle);
	void AddUsesVisibilityProxy(ZRenderGraphNode* pNode);
	void RemoveUsesVisibilityProxy(ZRenderGraphNode* pNode);
	void AddAntiProxy(ZRenderGraphNode* pNode);
	void RemoveAntiProxy(ZRenderGraphNode* pNode);
	ELightType GetLightType() const;
	bool CastShadows() const;
	bool CastOmniShadows() const;
	bool CastCSMShadows() const;
	bool IsSun() const;
	bool GetDirectionIsBoxAligned() const;
	unsigned int GetLightDescMask() const;
	bool GetIsDarkLight() const;
	float GetAspectXByY() const;
	float GetLightFadeIntensity() const;
	float GetLightSimplificationFactor() const;
	float GetMaxAngle() const;
	float GetMaxRange() const;
	float GetBleedingReduction() const;
	SVector4 GetCSMCascadeSplits() const;
	float CalcCSMScaledCascadeSplit(int idx, float scale) const;
	SVector3 GetCSMSplitFades() const;
	float4 GetProjectionBoxHalfSize() const;
	float4 GetDiffuseColor() const;
	float4 GetProjectorTilingOffset() const;
	float4 GetNearFarAttenuation() const;
	float GetCapsuleHalfHeight() const;
	SVector2 GetProjectorMapUVVelocity() const;
	SVector3 GetBoxHalfSize() const;
	SVector3 GetBoxFadeNeg() const;
	SVector3 GetBoxFadePos() const;
	bool GetEnableGI() const;
	float GetGIIntensity() const;
	SMatrix GetShadowProjection() const;
	SLightMinMaxGrid* GetMinMaxGrid() const;
	void SetLightIndex(unsigned short nLightIndex);
	SMatrix CalculateAndGetLightToBoxSpaceTransform() const;
	void CalculateClipplanes(unsigned int& nNumClipPlanes, float4* pClipPlanes);
	ZRenderShaderResourceView* GetProjectorMapSRV();
	float GetProjectedArea(ZRenderContext* pRenderContext) const;
	float4 GetDistToLight(const float4& vPositionLS) const;
	float4 GetDistToLightWS(const float4& vPositionWS) const;
	float GetPriority(ZRenderContext* pRenderContext) const;
	const TArray<ZRenderGraphNode*>& GetVisibilityProxies() const;
	const TArray<ZRenderGraphNode*>& GetAntiProxies() const;
	ILightEntity::ERoomLightFlow GetRoomLightFlow() const;
	void MakeDefaultLight();
	void SetLastShadowMapIndex(unsigned char nLastIndex);
	unsigned char GetLastShadowMapIndex() const;
	int GetLightPriorityQueryIndex() const;
	float GetProjectedAreaCullingFactor() const;
	void UpdateLightSimplification(const float4& vDistToLight);
	void UpdateLightFade(const float4& vDistToLight, const float fLightFadeDistance);
	float CalculateShadowFade(const float4& vDistToLight);
	void SetLightType(ELightType eLightType);
	void SetRoomLightFlow(ILightEntity::ERoomLightFlow eRoomLightFlow);
	void InitRenderContext(ZRenderContext* pRenderContext);
	void CalculateLightProjectionBox(const SMatrix& mLightDirToBoxMatrix);
	void UpdateLightList();
	void RemoveFromLightLists(TArray<SRoomInfoHeader>& RoomHeaders, const TArray<SGateInfoHeader>& GateHeaders);
	void FindRoomInfluence(const unsigned int nRoomID, TArray<SRoomInfoHeader>& RoomHeaders, const TArray<SGateInfoHeader>& GateHeaders);
	void FindRoomInfluenceRec(const unsigned int nRoomID, TArray<SRoomInfoHeader>& RoomHeaders, const TArray<SGateInfoHeader>& GateHeaders, const SMatrix& mWorldToObj, const float4& vWorldCenter, const float4& vOBBCenter, const float4& vOBBHalfSize);
	void DynamicRoomsInit();
	bool DynamicRoomsContains(unsigned short nRoomID) const;
	void DynamicRoomsPushBack(unsigned short nRoomId);
	void DynamicRoomsClear();
	void DynamicRoomsPop(unsigned int nPopCount);
	void UpdateAllRoomLight(TArray<SRoomInfoHeader>& RoomHeaders, const TArray<SGateInfoHeader>& GateHeaders);
	void MergeRoomList(unsigned short* pNewRoomIds, const unsigned int nNewRoomsSize);
	unsigned int DynamicRoomsSize();
	unsigned short* DynamicRoomsPtr();
};
