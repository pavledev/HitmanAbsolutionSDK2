#pragma once

#include "ZString.h"
#include "TArrayRef.h"

struct SPoseBone;
struct SQV;
struct SRawFacePose;

class ZAnimationFacePose
{
public:
	SRawFacePose* m_pRawFacePose;

	ZAnimationFacePose() = default;
	ZAnimationFacePose(const ZString& sName, const SPoseBone* pFirst, const int* pMeshIDs, int nCount);
	ZAnimationFacePose(const ZAnimationFacePose& rhs);
	~ZAnimationFacePose() = default;
	ZString GetName() const;
	const TArrayRef<SQV> GetBones() const;
	const TArrayRef<int> GetBoneMeshIDs() const;
};
