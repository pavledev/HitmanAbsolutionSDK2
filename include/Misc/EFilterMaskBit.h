#pragma once

enum EFilterMaskBit : __int32
{
    eFilterMaskBit_ObjectCollision = 0x0,
    eFilterMaskBit_CameraCollision = 0x1,
    eFilterMaskBit_CameraObstacleCollision = 0x2,
    eFilterMaskBit_OpaqueCollision = 0x3,
    eFilterMaskBit_UNUSED_LAST = 0x4
};
