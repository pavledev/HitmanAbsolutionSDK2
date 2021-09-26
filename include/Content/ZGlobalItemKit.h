#pragma once

#include "ZEntityImpl.h"
#include "STokenID.h"
#include "TResourcePtr.h"
#include "SComponentMapEntry.h"
#include "ZRuntimeResourceID.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZEntityRef;
struct STypeID;

class ZGlobalItemKit : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	STokenID m_TokenId;
	TResourcePtr<ZEntityRef> m_TokenResource;
	ZRuntimeResourceID m_ItemResource;

	static SComponentMapEntry s_componentMap[0];

	~ZGlobalItemKit() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	virtual const STokenID& GetTokenID() const;

	ZGlobalItemKit() = default;
	static void RegisterType();
	ZGlobalItemKit(ZComponentCreateInfo& info);
	ZRuntimeResourceID GetResource();
	void OnTokenResourceChanged();
};
