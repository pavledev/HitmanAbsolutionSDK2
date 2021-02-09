#pragma once

#include "ZSpatialEntity.h"
#include "IEntityFactory.h"

class alignas(4) ZTemplateFactoryBase : public ZSpatialEntity
{
public:
    ZEntityRef m_pInstance;
    __int8 m_bStreamedIn : 1;
    __int8 m_bActivated : 1;

    virtual void OnInstanceChanged();
    virtual TResourcePtr<IEntityFactory>* GetResource(TResourcePtr<IEntityFactory>* result);
};
