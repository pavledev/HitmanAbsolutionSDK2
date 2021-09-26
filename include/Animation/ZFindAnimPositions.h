#pragma once

#include "ZFindAnimPos.h"

class ZFindAnimPositions
{
public:
	ZFindAnimPos m_aFindAnimPos[2];
	bool m_abConstrainPos[2];
	bool m_bSolved;
	int m_iNumIter;
	float m_fTimeSpent;

	ZFindAnimPositions() = default;
	~ZFindAnimPositions() = default;
	void Init(const SMatrix& mConstrain0, const SMatrix& mConstrain1, const float4& vPos0, const float4& vPos1, const bool bConstrainPos0, const bool bConstrainPos1, const unsigned short nAllowMask);
	SAnimSample& GetAnimSample(int iIndex);
	SMatrix GetWorldMatrix(int iIndex);
	bool Solve(int iNumIter);
	bool GetSolved() const;
	void ClearSolved();
	void SetOwnerAnimSample(const SMatrix& mConstrain0, const float4& vSecoundGround, SAnimSample& AnimSample);
};
