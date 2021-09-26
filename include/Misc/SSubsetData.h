#pragma once

#include "ZString.h"
#include "TArray.h"

struct STypeID;
template <class A, class B> class TPair;

struct SSubsetData
{
	ZString m_sSubsetName;
	unsigned int m_nSubsetFlags;
	STypeID* m_subsetType;
	TArray<int> m_aEntityOffsets;
	TArray<TPair<int, SSubsetData*>> m_aEntitySubsets;

	SSubsetData(const SSubsetData& __that);
	SSubsetData() = default;
	~SSubsetData() = default;
};
