#pragma once

#include "EUIText.h"
#include "EControllerButton.h"

class ZString;
class ZVariant;
template <class A, class B> class TMap;

class ZItemLegend
{
public:
	enum EInputDevice
	{
		eAllInputDevices = -1,
		eNone = 0,
		eMouse = 1,
		eKeyboard = 2,
		eGamepad = 4
	};

	EUIText m_eTextId;
	EControllerButton m_eButton;
	unsigned short m_nItemId;
	int m_nVisibilityMask;

	virtual ~ZItemLegend() = default;
	virtual void GetInfo(TMap<ZString, ZVariant>& pInfo);

	ZItemLegend() = default;
	ZItemLegend(EUIText eTextId, EControllerButton eButton, int nVisibilityMask);
};
