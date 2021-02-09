#pragma once

enum EHumanShieldSpeechState : __int32
{
    HMSS_FirstWarning = 0x0,
    HMSS_SecondWarningVictim = 0x1,
    HMSS_SecondWarning = 0x2,
    HMSS_ThirdWarning = 0x3,
    HMSS_FlankTarget = 0x4,
    HMSS_TakeDown = 0x5,
    HMSS_Done = 0x6
};
