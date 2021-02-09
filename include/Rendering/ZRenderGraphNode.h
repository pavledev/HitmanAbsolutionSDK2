#pragma once

struct ZRenderGraphNode
{
    enum TYPE
    {
        GEOM = 0x0,
        LINKED = 0x1,
        PARTICLES = 0x2,
        SPATIAL = 0x3,
        LIGHT = 0x4,
        CAMERA = 0x5,
        MATERIAL = 0x6,
        VISIBILITY_PROXY = 0x7,
        POSTFILTER = 0x8,
        RAIN = 0x9,
        RAINMODIFIER = 0xA,
        COMPOSITOR = 0xB,
        DESTINATION = 0xC,
        VIDEO_PLAYER = 0xD,
        VOLUMELIGHT = 0xE,
        FOGBOX = 0xF,
        CROWDENTITY = 0x10,
        GLOBALLIGHT = 0x11,
        SCATTER = 0x12,
        MIRROR = 0x13,
        CUBEMAPPROBE = 0x14,
        TYPE_SIZE = 0x15,
        RENDERABLE_TYPE_MASK = 0x7,
        RENDERABLE_TYPE_FIRST = 0x0,
        RENDERABLE_TYPE_LAST = 0x2,
    };

    enum FLAGS
    {
        PERFORM_VISIBILITY_TEST = 0x800,
        IS_RENDERABLE = 0x1000,
        CAST_SHADOWS = 0x4000,
        HAS_TRANSPARENCY = 0x8000,
        HAS_PLANAR_REFLECTION = 0x10000,
        HAS_REFRACTION = 0x20000,
        HAS_DECALS = 0x40000,
        HAS_USES_DISCARD = 0x80000,
        HAS_USES_LM_SKIN = 0x100000,
        IS_DYNAMIC = 0x200000,
        HAS_TRANS_LIT = 0x400000,
        IS_PLAYER = 0x800000,
        DONT_DRAW = 0x1000000,
        ROOM_MANAGER_IN_CLIENT = 0x2000000,
        IS_GHOST = 0x4000000,
        TEST_MIRROR = 0x8000000,
        HAS_PACKED_OVERLAPING_ROOMS = 0x10000000,
        IS_GLOWING_BACKGROUND = 0x20000000,
        IS_GLOWING_BACKGROUND_UNMASKED = 0x40000000,
        DEBUG_ROOM_TRACK = 0x80000000,
    };

    enum LIGHT_SHADOW_PRIORITY_FLAGS
    {
        LSP_IS_INSIDE = 0x1,
        LSP_WANTS_SHADOW = 0x2,
        LSP_MAX_FLAG = 0x8000,
    };
};