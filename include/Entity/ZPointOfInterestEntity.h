#pragma once

#include "ZBoundedEntity.h"
#include "SVector3.h"
#include "ZResourcePtr.h"
#include "SComponentMapEntry.h"
#include "SMatrix.h"
#include "TEntityRef.h"
#include "ZVariantRef.h"
#include "float4.h"

class ZComponentCreateInfo;
class ZSpatialEntity;
struct STypeID;

class ZPointOfInterestEntity : public ZBoundedEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum POIType
	{
		POIT_Glance = 1,
		POIT_Inspect = 2,
		POIP_Stare = 3
	};

	SVector3 m_vClipDebugVerts[10];
	SVector3 m_vClipDebugVertsCenter;
	int m_nClipDebugVertsCount;
	SVector3 m_vPortalSize;
	bool m_bActive;
	bool m_bBillboard;
	float m_fMaxDistance;
	bool m_bGlobal;
	ZResourcePtr m_pHelper;
	POIType m_eType;

	static SComponentMapEntry s_componentMap[0];

	~ZPointOfInterestEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void CalculateBounds(float4& vMin, float4& vMax, const unsigned int nIncludeFlags, const unsigned int nExcludeFlags) override;
	virtual TEntityRef<ZSpatialEntity> GetSpatial();
	virtual bool GetIsActive();
	virtual float GetMaxDistance();
	virtual float GetDuration();
	virtual float GetQuarentineDuration();
	virtual float GetLocalDuration();
	virtual float GetViewConeAngle();
	virtual bool GetIsGlobal();
	virtual POIType GetType();

	ZPointOfInterestEntity() = default;
	static void RegisterType();
	ZPointOfInterestEntity(ZComponentCreateInfo& info);
	bool JustGlance() const;
	float4 GetLocalRandomPoint();
	float4 GetRandomPoint(const float4& vDirection);
	bool GetLocalRandomPointClipped(float4& vPoint, const float4& vStart, const float4& vDirection, float fFOV, float fNear, float fFar);
	bool GetRandomPointClipped(float4& vPoint, const float4& vPosition, const float4& vDirection, float fFOV, float fNear, float fFar);
	bool IsVisible(const float4& vStart, const float4& vDirection, float fFOV, float fNear, float fFar);
	void OnPortalSizeChanged();
	void GetFrustumNormals(float4* vNormals, const float4& vDirection, float fFOV);
	SMatrix GetBillboardMatrix(const float4& vDirection);
	void OnActivate();
	void OnDeactivate();
	void OnHelperChanged();
};
