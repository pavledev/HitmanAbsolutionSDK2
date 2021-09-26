#pragma once

#include "ZSpatialEntity.h"
#include "SComponentMapEntry.h"
#include "TEntityRef.h"
#include "ZVariantRef.h"
#include "float4.h"

class ZAISoundConnectorTarget;
class ZComponentCreateInfo;
class ZString;
struct STypeID;

class ZAISoundConnector : public ZSpatialEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TEntityRef<ZAISoundConnectorTarget> m_pConnectedTo;
	bool m_bRegistered;
	bool m_bTwoWay;

	static SComponentMapEntry s_componentMap[0];

	~ZAISoundConnector() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	ZAISoundConnector() = default;
	static void RegisterType();
	ZAISoundConnector(ZComponentCreateInfo& info);
	float4 GetConnectedTo() const;
	void SetTwoWay(bool bValue);
	bool IsTwoWay() const;
};
