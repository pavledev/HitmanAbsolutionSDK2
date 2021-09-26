#pragma once

#include "TArray.h"
#include "EUIText.h"
#include "TMap.h"
#include "ZVariant.h"

class ZItemLegend;
class ZMenuItem;
class ZMenuLegend;
class ZString;
template <class T> class alignas(8) ZDelegate;

class ZMenu
{
public:
	TArray<ZMenuItem*> m_aItems;
	TArray<ZMenuLegend*> m_aLegend;
	TMap<ZString, ZVariant> m_keyValues;
	EUIText m_eTitleTextId;
	unsigned short m_nMenuId;

	virtual ~ZMenu() = default;
	virtual ZMenuItem* GetItem(unsigned short nMenuItemId);
	virtual void Add(ZDelegate<void __cdecl(ZMenuItem*, TMap<ZString, ZVariant>&)> infoCallback);
	virtual void Add(ZItemLegend* pItemLegend);
	virtual void Add(ZMenuLegend* pMenuLegend);
	virtual void Add(ZMenuItem* pMenuItem);
	virtual void GetInfo(TMap<ZString, ZVariant>& pInfo);
	virtual void CollectMenuItems(TMap<ZString, ZVariant>& pInfo);
	virtual void CollectLegendItems(TMap<ZString, ZVariant>& pInfo);
	virtual void AddKeyValue(ZString sKey, ZVariant pData);

	ZMenu() = default;
	ZMenu(unsigned short nMenuId, EUIText eTitleText);
	void ClearItems();
	void ClearLegends();
};
