#pragma once

enum EOrderCompletionStatus : __int32
{
    OCS_Undetermined = 0x0,
    OCS_Succeeded = 0x1,
    OCS_Interrupted = 0x2,
    OCS_Blocked = 0x3,
    OCS_Failed = 0x4
};
