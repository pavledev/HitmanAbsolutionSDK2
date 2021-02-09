#pragma once

#include "SVector3.h"

struct alignas(4) SBoneDefinition
{
    SVector3 Center;
    unsigned int lPrevBoneNr;
    SVector3 Size;
    char Name[34];
    unsigned __int8 nBodyPart;
};
