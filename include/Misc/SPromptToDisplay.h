#pragma once

#include "ZString.h"
#include "EButtonDisplay.h"
#include "SVector2.h"
#include "EPromptState.h"

class SPromptToDisplay
{
public:
    ZString m_sText;
    EButtonDisplay m_eButtonDisplay;
    SVector2 m_vScreenPos;
    float m_fDistance;
    float m_fButtonValue;
    unsigned int m_uCacheKey;
    __int8 m_bIs3DPrompt : 1;
    __int8 m_bTextChanged : 1;
    __int8 m_bConsiderRejection : 1;
    __int8 m_bIllegalAction : 1;
    EPromptState m_eState;
};
