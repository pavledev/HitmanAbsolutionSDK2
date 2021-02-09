#pragma once

enum EPromptState : __int32
{
    ePS_Invalid = 0x0,
    ePS_ActionAvailable = 0x1,
    ePS_Activating = 0x2,
    ePS_CommunicateActivation = 0x3,
    ePS_GreyedOut = 0x4,
    ePS_Blinking = 0x5
};
