#pragma once

#include "ZEntityImpl.h"
#include "ZResourcePtr.h"
#include "TEntityRef.h"
#include "TSharedPointer.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZEntitySingleton;
class ZSpatialEntity;
struct STypeID;
struct float4;

class ZCrowdDebris : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZResourcePtr m_pPanicDebrisResource;
	TEntityRef<ZSpatialEntity> m_pPanicDebrisEntity;
	TSharedPointer<ZEntitySingleton> m_pPanicDebrisSingleton;
	unsigned int m_nPanicDebrisActivatePinID;

	static SComponentMapEntry s_componentMap[0];

	~ZCrowdDebris() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZCrowdDebris() = default;
	static void RegisterType();
	ZCrowdDebris(const ZCrowdDebris& __that);
	ZCrowdDebris(ZComponentCreateInfo& Info);
	bool InitDebris();
	void AddDebris(const float4& vWorldPos);
	ZCrowdDebris& operator=(const ZCrowdDebris& __that);
};
