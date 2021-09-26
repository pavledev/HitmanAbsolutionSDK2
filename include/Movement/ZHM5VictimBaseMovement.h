#pragma once

#include "ZHM5BaseMovement.h"
#include "TSharedPointer.h"
#include "HM5Utils.h"
#include "EBaseMovementType.h"
#include "EHM5ResetReason.h"
#include "SMatrix.h"
#include "TEntityRef.h"
#include "ZString.h"
#include "float4.h"

class IMorphemeEntity;
class ZActor;
class ZControlledAnimLocomotion;
class ZHitman5;
struct SGameUpdateEvent;

class ZHM5VictimBaseMovement : public ZHM5BaseMovement
{
public:
	TEntityRef<ZActor> m_pVictim;
	TSharedPointer<ZControlledAnimLocomotion> m_pVictimLocomotion;
	bool m_bWantsControl;
	ZString m_StateMachineName;
	ZString m_AnimNodeName;
	unsigned int m_nAnimNodeID;
	unsigned int m_nMovementStatMachineID;
	SMatrix m_mvHMStartPos;
	SMatrix m_mvHMBlendInPos;
	SMatrix m_mvHMBlendOutPos;
	SMatrix m_mvHMExitPos;
	float m_fBlendInFraction;
	float m_fBlendOutFraction;
	float m_fEarlyOutFraction;
	float m_fAnimDurationReciprocal;
	float m_fAnimFraction;
	float m_fActivateRagdollFraction;
	bool m_bAttachCamera;
	float m_fCameraFOV;
	float m_fCameraBlendTime;
	float m_fEndCameraFollowFraction;
	bool m_bCCScaleActor;
	float m_fCCScaleUpWindowStartTime;
	float m_fCCScaleUpWindowEndTime;
	float m_fCCScaleDownWindowStartTime;
	float m_fCCScaleDownWindowEndTime;
	float m_fCCScaleUpBlend;
	float m_fCCScaleDownBlend;
	float m_fFallSoundTime;
	bool m_bFallSoundTriggered;
	bool m_bControlledStateEntered;
	bool m_bBlendToControlledState;
	bool m_bInterpolateCamBetweenFrames;
	float4 m_vNPCTranslationOffset;
	HM5Utils::SAnimBlend* m_pAnimBlends;
	SMatrix* m_pBlendMats;
	unsigned int m_nNumBlends;
	HM5Utils::SAnimBlend m_aBaseAnimBlends[4];
	SMatrix m_aBaseBlendMats[4];

	~ZHM5VictimBaseMovement() override = default;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	void DeactivateMovement() override;
	void UpdateMovementMatPos(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent) override;
	void UpdateOutsideControl() override;
	void RemoveControl() override;
	void ResetMovement(EHM5ResetReason eReason) override;
	virtual bool SetUpAnimation();
	virtual bool InitTimeFractions();
	virtual void InitBlendMatrices();
	virtual SMatrix GetColiFreeStartPos() const;
	virtual SMatrix GetBlendInMatPos() const;
	virtual SMatrix GetBlendOutMatPos() const;
	virtual SMatrix CalcHitmanExitMatPos(const SMatrix& mvColiFreeStart, const SMatrix& mvBlendInPos, unsigned int nAninmNodeID, float fBlendInFraction, float fBlendOutFraction) const;
	virtual SMatrix CalcAlignedMatPos(const SMatrix& mHitman, unsigned int iAlignBoneID, float fAlignFraction);

	ZHM5VictimBaseMovement() = default;
	ZHM5VictimBaseMovement(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman, EBaseMovementType eType);
	const TEntityRef<ZActor>& GetVictim() const;
	void UpdateActorScaling();
	void UpdateEarlyOut(const SMatrix& mvTo, const bool bActivateRagdoll);
	void InitVictimLocomtion();
};
