#pragma once

#include "eItemType.h"

struct SRecoilEntry
{
	unsigned int m_nAnimNodeID;
	float m_fAnimDuration;
	float m_fAnimTime;
	bool m_bKeepHandsRelative;
	bool m_bLeftHandRelativeAnimation;
	bool m_bMirror;
	bool m_bSwapAttachers;
	eItemType m_eItemType;

	SRecoilEntry() = default;
	~SRecoilEntry() = default;
	void Reset();
};
