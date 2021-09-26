#pragma once

#include "ZEntityImpl.h"
#include "EMetaContent.h"
#include "SComponentMapEntry.h"
#include "STokenID.h"
#include "TArray.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZTokenIDEntity;
struct STypeID;
template <class T> class TEntityRef;

class ZMetaContentAccessEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	EMetaContent m_ContentType;
	TArray<TEntityRef<ZTokenIDEntity>> m_aUnlockTokens;

	static SComponentMapEntry s_componentMap[0];

	~ZMetaContentAccessEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZMetaContentAccessEntity() = default;
	static void RegisterType();
	ZMetaContentAccessEntity(ZComponentCreateInfo& Info);
	void Execute() const;
	void Remove() const;
	bool IsValidInCurrentContext() const;
	bool HasDLCUnlockBeenGranted(const STokenID& token) const;
};
