#pragma once

#include "IRenderRefCount.h"
#include "TListEnumerator.h"

class IRenderDestinationEntity;
class ZRenderShaderResourceView;
class ZRenderTargetView;
struct SRenderDestinationDesc;
template <class T> class alignas(8) ZDelegate;

class __declspec(novtable) IRenderDestination : public IRenderRefCount
{
public:
	~IRenderDestination() override = default;
	virtual const SRenderDestinationDesc& GetDesc() const = 0;
	virtual void Change_MainThread(const SRenderDestinationDesc* renderDestinationDesc) = 0;
	virtual void Change_MessagePumpThread(const SRenderDestinationDesc* renderDestinationDesc) = 0;
	virtual void Change_Synchronized(const SRenderDestinationDesc* renderDestinationDesc) = 0;
	virtual void RegisterChangedHandler(const ZDelegate<void __cdecl(SRenderDestinationDesc const&)>& param1) = 0;
	virtual void UnregisterChangedHandler(const ZDelegate<void __cdecl(SRenderDestinationDesc const&)>& param1) = 0;
	virtual void RegisterDeviceWillResetHandler(const ZDelegate<void __cdecl(SRenderDestinationDesc const&)>& param1) = 0;
	virtual void UnregisterDeviceWillResetHandler(const ZDelegate<void __cdecl(SRenderDestinationDesc const&)>& param1) = 0;
	virtual void RegisterDeviceDidResetHandler(const ZDelegate<void __cdecl(SRenderDestinationDesc const&)>& param1) = 0;
	virtual void UnregisterDeviceDidResetHandler(const ZDelegate<void __cdecl(SRenderDestinationDesc const&)>& param1) = 0;
	virtual TListEnumerator<IRenderDestinationEntity*> GetRenderDestinationEntities() = 0;
	virtual void AddRenderDestinationEntity(IRenderDestinationEntity* renderDestinationEntity) = 0;
	virtual void RemoveRenderDestinationEntity(IRenderDestinationEntity* renderDestinationEntity) = 0;
	virtual ZRenderTargetView* GetBackBufferRTV() const = 0;
	virtual ZRenderShaderResourceView* GetShaderResourceView() const = 0;

	IRenderDestination() = default;
};
