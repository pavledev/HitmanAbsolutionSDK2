#pragma once

#include "IRenderRefCount.h"
#include "SRenderDestinationDesc.h"
#include "ZDelegate.h"
#include "TListEnumerator.h"
#include "ZRenderTargetView.h"

class IRenderDestinationEntity;

class IRenderDestination : public IRenderRefCount
{
public:
    virtual const SRenderDestinationDesc* GetDesc();
    virtual void Change_MainThread(const SRenderDestinationDesc*);
    virtual void Change_MessagePumpThread(const SRenderDestinationDesc*);
    virtual void Change_Synchronized(const SRenderDestinationDesc*);
    virtual void RegisterChangedHandler(const ZDelegate<void __cdecl(SRenderDestinationDesc const&)>*);
    virtual void UnregisterChangedHandler(const ZDelegate<void __cdecl(SRenderDestinationDesc const&)>*);
    virtual void RegisterDeviceWillResetHandler(const ZDelegate<void __cdecl(SRenderDestinationDesc const&)>*);
    virtual void UnregisterDeviceWillResetHandler(const ZDelegate<void __cdecl(SRenderDestinationDesc const&)>*);
    virtual void RegisterDeviceDidResetHandler(const ZDelegate<void __cdecl(SRenderDestinationDesc const&)>*);
    virtual void UnregisterDeviceDidResetHandler(const ZDelegate<void __cdecl(SRenderDestinationDesc const&)>*);
    virtual TListEnumerator<IRenderDestinationEntity*> GetRenderDestinationEntities();
    virtual void AddRenderDestinationEntity(IRenderDestinationEntity*);
    virtual void RemoveRenderDestinationEntity(IRenderDestinationEntity*);
    virtual ZRenderTargetView* GetBackBufferRTV();
    virtual ZRenderShaderResourceView* GetShaderResourceView();
};
