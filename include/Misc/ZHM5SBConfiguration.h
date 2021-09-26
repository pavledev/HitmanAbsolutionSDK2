#pragma once

#include "ZEntityImpl.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class SSBConfiguration;
class ZComponentCreateInfo;
struct STypeID;

class ZHM5SBConfiguration : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_fDuration;
	float m_fEaseOutTime;
	float m_fStartMultiplier;
	float m_fEndMultiplier;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5SBConfiguration() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZHM5SBConfiguration() = default;
	static void RegisterType();
	ZHM5SBConfiguration(ZComponentCreateInfo& Info);
	void GetConfiguration(SSBConfiguration& Ret) const;
};
