#pragma once

#include "EUIText.h"
#include "TArray.h"
#include "ZItemLegend.h"
#include "ZDelegate.h"
#include "EUIMenuItemName.h"
#include "IScaleformExternalInterfaceArguments.h"

class ZMenuItem
{
public:
    alignas(8) EUIText m_eTextId;
    unsigned __int16 m_nItemId;
    TArray<ZItemLegend*> m_aLegend;
    ZDelegate<void __cdecl(ZMenuItem*, TMap<ZString, ZVariant>&)> infoCallback;
    EUIMenuItemName m_eName;
    bool m_bPerformPolls;
    bool m_bEnabled;

    virtual ~ZMenuItem();
    virtual void GetInfo(TMap<ZString, ZVariant>*);
    virtual void ExecuteAction(IScaleformExternalInterfaceArguments*);
    virtual EUIText GetTextId();
};
