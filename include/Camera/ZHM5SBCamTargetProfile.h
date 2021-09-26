#pragma once

#include "ZEntityImpl.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct SSBCamTargetProfile;
struct STypeID;

class ZHM5SBCamTargetProfile : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_fStickLength;
	float m_fRoll;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5SBCamTargetProfile() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZHM5SBCamTargetProfile() = default;
	static void RegisterType();
	ZHM5SBCamTargetProfile(ZComponentCreateInfo& pInfo);
	void GetSBCamTargetProfile(SSBCamTargetProfile& Ret) const;
};
