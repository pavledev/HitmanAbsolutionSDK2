#pragma once

#include "SVector3.h"

struct SBoneDefinition
{
	SVector3 Center;
	unsigned int lPrevBoneNr;
	SVector3 Size;
	char Name[34];
	unsigned char nBodyPart;

	SBoneDefinition() = default;
	~SBoneDefinition() = default;
};
