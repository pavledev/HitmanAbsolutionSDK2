#pragma once

#include "ZString.h"
#include "ZDelegate.h"
#include "EUIDialog.h"
#include "ZGameWideUI.h"

class IScaleformExternalInterfaceArguments;
class ZVariant;
template <class A, class B> class TMap;

class ZUIButtonMapper_Windows
{
public:
	enum ResetStatus
	{
		eProcessing = 0,
		eReset = 1,
		eCancelled = 2
	};

	ZString m_ButtonMappingName;
	ZString m_ButtonMappingResult;
	int m_iButtonMappingIndex;
	int m_iButtonMappingDevice;
	int m_iButtonMappingDikCode;
	ResetStatus m_iResetStatus;
	ZDelegate<void __cdecl(ZGameWideUI::EDialogContext, EUIDialog, ZGameWideUI::EDialogResult)> m_dialogCallback;

	ZUIButtonMapper_Windows() = default;
	~ZUIButtonMapper_Windows() = default;
	void SetDialogCallback(ZDelegate<void __cdecl(ZGameWideUI::EDialogContext, EUIDialog, ZGameWideUI::EDialogResult)> dialogCallback);
	void SetButtonMappingResult(const ZString& result);
	void SetResetStatus(ResetStatus resetStatus);
	void CollectButtonMapping(TMap<ZString, ZVariant>& pInfo, bool bIsSubmenu) const;
	void StartButtonMapCallback(IScaleformExternalInterfaceArguments& params);
	void QueryButtonMapCallback(IScaleformExternalInterfaceArguments& params);
	void CancelButtonMapCallback(IScaleformExternalInterfaceArguments& params);
	void RequestButtonMapCallback(IScaleformExternalInterfaceArguments& params) const;
	void ResetButtonMapCallback(IScaleformExternalInterfaceArguments& params);
	void ApplyButtonMap();
	void RemapCallback(int deviceID, int dikCode);
};
