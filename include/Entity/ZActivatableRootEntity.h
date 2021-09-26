#pragma once

#include "ZEntityImpl.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class IEntity;
class ZComponentCreateInfo;
class ZString;
struct STypeID;
template <class A, class B> class THashSet;
template <class T> class TDefaultHashSetPolicy;

class ZActivatableRootEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	static SComponentMapEntry s_componentMap[0];

	~ZActivatableRootEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZActivatableRootEntity() = default;
	static void RegisterType();
	ZActivatableRootEntity(ZComponentCreateInfo& info);
	void GetActivatableEntities(THashSet<IEntity*, TDefaultHashSetPolicy<IEntity*>>& activatableEntities, const ZString& sSubset) const;
};
