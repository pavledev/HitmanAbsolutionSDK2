#pragma once

#include "ZBoundedEntity.h"
#include "IBoxVolumeEntity.h"
#include "TSList.h"
#include "ZResourcePtr.h"
#include "SComponentMapEntry.h"
#include "SVector3.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZEntityRef;
struct STypeID;
struct float4;
template <class T> class alignas(8) ZDelegate;

class ZBoxVolumeEntity : public ZBoundedEntity, public IBoxVolumeEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	SVector3 m_vGlobalSize;
	TSList<ZDelegate<void __cdecl(ZEntityRef const&)>> m_ChangeHandlerList;
	ZResourcePtr m_pHelper;

	static SComponentMapEntry s_componentMap[0];

	~ZBoxVolumeEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	bool ContainsPoint(const float4& vPoint) const override;
	void GetAxisAlignedBox(float4& vMin, float4& vMax) override;
	void RegisterForChanges(const ZDelegate<void __cdecl(ZEntityRef const&)>& callback) override;
	void UnregisterForChanges(const ZDelegate<void __cdecl(ZEntityRef const&)>& callback) override;
	void Init() override;
	void CalculateBounds(float4& vMin, float4& vMax, const unsigned int nIncludeFlags, const unsigned int nExcludeFlags) override;

	const SVector3& GetGlobalSize() override;

	ZBoxVolumeEntity() = default;
	static void RegisterType();
	ZBoxVolumeEntity(const ZBoxVolumeEntity& __that);
	ZBoxVolumeEntity(ZComponentCreateInfo& Info);
	void OnGlobalSizeChanged();
	void OnHelperChanged();
	ZBoxVolumeEntity& operator=(const ZBoxVolumeEntity& __that);
};
