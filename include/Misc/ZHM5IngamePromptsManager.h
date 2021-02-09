#pragma once

#include "float4.h"
#include "SPromptToDisplay.h"
#include "TEntityRef.h"
#include "ZActor.h"
#include "ZHM5GuideLedge.h"
#include "ZHM5GuideWindow.h"

class ZUserFeedbackManager;

class alignas(16) ZHM5IngamePromptsManager
{
public:
    float4 m_vClipPlanesOuter[6];
    float4 m_vClipPlanesInner[6];
    SPromptToDisplay m_ActivePrompts[8];
    SPromptToDisplay m_LastPrompts[8];
    SPromptToDisplay m_ActivatedActionPrompt;
    ZUserFeedbackManager* m_pUserFBManager;
    unsigned __int8 m_iActPromptsCount;
    unsigned __int8 m_iLastPromptsCount;
    bool m_bHasPrimaryLedgePromptActive;
    TEntityRef<ZActor> m_pPreviousCandidate;
};
