#pragma once

#include "IComponentInterface.h"
#include "ZEvent.h"
#include "ZEventNull.h"

class ZHM5SystemEventHandler : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_SystemMenuShownEvent;
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_SystemMenuHiddenEvent;
	int m_nControllerDisconnectedFrameCount;
	bool m_bActive;
	bool m_bShowingControllerMessage;
	bool m_bShowingSystemMenu;
	bool m_bSystemMenuEventPending;

	~ZHM5SystemEventHandler() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	virtual void Initialize();
	virtual void OnSystemMenuShown(bool bShown);
	virtual void PlatformFrameUpdate();

	ZHM5SystemEventHandler() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void SetActive(bool bActive);
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetSystemMenuShownEvent();
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetSystemMenuHiddenEvent();
	void ResetPrimaryUser();
	void SetPrimaryUser(int nControllerIndex);
	void OnSignInChanged(ZUserProfile* pUser, ESignInState eNewState);
	void OnStorageDeviceChanged();
	void OnUpdate(const SGameUpdateEvent& __formal);
	void DialogCallback(ZGameWideUI::EDialogContext eContext, EUIDialog eDialog, ZGameWideUI::EDialogResult eResult);
	void OnDLCItemChanged(const SDLCItem& dlcItem);
};
