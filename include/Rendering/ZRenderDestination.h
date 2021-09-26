#pragma once

#include "TRenderReferencedCountedImpl.h"
#include "ZEvent.h"
#include "SRenderDestinationDesc.h"
#include "TList.h"
#include "TListEnumerator.h"

class IRenderDestination;
class IRenderDestinationEntity;
class ZEventNull;
class ZRenderDevice;
class ZRenderShaderResourceView;
class ZRenderSwapChain;
class ZRenderTargetView;
class ZRenderTexture2D;
template <class T> class alignas(8) ZDelegate;

class ZRenderDestination : public TRenderReferencedCountedImpl<IRenderDestination, 0>
{
public:
	SRenderDestinationDesc m_Description;
	ZRenderDevice* m_pRenderDevice;
	ZEvent<SRenderDestinationDesc const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_ChangedHandlers;
	ZEvent<SRenderDestinationDesc const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_DeviceWillResetHandlers;
	ZEvent<SRenderDestinationDesc const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_DeviceDidResetHandlers;
	ZRenderSwapChain* m_pSwapChain;
	ZRenderTexture2D* m_pTexture;
	ZRenderTargetView* m_pRTV;
	ZRenderShaderResourceView* m_pSRV;
	TList<IRenderDestinationEntity*> m_RenderDestinationEntities;
	bool m_bHasChanged;
	bool m_bSizeChanged;
	bool m_bNeedsClear;

	~ZRenderDestination() override = default;
	const SRenderDestinationDesc& GetDesc() const override;
	void Change_MainThread(const SRenderDestinationDesc* pDescription) override;
	void Change_MessagePumpThread(const SRenderDestinationDesc* pDescription) override;
	void Change_Synchronized(const SRenderDestinationDesc* pDescription) override;
	void RegisterChangedHandler(const ZDelegate<void __cdecl(SRenderDestinationDesc const&)>& handler) override;
	void UnregisterChangedHandler(const ZDelegate<void __cdecl(SRenderDestinationDesc const&)>& handler) override;
	void RegisterDeviceWillResetHandler(const ZDelegate<void __cdecl(SRenderDestinationDesc const&)>& handler) override;
	void UnregisterDeviceWillResetHandler(const ZDelegate<void __cdecl(SRenderDestinationDesc const&)>& handler) override;
	void RegisterDeviceDidResetHandler(const ZDelegate<void __cdecl(SRenderDestinationDesc const&)>& handler) override;
	void UnregisterDeviceDidResetHandler(const ZDelegate<void __cdecl(SRenderDestinationDesc const&)>& handler) override;
	TListEnumerator<IRenderDestinationEntity*> GetRenderDestinationEntities() override;
	void AddRenderDestinationEntity(IRenderDestinationEntity* entity) override;
	void RemoveRenderDestinationEntity(IRenderDestinationEntity* entity) override;
	ZRenderTargetView* GetBackBufferRTV() const override;
	ZRenderShaderResourceView* GetShaderResourceView() const override;
	virtual void DeviceWillReset();
	virtual void DeviceDidReset();

	ZRenderDestination() = default;
	ZRenderDestination(const SRenderDestinationDesc& description, ZRenderDevice* pRenderDevice);
	void Update();
	ZRenderDevice* GetRenderDevice() const;
	void Allocate();
	void Free();
};
