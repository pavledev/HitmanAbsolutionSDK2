#pragma once

class ZAnimationClipEntity;

struct ZAnimationClipInfo
{
	ZAnimationClipEntity* m_clip;
	unsigned short m_clipIndex;
	unsigned int m_numFrames;
	unsigned int m_usedCount;
	unsigned int m_keyframeOffset;

	ZAnimationClipInfo() = default;
	ZAnimationClipInfo(ZAnimationClipEntity* clip, unsigned short clipIndex, unsigned int numFrames, unsigned int offset);
	~ZAnimationClipInfo() = default;
};
