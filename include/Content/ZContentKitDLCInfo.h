#pragma once

#include "ZEntityImpl.h"
#include "ZRuntimeResourceID.h"
#include "TEntityRef.h"
#include "EContentKitDLCInfoType.h"
#include "SComponentMapEntry.h"
#include "ZString.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZTokenIDEntity;
struct STokenID;
struct STypeID;

class ZContentKitDLCInfo : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZRuntimeResourceID m_ridIcon;
	ZString m_sTitleID;
	ZString m_sDescriptionID;
	TEntityRef<ZTokenIDEntity> m_Token;
	EContentKitDLCInfoType m_eType;
	ZString m_sPS3StoreID;
	ZString m_sXboxStoreID;

	static SComponentMapEntry s_componentMap[0];

	~ZContentKitDLCInfo() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZContentKitDLCInfo() = default;
	static void RegisterType();
	ZContentKitDLCInfo(ZComponentCreateInfo& Info);
	const STokenID& GetTokenID() const;
};
