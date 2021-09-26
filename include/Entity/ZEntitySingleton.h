#pragma once

#include "ZSharedPointerTarget.h"
#include "ZEntityRef.h"
#include "TResourcePtr.h"

class IEntityFactory;

class ZEntitySingleton : public ZSharedPointerTarget
{
public:
	ZEntityRef m_Entity;
	TResourcePtr<IEntityFactory> m_Factory;

	~ZEntitySingleton() override = default;

	ZEntitySingleton() = default;
	ZEntitySingleton(const ZEntitySingleton& __that);
	ZEntitySingleton(TResourcePtr<IEntityFactory> pEntityFactory);
	ZEntityRef GetEntity();
	ZEntitySingleton& operator=(const ZEntitySingleton& __that);
};
