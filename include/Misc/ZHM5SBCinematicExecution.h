#pragma once

#include "SHM5SBShared.h"
#include "ESBHand.h"
#include "ESBCinematicState.h"
#include "SSBConfiguration.h"
#include "SCinematicTags.h"

class ZHM5SBCinematicExecution
{
public:
	struct SCinematicTags
	{
		bool m_bCinematicShot;
		bool m_bCinematicShotSlow;
		bool m_bSequenceEnd;
		bool m_bSequenceActorEnd;

		void Reset();
	};

	const SHM5SBShared& m_SBShared;
	float m_fMaxTimeMultiplier;
	unsigned int m_nCurrentTag;
	ZMapPoly m_MapPoly;
	ZMapPoly m_MapPolyZoom;
	float4 m_vAimPos;
	SSBAnim::ESBHand m_eAimingHand;
	float m_fExecutionFraction;
	float m_afTimeSinceLastShot[2];
	bool m_bTriggeredPushed[2];
	bool m_bZoomHasBeenReleasedSinceStart;
	ESBCinematicState m_eCinematicState;
	SSBConfiguration m_ConfigurationShot;
	SSBConfiguration m_ConfigurationBulletImpact;
	SSBConfiguration m_ConfigurationHitmanView;
	SSBConfiguration m_ConfigurationBulletImpactPre;
	SSBConfiguration m_ConfigurationLastKill;
	unsigned int m_nCinematicTag;
	float m_fCinematicMultiplier;
	float m_fCinematicStateTime;
	float m_fLockExecutionFraction;
	float m_fHitmanViewFraction;
	unsigned int m_nLastZoomTag;
	unsigned int m_nLastHitmanTag;
	bool m_bPlayImpacts;
	bool m_bCinematicShotRightHand;
	unsigned int m_nSequenceElements;
	unsigned int m_nReverseShotIndex;
	unsigned int m_nCinematicIndex;
	bool m_bIsCinematic;
	bool m_bCinematicExit;
	bool m_bZoomActivated;
	bool m_bZoomStartLock;
	bool m_bZoomAllowed;
	bool m_bCheckTransitionToTargetView;
	HM5Utils::SAnimBlend m_sAnimBlend;
	SMatrix m_mvStart;
	SMatrix m_mvEnd;
	float m_fAnimFraction;
	float m_fAnimFractionStart;
	bool m_bAnimating;
	unsigned int m_nNumShotsAtAnimStart;
	const SSBAnim* m_pCurrentAnimation;
	const SSBAnim* m_pLastAnimation;
	SSBAimInfo m_SBAimInfo;
	ESBWeaponType m_eSBWeaponType;
	float m_fEndTimer;
	float4 m_vFilterAimPos;
	unsigned int m_nAimTag;
	float m_fMinTimeForHitmanView;
	SCinematicTags m_anCinematic[32];

	ZHM5SBCinematicExecution() = default;
	ZHM5SBCinematicExecution(const SHM5SBShared& SBShared);
	bool Update(const SGameUpdateEvent& updateEvent, SMatrix& mvTo);
	void Reset(ESBTagMode eSBTagMode, ESBWeaponType eSBWeaponType);
	float GetMaxTimeMultiplier() const;
	float GetAnimFraction() const;
	unsigned int GetAnimNode() const;
	bool IsAnimating() const;
	const SSBAnim* GetCurrentAnimation() const;
	SMatrix GetAnimEnd() const;
	float GetExecutionFraction() const;
	bool CameraZoom() const;
	float GetHitmanViewFraction() const;
	void Start(const SMatrix& mvHitman);
	bool IsCinematic() const;
	void SkipCinematic();
	float GetCinematicMultiplier() const;
	const SSBAimInfo& GetSBAimInfo() const;
	void CalcCinematicSequence();
	void FireAtTag(bool bRightHand);
	void UpdateReleaseTrigger(const SGameUpdateEvent& updateEvent, bool bForce);
	bool WillFireUsingRightHand() const;
	void StartMorphemeNetworkIfNeeded();
	void UpdateCinematics(const bool bExit);
	void ShotFiredCinematics(unsigned int nTagShotAt, bool bRightHand);
	bool GotSameTarget(const ZHM5SBTag& LHS, const ZHM5SBTag& RHS) const;
	bool UpdateAnimation(float fExecutionFraction, bool bShotFired, const SMatrix& mvTo);
	void EnterHitmanView(const unsigned int nTag);
	bool EnterHitmanViewFromAnimation(const unsigned int nTag);
	bool StayInHitmanView(const unsigned int nTag);
	void UpdateCinematicShot(bool bNewAnimation, const SSBAnim* pAnim, const unsigned int nTag);
	bool UpdateAnimationBlend(SMatrix& mvTo, const ZHM5SBTag& Tag);
	const SSBAnim* SelectAnimation(const SMatrix& mHitman, const bool bShotFired, const unsigned int nTag, const bool bForceAnimationWithRotation) const;
	void StartAnimation(const SMatrix& mHitman, const SSBAnim* pAnim, const unsigned int nTag);
	void UpdateAimInfo(float fExecutionFraction, const ZHM5SBTag& Tag, bool bShotFired, const unsigned int nTagIndex);
	~ZHM5SBCinematicExecution() = default;
};
