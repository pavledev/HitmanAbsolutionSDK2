#pragma once

#include "ZPathfinder2.h"
#include "SAnimSample.h"
#include "SMatrix33.h"
#include "SAnimCollision.h"

class ZFindAnimPos
{
public:
	struct SAnimCollision
	{
		float4 m_vEdgeVertex0;
		float4 m_vEdgeVertex1;
		float4 m_vNormal;
		float m_fTranslation;
		ZPF5Location m_PF5Collision;
		bool m_bGround;
		bool m_bCollision;

		void Reset();
		SAnimCollision() = default;
	};

	ZPathfinder2* m_pPathfinder;
	SAnimSample m_AnimSample;
	ZFindAnimPos* m_pAnimPosConstrain;
	SMatrix33 m_mRotContrainAnim;
	float m_fLengthContrainAnim;
	ZPF5Location m_PF5Location;
	float4 m_vStartPos;
	unsigned short m_nAllowMask;
	SAnimCollision m_AnimCollision;

	ZFindAnimPos() = default;
	~ZFindAnimPos() = default;
	void Init(const float4& vPos, ZFindAnimPos* pAnimPos, float fLength, const SMatrix& mConstrainRot, bool bMapOnPathfinder, unsigned short nAllowMask);
	bool Relax();
	SMatrix GetWorldMatrix() const;
	SAnimSample& GetAnimSample();
	void DrawDebug(unsigned int iColor);
	void UpdateAnimCollision(const ZPF5LineHitInfo& Coli, SVector3 vEndPos, bool bGround);
	void SolveGroundCollision();
	bool Solve();
	bool DistConstrainSatisfied() const;
	void FindCollisions();
	void SolveAnimDistConstrain();
	bool FindBoneCollisions(ZFindAnimPos* pFindAnimPos, bool bOwn, const ZPF5Location* pBuffer);
	bool FindGroundCollisions(ZFindAnimPos* pFindAnimPos, bool bOwn, ZPF5Location* pBuffer);
};
