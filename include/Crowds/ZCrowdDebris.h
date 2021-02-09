#pragma once

#include "ZEntityImpl.h"
#include "ZResourcePtr.h"
#include "TEntityRef.h"
#include "ZSpatialEntity.h"
#include "TSharedPointer.h"
#include "ZEntitySingleton.h"

class ZCrowdDebris : public ZEntityImpl
{
public:
    ZResourcePtr m_pPanicDebrisResource;
    TEntityRef<ZSpatialEntity> m_pPanicDebrisEntity;
    TSharedPointer<ZEntitySingleton> m_pPanicDebrisSingleton;
    unsigned int m_nPanicDebrisActivatePinID;
};
