#pragma once

#include "TArray.h"
#include "EUIDialog.h"
#include "EUIDialogButton.h"
#include "EControllerButton.h"
#include "EUIText.h"
#include "TMap.h"
#include "ZVariant.h"

class IScaleformExternalInterfaceArguments;
class ZMenu;
class ZMenuItem;
class ZString;

class ZMenuSystem
{
public:
	TArray<ZMenu*> Menus;

	virtual ~ZMenuSystem() = default;
	virtual void Setup();
	virtual void Shutdown();
	virtual ZMenuItem* GetItemWithId(unsigned short nMenuItemId);
	virtual ZMenu* GetMenuWithId(unsigned short nMenuId);
	virtual ZMenu* AddMenu(unsigned short nMenuId, EUIText eTitleText);
	virtual void OnAction(IScaleformExternalInterfaceArguments& params);
	virtual bool HandleConfirmationDialogResult(EUIDialog eDialog, EUIDialogButton eDialogButton);
	virtual TMap<ZString, ZVariant> GetMenuInfoMap(IScaleformExternalInterfaceArguments& params);

	ZMenuSystem() = default;
	static ZVariant MakeLegend(EControllerButton eButton, EUIText eText, EControllerButton eButton2, EUIText eText2, int nVisibilityMask, int nVisibilityMask2);
};
