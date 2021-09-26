#pragma once

#include "ZBoundedEntity.h"
#include "ITriggerVolume.h"
#include "TSList.h"
#include "ZResourcePtr.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZEntityRef;
struct STypeID;
struct float4;
template <class T> class alignas(8) ZDelegate;

class ZSphereVolumeEntity : public ZBoundedEntity, public ITriggerVolume
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_fRadius;
	TSList<ZDelegate<void __cdecl(ZEntityRef const&)>> m_ChangeHandlerList;
	ZResourcePtr m_pHelper;

	static SComponentMapEntry s_componentMap[0];

	~ZSphereVolumeEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void CalculateBounds(float4& vMin, float4& vMax, const unsigned int nIncludeFlags, const unsigned int nExcludeFlags) override;

	bool ContainsPoint(const float4& vPoint) const override;
	void GetAxisAlignedBox(float4& vMin, float4& vMax) override;
	void RegisterForChanges(const ZDelegate<void __cdecl(ZEntityRef const&)>& callback) override;
	void UnregisterForChanges(const ZDelegate<void __cdecl(ZEntityRef const&)>& callback) override;

	ZSphereVolumeEntity() = default;
	static void RegisterType();
	ZSphereVolumeEntity(ZComponentCreateInfo& Info);
	void OnRadiusChanged();
	void OnHelperChanged();
};
