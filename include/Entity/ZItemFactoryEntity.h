#pragma once

#include "ZTemplateFactoryBase.h"
#include "TResourcePtr.h"
#include "STokenID.h"

class ZItemFactoryEntity : public ZTemplateFactoryBase
{
public:
    TResourcePtr<IEntityFactory> m_pResourcePtr;
    TResourcePtr<ZEntityRef> m_ContentKitEntity;
    STokenID m_TokenId;
};
