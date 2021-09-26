#pragma once

#include "ZBoundedEntity.h"
#include "SComponentMapEntry.h"
#include "SMatrix.h"
#include "SVector3.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZString;
struct STypeID;
struct float4;

class ZAIVisionBlockerPlane : public ZBoundedEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bEnabled;
	SVector3 m_vPortalSize;
	SMatrix m_world;

	static SComponentMapEntry s_componentMap[0];

	~ZAIVisionBlockerPlane() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;
	void CalculateBounds(float4& vMin, float4& vMax, const unsigned int nIncludeFlags, const unsigned int nExcludeFlags) override;

	ZAIVisionBlockerPlane() = default;
	static void RegisterType();
	ZAIVisionBlockerPlane(ZComponentCreateInfo& info);
	bool IsEnabled() const;
	bool LineIntersect(const float4& vStart, const float4& vEnd);
	void OnEnable();
	void OnDisable();
	void OnPortalSizeChanged();
};
