#pragma once

#include "THashMap.h"
#include "TArrayRef.h"

class ZAnimationFacePose;
struct SRawFacePoseCollection;
template <class A, class B> class TDefaultHashMapPolicy;

class ZAnimationFacePoseCollection
{
public:
	THashMap<unsigned int, ZAnimationFacePose, TDefaultHashMapPolicy<unsigned int, ZAnimationFacePose>> m_facePoses;
	SRawFacePoseCollection* m_pRawFacePoseCollection;

	ZAnimationFacePoseCollection(const ZAnimationFacePoseCollection& __that);
	ZAnimationFacePoseCollection() = default;
	~ZAnimationFacePoseCollection() = default;
	void Init(const THashMap<unsigned int, ZAnimationFacePose, TDefaultHashMapPolicy<unsigned int, ZAnimationFacePose>>& facePoses, const int* pBoneIDs, int nBoneCount);
	const ZAnimationFacePose* GetFacePose(const char* pName) const;
	const ZAnimationFacePose& GetFacePose(int nIndex) const;
	int Count() const;
	const TArrayRef<int> GetFaceBoneIDs() const;
	const SRawFacePoseCollection* GetRawData() const;
	ZAnimationFacePoseCollection& operator=(const ZAnimationFacePoseCollection& __that);
};
