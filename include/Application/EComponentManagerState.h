#pragma once

enum EComponentManagerState : __int32
{
    CMS_UNINITIALIZED = 0x0,
    CMS_RUNNING = 0x1,
    CMS_CLOSING = 0x2,
    CMS_DISPOSED = 0x3
};
