#pragma once

#include "ZMenuItem.h"
#include "EUIText.h"
#include "ZString.h"

class IScaleformExternalInterfaceArguments;
class ZVariant;
template <class A, class B> class TMap;

class ZMenuToggleItem : public ZMenuItem
{
public:
	unsigned short m_nOptionKey;
	bool m_bValue;
	ZString m_sText;

	~ZMenuToggleItem() override = default;
	void GetInfo(TMap<ZString, ZVariant>& pInfo) override;
	void ExecuteAction(IScaleformExternalInterfaceArguments& params) override;

	ZMenuToggleItem() = default;
	ZMenuToggleItem(EUIText eTextId, unsigned short nOptionKey);
	ZMenuToggleItem(const char* szText, unsigned short nOptionKey);
	void SetValue(bool bValue);
	bool GetValue();
};
