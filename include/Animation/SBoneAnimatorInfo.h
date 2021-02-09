#pragma once

#include "ZAnimationBoneData.h"
#include "ZDelegate.h"

class SBoneAnimatorInfo
{
    ZAnimationBoneData* m_pBoneData;
    ZDelegate<void __cdecl(void)> m_NotifyBonesChanged;
    ZDelegate<void __cdecl(void)> m_ResendInfo;
};
