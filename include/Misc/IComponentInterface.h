#pragma once

#include "ZVariantRef.h"

class IComponentInterface
{
public:
    virtual ~IComponentInterface();
    virtual ZVariantRef* GetVariantRef(ZVariantRef* result);
    virtual int AddRef();
    virtual int Release();
    virtual void* QueryInterface(STypeID*);

    IComponentInterface();
    IComponentInterface(IComponentInterface const&);
    IComponentInterface* operator=(IComponentInterface const&);
    static void RegisterType();
};
