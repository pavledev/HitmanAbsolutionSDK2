#pragma once

#include "TMaxArray.h"
#include "SAttentionMeterInfo.h"
#include "SAttentionHudDataElement.h"

class alignas(16) ZAttentionHUD
{
public:
    bool m_bBlinkState;
    float m_fBlinkDuration;
    bool m_bPrevAttentionOn;
    bool m_bEnabled;
    TMaxArray<SAttentionMeterInfo, 100> m_attentionMeterInfos;
    TMaxArray<SAttentionHudDataElement, 6> m_aAttentionHUDScaleformData;

    enum
    {
        MAX_ATTENTION_PEAKS = 0x6
    };
};
