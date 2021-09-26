#pragma once

struct SFacePoseChannel
{
	char* pszPoseName;
	float* aWeights;
	unsigned int nUid;

	SFacePoseChannel() = default;
	~SFacePoseChannel() = default;
};
