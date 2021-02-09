#pragma once

struct alignas(2) SRoomInsideOutsideInfo
{
    unsigned __int16 nRoomId;
    unsigned __int16 nAreaBoxId;
    unsigned __int16 nRoomIdInside;
    unsigned __int16 nRoomIdOutside;
    bool bOutside;
};
