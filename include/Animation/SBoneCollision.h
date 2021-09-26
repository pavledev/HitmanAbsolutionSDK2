#pragma once

struct SBoneCollision
{
	unsigned char m_nBoneId;
	float m_nT;

	SBoneCollision(unsigned char nBone, float nT);
	SBoneCollision() = default;
	~SBoneCollision() = default;
};
