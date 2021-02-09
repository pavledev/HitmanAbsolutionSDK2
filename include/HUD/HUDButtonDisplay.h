#pragma once

#include "IScaleformPlayer.h"
#include "TFixedArray.h"
#include "SButtonStatus.h"
#include "SPromptToDisplay.h"
#include "SGameplayInputControlBind.h"

class HUDButtonDisplay
{
public:
    IScaleformPlayer* m_mcHUD;
    GFxValue m_aButtonClips;
    TFixedArray<SButtonStatus, 9> m_aButtons;
    TFixedArray<SButtonStatus, 9> m_aButtonsLastFrame;
    bool m_bScaleformUpdatePrompts;
    bool m_bScaleformClearPrompts;
    bool m_bInstinctActive;
    bool m_bIsInputDeviceLastChanged;
    bool m_bRosettaVisible;
    TArray<SPromptToDisplay> m_aScaleformPrompts;
    TArray<SGameplayInputControlBind> m_aControlBinds;
};
