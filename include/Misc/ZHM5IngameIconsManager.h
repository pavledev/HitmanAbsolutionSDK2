#pragma once

#pragma pack(push, 4)

#include "TFixedArray.h"
#include "SHUDIconInfo.h"
#include "UserFBIcons.h"

class ZUserFeedbackManager;

class ZHM5IngameIconsManager
{
public:
	struct SIconElement
	{
		unsigned int m_iHandle;
		SHUDIconInfo m_iconInfo;
		unsigned char m_iChangedFlags;
		bool m_bUpdated;

		SIconElement() = default;
		~SIconElement() = default;
	};

	TFixedArray<SIconElement, 10> m_IconElements;
	const ZUserFeedbackManager* m_rUserFBManager = {}; //Original declaration: const ZUserFeedbackManager& m_rUserFBManager;

	ZHM5IngameIconsManager() = default;
	ZHM5IngameIconsManager(ZUserFeedbackManager* pUserFBMan);
	~ZHM5IngameIconsManager() = default;
	void OnStart();
	void Update();
	void Reset();
	void UpdateFromTimers();
	SIconElement* ArrayFindElement(const unsigned int iKey);
	SIconElement* ArrayAddElement(const unsigned int iKey);
	unsigned int UpdateIconInfo(SHUDIconInfo& iconInfo, const UserFBIcons::STimerToOSDElement& timerInfo);
};

#pragma pack(pop)
