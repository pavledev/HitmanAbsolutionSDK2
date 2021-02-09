#pragma once

enum ERenderJobFlags : __int32
{
    TYPE_SPRITES = 0x1,
    TYPE_SPAWNER = 0x2,
    WRAP_TILE_INDEX = 0x4,
    IGNORE_ROTATION = 0x8,
    SCREEN_ALIGNED = 0x10,
    SHARED_WS_FEEDBACK = 0x20
};
