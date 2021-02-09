#pragma once

#include "IComponentInterface.h"
#include "ZComponentCreateInfo.h"

class IModule : public IComponentInterface
{
public:
    virtual const ZString* Name();
    virtual bool Initialize();
    virtual void Shutdown();
    virtual void Activate();
    virtual void Deactivate();
    virtual ZString* GetOption(ZString* result, const ZString*);
    virtual bool GetOptionBool(const ZString*);
    virtual void SetOption(const ZString*, const ZString*);
    virtual void BeginInitialization();
    virtual void EndInitialization();
    virtual void WaitForInitialization();
    virtual IComponentInterface* CreateComponent(const ZString*, ZComponentCreateInfo*);
};
