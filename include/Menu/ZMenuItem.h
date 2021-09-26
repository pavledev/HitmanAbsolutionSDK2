#pragma once

#include "EUIText.h"
#include "TArray.h"
#include "ZDelegate.h"
#include "EUIMenuItemName.h"

class IScaleformExternalInterfaceArguments;
class ZItemLegend;
class ZString;
class ZVariant;
template <class A, class B> class TMap;

class ZMenuItem
{
public:
	EUIText m_eTextId;
	unsigned short m_nItemId;
	TArray<ZItemLegend*> m_aLegend;
	ZDelegate<void __cdecl(ZMenuItem*, TMap<ZString, ZVariant>&)> infoCallback;
	EUIMenuItemName m_eName;
	bool m_bPerformPolls;
	bool m_bEnabled;

	virtual ~ZMenuItem() = default;
	virtual void GetInfo(TMap<ZString, ZVariant>& pInfo);
	virtual void ExecuteAction(IScaleformExternalInterfaceArguments& params);
	virtual EUIText GetTextId();

	ZMenuItem() = default;
	ZMenuItem(EUIText eTextId);
	bool IsEnabled();
	void SetEnabled(bool bEnabled);
	void SetItemName(EUIMenuItemName eItemName);
	void SetPreformPolls(bool bPerformPolls);
};
