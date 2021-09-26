#pragma once

#include "float4.h"

class IEntity;

class ZHM5CameraColi
{
public:
	struct SCameraCollision
	{
		float4 lp;
		float4 ln;
		float4 cp;
		float t;
		IEntity* pEntity;
		float fLength;
		bool bColi;
	};

	SCameraCollision m_ColiInfo[5];
	float m_fColiLength;
	bool m_bColi;
	float m_fDistWall;
	int m_iCurColi;
	int m_iClosestColi;
	float4 m_vRatioDistanceToWall;

	ZHM5CameraColi() = default;
	~ZHM5CameraColi() = default;
	float GetColiLength();
	bool CheckColi(const float4& vFrom, const float4& vTo);
	void CalcCollisionParameters(const float4& vFrom, const float4& vTo);
};
