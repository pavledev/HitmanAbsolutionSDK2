#pragma once

#include "ZEntityImpl.h"
#include "STokenID.h"
#include "TResourcePtr.h"

class ZGlobalItemKit : public ZEntityImpl
{
public:
    STokenID m_TokenId;
    TResourcePtr<ZEntityRef> m_TokenResource;
    ZRuntimeResourceID m_ItemResource;

    virtual const STokenID* GetTokenID();
};
