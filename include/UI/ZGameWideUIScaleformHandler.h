#pragma once

#include "ZEntityImpl.h"
#include "IScaleformExternalInterfaceHandler.h"
#include "TEntityRef.h"
#include "IScaleformPlayer.h"

class ZGameWideUIScaleformHandler : public ZEntityImpl, public IScaleformExternalInterfaceHandler
{
public:
    bool m_bCursorVisible;
    bool m_bLoadingVisible;
    bool m_bPcNewFeatures;
    bool m_bLoadSaveIndicatorShown;
    TEntityRef<IScaleformPlayer> m_pSystemMessagesMovie;
};
