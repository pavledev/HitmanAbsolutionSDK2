#pragma once

#include "IComponentInterface.h"
#include "ZEvent.h"
#include "ZEventNull.h"

class ZHM5SystemEventHandler : public IComponentInterface
{
public:
    ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_SystemMenuShownEvent;
    ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_SystemMenuHiddenEvent;
    int m_nControllerDisconnectedFrameCount;
    bool m_bActive;
    bool m_bShowingControllerMessage;
    bool m_bShowingSystemMenu;
    bool m_bSystemMenuEventPending;

    virtual void Initialize();
    virtual void OnSystemMenuShown(bool);
    virtual void PlatformFrameUpdate();
};
