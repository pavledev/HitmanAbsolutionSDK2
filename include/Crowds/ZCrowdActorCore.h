#pragma once

#include "SVector3.h"
#include "SVector2.h"
#include "CrowdUtil.h"

struct float4;

class ZCrowdActorCore
{
public:
	struct SActorIndex
	{
		unsigned short m_type : 3;
		unsigned short m_index : 13;

		SActorIndex() = default;
	};

	SVector3 m_vPosition;
	SVector2 m_vForward;
	SActorIndex m_actorIndex;
	short m_nNextObstacleInCellIndex;
	int m_nPackedCellData;
	float m_nSpeed;
	unsigned char m_nPossessed : 1;
	unsigned char m_nMood : 7;
	unsigned char m_nLODAndCulledFlag;

	ZCrowdActorCore() = default;
	~ZCrowdActorCore() = default;
	void SetPosition(const float4& vPos);
	float4 GetPosition() const;
	void SetForward(const float4& v);
	float4 GetForward() const;
	float4 GetUp() const;
	float4 GetSide() const;
	void SetSpeed(float s);
	float GetSpeed() const;
	float4 GetVelocity() const;
	CrowdUtil::ECrowdActorMood GetMood() const;
	void SetMood(CrowdUtil::ECrowdActorMood eMood);
	unsigned char GetPossessed() const;
	void SetPossessed(unsigned char nPossessed);
	void SetLODAndCulledFlag(unsigned char nFlag);
	unsigned char GetLODAndCulledFlag() const;
	unsigned char GetCurrentLOD() const;
	bool IsCulled() const;
	bool IsEnabled() const;
	bool IsPossessed() const;
	unsigned short GetActorType() const;
	unsigned short GetActorIndex() const;
	void SetActorType(unsigned short type);
	short GetNextObstacle() const;
	void SetNextObstacle(short nNext);
	void SetPackedCellData(int i);
	unsigned int GetPackedCellData() const;
	bool IsInCrowd() const;
	unsigned int GetCrowdIndex() const;
	unsigned int GetCellIndex() const;
};
