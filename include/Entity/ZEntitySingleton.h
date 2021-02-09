#pragma once

#include "ZSharedPointerTarget.h"
#include "ZEntityRef.h"
#include "TResourcePtr.h"
#include "IEntityFactory.h"

class ZEntitySingleton : public ZSharedPointerTarget
{
public:
    ZEntityRef m_Entity;
    TResourcePtr<IEntityFactory> m_Factory;
};
