#pragma once

#include "SVector3.h"

class alignas(4) SGateDesc
{
    SVector3 vPortalOS[4];
    unsigned __int8 nFlags;
};
