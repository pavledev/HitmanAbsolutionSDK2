#pragma once

enum EFiberState : __int32
{
    FS_INITIALIZED = 0x0,
    FS_RUNNING = 0x1,
    FS_TERMINATING = 0x2,
    FS_COMPLETED = 0x3
};
