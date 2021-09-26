#pragma once

#include "IGameStatsListener.h"
#include "ZGameTime.h"
#include "TResourcePtr.h"
#include "ECommunicationBarMessage.h"
#include "EMeBarState.h"
#include "EGameEventArgType.h"
#include "SGameEventArgs.h"
#include "ZString.h"

class ZAIGameState;
class ZTextListData;

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

	~ZHM5IngameMessageBarManager() override = default;
	void ProcessGameEvent(const SGameEventArgs& args) override;
	EGameEventArgType GetArgType() const override;

	ZHM5IngameMessageBarManager() = default;
	void OnStart();
	void OnStop();
	void Reset();
	void UpdateAIState(const ZAIGameState* const pOldState, const ZAIGameState* const pNewState);
	void SetTextlistResource(TResourcePtr<ZTextListData> pTextlistResource);
	ZString GetAllLevelsLocalizedString(ZString& sID);
	void ShowSuspiciousBehaviorText(EMeBarState state);
	ECommunicationBarMessage MapToMessage(const ZAIGameState* const pOldState, const ZAIGameState* const pNewState);
	void DisplayCommunicationBarMessage(ECommunicationBarMessage eMsg);
};
