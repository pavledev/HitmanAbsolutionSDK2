#pragma once

#include "TArrayRef.h"

struct SBoneDefinition;

class ZAnimationBoneHierarchy
{
public:
	int* m_pParentIndexes;
	TArrayRef<int> m_aParentIndexes;
	int* m_pParentListIndexes;
	TArrayRef<int> m_aParentListIndexes;
	bool m_bDirty;

	ZAnimationBoneHierarchy(const ZAnimationBoneHierarchy& __that);
	ZAnimationBoneHierarchy() = default;
	~ZAnimationBoneHierarchy() = default;
	void SetParentIndexes(const SBoneDefinition* pBoneDefinitions, int nBoneCount);
	const int operator[](int nIndex) const;
	void Set(int nIndex, int nValue);
	const TArrayRef<int> ToArrayRef() const;
	const TArrayRef<int> ToArrayRefUpdateList() const;
	void ResizeParentIndices(unsigned int size) const;
	void ResizeParentListIndices(unsigned int size) const;
	void Rebuild() const;
	ZAnimationBoneHierarchy& operator=(const ZAnimationBoneHierarchy& __that);
};
