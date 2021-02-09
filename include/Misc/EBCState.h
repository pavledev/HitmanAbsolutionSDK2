#pragma once

enum EBCState : __int32
{
    BC_CLOSED = 0x0,
    BC_OPEN = 0x1,
    BC_FLUSH = 0x2,
    BC_OPENING = 0x3,
    BC_CLOSING = 0x4,
    BC_FLUSHING = 0x5
};
