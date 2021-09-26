#pragma once

#include "sAttacherBoneElement.h"

struct sHand : sAttacherBoneElement
{
	bool bRightHand;

	sHand() = default;
	sHand(bool bRightH);
	~sHand() = default;
};
