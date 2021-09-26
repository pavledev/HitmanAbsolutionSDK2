#pragma once

#include "ZBoundedEntity.h"
#include "SComponentMapEntry.h"
#include "SVector3.h"
#include "ZVariantRef.h"
#include "float4.h"

class ZComponentCreateInfo;
class ZString;
struct STypeID;

class ZAISoundModifierVolume : public ZBoundedEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	SVector3 m_vGlobalSize;
	float m_fDampening;

	static SComponentMapEntry s_componentMap[0];

	~ZAISoundModifierVolume() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;
	void CalculateBounds(float4& vMin, float4& vMax, const unsigned int nIncludeFlags, const unsigned int nExcludeFlags) override;

	ZAISoundModifierVolume() = default;
	static void RegisterType();
	ZAISoundModifierVolume(ZComponentCreateInfo& info);
	float4 GetVolumeHalfSize() const;
	float GetDampening() const;
	void OnGlobalSizeChanged();
};
