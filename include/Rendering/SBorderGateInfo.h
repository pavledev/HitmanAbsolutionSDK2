#pragma once

struct SBorderGateInfo
{
	float fSortValue;
	unsigned short nGateId;
	bool bReverse;

	SBorderGateInfo() = default;
	~SBorderGateInfo() = default;
	bool operator<(const SBorderGateInfo& other);
};
