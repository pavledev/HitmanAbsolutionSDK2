#pragma once

#include "IGameStatsListener.h"
#include "ZGameTime.h"
#include "TResourcePtr.h"
#include "ZTextListData.h"
#include "ECommunicationBarMessage.h"
#include "EMeBarState.h"

class ZHM5IngameMessageBarManager : public IGameStatsListener
{
public:
    ZGameTime m_tTimeLastBodyMessage;
    ZGameTime m_tTimeLastBloodpoolMessage;
    ZGameTime m_tTimeLastDisguiseBlownMessage;
    TResourcePtr<ZTextListData> m_pTextListResource;
    ZGameTime m_tPendingGametensionMessageTime;
    ZGameTime m_tPendingCiviliansGotHelpMessage;
    ECommunicationBarMessage m_ePendingMessage;
    ECommunicationBarMessage m_eLastMessageShown;
    ZGameTime m_tPendingMessagebarMessageTime;
    EMeBarState m_ePendingMessagebarMessage;
    EMeBarState m_eLastMessageBarMessageShown;

    virtual ~ZHM5IngameMessageBarManager();
    virtual void ProcessGameEvent(SGameEventArgs* args);
    virtual EGameEventArgType GetArgType();
};
