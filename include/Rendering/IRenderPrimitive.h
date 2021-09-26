#pragma once

#include "TRenderReferencedCountedImpl.h"
#include "float4.h"
#include "TResourcePtr.h"
#include "SRenderPrimitiveMeshDesc.h"
#include "TArray.h"
#include "TBag.h"

class ZDebugRender;
class ZRenderAsyncUpdateRenderPrimitiveProperties;
class IRenderRefCount;
class ZAnimationBoneData;
class ZAnimationBonePose;
class ZRenderContext;
class ZRenderIndexBuffer;
class ZRenderInputLayout;
class ZRenderMaterialInstance;
class ZRenderVertexBuffer;
class ZRuntimeResourceID;
struct SMatrix;
template <class T> class alignas(8) ZDelegate;

class __declspec(novtable) IRenderPrimitive : public TRenderReferencedCountedImpl<IRenderRefCount, 0>
{
public:
	enum ERenderPrimType
	{
		RENDER_PRIM_TYPE_INVALID = 0,
		RENDER_PRIM_TYPE_MESH = 1,
		RENDER_PRIM_TYPE_MESH_EDGE = 2,
		RENDER_PRIM_TYPE_SPRITES = 3,
		RENDER_PRIM_TYPE_SPRITES_SLAVE = 4
	};

	float4 m_vPosScale;
	float4 m_vPosBias;
	float4 m_vTexScaleBias;
	float4 m_vMin;
	float4 m_vMax;
	TResourcePtr<ZRenderMaterialInstance> m_pMaterial;
	ZRenderMaterialInstance* m_pMaterialInstance;
	unsigned int m_nNumIndicesToDraw;
	unsigned int m_nWireColor;
	TBag<ZDelegate<void __cdecl(void)>, TArray<ZDelegate<void __cdecl(void)>>> m_ChangedEventHandlers;
	unsigned char m_nLODMask;
	unsigned char m_nZBias;
	unsigned char m_nZOffset;
	unsigned char m_nAxisLockedMask : 3;
	bool m_bUseMaterialStatusChangedCallbacks : 1;
	bool m_bInsideBeginUpdate : 1;
	unsigned char m_nType;
	ZRenderVertexBuffer* m_pVertexBuffers[3];
	ZRenderIndexBuffer* m_pIndexBuffer;
	ZRenderInputLayout* m_pInputLayout;
	SRenderPrimitiveMeshDesc m_Description;

	~IRenderPrimitive() override = default;
	virtual void DrawNew(ZRenderContext* renderContext) = 0;
	virtual void DrawDebug(ZDebugRender* pDebugRender, const SMatrix& mObjectToWorld, bool bDrawNormals, const ZAnimationBonePose* pBonePose, const ZAnimationBoneData* pBoneData, const bool* pVisibilityArray);

	IRenderPrimitive() = default;
	const TResourcePtr<ZRenderMaterialInstance>& GetMaterial() const;
	ZRenderMaterialInstance* GetMaterialInstance() const;
	void GetBounds(float4& vMin, float4& vMax) const;
	unsigned char GetLODMask() const;
	unsigned char GetZBias() const;
	unsigned char GetZOffset() const;
	unsigned char GetAxisLockedMask() const;
	unsigned int GetWireColor() const;
	const float4 GetPositionScale();
	const float4 GetPositionBias();
	const float4 GetTextureScaleBias();
	unsigned char GetType();
	ZRenderInputLayout* GetInputLayout() const;
	unsigned int GetNumIndicesToDraw() const;
	const SRenderPrimitiveMeshDesc& GetMeshDesc() const;
	ZRenderVertexBuffer* GetVertexBufferInternal(const int nSlot);
	ZRenderIndexBuffer* GetIndexBufferInternal();
	ZRenderAsyncUpdateRenderPrimitiveProperties* BeginUpdate();
	void EndUpdate(ZRenderAsyncUpdateRenderPrimitiveProperties* pUpdate);
	void SetMaterial(const TResourcePtr<ZRenderMaterialInstance>& pMaterial);
	void SetBounds_RT(const float4& vMin, const float4& vMax);
	void SetLODMask_RT(unsigned char nLODMask);
	void SetPositionScale_RT(const float4& vPosScale);
	void SetPositionBias_RT(const float4& vPosBias);
	void SetTextureScaleBias_RT(const float4& vTexScaleBias);
	void SetNumIndicesToDraw_RT(unsigned int nNumIndicesToDraw);
	void UpdateMaterialInstance();
	void AddChangedListener(const ZDelegate<void __cdecl(void)>& callback);
	void RemoveChangedListener(const ZDelegate<void __cdecl(void)>& callback);
	void SetBounds_Direct(const float4& vMin, const float4& vMax);
	void SetLODMask_Direct(unsigned char nLODMask);
	void SetZBias_Direct(unsigned char nZBias);
	void SetZOffset_Direct(unsigned char nZOffset);
	void SetAxisLockedMask_Direct(unsigned char nAxisLockedMask);
	void SetWireColor_Direct(unsigned int nWireColor);
	void SetPositionScale_Direct(const float4& vPosScale);
	void SetPositionBias_Direct(const float4& vPosBias);
	void SetTextureScaleBias_Direct(const float4& vTexScaleBias);
	void SetNumIndicesToDraw_Direct(unsigned int nNumIndicesToDraw);
	void UpdateBoundsForAxisLock();
	void OnMaterialPtrChanged(const ZRuntimeResourceID& args);
	void OnMaterialInstanceChanged(const ZRenderMaterialInstance* pMaterialInstance);
	void OnChanged();
};
