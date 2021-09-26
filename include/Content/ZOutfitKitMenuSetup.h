#pragma once

#include "ZContentKitMenuSetup.h"
#include "ELevelIndex.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct STypeID;

class ZOutfitKitMenuSetup : public ZContentKitMenuSetup
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ELevelIndex m_LevelIndex;

	static SComponentMapEntry s_componentMap[0];

	~ZOutfitKitMenuSetup() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZOutfitKitMenuSetup() = default;
	static void RegisterType();
	ZOutfitKitMenuSetup(ZComponentCreateInfo& Info);
};
