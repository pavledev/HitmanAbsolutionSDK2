#pragma once

enum StateFlags : __int32
{
    FORCE_UPDATE = 0x1,
    IS_RUNNING = 0x2,
    IS_PAUSED = 0x4,
    LAST_IS_PAUSED_STATE = 0x8,
    IS_STOPPED_NATURALLY = 0x10,
    IS_PREVIEWING = 0x20,
    IS_READY = 0x40,
    IS_PREFETCH_ENABLED = 0x80,
    IS_FORCING_2DSOUNDS = 0x100
};
