#pragma once

#include "TArray.h"
#include "ZMenuItem.h"
#include "ZMenuLegend.h"

class alignas(4) ZMenu
{
public:
    TArray<ZMenuItem*> m_aItems;
    TArray<ZMenuLegend*> m_aLegend;
    TMap<ZString, ZVariant> m_keyValues;
    EUIText m_eTitleTextId;
    unsigned __int16 m_nMenuId;

    virtual ~ZMenu();
    virtual ZMenuItem* GetItem(unsigned __int16);
    virtual void Add(ZDelegate<void __cdecl(ZMenuItem*, TMap<ZString, ZVariant>&)>);
    virtual void Add(ZItemLegend*);
    virtual void Add(ZMenuLegend*);
    virtual void Add(ZMenuItem*);
    virtual void GetInfo(TMap<ZString, ZVariant>*);
    virtual void CollectMenuItems(TMap<ZString, ZVariant>*);
    virtual void CollectLegendItems(TMap<ZString, ZVariant>*);
    virtual void AddKeyValue(ZString, ZVariant);
};
