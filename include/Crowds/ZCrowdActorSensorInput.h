#pragma once

#include "SVector2.h"

struct float4;

class ZCrowdActorSensorInput
{
public:
	float m_nActorRadius;
	float m_nStaticProbeLength;
	SVector2 m_vStaticProbeDir;
	float m_nWantedNeighborhoodRadius;
	SVector2 m_vDynamicProbeDir;
	float m_nDynamicProbeOffset;
	float m_nDensityCheckRadius;
	SVector2 m_vDensityCheckDir;
	float m_nDensityCheckOffset;
	short m_nIgnoreList[4];
	unsigned char m_nNumActiveIgnoreSlots;
	unsigned char m_bAllowPanicOnlyCells;
	unsigned char m_bAllowTeleportOutCells;
	unsigned char m_bIgnoreDeadBodies;
	unsigned char m_bIgnorePanicedActors;
	unsigned char __padding__[3];

	static const unsigned int IGNORE_LIST_SIZE;
	static const short UNUSED_IGNORE_SLOT;

	ZCrowdActorSensorInput() = default;
	~ZCrowdActorSensorInput() = default;
	void ClearSensorInput();
	bool GetAllowPanicOnlyCells() const;
	void SetAllowPanicOnlyCells(bool b);
	bool GetAllowTeleportOutCells() const;
	void SetAllowTeleportOutCells(bool b);
	bool GetIgnoreDeadBodies() const;
	void SetIgnoreDeadBodies(bool b);
	bool GetIgnorePanicedActors() const;
	void SetIgnorePanicedActors(bool b);
	bool AddToIgnoreList(short nIgnoreID);
	bool IsOnIgnoreList(short nIgnoreID) const;
	unsigned char GetNumActiveIgnoreSlots() const;
	short GetIgnoredActorSlot(unsigned char nIndex) const;
	void ClearIgnoredActorSlot(unsigned char nIndex);
	float GetActorRadius() const;
	void SetActorRadius(float nDist);
	float GetStaticProbeLength() const;
	void SetStaticProbeLength(float nDist);
	void SetStaticProbeDir(const float4& vDir);
	float4 GetStaticProbeDir() const;
	float GetWantedNeighborhoodRadius() const;
	void SetWantedNeighborhoodRadius(float nRadius);
	void SetDynamicProbeDir(const float4& vDir);
	float4 GetDynamicProbeDir() const;
	void SetDynamicProbeOffset(float nOfs);
	float GetDynamicProbeOffset() const;
	float GetDensityCheckRadius() const;
	void SetDensityCheckRadius(float nRadius);
	void SetDensityCheckDir(const float4& vDir);
	float4 GetDensityCheckDir() const;
	void SetDensityCheckOffset(float nOfs);
	float GetDensityCheckOffset() const;
};
