#pragma once

#include "ZEntityImpl.h"
#include "IGameStatsListener.h"
#include "EGameEventArgType.h"
#include "SComponentMapEntry.h"
#include "SGameEventArgs.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZString;
struct STypeID;

class ZGameStatsEntityBase : public ZEntityImpl, public IGameStatsListener
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	static SComponentMapEntry s_componentMap[0];

	~ZGameStatsEntityBase() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	void ProcessGameEvent(const SGameEventArgs& __formal) override;
	EGameEventArgType GetArgType() const override;

	ZGameStatsEntityBase() = default;
	static void RegisterType();
	ZGameStatsEntityBase(ZComponentCreateInfo& info);
};
