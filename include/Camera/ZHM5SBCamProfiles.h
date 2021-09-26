#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZHM5SBCamHitmanProfile;
class ZHM5SBCamTargetProfile;
class ZHM5SBConfiguration;
struct STypeID;

class ZHM5SBCamProfiles : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TArray<TEntityRef<ZHM5SBCamHitmanProfile>> m_SBCamHitmanTargetProfiles;
	TArray<TEntityRef<ZHM5SBCamHitmanProfile>> m_SBCamHitmanViewProfiles;
	TArray<TEntityRef<ZHM5SBCamTargetProfile>> m_SBCamTargetProfiles;
	TEntityRef<ZHM5SBConfiguration> m_SBConfigurationShot;
	TEntityRef<ZHM5SBConfiguration> m_SBConfigurationBulletImpactPre;
	TEntityRef<ZHM5SBConfiguration> m_SBConfigurationBulletImpact;
	TEntityRef<ZHM5SBConfiguration> m_SBConfigurationHitmanView;
	TEntityRef<ZHM5SBConfiguration> m_SBConfigurationLastKill;
	float m_fMinTimeForHitmanView;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5SBCamProfiles() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZHM5SBCamProfiles() = default;
	static void RegisterType();
	ZHM5SBCamProfiles(ZComponentCreateInfo& pInfo);
};
