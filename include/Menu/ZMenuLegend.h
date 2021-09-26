#pragma once

#include "ZItemLegend.h"
#include "EControllerButton.h"
#include "EUIText.h"

class ZString;
class ZVariant;
template <class A, class B> class TMap;

class ZMenuLegend : public ZItemLegend
{
public:
	unsigned short m_nActionId;
	unsigned short m_nActionObject;

	~ZMenuLegend() override = default;
	void GetInfo(TMap<ZString, ZVariant>& pInfo) override;

	ZMenuLegend() = default;
	ZMenuLegend(EUIText eTextId, EControllerButton eButton, unsigned short nActionId, unsigned short nActionObject, int nVisibilityMask);
};
