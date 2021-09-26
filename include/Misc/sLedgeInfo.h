#pragma once

#include "SVector3.h"

struct sLedgeInfo
{
	SVector3 m_vPelvisPushDir;
	float m_fClavRot;
	bool m_bRetargetFeet;

	sLedgeInfo() = default;
	~sLedgeInfo() = default;
	sLedgeInfo& operator=(sLedgeInfo& other);
};
