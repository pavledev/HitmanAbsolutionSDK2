#pragma once

#include "ZSPUAnimationClip.h"
#include "ESyncEvent.h"

class ZSPUTransitionClip : public ZSPUAnimationClip
{
public:
	const unsigned short* m_ppuTransitionTable;
	unsigned char m_numSourceClips;
	unsigned char m_numTargetClips;
	unsigned char m_firstSyncEvent;
	unsigned char m_bMustAlwaysBeUsed;

	ZSPUTransitionClip() = default;
	~ZSPUTransitionClip() = default;
	bool canTransition(unsigned short source, unsigned short target) const;
	bool mustAlwaysBeUsed() const;
	ESyncEvent getFirstSyncEvent() const;
};
