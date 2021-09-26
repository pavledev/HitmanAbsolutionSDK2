#pragma once

#include "SQV.h"

struct SCamAlignData
{
	SQV mObjectToWorld;
	SQV mViewToWorld;
	unsigned char numBones;
	unsigned char* pBonesStart;

	int GetSize() const;
	static int GetSize(const int numBonesInput);
	static int GetBonesOffset();
	SCamAlignData() = default;
	~SCamAlignData() = default;
};
