#pragma once

#include "SSBCamHitmanProfile.h"
#include "ESBPose.h"

class ZHM5SBCamProfiles;
class ZLinkedEntity;
struct SMatrix;
struct float4;
template <class T> class TEntityRef;

class ZHM5SBCameraProfileDatabase
{
public:
	SSBCamHitmanProfile m_aHitmanTargetView[64];
	unsigned int m_nNumHitmanTargetView;
	SSBCamHitmanProfile m_aHitmanView[64];
	unsigned int m_nNumHitmanView;
	ZLinkedEntity* m_pLinkedEntity;

	static const unsigned int MAX_HTV_PROFILES;
	static const unsigned int MAX_HV_PROFILES;

	ZHM5SBCameraProfileDatabase() = default;
	~ZHM5SBCameraProfileDatabase() = default;
	void AddProfiles(const TEntityRef<ZHM5SBCamProfiles>& rSBCamProfiles);
	void AddHitmanTargetViewProfile(const SSBCamHitmanProfile& Profile);
	void AddHitmanViewProfile(const SSBCamHitmanProfile& Profile);
	void SetLinkedEntity(ZLinkedEntity* pLinkedEntity);
	SSBCamHitmanProfile GetClosestProfile(const SMatrix& mCam, const float4& vLookAtPoint, ESBPose eSBPose, const bool bTargetView) const;
	SSBCamHitmanProfile CutToHitman(const SMatrix& mCam, const float4& vLookAtPoint, ESBPose eSBPose, const float4& vTarget, const bool bTargetView) const;
};
