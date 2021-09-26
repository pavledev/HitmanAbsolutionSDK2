#pragma once

#include "ZString.h"
#include "EButtonDisplay.h"
#include "SVector2.h"

struct SPromptToDisplay
{
	enum EPromptState
	{
		ePS_Invalid = 0,
		ePS_ActionAvailable = 1,
		ePS_Activating = 2,
		ePS_CommunicateActivation = 3,
		ePS_GreyedOut = 4,
		ePS_Blinking = 5
	};

	ZString m_sText;
	EButtonDisplay m_eButtonDisplay;
	SVector2 m_vScreenPos;
	float m_fDistance;
	float m_fButtonValue;
	unsigned int m_uCacheKey;
	bool m_bIs3DPrompt : 1;
	bool m_bTextChanged : 1;
	bool m_bConsiderRejection : 1;
	bool m_bIllegalAction : 1;
	EPromptState m_eState;

	SPromptToDisplay(const SPromptToDisplay& __that);
	SPromptToDisplay() = default;
	void Invalidate();
	bool IsPromptValid() const;
	void SetData(EButtonDisplay buttonDisplay, const ZString& sText, EPromptState state, float xCor, float yCor, float dist, bool is3DPrompt, float buttonValue, unsigned int cacheKey, bool bTextChanged, bool bIllegalAction);
	void SetData(const SPromptToDisplay& source);
	void SetDataCached(EButtonDisplay buttonDisplay, unsigned int cacheKey, EPromptState state);
	void SetState(EPromptState newState);
	~SPromptToDisplay() = default;
	SPromptToDisplay& operator=(const SPromptToDisplay& __that);
};
