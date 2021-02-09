#pragma once

#include "EUIText.h"
#include "EControllerButton.h"
#include "TMap.h"
#include "ZString.h"
#include "ZVariant.h"

class ZItemLegend
{
public:
    EUIText m_eTextId;
    EControllerButton m_eButton;
    unsigned __int16 m_nItemId;
    int m_nVisibilityMask;

    enum EInputDevice : unsigned __int32
    {
        eAllInputDevices = 0xFFFFFFFF,
        eNone = 0x0,
        eMouse = 0x1,
        eKeyboard = 0x2,
        eGamepad = 0x4
    };

    virtual ~ZItemLegend();
    virtual void GetInfo(TMap<ZString, ZVariant>*);
};
