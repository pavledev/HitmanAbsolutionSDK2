#pragma once

#include "ZString.h"
#include "IComponentInterface.h"
#include "ZComponentCreateInfo.h"

class ZComponentInfoBase
{
public:
    ZString m_sName;

    virtual ~ZComponentInfoBase();
    virtual void Initialize();
    virtual IComponentInterface* CreateComponent(ZComponentCreateInfo*);
    virtual void Shutdown();
    virtual ZString* GetName(ZString* result);
};
