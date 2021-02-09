#pragma once

enum EQueryState : __int32
{
    eRS_NoRequest = 0x0,
    eRS_NewInQueue = 0x1,
    eRS_ResultClear = 0x2,
    eRS_ResultHit = 0x3
};
