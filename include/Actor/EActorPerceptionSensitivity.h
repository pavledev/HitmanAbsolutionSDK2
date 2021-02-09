#pragma once

enum EActorPerceptionSensitivity : __int32
{
    APS_AMBIENT_DEAFBLIND = 0x0,
    APS_AMBIENT_SLEEPING = 0x1,
    APS_AMBIENT_PREOCCUPIED = 0x2,
    APS_AMBIENT = 0x3,
    APS_ALERT = 0x4,
    APS_COMBAT = 0x5,
    APS_SPIDER_SENSE = 0x6,
    APS_NUM_PERCEPTION_LEVELS = 0x7
};
