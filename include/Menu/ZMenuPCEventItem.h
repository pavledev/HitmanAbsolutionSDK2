#pragma once

#include "ZMenuItem.h"
#include "EUIText.h"

class IScaleformExternalInterfaceArguments;
class ZString;
class ZVariant;
template <class A, class B> class TMap;

class ZMenuPCEventItem : public ZMenuItem
{
public:
	~ZMenuPCEventItem() override = default;
	void GetInfo(TMap<ZString, ZVariant>& pInfo) override;
	void ExecuteAction(IScaleformExternalInterfaceArguments& params) override;

	ZMenuPCEventItem() = default;
	ZMenuPCEventItem(EUIText eTextID, bool bAddLegend);
};
