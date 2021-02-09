#pragma once

enum EMovementType : __int32
{
    MT_WALK = 0x0,
    MT_WALK_IF_NOT_IN_SEQUENCE = 0x1,
    MT_SNAP = 0x2,
    MT_IGNORE_POSITION = 0x3
};
