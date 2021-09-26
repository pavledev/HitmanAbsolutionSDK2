#pragma once

#include "ZEntityImpl.h"
#include "IDecalControllerEntity.h"
#include "SDecalCreationContextInternal.h"
#include "SComponentMapEntry.h"
#include "SMatrix.h"
#include "ZVariantRef.h"
#include "float4.h"

class ZRenderPrimitiveResource;
class ZComponentCreateInfo;
class ZSpatialEntity;
class ZString;
struct SDecalCreationContext;
struct SDecalIntersectionInfo;
struct STypeID;
struct SVertexDecal;
struct SVertexW1Decal;
struct SVertexW4Decal;
template <class T> class TEntityRef;
template <class T> class TResourcePtr;

class ZDecalControllerEntity : public ZEntityImpl, public IDecalControllerEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EClipInclusionMode
	{
		CLIP_MODE_CLIP = 0,
		CLIP_MODE_PARTIALLY_INSIDE = 1
	};

	enum EScaleType
	{
		eScaleDisable = 0,
		eScaleUniform = 1,
		eScaleY = 2
	};

	enum ERotationType
	{
		eRotationDisable = 0,
		eRotationAlignRay = 1,
		eRotationRandom = 2
	};

	struct SBaryCentricVertex
	{
		unsigned int nTriangleIndex;
		float4 vBaryCentricCoord;
	};

	struct SSlot
	{
		unsigned char aSlot[16];
	};

	struct SBucketInfo
	{
		unsigned short nHead;

		union 
		{
			unsigned short nCur;
			unsigned short nStart;
		};
	};

	struct SRemapInfo
	{
		unsigned short aBucketCounts[256];
		SBucketInfo aBucketInfo[256];
		unsigned short* pNext;
		SSlot* pSlots;
	};

	unsigned short* m_pDecalTrivialAccept;
	unsigned int m_nNumDecalTrivialAccept;
	SBaryCentricVertex* m_pDecalClippedTriangleVBNew;
	unsigned int m_nNumClippedTriangleVtx;
	ERotationType m_eRotationType;
	EScaleType m_eScaleType;
	float m_fScaleTarget;
	float m_fScaleTime;
	float m_fScaleStartSlope;
	float m_fScaleEndSlope;
	float m_fExpirationFadeTime;
	unsigned int m_nLastLOD;
	unsigned char m_nDecalBuffer;

	static SComponentMapEntry s_componentMap[0];

	~ZDecalControllerEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	bool GenerateDecal(const SDecalIntersectionInfo& IntersectionInfo, SDecalCreationContext& Context, TEntityRef<ZSpatialEntity> pSpatialEntity, const SMatrix& mOffset) override;
	SMatrix GetMatrixFromRotation(const SDecalIntersectionInfo& IntersectionInfo, SDecalCreationContext& Context) const override;

	ZDecalControllerEntity() = default;
	static void RegisterType();
	ZDecalControllerEntity(ZComponentCreateInfo& Info);
	void OnGameStop(const ZString& sEvent, const ZVariantRef& __formal);
	float GetExpirationFadeTime();
	EScaleType GetScaleType();
	unsigned char GetDecalBuffer();
	float GetScaleTime();
	float GetScaleTarget();
	float GetStartSlope();
	float GetEndSlope();
	bool GenerateDecalInternal(SDecalCreationContextInternal& Context, TEntityRef<ZSpatialEntity> pSpatialEntity);
	float4 CalculateTexCoord(const float4& vPosition, const SMatrix& mProjection) const;
	bool ClipTriangle(float4** pTriangle, unsigned int nTriangleIndex, const float4* pDecalClipPlanes, EClipInclusionMode eClipMode);
	bool CheckIsQualified(const TEntityRef<ZSpatialEntity>& pSpatialEntity, TResourcePtr<ZRenderPrimitiveResource>& pPrimitiveResource) const;
	unsigned int BuildRemapTable(SRemapInfo* pRemapInfo, unsigned int nMaxSlots);
	void Remap(SRemapInfo* pRemapInfo, unsigned short* pDecalIndices);
	void StoreMeshVertex(SVertexDecal* vVertexOut, const void* pVertex, const SDecalCreationContextInternal& Context) const;
	void StoreMeshVertex_Compressed(SVertexDecal* vVertexOut, const void* pVertex, const SDecalCreationContextInternal& Context, const float4& vPosScale, const float4& vPosBias) const;
	void StoreMeshLinkedVertex_Compressed(SVertexW1Decal* vVertexOut, const void* pVertexPos, const void* pVertexOther, const SDecalCreationContextInternal& Context, const float4& vPosScale, const float4& vPosBias) const;
	void StoreMeshWeightedVertex_Compressed(SVertexW4Decal* vVertexOut, const unsigned char* pStream0, const unsigned char* pStream1, const unsigned char* pStream2, const SDecalCreationContextInternal& Context, const float4& vPosScale, const float4& vPosBias) const;
	void CalcMeshVertex(SVertexDecal* vVertexOut, const void** ppTriangle, const float4& vBarycentricCoord, const SDecalCreationContextInternal& Context) const;
	void CalcMeshVertex_Compressed(SVertexDecal* vVertexOut, const void** ppTriangle, const float4& vBarycentricCoord, const SDecalCreationContextInternal& Context, const float4& vPosScale, const float4& vPosBias) const;
	void CalcMeshLinkedVertex_Compressed(SVertexW1Decal* vVertexOut, const void** ppTriangle, const void** ppTriangleOther, const float4& vBarycentricCoord, const SDecalCreationContextInternal& Context, const float4& vPosScale, const float4& vPosBias) const;
	void CopyTrivial_Standard_Compressed(SRemapInfo* pRemapInfo, unsigned char* pDecalVertices, const unsigned char* pVertices, unsigned int nInStride, unsigned int nOutStride, const SDecalCreationContextInternal& Context, const float4& vPosScale, const float4& vPosBias);
	void CopyTrivial_Standard(SRemapInfo* pRemapInfo, unsigned char* pDecalVertices, const unsigned char* pVertices, unsigned int nInStride, unsigned int nOutStride, const SDecalCreationContextInternal& Context);
	void CopyTrivial_Linked_Compressed(SRemapInfo* pRemapInfo, unsigned char* pDecalVertices, const unsigned char* pVerticesPos, const unsigned char* pVerticesOther, unsigned int nInStridePos, unsigned int nInStrideOther, unsigned int nOutStride, const SDecalCreationContextInternal& Context, const float4& vPosScale, const float4& vPosBias);
	void CopyTrivial_Weighted_Compressed(SRemapInfo* pRemapInfo, unsigned char* pDecalVertices, const unsigned char* pStream0, const unsigned char* pStream1, const unsigned char* pStream2, unsigned int nOutStride, const SDecalCreationContextInternal& Context, const float4& vPosScale, const float4& vPosBias);
};
