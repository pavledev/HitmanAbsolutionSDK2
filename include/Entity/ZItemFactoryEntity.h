#pragma once

#include "ZTemplateFactoryBase.h"
#include "TResourcePtr.h"
#include "STokenID.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class IEntityFactory;
class ZComponentCreateInfo;
class ZEntityRef;
struct STypeID;

class ZItemFactoryEntity : public ZTemplateFactoryBase
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TResourcePtr<IEntityFactory> m_pResourcePtr;
	TResourcePtr<ZEntityRef> m_ContentKitEntity;
	STokenID m_TokenId;

	static SComponentMapEntry s_componentMap[0];

	~ZItemFactoryEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void OnInstanceChanged() override;
	TResourcePtr<IEntityFactory> GetResource() const override;

	ZItemFactoryEntity() = default;
	static void RegisterType();
	ZItemFactoryEntity(ZComponentCreateInfo& info);
	void OnContentKitEntityChanged();
};
