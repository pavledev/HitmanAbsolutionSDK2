#pragma once

#include "ZEntityImpl.h"
#include "STokenID.h"
#include "SComponentMapEntry.h"
#include "ZString.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZEntityRef;
struct STypeID;
template <class T> class TResourcePtr;

class ZTokenIDEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZString m_sName;
	STokenID m_TokenIDCached;

	static SComponentMapEntry s_componentMap[0];

	~ZTokenIDEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZTokenIDEntity() = default;
	static void RegisterType();
	ZTokenIDEntity(ZComponentCreateInfo& Info);
	const STokenID& GetTokenID();
	static const STokenID& GetTokenIdFromResource(TResourcePtr<ZEntityRef> pTokenResource);
	static unsigned int CalcHash(const ZString& str);
};
