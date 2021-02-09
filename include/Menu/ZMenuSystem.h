#pragma once

#include "TArray.h"
#include "ZMenu.h"
#include "EUIDialog.h"
#include "EUIDialogButton.h"

class ZMenuSystem
{
public:
    TArray<ZMenu*> Menus;

    virtual ~ZMenuSystem();
    virtual void Setup();
    virtual void Shutdown();
    virtual ZMenuItem* GetItemWithId(unsigned __int16);
    virtual ZMenu* GetMenuWithId(unsigned __int16);
    virtual ZMenu* AddMenu(unsigned __int16, EUIText);
    virtual void OnAction(IScaleformExternalInterfaceArguments*);
    virtual bool HandleConfirmationDialogResult(EUIDialog, EUIDialogButton);
    virtual TMap<ZString, ZVariant>* GetMenuInfoMap(TMap<ZString, ZVariant>* result, IScaleformExternalInterfaceArguments*);
};
