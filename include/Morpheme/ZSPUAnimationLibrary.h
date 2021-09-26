#pragma once

class ZSPUAnimationClip;
class ZSPUTransitionClip;

class ZSPUAnimationLibrary
{
public:
	unsigned int m_instanceSizeInBytes;
	unsigned int m_numAnimationClips;
	unsigned int m_numOverrideClips;
	unsigned int m_numTransitionClips;
	unsigned int m_numTotalClips;
	unsigned short m_defaultClip;
	const ZSPUAnimationClip* m_animClips;
	const ZSPUTransitionClip* m_transitionClips;
	const unsigned short* m_transitionTable;

	ZSPUAnimationLibrary() = default;
	~ZSPUAnimationLibrary() = default;
	unsigned short GetDefaultClip() const;
	const ZSPUAnimationClip* GetClip(unsigned short clipIndex) const;
	const ZSPUTransitionClip* GetTransitionClip(unsigned int nIndex) const;
	unsigned int GetNumAnimationClips() const;
	unsigned int GetNumOverrideClips() const;
	unsigned int GetNumTransitionClips() const;
};
