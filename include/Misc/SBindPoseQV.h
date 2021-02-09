#pragma once

#include "SFloat16.h"

class SBindPoseQV
{
public:
    SFloat16 rotation[4];
    SFloat16 translation[3];
};
