#pragma once

#include "ZEntityImpl.h"
#include "TResourcePtr.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

struct STokenID;
class ZComponentCreateInfo;
class ZEntityRef;
struct STypeID;

class ZContentKitMenuSetup : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TResourcePtr<ZEntityRef> m_ContentKitEntity;

	static SComponentMapEntry s_componentMap[0];

	~ZContentKitMenuSetup() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	virtual void OnSavegameLoadDone();
	virtual void BeforeUnregisterKit();
	virtual void AfterRegisterKit();

	ZContentKitMenuSetup() = default;
	static void RegisterType();
	ZContentKitMenuSetup(ZComponentCreateInfo& Info);
	const STokenID& GetTokenID() const;
	void OnContentKitEntityChanged();
};
