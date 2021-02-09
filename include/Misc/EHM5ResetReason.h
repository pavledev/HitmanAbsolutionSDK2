#pragma once

enum EHM5ResetReason : __int32
{
    eHM5ResetReason_ResetHitman = 0x0,
    eHM5ResetReason_DeactivateCheckPoint = 0x1,
    eHM5ResetReason_Destroy = 0x2,
    eHM5ResetReason_Internal = 0x3
};
