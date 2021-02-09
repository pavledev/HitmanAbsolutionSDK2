#pragma once

#include "ZEntityImpl.h"
#include "TResourcePtr.h"

class ZContentKitMenuSetup : public ZEntityImpl
{
public:
    TResourcePtr<ZEntityRef> m_ContentKitEntity;

    virtual void OnSavegameLoadDone();
    virtual void BeforeUnregisterKit();
    virtual void AfterRegisterKit();
};
