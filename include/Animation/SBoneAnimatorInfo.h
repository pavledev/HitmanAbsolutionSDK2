#pragma once

#include "ZDelegate.h"

class ZAnimationBoneData;

struct SBoneAnimatorInfo
{
	ZAnimationBoneData* m_pBoneData;
	ZDelegate<void __cdecl(void)> m_NotifyBonesChanged;
	ZDelegate<void __cdecl(void)> m_ResendInfo;

	SBoneAnimatorInfo() = default;
	~SBoneAnimatorInfo() = default;
	static void DoNothing();
};
